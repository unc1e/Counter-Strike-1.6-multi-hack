#pragma once

#include "std.h"

void __cdecl handler_TeamInfo         (const char* name, int size, void* buf);
void __cdecl handler_ResetHUD         (const char* name, int size, void* buf);
void __cdecl handler_CreateSmoke      (struct event_args_s* args);
void __cdecl handler_SVC_Sound        (void);
void __cdecl handler_StudioEntityLight(struct alight_s* plight);
int  __cdecl handler_StudioCheckBBox  (void);
int  __cdecl handler_HUD_Key_Event    (int down, int keynum, const char* pszCurrentBinding);
void __cdecl handler_HUD_PlayerMove   (struct playermove_s* ppmove, int server);
void __cdecl handler_V_CalcRefdef     (struct ref_params_s* pparams);
void __cdecl handler_CL_CreateMove    (float frametime, struct usercmd_s* cmd, int active);
int  __cdecl handler_HUD_AddEntity    (int type, struct cl_entity_s* ent, const char* modelname);
void __cdecl handler_HUD_Redraw       (float time, int intermission);

UserMsg_t           original_TeamInfo;
UserMsg_t           original_ResetHUD;
Event_t             original_CreateSmoke;
EngineMsg_t         original_SVC_Sound;
StudioEntityLight_t original_StudioEntityLight;
StudioCheckBBox_t   original_StudioCheckBBox;

StartReading_t StartReading;
EndReading_t   EndReading;
ReadBits_t     ReadBits;
ReadOrigin_t   ReadOrigin;

double* GlobalTime;