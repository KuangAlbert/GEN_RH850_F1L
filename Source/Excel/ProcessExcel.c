/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: Open Excel
 * Instance		:
 * Description	:
 *-----------------------------------------------------------------------
 * Version		: v1.0
 * Date			: 2018/08/27
 * Author		: uidp5021
 ***********************************************************************/
 /*-History--------------------------------------------------------------
 * Version       Date               Name            Changes and comments
 * 1.0           2018/08/27			Lishi           add Init version
*=========================================================================*/
#include <stdio.h>
#include <conio.h>
#include "libxl.h"
#include <windows.h>

#include "ProcessExcel.h"
#include "PinmuxRegister.h"

#define PORT_NUM 5

_c_pinmux_register_bit_Buf PMC[PORT_NUM];		/* port mode */
_c_pinmux_register_bit_Buf PIPC[PORT_NUM];		/* Port IP Control */
_c_pinmux_register_bit_Buf PM[PORT_NUM];		/* output/Iinput */
_c_pinmux_register_bit_Buf PIBC[PORT_NUM];		/* Port InputBuffer Control */


_c_pinmux_register_bit_Buf PFC[PORT_NUM];		/* alternative mode */
_c_pinmux_register_bit_Buf PFCE[PORT_NUM];
_c_pinmux_register_bit_Buf PFCAE[PORT_NUM];

_c_pinmux_register_bit_Buf PBD[PORT_NUM];		/* Port Bidirection Control */
_c_pinmux_register_bit_Buf PU[PORT_NUM];		/* PullUp Control */
_c_pinmux_register_bit_Buf PD[PORT_NUM];		/* PullDown Control */
_c_pinmux_register_bit_Buf PDSC[PORT_NUM];		/* Port Driver Strength */
_c_pinmux_register_bit_Buf PODC[PORT_NUM];		/* output mode */
_c_pinmux_register_bit_Buf P[PORT_NUM];			/* Port Value */

/*****************************************************************************
 *  Name        : ProcessExcel
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void ProcessExcel(void)
{
	BookHandle book = xlCreateXMLBook();

	const wchar_t * x = L"Halil Kural";
	const wchar_t * y = L"windows-2723210a07c4e90162b26966a8jcdboe";
	xlBookSetKey(book, x, y);

	if (book)
	{
		if (xlBookLoad(book, L"Pin100.xlsx"))
		{
			SheetHandle sheet = xlBookGetSheet(book, 0);
			if (sheet)
			{
				double d = xlSheetReadNum(sheet, 3, 1, 0);
				const wchar_t* s = xlSheetReadStr(sheet, 1, 5, 0);


				printf("ACTIVE len is %d %d\n", sizeof(unsigned int), wcscmp(s, L"ACTIVE"));
				printf("%f\n", d);
				printf("%ls\n", s);

				//WideCharToMultiByte(CP_ACP, 0, s, wcslen(s) + 1, hh, 256, NULL, NULL);

				printf("ACTIVE len is %d\n", wcslen(s));

				xlSheetWriteNum(sheet, 3, 1, d * 2, 0);
				xlSheetWriteStr(sheet, 4, 1, L"1new string", 0);
			}

			if (xlBookSave(book, L"Pin100.xlsx")) printf("\nFile example.xls has been modified.\n");
		}

		xlBookRelease(book);
	}

}