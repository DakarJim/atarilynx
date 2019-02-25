#ifndef __LYNX_SD_DIRECTORY__
#define __LYNX_SD_DIRECTORY__

#include "LynxSD.h"

typedef struct {
	char	szFilename[13];
	u8		bDirectory;
	char  szLongName[50];
} SDirEntry;


extern char gszCurrentDir[256];
extern u8 gnSelectIndex;

extern u8 gnNumDirEntries;
extern u8 ganDirOrder[256];
extern SDirEntry gsDirEntry[256];


void __fastcall__ DIR_read(const char *pDir);
u8 __fastcall__ DIR_IsValidFilePath(const char romFile[]);
void __fastcall__ DIR_FullFilePath(char buf[], const char file[]);

#endif // __LYNX_SD_DIRECTORY__
