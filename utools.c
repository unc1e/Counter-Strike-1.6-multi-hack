#include "utools.h"

void CreateConsole()
{
	int   conHandle;
	DWORD stdHandle;
	FILE* f;
	FILE* cout;

	AllocConsole();
	stdHandle = (DWORD)GetStdHandle(STD_OUTPUT_HANDLE);
	conHandle = _open_osfhandle(stdHandle, _O_TEXT);
	f = _fdopen(conHandle, "w");

	*stdout = *f;
	setvbuf(stdout, NULL, _IONBF, 0);
	freopen_s(&cout, "conout$", "w", stdout);
}

BYTE* DetourFunc(BYTE *src, const BYTE *dst, const int len)
{
	BYTE *jmp = (BYTE*)malloc(len + 5);
	DWORD dwback;
	VirtualProtect(src, len, PAGE_READWRITE, &dwback);
	memcpy(jmp, src, len);
	jmp += len;
	jmp[0] = 0xE9;
	*(DWORD*)(jmp + 1) = (DWORD)(src + len - jmp) - 5;
	src[0] = 0xE9;
	*(DWORD*)(src + 1) = (DWORD)(dst - src) - 5;
	VirtualProtect(src, len, dwback, &dwback);
	return (jmp - len);
}

BOOL CompareData(const BYTE* pData, const BYTE* bMask, const char* szMask) {
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return false;
	return (*szMask) == 0;
}

BYTE* FindPattern(DWORD dwAddress, ULONG dwLen, const BYTE* bMask, const char* szMask) {
	for (DWORD i = 0; i < dwLen; i++)
		if (CompareData((BYTE*)dwAddress + i, bMask, szMask))
			return (BYTE*)dwAddress + i;
	return false;
}