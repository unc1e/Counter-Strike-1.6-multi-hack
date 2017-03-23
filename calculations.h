#pragma once

#include "std.h"

bool IsValid   (struct cl_entity_s* ent);
bool IsVisible (float* orig);
bool CalcScreen(float* world, float* scr);