#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <string.h>



BOOL APIENTRY manuelle_eingabe (HWND hwnd, UINT msg,WPARAM wParam,LPARAM lParam);
BOOL WINAPI HandleDefaultMessages(HWND hwnd,UINT msg,WPARAM wParam,DWORD lParam);
BOOL APIENTRY eng_ger (HWND hwnd, UINT msg,WPARAM wParam,LPARAM lParam);
BOOL APIENTRY ger_eng (HWND hwnd, UINT msg,WPARAM wParam,LPARAM lParam);
