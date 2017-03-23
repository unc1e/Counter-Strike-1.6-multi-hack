#include "main.h"

DWORD WINAPI DllMain(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hinstDLL);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thread, 0, 0, 0);
	}

	return true;
}

DWORD WINAPI Thread()
{
	CreateConsole();

	DWORD HlBase = (DWORD)GetModuleHandleA(NULL);
	DWORD HwBase = (DWORD)GetModuleHandleA("hw");
	DWORD SwBase = (DWORD)GetModuleHandleA("sw");
	DWORD baseAddr;

	if (HwBase == 0 && SwBase == 0)
		baseAddr = HlBase;
	else
		if (HwBase == 0) baseAddr = SwBase;
		else baseAddr = HwBase;

	pEngine = (struct cl_enginefuncs_s*)(FindPattern(baseAddr, INFINITE, "\x69\x6E\x76\x61\x6C\x69\x64\x20\x73\x6F\x75\x6E\x64\x20\x25\x69\x0A", "xxxxxxxxxxxxxxxxx") + 24);
	pClient = *(struct cl_clientfuncs_s**)(FindPattern(baseAddr, INFINITE, "\xFF\x15\x00\x00\x00\x00\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x83\xC4\x1C", "xx????x????x????xxx") + 2);
	pStudio = *(struct engine_studio_api_s**)(FindPattern(baseAddr, INFINITE, "\x68\x00\x00\x00\x00\x68\x00\x00\x00\x00\x6A\x01\xFF\xD0\x83\xC4\x0C", "x????x????xxxxxxx") + 1);

	memcpy(&Engine, pEngine, sizeof(struct cl_enginefuncs_s));
	memcpy(&Client, pClient, sizeof(struct cl_clientfuncs_s));
	memcpy(&Studio, pStudio, sizeof(struct engine_studio_api_s));
	
	Sound.ReadCount = (unsigned int*)(FindPattern(baseAddr, INFINITE, "\x08\xDB\xA8\x04\x00\x00", "xxxxxx") - 24);
	Sound.buf = (DWORD*)(FindPattern(baseAddr, INFINITE, "\x00\xC0\xE5\x37", "xxxx") + 25);
	StartReading = (StartReading_t)FindPattern(baseAddr, INFINITE, "\xA1\x28\x3D\x8F\x05\x33\xC9", "xxxxxxx");
	EndReading = (EndReading_t)FindPattern(baseAddr, INFINITE, "\x8B\x4C\x24\x04\xA1\x50\xCB\xC4\x04\x3B", "xxxxxxxxxx");
	ReadBits = (ReadBits_t)FindPattern(baseAddr, INFINITE, "\xA1\x2C\x3D\x00\x05\x85\xC0\x74\x06\xB8\x01\x00\x00\x00\xC3\x53", "xxx?xxxxxxxxxxxx");
	ReadOrigin = (ReadOrigin_t)FindPattern(baseAddr, INFINITE, "\x53\x56\x57\xE8\x48\xFC\xFF\xFF", "xxxxxxxx");

	GlobalTime = *(double**)((DWORD)Engine.pNetAPI->SendRequest + 81);

	struct usermsg_s* userMsg;
	userMsg = **(struct usermsg_s***)(FindPattern(baseAddr, INFINITE, "\x8B\x35\x00\x00\x00\x00\x83\xC4\x30", "xx????xxx") + 2);
	while (userMsg)
	{
		if (!strcmp(userMsg->name, "TeamInfo"))
		{
			original_TeamInfo = userMsg->pfn;
			userMsg->pfn = (UserMsg_t)handler_TeamInfo;
		}
		else if (!strcmp(userMsg->name, "ResetHUD"))
		{
			original_ResetHUD = userMsg->pfn;
			userMsg->pfn = (UserMsg_t)handler_ResetHUD;
		}

		userMsg = userMsg->next;
	}

	struct event_s* event;
	event = *(struct event_s**)(baseAddr + 0x1AFF90);
	while (event)
	{
		if (!strcmp(event->name, "events/createsmoke.sc"))
		{
			original_CreateSmoke = event->pfn;
			event->pfn = (Event_t)handler_CreateSmoke;
		}

		event = event->next;
	}

	struct enginemsg_s* engineMsg;
	engineMsg = (struct enginemsg_s*)FindPattern(baseAddr, INFINITE, "\x00\x00\x00\x00\xFC\xB8\x00\x04", "xxxxxx?x");
	while (strcmp(engineMsg->name, "End of List")) //this name means that it is the end
	{
		if (!strcmp(engineMsg->name, "svc_sound"))
		{
			original_SVC_Sound = engineMsg->pfn;
			engineMsg->pfn = (EngineMsg_t)handler_SVC_Sound;
		}

		engineMsg++;
	}

	pClient->HUD_Redraw     = handler_HUD_Redraw;
	pClient->CL_CreateMove  = handler_CL_CreateMove;
	pClient->V_CalcRefdef   = handler_V_CalcRefdef;
	pClient->HUD_Key_Event  = handler_HUD_Key_Event;
	pClient->HUD_PlayerMove = handler_HUD_PlayerMove;
	pClient->HUD_AddEntity  = handler_HUD_AddEntity;
	
	original_StudioEntityLight = (StudioEntityLight_t)DetourFunc((BYTE*)pStudio->StudioEntityLight, (BYTE*)handler_StudioEntityLight, 10);
	original_StudioCheckBBox   = (StudioCheckBBox_t)DetourFunc((BYTE*)pStudio->StudioCheckBBox, (BYTE*)handler_StudioCheckBBox, 5);

	FillMenu();
	UpdateSettings();

	return true;
}