#pragma once

#include "std.h"

void FillMenu      (void);
void UpdateSettings(void);
void OnSubMenu     (void);
void MenuKeyEvent  (int keynum);

unsigned char MenuNames[20][50];
unsigned char SubMenuNames[20][50][50];
unsigned char SubMenuValues[20][50];
unsigned char SubMenuSValues[20][50][4];