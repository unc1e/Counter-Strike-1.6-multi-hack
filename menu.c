#include "menu.h"

void FillMenu()
{
	memcpy(MenuNames[0], MENU_NAME_ESP,      sizeof(MENU_NAME_ESP));
	memcpy(MenuNames[1], MENU_NAME_AIMBOT,   sizeof(MENU_NAME_AIMBOT));
	memcpy(MenuNames[2], MENU_NAME_REMOVALS, sizeof(MENU_NAME_REMOVALS));
	memcpy(MenuNames[3], MENU_NAME_OTHER,    sizeof(MENU_NAME_OTHER));

	//esp
	memcpy(SubMenuNames[0][0],  SUBMENU_NAME_ESP_ESP,       sizeof(SUBMENU_NAME_ESP_ESP));
	memcpy(SubMenuNames[0][1],  SUBMENU_NAME_ESP_T_RED,     sizeof(SUBMENU_NAME_ESP_T_RED));
	memcpy(SubMenuNames[0][2],  SUBMENU_NAME_ESP_T_GREEN,   sizeof(SUBMENU_NAME_ESP_T_GREEN));
	memcpy(SubMenuNames[0][3],  SUBMENU_NAME_ESP_T_BLUE,    sizeof(SUBMENU_NAME_ESP_T_BLUE));
	memcpy(SubMenuNames[0][4],  SUBMENU_NAME_ESP_T_ALPHA,   sizeof(SUBMENU_NAME_ESP_T_ALPHA));
	memcpy(SubMenuNames[0][5],  SUBMENU_NAME_ESP_T_WEIGHT,  sizeof(SUBMENU_NAME_ESP_T_WEIGHT));
	memcpy(SubMenuNames[0][6],  SUBMENU_NAME_ESP_CT_RED,    sizeof(SUBMENU_NAME_ESP_CT_RED));
	memcpy(SubMenuNames[0][7],  SUBMENU_NAME_ESP_CT_GREEN,  sizeof(SUBMENU_NAME_ESP_CT_GREEN));
	memcpy(SubMenuNames[0][8],  SUBMENU_NAME_ESP_CT_BLUE,   sizeof(SUBMENU_NAME_ESP_CT_BLUE));
	memcpy(SubMenuNames[0][9],  SUBMENU_NAME_ESP_CT_ALPHA,  sizeof(SUBMENU_NAME_ESP_CT_ALPHA));
	memcpy(SubMenuNames[0][10], SUBMENU_NAME_ESP_CT_WEIGHT, sizeof(SUBMENU_NAME_ESP_CT_WEIGHT));
	memcpy(SubMenuNames[0][11], SUBMENU_NAME_ESP_BARREL,    sizeof(SUBMENU_NAME_ESP_BARREL));
	memcpy(SubMenuNames[0][12], SUBMENU_NAME_ESP_GLOW,      sizeof(SUBMENU_NAME_ESP_GLOW));
	memcpy(SubMenuNames[0][13], SUBMENU_NAME_ESP_SOUND,     sizeof(SUBMENU_NAME_ESP_SOUND));


	SubMenuValues[0][0]  = SUBMENU_VALUE_ESP_ESP;
	SubMenuValues[0][1]  = SUBMENU_VALUE_ESP_T_RED;
	SubMenuValues[0][2]  = SUBMENU_VALUE_ESP_T_GREEN;
	SubMenuValues[0][3]  = SUBMENU_VALUE_ESP_T_BLUE;
	SubMenuValues[0][4]  = SUBMENU_VALUE_ESP_T_ALPHA;
	SubMenuValues[0][5]  = SUBMENU_VALUE_ESP_T_WEIGHT;
	SubMenuValues[0][6]  = SUBMENU_VALUE_ESP_CT_RED;
	SubMenuValues[0][7]  = SUBMENU_VALUE_ESP_CT_GREEN;
	SubMenuValues[0][8]  = SUBMENU_VALUE_ESP_CT_BLUE;
	SubMenuValues[0][9]  = SUBMENU_VALUE_ESP_CT_ALPHA;
	SubMenuValues[0][10] = SUBMENU_VALUE_ESP_CT_WEIGHT;
	SubMenuValues[0][11] = SUBMENU_VALUE_ESP_BARREL;
	SubMenuValues[0][12] = SUBMENU_VALUE_ESP_GLOW;
	SubMenuValues[0][13] = SUBMENU_VALUE_ESP_SOUND;

	sprintf_s(SubMenuSValues[0][0],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][0]);
	sprintf_s(SubMenuSValues[0][1],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][1]);
	sprintf_s(SubMenuSValues[0][2],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][2]);
	sprintf_s(SubMenuSValues[0][3],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][3]);
	sprintf_s(SubMenuSValues[0][4],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][4]);
	sprintf_s(SubMenuSValues[0][5],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][5]);
	sprintf_s(SubMenuSValues[0][6],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][6]);
	sprintf_s(SubMenuSValues[0][7],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][7]);
	sprintf_s(SubMenuSValues[0][8],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][8]);
	sprintf_s(SubMenuSValues[0][9],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][9]);
	sprintf_s(SubMenuSValues[0][10], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][10]);
	sprintf_s(SubMenuSValues[0][11], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][11]);
	sprintf_s(SubMenuSValues[0][12], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][12]);
	sprintf_s(SubMenuSValues[0][13], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][13]);

	//aimbot
	memcpy(SubMenuNames[1][0], SUBMENU_NAME_AIMBOT_AIMBOT,     sizeof(SUBMENU_NAME_AIMBOT_AIMBOT));
	memcpy(SubMenuNames[1][1], SUBMENU_NAME_AIMBOT_BONE,       sizeof(SUBMENU_NAME_AIMBOT_BONE));
	memcpy(SubMenuNames[1][2], SUBMENU_NAME_AIMBOT_DEATHMATCH, sizeof(SUBMENU_NAME_AIMBOT_DEATHMATCH));

	SubMenuValues[1][0] = SUBMENU_VALUE_AIMBOT_AIMBOT;
	SubMenuValues[1][1] = SUBMENU_VALUE_AIMBOT_BONE;
	SubMenuValues[1][2] = SUBMENU_VALUE_AIMBOT_DEATHMATCH;

	sprintf_s(SubMenuSValues[1][0], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[1][0]);
	sprintf_s(SubMenuSValues[1][1], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[1][1]);
	sprintf_s(SubMenuSValues[1][2], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[1][2]);

	//removals
	memcpy(SubMenuNames[2][0], SUBMENU_NAME_REMOVALS_FLASH,  sizeof(SUBMENU_NAME_REMOVALS_FLASH));
	memcpy(SubMenuNames[2][1], SUBMENU_NAME_REMOVALS_SMOKE,  sizeof(SUBMENU_NAME_REMOVALS_SMOKE));
	memcpy(SubMenuNames[2][2], SUBMENU_NAME_REMOVALS_SPREAD, sizeof(SUBMENU_NAME_REMOVALS_SPREAD));

	SubMenuValues[2][0] = SUBMENU_VALUE_REMOVALS_FLASH;
	SubMenuValues[2][1] = SUBMENU_VALUE_REMOVALS_SMOKE;
	SubMenuValues[2][2] = SUBMENU_VALUE_REMOVALS_SPREAD;

	sprintf_s(SubMenuSValues[2][0], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[2][0]);
	sprintf_s(SubMenuSValues[2][1], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[2][1]);
	sprintf_s(SubMenuSValues[2][2], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[2][2]);

	//other
	memcpy(SubMenuNames[3][0], SUBMENU_NAME_OTHER_BUNNYHOP, sizeof(SUBMENU_NAME_OTHER_BUNNYHOP));
	memcpy(SubMenuNames[3][1], SUBMENU_NAME_OTHER_SPEEDHACK, sizeof(SUBMENU_NAME_OTHER_SPEEDHACK));

	SubMenuValues[3][0] = SUBMENU_VALUE_OTHER_BUNNYHOP;
	SubMenuValues[3][1] = SUBMENU_VALUE_OTHER_SPEEDHACK;

	sprintf_s(SubMenuSValues[3][0], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[3][0]);
	sprintf_s(SubMenuSValues[3][1], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[3][1]);
}

