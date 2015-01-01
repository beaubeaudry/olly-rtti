#include "OllyRTTI.h"
#include <stdio.h>
#include <string.h>
#include <winnt.h>

#pragma comment(lib, "ollydbg")

HINSTANCE pluginHandle;

// Menu setup
extc _export t_menu * cdecl ODBG2_Pluginmenu(wchar_t *type)  
{
  return NULL;
};

// Module entry
BOOL WINAPI DllEntryPoint(HINSTANCE hi, DWORD reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
		pluginHandle = hi;
	return 1;
};

// Register plugin
extc int _export cdecl  ODBG2_Pluginquery(int ollydbgversion, ulong *features,
	wchar_t pluginname[SHORTNAME],
	wchar_t pluginversion[SHORTNAME])
{
	int restore;
	if (ollydbgversion < 201)
		return 0;

	wcscpy_s(pluginname, SHORTNAME, PLUGINNAME);
	wcscpy_s(pluginversion, SHORTNAME, PLUGINVERSION);

	return PLUGIN_VERSION;
};

// One-time initialization
extc int __cdecl ODBG2_Plugininit(void) 
{
    return 0;
}

// New target started or restarted
extc void _export cdecl ODBG2_Pluginreset(void) 
{
};

// Olly exiting
extc void _export cdecl ODBG2_Plugindestroy(void) 
{ 
};

// Dump callback
extc int _export cdecl ODBG2_Plugindump(t_dump *pd,wchar_t *s,uchar *mask,int n,int *select,ulong addr,int column)
{
	return 0;
}
