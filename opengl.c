#include "opengl.h"

GLuint base;

void BuildFont()
{
	HDC	   hDC;
	HFONT  font;
	HFONT  oldfont;

	hDC     = wglGetCurrentDC();
	font    = CreateFontA(MENU_FONT_HEIGHT, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, FALSE, OUT_TT_PRECIS, FALSE, PROOF_QUALITY, FALSE, "Verdana");
	oldfont = (HFONT)SelectObject(hDC, font);
	base    = glGenLists(96);

	wglUseFontBitmapsA(hDC, 32, 96, base);
	SelectObject(hDC, oldfont);
	DeleteObject(font);
}

void DrawMenu()
{	
	glDisable(GL_TEXTURE_2D);
		
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
		glVertex2i(MENU_MARGIN_LEFT, MENU_MARGIN_TOP);
		glVertex2i(MENU_MARGIN_LEFT + MENU_WIDTH, MENU_MARGIN_TOP);
		glVertex2i(MENU_MARGIN_LEFT + MENU_WIDTH, MENU_MARGIN_TOP + MENU_TOTAL * MENU_LINE_HEIGHT);
		glVertex2i(MENU_MARGIN_LEFT, MENU_MARGIN_TOP + MENU_TOTAL * MENU_LINE_HEIGHT);
	glEnd();
		
	glColor3ub(0, 0, 0);
	glListBase(base - 32);
	for (unsigned char i = 0; i < MENU_TOTAL; i++)
	{
		glRasterPos2i(MENU_MARGIN_LEFT + MENU_PADDING_LEFT, MENU_MARGIN_TOP + MENU_FONT_HEIGHT + i * MENU_LINE_HEIGHT + 2);
		glCallLists(strlen(MenuNames[i]), GL_UNSIGNED_BYTE, MenuNames[i]);
	}
	glColor3ub(255, 0, 0);
	glRasterPos2i(MENU_MARGIN_LEFT + MENU_PADDING_LEFT, MENU_MARGIN_TOP + MENU_FONT_HEIGHT + Settings.MenuPos * MENU_LINE_HEIGHT + 2);
	glCallLists(strlen(MenuNames[Settings.MenuPos]), GL_UNSIGNED_BYTE, MenuNames[Settings.MenuPos]);

	glEnable(GL_TEXTURE_2D);
}

void DrawSubMenu()
{
	glDisable(GL_TEXTURE_2D);

	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
		glVertex2i(MENU_MARGIN_LEFT + MENU_WIDTH, MENU_MARGIN_TOP);
		glVertex2i(MENU_MARGIN_LEFT + MENU_WIDTH + SUBMENU_WIDTH, MENU_MARGIN_TOP);
		glVertex2i(MENU_MARGIN_LEFT + MENU_WIDTH + SUBMENU_WIDTH, MENU_MARGIN_TOP + Settings.SubMenuTotal * MENU_LINE_HEIGHT);
		glVertex2i(MENU_MARGIN_LEFT + MENU_WIDTH, MENU_MARGIN_TOP + Settings.SubMenuTotal * MENU_LINE_HEIGHT);
	glEnd();

	glColor3ub(0, 0, 0);
	glListBase(base - 32);
	for (unsigned char i = 0; i < Settings.SubMenuTotal; i++)
	{
		glRasterPos2i(MENU_MARGIN_LEFT + MENU_PADDING_LEFT + MENU_WIDTH, MENU_MARGIN_TOP + MENU_FONT_HEIGHT + i * MENU_LINE_HEIGHT + 2);
		glCallLists(strlen(SubMenuNames[Settings.MenuPos][i]), GL_UNSIGNED_BYTE, SubMenuNames[Settings.MenuPos][i]);
		glRasterPos2i(MENU_MARGIN_LEFT + MENU_PADDING_LEFT + MENU_WIDTH + SUBMENU_VALUES_MARGIN_LEFT, MENU_MARGIN_TOP + MENU_FONT_HEIGHT + i * MENU_LINE_HEIGHT + 2);
		glCallLists(strlen(SubMenuSValues[Settings.MenuPos][i]), GL_UNSIGNED_BYTE, SubMenuSValues[Settings.MenuPos][i]);
	}
	glColor3ub(255, 0, 0);
	glRasterPos2i(MENU_MARGIN_LEFT + MENU_PADDING_LEFT + MENU_WIDTH, MENU_MARGIN_TOP + MENU_FONT_HEIGHT + Settings.SubMenuPos * MENU_LINE_HEIGHT + 2);
	glCallLists(strlen(SubMenuNames[Settings.MenuPos][Settings.SubMenuPos]), GL_UNSIGNED_BYTE, SubMenuNames[Settings.MenuPos][Settings.SubMenuPos]);
	glRasterPos2i(MENU_MARGIN_LEFT + MENU_PADDING_LEFT + MENU_WIDTH + SUBMENU_VALUES_MARGIN_LEFT, MENU_MARGIN_TOP + MENU_FONT_HEIGHT + Settings.SubMenuPos * MENU_LINE_HEIGHT + 2);
	glCallLists(strlen(SubMenuSValues[Settings.MenuPos][Settings.SubMenuPos]), GL_UNSIGNED_BYTE, SubMenuSValues[Settings.MenuPos][Settings.SubMenuPos]);

	glEnable(GL_TEXTURE_2D);
}