void UpdateSettings()
{
	//esp
	Settings.esp           = SubMenuValues[0][0];
	Settings.t_esp.red     = SubMenuValues[0][1];
	Settings.t_esp.green   = SubMenuValues[0][2];
	Settings.t_esp.blue    = SubMenuValues[0][3];
	Settings.t_esp.alpha   = SubMenuValues[0][4];
	Settings.t_esp.weight  = SubMenuValues[0][5] * 0.02f;
	Settings.ct_esp.red    = SubMenuValues[0][6];
	Settings.ct_esp.green  = SubMenuValues[0][7];
	Settings.ct_esp.blue   = SubMenuValues[0][8];
	Settings.ct_esp.alpha  = SubMenuValues[0][9];
	Settings.ct_esp.weight = SubMenuValues[0][10] * 0.02f;
	Settings.barrel        = SubMenuValues[0][11];
	Settings.glow          = SubMenuValues[0][12];
	Settings.sound         = SubMenuValues[0][13];

	sprintf_s(SubMenuSValues[0][0],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][0]);
	sprintf_s(SubMenuSValues[0][1],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][1]);
	sprintf_s(SubMenuSValues[0][2],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][2]);
	sprintf_s(SubMenuSValues[0][3],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][3]);
	sprintf_s(SubMenuSValues[0][4],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][4]);
	sprintf_s(SubMenuSValues[0][5],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][5]);
	sprintf_s(SubMenuSValues[0][6],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][6]);
	sprintf_s(SubMenuSValues[0][7],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][7]);
	sprintf_s(SubMenuSValues[0][8],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][8]);
	sprintf_s(SubMenuSValues[0][9],  sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][9]);
	sprintf_s(SubMenuSValues[0][10], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][10]);
	sprintf_s(SubMenuSValues[0][11], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][11]);
	sprintf_s(SubMenuSValues[0][12], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][12]);
	sprintf_s(SubMenuSValues[0][13], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[0][13]);

	//aimbot
	Settings.aimbot     = SubMenuValues[1][0];
	Settings.bone       = SubMenuValues[1][1];
	Settings.DeathMatch = SubMenuValues[1][2];

	sprintf_s(SubMenuSValues[1][0], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[1][0]);
	sprintf_s(SubMenuSValues[1][1], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[1][1]);
	sprintf_s(SubMenuSValues[1][2], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[1][2]);

	//removals
	Settings.flash  = SubMenuValues[2][0];
	Settings.smoke  = SubMenuValues[2][1];
	Settings.spread = SubMenuValues[2][2];

	sprintf_s(SubMenuSValues[2][0], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[2][0]);
	sprintf_s(SubMenuSValues[2][1], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[2][1]);
	sprintf_s(SubMenuSValues[2][2], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[2][2]);

	//other
	Settings.BunnyHop  = SubMenuValues[3][0];
	Settings.SpeedHack = SubMenuValues[3][1];

	sprintf_s(SubMenuSValues[3][0], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[3][0]);
	sprintf_s(SubMenuSValues[3][1], sizeof(SubMenuSValues[0][0]), "%d", SubMenuValues[3][1]);
}

