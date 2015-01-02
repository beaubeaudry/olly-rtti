#pragma once

#include <Windows.h>
#include "plugin.h"

#define PLUGINNAME      L"OllyRTTI"
#define PLUGINVERSION   L"0.0"

static int CheckRTTIDump(t_table *pt, wchar_t *name, ulong index, int mode);
static int CheckRTTIRegisters(t_table *pt, wchar_t *name, ulong index, int mode);

static t_menu DumpMenu[] =
{
	{
		L"Check RTTI",
		L"Checks current address for RTTI",
		K_NONE, CheckRTTIDump, NULL, 0
	},
	{ NULL, NULL, K_NONE, NULL, NULL, 0 }
};

static t_menu RegistersMenu[] =
{
	{
		L"Check RTTI",
		L"Checks each register for RTTI",
		K_NONE, CheckRTTIRegisters, NULL, 0
	},
	{ NULL, NULL, K_NONE, NULL, NULL, 0 }
};