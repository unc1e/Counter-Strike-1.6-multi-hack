#include "calculations.h"

bool IsValid(struct cl_entity_s* ent)
{
	return !(ent->curstate.effects & 128) && ent->curstate.movetype != 6 &&
		ent->curstate.movetype != 0  && !(ent->curstate.messagenum < Me.entity->curstate.messagenum) &&
		!(Me.entity->curstate.iuser1 == 4 && Me.entity->curstate.iuser2 == ent->index) &&
		Me.entity->index != ent->index;
}

bool IsVisible(float* orig)
{
	pmtrace_t tr;

	Engine.pEventAPI->EV_SetTraceHull(2);
	Engine.pEventAPI->EV_PlayerTrace(Me.eye, orig, 0x00000004, Me.entity->index, &tr);
	return tr.fraction >= 0.85f;
}

bool CalcScreen(float* world, float* scr)
{
	if (!Engine.pTriAPI->WorldToScreen(world, scr) && scr[0] < 1 && scr[1] < 1 && scr[0] > -1 && scr[1] > -1)
	{
		scr[0] =  scr[0] * Screen.width / 2 + Screen.width / 2;
		scr[1] = -scr[1] * Screen.height / 2 + Screen.height / 2;

		return true;
	}

	return false;
}