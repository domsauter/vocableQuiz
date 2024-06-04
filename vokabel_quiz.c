/*@@ Wedit generated application. Written Mon Nov 16 14:01:28 2020
 @@header: d:\hse\edv_2\vokabel_quizres.h
 @@resources: d:\hse\edv_2\vokabel_quiz.rc
 Do not edit outside the indicated areas */
/*<---------------------------------------------------------------------->*/
/*<---------------------------------------------------------------------->*/
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <string.h>
#include "vokabel_quizres.h"
#include "prototypen.h"

//nur scnaf und printf
#include <stdio.h>
/*<---------------------------------------------------------------------->*/
HINSTANCE hInst;		// Instance handle
HWND hwndMain;		//Main window handle

LRESULT CALLBACK MainWndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
/* --- The following code comes from c:\lcc\lib\wizard\statbar.tpl. */

// Global Variables for the status bar control.

HWND  hWndStatusbar;

/*------------------------------------------------------------------------
 Procedure:     UpdateStatusBar ID:1
 Purpose:       Updates the statusbar control with the appropiate
                text
 Input:         lpszStatusString: Charactar string that will be shown
                partNumber: index of the status bar part number.
                displayFlags: Decoration flags
 Output:        none
 Errors:        none

------------------------------------------------------------------------*/
void UpdateStatusBar(LPSTR lpszStatusString, WORD partNumber, WORD displayFlags)
{
    SendMessage(hWndStatusbar,
                SB_SETTEXT,
                partNumber | displayFlags,
                (LPARAM)lpszStatusString);
}


/*------------------------------------------------------------------------
 Procedure:     MsgMenuSelect ID:1
 Purpose:       Shows in the status bar a descriptive explaation of
                the purpose of each menu item.The message
                WM_MENUSELECT is sent when the user starts browsing
                the menu for each menu item where the mouse passes.
 Input:         Standard windows.
 Output:        The string from the resources string table is shown
 Errors:        If the string is not found nothing will be shown.
------------------------------------------------------------------------*/
LRESULT MsgMenuSelect(HWND hwnd, UINT uMessage, WPARAM wparam, LPARAM lparam)
{
    static char szBuffer[256];
    UINT   nStringID = 0;
    UINT   fuFlags = GET_WM_MENUSELECT_FLAGS(wparam, lparam) & 0xffff;
    UINT   uCmd    = GET_WM_MENUSELECT_CMD(wparam, lparam);
    HMENU  hMenu   = GET_WM_MENUSELECT_HMENU(wparam, lparam);

    szBuffer[0] = 0;                            // First reset the buffer
    if (fuFlags == 0xffff && hMenu == NULL)     // Menu has been closed
        nStringID = 0;

    else if (fuFlags & MFT_SEPARATOR)           // Ignore separators
        nStringID = 0;

    else if (fuFlags & MF_POPUP)                // Popup menu
    {
        if (fuFlags & MF_SYSMENU)               // System menu
            nStringID = IDS_SYSMENU;
        else
            // Get string ID for popup menu from idPopup array.
            nStringID = 0;
    }  // for MF_POPUP
    else                                        // Must be a command item
        nStringID = uCmd;                       // String ID == Command ID

    // Load the string if we have an ID
    if (0 != nStringID)
        LoadString(hInst, nStringID, szBuffer, sizeof(szBuffer));
    // Finally... send the string to the status bar
    UpdateStatusBar(szBuffer, 0, 0);
    return 0;
}


/*------------------------------------------------------------------------
 Procedure:     InitializeStatusBar ID:1
 Purpose:       Initialize the status bar
 Input:         hwndParent: the parent window
                nrOfParts: The status bar can contain more than one
                part. What is difficult, is to figure out how this
                should be drawn. So, for the time being only one is
                being used...
 Output:        The status bar is created
 Errors:
------------------------------------------------------------------------*/
void InitializeStatusBar(HWND hwndParent,int nrOfParts)
{
    const int cSpaceInBetween = 8;
    int   ptArray[40];   // Array defining the number of parts/sections
    RECT  rect;
    HDC   hDC;

   /* * Fill in the ptArray...  */

    hDC = GetDC(hwndParent);
    GetClientRect(hwndParent, &rect);

    ptArray[nrOfParts-1] = rect.right;
    //---TODO--- Add code to calculate the size of each part of the status
    // bar here.

    ReleaseDC(hwndParent, hDC);
    SendMessage(hWndStatusbar,
                SB_SETPARTS,
                nrOfParts,
                (LPARAM)(LPINT)ptArray);

    UpdateStatusBar("Ready", 0, 0);
    //---TODO--- Add code to update all fields of the status bar here.
    // As an example, look at the calls commented out below.

//    UpdateStatusBar("Cursor Pos:", 1, SBT_POPOUT);
//    UpdateStatusBar("Time:", 3, SBT_POPOUT);
}


