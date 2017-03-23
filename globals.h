#pragma once

#include "std.h"

struct cl_enginefuncs_s*    pEngine;
struct cl_clientfuncs_s*    pClient;
struct engine_studio_api_s* pStudio;
struct cl_enginefuncs_s     Engine;
struct cl_clientfuncs_s     Client;
struct engine_studio_api_s  Studio;

struct usersettings_s Settings;
struct screen_s       Screen;
struct player_s       Players[MAX_PLAYERS + 1]; //players[0] is not used
struct l_player_s     Me;
struct sound_s        Sound;