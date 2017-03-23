#include "handlers.h"

//user msg
void __cdecl handler_TeamInfo(const char* name, int size, void* buf)
{
	if (!strcmp((char*)buf + 1, "CT"))
		Players[*(BYTE*)buf].team = 1;
	else if (!strcmp((char*)buf + 1, "TERRORIST"))
		Players[*(BYTE*)buf].team = 2;

	original_TeamInfo(name, size, buf);
}

void __cdecl handler_ResetHUD(const char* name, int size, void* buf)
{
	GLint dims[4];

	glGetIntegerv(GL_VIEWPORT, dims);

	Screen.width = dims[2];
	Screen.height = dims[3];

	if (!fontBuilt)
	{
		BuildFont();
		fontBuilt = true;
	}

	original_ResetHUD(name, size, buf);
}

//event msg
void __cdecl handler_CreateSmoke(struct event_args_s* args)
{
	if (!Settings.smoke)
		original_CreateSmoke(args);
}

//engine msg
void __cdecl handler_SVC_Sound()
{
	if (Settings.sound)
	{
		int old_ReadCount, msk;
		float origin[3];

		old_ReadCount = *Sound.ReadCount;
		StartReading(Sound.buf);

		msk = ReadBits(9);

		if (msk & (1 << 0))
			ReadBits(8);

		if (msk & (1 << 1))
			ReadBits(8);

		ReadBits(3);
		ReadBits(11);

		if (msk & (1 << 2))
			ReadBits(16);
		else
			ReadBits(8);

		ReadOrigin(origin);

		Sound.index++;
		Sound.origins[Sound.index][0] = origin[0];
		Sound.origins[Sound.index][1] = origin[1];
		Sound.origins[Sound.index][2] = origin[2];

		Sound.time[Sound.index] = GetTickCount();

		EndReading(Sound.buf);
		*Sound.ReadCount = old_ReadCount;
	}

	original_SVC_Sound();
}

//studio funcs
void __cdecl handler_StudioEntityLight(struct alight_s* plight)
{
	if (Settings.aimbot)
	{
		struct cl_entity_s* ent;

		ent = Studio.GetCurrentEntity();
		if (ent->player && Players[ent->index].valid)
			GetBoneOrigin(ent->index);
	}

	original_StudioEntityLight(plight);
}

int __cdecl handler_StudioCheckBBox()
{
	if (Settings.aimbot)
		return 1;

	return original_StudioCheckBBox();
}

//client funcs
int __cdecl handler_HUD_Key_Event(int down, int keynum, const char* pszCurrentBinding)
{
	if (keynum == K_INS && down)
	{
		Settings.Menu = !Settings.Menu;
		return 0;
	}
	else if (keynum == K_ENTER && Settings.Menu && down)
	{
		if (!Settings.SubMenu)
			OnSubMenu();

		Settings.SubMenu = !Settings.SubMenu;
		return 0;
	}

	if (!Settings.Menu || !down)
		return Client.HUD_Key_Event(down, keynum, pszCurrentBinding);

	MenuKeyEvent(keynum);
	return 0;
}

void __cdecl handler_HUD_PlayerMove(struct playermove_s* ppmove, int server)
{
	Me.flag = ppmove->flags;

	Me.eye[0] += ppmove->view_ofs.x;
	Me.eye[1] += ppmove->view_ofs.y;
	Me.eye[2] += ppmove->view_ofs.z;

	Client.HUD_PlayerMove(ppmove, server);
}

void __cdecl handler_V_CalcRefdef(struct ref_params_s* pparams)
{
	if (Settings.spread)
	{
		Me.punchangle[0] = pparams->punchangle[0];
		Me.punchangle[1] = pparams->punchangle[1];

		pparams->punchangle[0] = 0;
		pparams->punchangle[1] = 0;
	}

	Me.eye[0] = pparams->vieworg[0];
	Me.eye[1] = pparams->vieworg[1];
	Me.eye[2] = pparams->vieworg[2];

	Client.V_CalcRefdef(pparams);
}

void __cdecl handler_CL_CreateMove(float frametime, struct usercmd_s* cmd, int active)
{
	Client.CL_CreateMove(frametime, cmd, active);

	Me.frametime = frametime;

	if (cmd->buttons & IN_ATTACK)
	{
		if (Settings.aimbot)
		{
			for (unsigned char i = 1; i <= MAX_PLAYERS; i++)
			{
				if (!Players[i].valid)
					continue;

				if (!Settings.DeathMatch && Players[i].team == Players[Me.entity->index].team)
					continue;

				if (!Players[i].visible)
					continue;

				float aangles[3];
				GetAimAngles(Players[i].entity->index, aangles);

				cmd->viewangles.x = aangles[0];
				cmd->viewangles.y = aangles[1];

				break;
			}
		}

		if (Settings.spread)
		{
			cmd->viewangles.x -= Me.punchangle[0] * 0.04f * Settings.spread;
			cmd->viewangles.y -= Me.punchangle[1] * 0.04f * Settings.spread;
		}
	}

	if (Settings.BunnyHop)
		if ((cmd->buttons & IN_JUMP) && !(Me.flag & FL_ONGROUND))
			cmd->buttons &= ~IN_JUMP;

	if (Settings.SpeedHack)
		*GlobalTime += Settings.SpeedHack * 0.0001f;
}