/*------------------------------------------------------------------------
 Procedure:     CreateSBar ID:1
 Purpose:       Calls CreateStatusWindow to create the status bar
 Input:         hwndParent: the parent window
                initial text: the initial contents of the status bar
 Output:
 Errors:
------------------------------------------------------------------------*/
static BOOL CreateSBar(HWND hwndParent,char *initialText,int nrOfParts)
{
    hWndStatusbar = CreateStatusWindow(WS_CHILD | WS_VISIBLE | WS_BORDER|SBARS_SIZEGRIP,
                                       initialText,
                                       hwndParent,
                                       IDM_STATUSBAR);
    if(hWndStatusbar)
    {
        InitializeStatusBar(hwndParent,nrOfParts);
        return TRUE;
    }

    return FALSE;
}

/*<---------------------------------------------------------------------->*/
/*@@0->@@*/
static BOOL InitApplication(void)
{
	WNDCLASS wc;

	memset(&wc,0,sizeof(WNDCLASS));
	wc.style = CS_HREDRAW|CS_VREDRAW |CS_DBLCLKS ;
	wc.lpfnWndProc = (WNDPROC)MainWndProc;
	wc.hInstance = hInst;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "vokabel_quizWndClass";
	wc.lpszMenuName = MAKEINTRESOURCE(IDMAINMENU);
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	if (!RegisterClass(&wc))
		return 0;
/*@@0<-@@*/
	// ---TODO--- Call module specific initialization routines here

	return 1;
}

/*<---------------------------------------------------------------------->*/
/*@@1->@@*/
HWND Createvokabel_quizWndClassWnd(void)
{
	return CreateWindow("vokabel_quizWndClass","Schlage den Vokabelkönig",
		WS_MINIMIZEBOX|WS_VISIBLE|WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_MAXIMIZEBOX|WS_CAPTION|WS_BORDER|WS_SYSMENU|WS_THICKFRAME,
		CW_USEDEFAULT,0,CW_USEDEFAULT,0,
		NULL,
		NULL,
		hInst,
		NULL);
}
/*@@1<-@@*/
/*<---------------------------------------------------------------------->*/
/* --- The following code comes from c:\lcc\lib\wizard\defOnCmd.tpl. */
void MainWndProc_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch(id) {
		// ---TODO--- Add new menu commands here
		/*@@NEWCOMMANDS@@*/
		case IDM_EXIT:
		PostMessage(hwnd,WM_CLOSE,0,0);
		break;

		case IDM_Datei_neu:
			DialogBox(hInst, MAKEINTRESOURCE(Maske_eingabe), hwnd, &manuelle_eingabe);
			break;
		case IDM_eng_ger:
			DialogBox(hInst, MAKEINTRESOURCE(Maske_eng_ger), hwnd, &eng_ger);
			break;
		case IDM_ger_eng:
			DialogBox(hInst, MAKEINTRESOURCE(Maske_ger_eng), hwnd, &ger_eng);
			break;
		}
}
/*@@2->@@*/
LRESULT CALLBACK MainWndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch (msg) {
/*@@3->@@*/
	case WM_SIZE:
		SendMessage(hWndStatusbar,msg,wParam,lParam);
		InitializeStatusBar(hWndStatusbar,1);
		break;
	case WM_MENUSELECT:
		return MsgMenuSelect(hwnd,msg,wParam,lParam);
	case WM_COMMAND:
		HANDLE_WM_COMMAND(hwnd,wParam,lParam,MainWndProc_OnCommand);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd,msg,wParam,lParam);
	}
/*@@3<-@@*/
	return 0;
}
/*@@2<-@@*/

/*<---------------------------------------------------------------------->*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
	MSG msg;
	HANDLE hAccelTable;

	hInst = hInstance;
	if (!InitApplication())
		return 0;
	hAccelTable = LoadAccelerators(hInst,MAKEINTRESOURCE(IDACCEL));
	if ((hwndMain = Createvokabel_quizWndClassWnd()) == (HWND)0)
		return 0;
	CreateSBar(hwndMain,"Ready",1);
	ShowWindow(hwndMain,SW_SHOW);
	while (GetMessage(&msg,NULL,0,0)) {
		if (!TranslateAccelerator(msg.hwnd,hAccelTable,&msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}
