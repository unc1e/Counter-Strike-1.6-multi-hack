#pragma once
#include "std.h"

void DrawBox    (GLfloat* center, GLfloat* top, GLfloat weight, GLubyte r, GLubyte g, GLubyte b, GLubyte a);
void DrawMenu   (void);
void DrawSubMenu(void);
void BuildFont  (void);

bool fontBuilt;