void DrawBox(GLfloat* center, GLfloat* top, GLfloat weight, GLubyte r, GLubyte g, GLubyte b, GLubyte a)
{
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4ub(r, g, b, a);
	glBegin(GL_QUADS);
		glVertex2f(center[0] - ASPECT_RATIO * (center[1] - top[1]) - weight, top[1]);
		glVertex2f(center[0] - ASPECT_RATIO * (center[1] - top[1]) - weight, top[1] + weight);
		glVertex2f(center[0] + ASPECT_RATIO * (center[1] - top[1]) + weight, top[1] + weight);
		glVertex2f(center[0] + ASPECT_RATIO * (center[1] - top[1]) + weight, top[1]);

		glVertex2f(center[0] + ASPECT_RATIO * (center[1] - top[1]), top[1] + weight);
		glVertex2f(center[0] + ASPECT_RATIO * (center[1] - top[1]) + weight, top[1] + weight);
		glVertex2f(center[0] + ASPECT_RATIO * (center[1] - top[1]) + weight, top[1] + 2.f * (center[1] - top[1]) - weight);
		glVertex2f(center[0] + ASPECT_RATIO * (center[1] - top[1]), top[1] + 2.f * (center[1] - top[1]) - weight);

		glVertex2f(center[0] - ASPECT_RATIO * (center[1] - top[1]) - weight, top[1] + 2.f * (center[1] - top[1]));
		glVertex2f(center[0] - ASPECT_RATIO * (center[1] - top[1]) - weight, top[1] + 2.f * (center[1] - top[1]) - weight);
		glVertex2f(center[0] + ASPECT_RATIO * (center[1] - top[1]) + weight, top[1] + 2.f * (center[1] - top[1]) - weight);
		glVertex2f(center[0] + ASPECT_RATIO * (center[1] - top[1]) + weight, top[1] + 2.f * (center[1] - top[1]));

		glVertex2f(center[0] - ASPECT_RATIO * (center[1] - top[1]), top[1] + weight);
		glVertex2f(center[0] - ASPECT_RATIO * (center[1] - top[1]) - weight, top[1] + weight);
		glVertex2f(center[0] - ASPECT_RATIO * (center[1] - top[1]) - weight, top[1] + 2.f * (center[1] - top[1]) - weight);
		glVertex2f(center[0] - ASPECT_RATIO * (center[1] - top[1]), top[1] + 2.f * (center[1] - top[1]) - weight);
	glEnd();
	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
}