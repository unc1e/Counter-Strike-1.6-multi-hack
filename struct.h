#pragma once

#include "std.h"

struct usermsg_s
{
	int unk1;
	unsigned int unk2;
	unsigned char name[16];
	struct usermsg_s* next;
	UserMsg_t pfn;
}; //thnks sk0r/mencore from unknowncheats.me

struct event_s
{
	struct event_s* next;
	DWORD unk2;
	DWORD unk3;
	DWORD unk4;
	DWORD unk5;
	DWORD unk6;
	DWORD unk7;
	DWORD unk8;
	unsigned char name[22];
	byte unk10;
	byte unk11;
	DWORD unk12;
	DWORD unk13;
	DWORD unk14;
	DWORD unk15;
	Event_t pfn;
	//... and other elements of struct ...
};

struct enginemsg_s
{
	int id;
	char* name;
	EngineMsg_t pfn;
}; 

struct esp_s
{
	GLubyte red;
	GLubyte green;
	GLubyte blue;
	GLubyte alpha;
	GLfloat weight;
};

struct usersettings_s
{
	//menu
	bool Menu;
	unsigned char MenuPos;

	bool SubMenu;
	unsigned char SubMenuPos;
	unsigned char SubMenuTotal;

	//esp
	bool esp;
	struct esp_s t_esp;
	struct esp_s ct_esp;
	unsigned char barrel;
	unsigned char glow;
	bool sound;

	//aimbot
	bool aimbot;
	unsigned char bone;
	bool DeathMatch;

	//removals
	bool flash;
	bool smoke;
	unsigned char spread;

	//other
	bool BunnyHop;
	unsigned char SpeedHack;
};

struct screen_s
{
	unsigned short width;
	unsigned short height;
};

struct sound_s
{
	DWORD* buf;
	unsigned int* ReadCount;
	unsigned char index;
	float origins[256][3];
	unsigned int time[256];
};

struct player_s
{
	unsigned char team;
	bool valid;
	bool visible;
	struct cl_entity_s* entity;
	float bones[53][3];
	float velocity[3];
	float frametime;
};

struct l_player_s
{
	struct cl_entity_s* entity;
	float eye[3];
	int flag;
	float frametime;
	float punchangle[2];
};