void OnSubMenu()
{
	switch (Settings.MenuPos)
	{
		case 0:
			Settings.SubMenuTotal = SUBMENU_TOTAL_ESP;
			break;

		case 1:
			Settings.SubMenuTotal = SUBMENU_TOTAL_AIMBOT;
			break;

		case 2:
			Settings.SubMenuTotal = SUBMENU_TOTAL_REMOVALS;
			break;

		case 3:
			Settings.SubMenuTotal = SUBMENU_TOTAL_OTHER;
			break;
	}
}

void MenuKeyEvent(int keynum)
{
	if (!Settings.SubMenu)
	{
		switch (keynum)
		{
			case K_DOWNARROW:
				if (Settings.MenuPos + 1 == MENU_TOTAL)
					Settings.MenuPos = 0;
				else Settings.MenuPos++;
				break;

			case K_UPARROW:
				if (Settings.MenuPos - 1 == -1)
					Settings.MenuPos = MENU_TOTAL - 1;
				else Settings.MenuPos--;
				break;
		}
	}
	else if (Settings.SubMenu)
	{
		switch (keynum)
		{
			case K_DOWNARROW:
				if (Settings.SubMenuPos + 1 == Settings.SubMenuTotal)
					Settings.SubMenuPos = 0;
				else Settings.SubMenuPos++;
				break;

			case K_UPARROW:
				if (Settings.SubMenuPos - 1 == -1)
					Settings.SubMenuPos = Settings.SubMenuTotal - 1;
				else Settings.SubMenuPos--;
				break;

			case K_RIGHTARROW:
				SubMenuValues[Settings.MenuPos][Settings.SubMenuPos] += 1;
				UpdateSettings();
				break;

			case K_LEFTARROW:
				SubMenuValues[Settings.MenuPos][Settings.SubMenuPos] -= 1;
				UpdateSettings();
				break;
		}
	}
}