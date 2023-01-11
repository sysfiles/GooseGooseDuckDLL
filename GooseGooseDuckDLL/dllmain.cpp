#include <windows.h>

#include "GooseGooseDuck.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GooseGooseDuckMain, 0, 0, 0);
        break;
    }
    return TRUE;
}