float begin[3], end[3], forward[3], right[3], up[3];
int  __cdecl handler_HUD_AddEntity(int type, struct cl_entity_s* ent, const char* modelname)
{
	if (ent->player && Players[ent->index].valid)
	{
		if (Settings.barrel)
		{
			int beam;
			beam = Engine.pEventAPI->EV_FindModelIndex("sprites/laserbeam.spr");

			begin[0] = ent->origin.x;
			begin[1] = ent->origin.y;
			begin[2] = ent->origin.z;

			if (ent->curstate.usehull)
				begin[2] += 12;
			else
				begin[2] += 17;

			Engine.pfnAngleVectors((float*)&ent->angles, forward, right, up);
			forward[2] = -forward[2];

			end[0] = begin[0] + forward[0] * Settings.barrel * 24;
			end[1] = begin[1] + forward[1] * Settings.barrel * 24;
			end[2] = begin[2] + forward[2] * Settings.barrel * 24;

			if (Players[ent->index].team == 1)
				Engine.pEfxAPI->R_BeamPoints(begin, end, beam, 0.001f, 1, 0, 32, 2, 0, 0, Settings.ct_esp.red, Settings.ct_esp.green, Settings.ct_esp.blue);
			else if (Players[ent->index].team == 2)
				Engine.pEfxAPI->R_BeamPoints(begin, end, beam, 0.001f, 1, 0, 32, 2, 0, 0, Settings.t_esp.red, Settings.t_esp.green, Settings.t_esp.blue);
		}

		if (Settings.glow)
		{
			if (Players[ent->index].team == 1)
			{
				ent->curstate.rendercolor.r = Settings.ct_esp.red;
				ent->curstate.rendercolor.g = Settings.ct_esp.green;
				ent->curstate.rendercolor.b = Settings.ct_esp.blue;
			}
			else if (Players[ent->index].team == 2)
			{
				ent->curstate.rendercolor.r = Settings.t_esp.red;
				ent->curstate.rendercolor.g = Settings.t_esp.green;
				ent->curstate.rendercolor.b = Settings.t_esp.blue;
			}

			ent->curstate.renderamt = Settings.glow;
			ent->curstate.renderfx = kRenderFxGlowShell;
		}
	}

	return Client.HUD_AddEntity(type, ent, modelname);
}

float origin[3], center[3], top[3];
struct screenfade_s sf = { 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0 };
void __cdecl handler_HUD_Redraw(float time, int intermission)
{
	Client.HUD_Redraw(time, intermission);

	if (Settings.Menu)
	{
		DrawMenu();

		if (Settings.SubMenu)
			DrawSubMenu();
	}
	
	if (Settings.flash)
		Engine.pfnSetScreenFade(&sf);

	Me.entity = Engine.GetLocalPlayer();

	for (unsigned char i = 1; i <= MAX_PLAYERS; i++)
	{
		Players[i].entity = Engine.GetEntityByIndex(i);

		if (!Players[i].entity->player)
		{
			Players[i].valid = false;
			continue;
		}

		Players[i].valid = IsValid(Players[i].entity);

		if (!Players[i].valid)
			continue;

		Players[i].visible = IsVisible(Players[i].bones[Settings.bone]);

		Players[i].velocity[0] = Players[i].entity->curstate.origin.x - Players[i].entity->prevstate.origin.x;
		Players[i].velocity[1] = Players[i].entity->curstate.origin.y - Players[i].entity->prevstate.origin.y;
		Players[i].velocity[2] = Players[i].entity->curstate.origin.z - Players[i].entity->prevstate.origin.z;

		Players[i].frametime = Players[i].entity->curstate.animtime - Players[i].entity->prevstate.animtime;
		if (Players[i].frametime == 0)
			Players[i].frametime = Me.frametime;

		if (Settings.esp)
		{
			origin[0] = Players[i].entity->origin.x;
			origin[1] = Players[i].entity->origin.y;
			origin[2] = Players[i].entity->origin.z;

			if (!CalcScreen(origin, center))
				continue;

			origin[2] = origin[2] + HEAD_OFFSET;

			if (!CalcScreen(origin, top))
				continue;

			if (Players[i].team == 1) 
				DrawBox(center, top, Settings.ct_esp.weight, Settings.ct_esp.red, Settings.ct_esp.green, Settings.ct_esp.blue, Settings.ct_esp.alpha);
			else if (Players[i].team == 2)
				DrawBox(center, top, Settings.t_esp.weight, Settings.t_esp.red, Settings.t_esp.green, Settings.t_esp.blue, Settings.t_esp.alpha);
		}

		if (Settings.aimbot)
		{
			origin[0] = Players[i].bones[Settings.bone][0];
			origin[1] = Players[i].bones[Settings.bone][1];
			origin[2] = Players[i].bones[Settings.bone][2];

			if (!CalcScreen(origin, center))
				continue;

			origin[2] = origin[2] + BONE_OFFSET;

			if (!CalcScreen(origin, top))
				continue;

			if (Players[i].team == 1)
				DrawBox(center, top, Settings.ct_esp.weight, Settings.ct_esp.red, Settings.ct_esp.green, Settings.ct_esp.blue, Settings.ct_esp.alpha);
			else if (Players[i].team == 2)
				DrawBox(center, top, Settings.t_esp.weight, Settings.t_esp.red, Settings.t_esp.green, Settings.t_esp.blue, Settings.t_esp.alpha);
		}
	}

	if (Settings.sound)
	{
		for (unsigned char i = Sound.index; i >= 0; i--)
		{
			if (Sound.time[i] + 800 < GetTickCount())
				break;

			origin[0] = Sound.origins[i][0];
			origin[1] = Sound.origins[i][1];
			origin[2] = Sound.origins[i][2];

			if (!CalcScreen(origin, center))
				continue;

			origin[2] = origin[2] + SOUNDOBJ_OFFSET;

			if (!CalcScreen(origin, top))
				continue;

			DrawBox(center, top, SOUNDOBJ_WEIGHT, SOUNDOBJ_RED, SOUNDOBJ_GREEN, SOUNDOBJ_BLUE, SOUNDOBJ_ALPHA);
		}
	}
}