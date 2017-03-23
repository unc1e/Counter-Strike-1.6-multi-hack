#pragma once

#include "std.h"

void  CreateConsole(void);
BYTE* DetourFunc   (BYTE* src, const BYTE* dst, const int len);
BOOL  CompareData  (const BYTE* pData, const BYTE* bMask, const char* szMask);
BYTE* FindPattern  (DWORD dwAddress, ULONG dwLen, const BYTE* bMask, const char* szMask);