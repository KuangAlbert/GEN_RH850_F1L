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
#include "config.h"

#define PORT_NUM 7
#define MODE_NUM 3
_c_pinmux_register_bit_Buf PMC[MODE_NUM][PORT_NUM];		/* port mode */
_c_pinmux_register_bit_Buf PIPC[MODE_NUM][PORT_NUM];		/* Port IP Control */
_c_pinmux_register_bit_Buf PM[MODE_NUM][PORT_NUM];		/* output/Iinput */
_c_pinmux_register_bit_Buf PIBC[MODE_NUM][PORT_NUM];		/* Port InputBuffer Control */


_c_pinmux_register_bit_Buf PFC[MODE_NUM][PORT_NUM];		/* alternative mode */
_c_pinmux_register_bit_Buf PFCE[MODE_NUM][PORT_NUM];
_c_pinmux_register_bit_Buf PFCAE[MODE_NUM][PORT_NUM];

_c_pinmux_register_bit_Buf PBD[MODE_NUM][PORT_NUM];		/* Port Bidirection Control */
_c_pinmux_register_bit_Buf PU[MODE_NUM][PORT_NUM];		/* PullUp Control */
_c_pinmux_register_bit_Buf PD[MODE_NUM][PORT_NUM];		/* PullDown Control */
_c_pinmux_register_bit_Buf PDSC[MODE_NUM][PORT_NUM];		/* Port Driver Strength */
_c_pinmux_register_bit_Buf PODC[MODE_NUM][PORT_NUM];		/* output mode */
_c_pinmux_register_bit_Buf P[MODE_NUM][PORT_NUM];			/* Port Value */


/*****************************************************************************
 *  Name        : ProcessExcel
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void ProcessExcel(void)
{
	BookHandle book = xlCreateXMLBook();
	wchar_t* register = NULL;
	_GroupNumber GroupNumber;
	U8 PortNumber;
	_PORT_TYPE PORT_TYPE;

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
				U16 Row, Line;
				
				for (Row = R_STAET_100; Row <= R_END_100; Row++)
				{
						/* 第A列 */
						register = xlSheetReadStr(sheet, Row, L('A'), 0);

						if (NULL != register && 0 == wcscmp(register, L"yes"))
						{
							;
						}
						else if(NULL != register && 0 == wcscmp(register, L"NO"))
						{
							continue;
						}
						else
						{
							printf("表格错误\n");
							continue;
						}
					
						/* 第D列 */
						register = xlSheetReadStr(sheet, Row, L('D'), 0);
						if (NULL != register && 0 == wcscmp(register, L"0"))
						{
							GroupNumber = P0;
						}
						else if (NULL != register && 0 == wcscmp(register, L"8"))
						{
							GroupNumber = P8;
						}
						else if (NULL != register && 0 == wcscmp(register, L"9"))
						{
							GroupNumber = P9;
						}
						else if (NULL != register && 0 == wcscmp(register, L"10"))
						{
							GroupNumber = P10;
						}
						else if (NULL != register && 0 == wcscmp(register, L"11"))
						{
							GroupNumber = P11;
						}
						else if (NULL != register && 0 == wcscmp(register, L"20"))
						{
							GroupNumber = JP;
						}
						else if (NULL != register && 0 == wcscmp(register, L"30"))
						{
							GroupNumber = AP;
						}
						else
						{
							continue;
						}

						/* 第E列 */
						FormatHandle * format = 0;
						PortNumber = xlSheetReadNum(sheet, Row, L('E'), format);
						if (PortNumber < 0 || PortNumber > 15 || format = 0)
						{
							printf("有问题\n");
						}

						/* 第F列 */
						register = xlSheetReadStr(sheet, Row, L('F'), 0);
						if (NULL != register && 0 == wcscmp(register, L"ACTIVE"))
						{
							PORT_TYPE = ACTIVE;
						}
						else if (NULL != register && 0 == wcscmp(register, L"STANDBY"))
						{
							PORT_TYPE = STANDBY;
						}
						else if (NULL != register && 0 == wcscmp(register, L"RESET"))
						{
							PORT_TYPE = RESET;
						}
						else
						{
							printf("有问题\n");
						}

						/* 第G列 */
						register = xlSheetReadStr(sheet, Row, L('G'), 0);
						if (NULL != register && 0 == wcscmp(register, L"GPIO"))
						{
							SET_BIT(PM[PORT_TYPE][GroupNumber], PortNumber);
						}
						else if (NULL != register && 0 == wcscmp(register, L"ALT"))
						{
							CLEAR_BIT(PM[PORT_TYPE][GroupNumber], PortNumber);
						}
						else
						{
							printf("有问题\n");
						}

						/* 第H列 */
						register = xlSheetReadStr(sheet, Row, L('H'), 0);
						if (NULL != register && 0 == wcscmp(register, L"GPIO"))
						{
							SET_BIT(PM[PORT_TYPE][GroupNumber], PortNumber);
						}
						else if (NULL != register && 0 == wcscmp(register, L"ALT"))
						{
							CLEAR_BIT(PM[PORT_TYPE][GroupNumber], PortNumber);
						}
						else
						{
							printf("有问题\n");
						}


				}



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

/*****************************************************************************
*  Name        : ProcessAll_Line
*  Description :
*  Parameter   :
*  Returns     : None
*****************************************************************************/
void Setbit(U32* dat, U8 n,)
{
	
}
