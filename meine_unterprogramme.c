#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <string.h>
#include "vokabel_quizres.h"
#include "prototypen.h"
#include <stdio.h>
#include <time.h>

struct vokabel
	{
		char deutsch [80];
		char englisch [80];
	};
	struct vokabel feld[100];
	int i=0;



BOOL APIENTRY manuelle_eingabe (HWND hwnd, UINT msg,WPARAM wParam,LPARAM lParam)
{
	/*struct vokabel
	{
		char deutsch [80];
		char englisch [80];
	};*/
	//struct vokabel feld[100];
		//static int i=0;
		//static int j=0;




		//sprintf(feld_1, "%i",2007);
		//sprintf(feld_2, "%i", 3);

		switch(msg)
	{
		case WM_INITDIALOG:
			            // Dieser Teil wird durchlaufen, wenn Maske
                        // das 1. Mal geoeffnet wird
						    printf("\nDie Maske wurde aufgemacht");
		break;

		case WM_COMMAND:
                        // Dieser Teil wird durchlaufen,
                        // wenn in Maske etwas ausgefuehrt werden soll.

			switch (LOWORD(wParam))
			{
				/*case EINGABEFELD_1:
						    printf("\nEs erfolgt eine Aktion im EINGABEFELD_1");
				break;

                case EINGABEFELD_2:
                            printf("\nEs erfolgt eine Aktion im EINGABEFELD_2");
                break;*/


				case KNOPF_1:

							Edit_GetText(GetDlgItem(hwnd, EINGABEFELD_1), feld[i].deutsch,20);
							Edit_GetText(GetDlgItem(hwnd, EINGABEFELD_2), feld[i].englisch,20);
							//zahl_1 = atoi(feld_1);
							//zahl_2 = atoi(feld_2);

                            printf("\nDeutsch: %s",feld[i].deutsch);
							printf("\nEnglisch: %s",feld[i].englisch);
							printf("\nDeutsch: %i",i);
							printf("\nEnglisch: %i",i);
							/*printf("\nDeutsch: %s",feld[1].deutsch);
							printf("\nEnglisch: %s",feld[1].englisch);*/
							i=i+1;
							//j=j+1;


				break;


			}
		break;

	}
	return(HandleDefaultMessages(hwnd,msg,wParam,lParam));
}

//eng_ger
BOOL APIENTRY eng_ger (HWND hwnd, UINT msg,WPARAM wParam,LPARAM lParam)
{
	//struct vokabel feld1[100];
		int ret_1;
		static char naidoo[80];
		static int x=0;
		ret_1 = strcmp (naidoo,feld[x].deutsch);
		srand((unsigned)time(NULL));



		switch(msg)
	{
		case WM_INITDIALOG:
			            // Dieser Teil wird durchlaufen, wenn Maske
                        // das 1. Mal geoeffnet wird
						    printf("\nDie Maske wurde aufgemacht");
							Edit_SetText(GetDlgItem(hwnd, Vorgabewort_eng), feld[x].englisch);
							Edit_GetText(GetDlgItem(hwnd, EINGABE_ger), naidoo,20);
		break;

		case WM_COMMAND:
                        // Dieser Teil wird durchlaufen,
                        // wenn in Maske etwas ausgefuehrt werden soll.

			switch (LOWORD(wParam))
			{
				case EINGABE_ger:
					Edit_GetText(GetDlgItem(hwnd, EINGABE_ger), naidoo,20);
				break;

				case KNOPF_1_eng_ger:

							if (ret_1 == 0)
					{
							Edit_SetText(GetDlgItem(hwnd, KONTROLLE_1), "Du hast das Zeug zum Vokabelkönig ;)");
							x = 0+(rand()%((i-1)-0+1));
							Edit_SetText(GetDlgItem(hwnd, Vorgabewort_eng), feld[x].englisch);
					}
					else
						{

							Edit_SetText(GetDlgItem(hwnd, KONTROLLE_1), "Das war wohl nichts, Du hast noch ein Versuch");
						}
							/*x++;
							Edit_SetText(GetDlgItem(hwnd, Vorgabewort_eng), feld[x].englisch);*/



				break;


			}
		break;

	}
	return(HandleDefaultMessages(hwnd,msg,wParam,lParam));
}

//ger_eng
BOOL APIENTRY ger_eng (HWND hwnd, UINT msg,WPARAM wParam,LPARAM lParam)
{


		int ret;
		static char xavier[80];
		static int a = 0;
		ret = strcmp (xavier,feld[a].englisch);
		srand((unsigned)time(NULL));

		//int zahl1,zahl2;

		//static int b=0;

		//sprintf(feld_1, "%i",2007);
		//sprintf(feld_2, "%i", 3);

		switch(msg)
	{
		case WM_INITDIALOG:
			            // Dieser Teil wird durchlaufen, wenn Maske
                        // das 1. Mal geoeffnet wird

						    printf("\nDie Maske wurde aufgemacht");
							Edit_SetText(GetDlgItem(hwnd, Vorgabewort_ger), feld[a].deutsch);
							Edit_GetText(GetDlgItem(hwnd, EINGABE_eng), xavier,20);

		break;

		case WM_COMMAND:

			switch (LOWORD(wParam))
			{

				case EINGABE_eng:
					Edit_GetText(GetDlgItem(hwnd, EINGABE_eng), xavier,20);
				break;

				case KNOPF_1_ger_eng:


							//printf("\n%s",feld[a].englisch);
							//printf("\n%s",xavier);

					if (ret == 0)
					{
							Edit_SetText(GetDlgItem(hwnd, KONTROLLE), "Du hast das Zeug zum Vokabelkönig ;)");
							a = 0+(rand()%((i-1)-0+1));
							Edit_SetText(GetDlgItem(hwnd, Vorgabewort_ger), feld[a].deutsch);
					}
					else
						{

							Edit_SetText(GetDlgItem(hwnd, KONTROLLE), "Das war wohl nichts, Du hast noch ein Versuch");
						}




				break;


			}
		break;

	}


	return(HandleDefaultMessages(hwnd,msg,wParam,lParam));
}
