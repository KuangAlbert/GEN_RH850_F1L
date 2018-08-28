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
#include "log.h"

#define PORT_NUM 7
#define MODE_NUM 3
U32 PMC[MODE_NUM][PORT_NUM];		/* port mode */
U32 PIPC[MODE_NUM][PORT_NUM];		/* Port IP Control */
U32 PM[MODE_NUM][PORT_NUM];		/* output/Iinput */
U32 PIBC[MODE_NUM][PORT_NUM];		/* Port InputBuffer Control */


U32 PFC[MODE_NUM][PORT_NUM];		/* alternative mode */
U32 PFCE[MODE_NUM][PORT_NUM];
U32 PFCAE[MODE_NUM][PORT_NUM];

U32 PBDC[MODE_NUM][PORT_NUM];		/* Port Bidirection Control */
U32 PU[MODE_NUM][PORT_NUM];		/* PullUp Control */
U32 PD[MODE_NUM][PORT_NUM];		/* PullDown Control */
U32 PDSC[MODE_NUM][PORT_NUM];		/* Port Driver Strength */
U32 PODC[MODE_NUM][PORT_NUM];		/* output mode */
U32 P[MODE_NUM][PORT_NUM];			/* Port Value */


/*****************************************************************************
 *  Name        : ProcessExcel
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void ProcessExcel(void)
{
	BookHandle book = xlCreateXMLBook();
	wchar_t* cell;
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
					/* 第F列 */
					cell = xlSheetReadStr(sheet, Row, L('F'), 0);

					write_log(logFile, "[%3d,F]	%ls\n", Row + 1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"Yes"))
					{
						//printf("line if yes\n");
					}
					else if(NULL != cell && 0 == wcscmp(cell, L"No"))
					{
						continue;
					}
					else
					{
						write_log(logFile, "[%3d,F]	error 表格的第一列的值必须为Yes或者No,不能为空或者其他值，也有可能是读取错误！\n", Row + 1);
						continue;
					}
					
					/* 第C列 */
					cell = xlSheetReadStr(sheet, Row, L('C'), 0);

					write_log(logFile, "[%3d,C]	%ls\n", Row+1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"0"))
					{
						GroupNumber = P0;
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"8"))
					{
						GroupNumber = P8;
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"9"))
					{
						GroupNumber = P9;
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"10"))
					{
						GroupNumber = P10;
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"11"))
					{
						GroupNumber = P11;
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"20"))
					{
						GroupNumber = JP;
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"30"))
					{
						GroupNumber = AP;
					}
					else if (NULL != cell && 0 != wcscmp(cell, L"NA"))
					{
						write_log(logFile, "[%3d,C]	error该单元格错误，也有可能是读取错误！\n", Row + 1);
						continue;
					}

					/* 第D列 */
					PortNumber = xlSheetReadNum(sheet, Row, L('D'), NULL);
					write_log(logFile, "[%3d,D]	%d\n", Row + 1, PortNumber);

					if (PortNumber < 0 || PortNumber > 15)
					{
						write_log(logFile, "[%3d,D]	error PortNumber错误！\n", Row + 1);
					}

					/* 第E列 */
					cell = xlSheetReadStr(sheet, Row, L('E'), 0);
					write_log(logFile, "[%3d,E]	%ls\n", Row + 1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"ACTIVE"))
					{
						PORT_TYPE = ACTIVE;
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"STANDBY"))
					{
						PORT_TYPE = STANDBY;
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"RESET"))
					{
						PORT_TYPE = RESET;
					}
					else if(NULL != cell && 0 != wcscmp(cell, L"NA"))
					{
						write_log(logFile, "[%3d,E]	error出现错误！\n", Row + 1);
					}

					/* 第G列 */
					cell = xlSheetReadStr(sheet, Row, L('G'), 0);
					write_log(logFile, "[%3d,G]	%ls\n", Row + 1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"GPIO"))
					{
						SET_BIT(PMC[PORT_TYPE][GroupNumber], PortNumber);
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"ALT"))
					{
						CLEAR_BIT(PMC[PORT_TYPE][GroupNumber], PortNumber);
					}
					else
					{
						write_log(logFile, "[%3d,G]	error出现错误！\n", Row + 1);
					}

					printf("line X 0x%08x\n", PMC[PORT_TYPE][GroupNumber]);

					/* 第H列 */
					
					cell = xlSheetReadStr(sheet, Row, L('H'), 0);
					write_log(logFile, "[%3d,H]	%ls\n", Row + 1, cell);
					if (NULL != cell )
					{
						SearchAlternativNum(cell);
					}
					else
					{
						write_log(logFile, "[%3d,H]	error出现错误！\n", Row + 1);
					}
					

					/* 第I列 */
					cell = xlSheetReadStr(sheet, Row, L('I'), 0);
					write_log(logFile, "[%3d,I]	%ls\n", Row + 1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"IN"))
					{
						SET_BIT(PM[PORT_TYPE][GroupNumber], PortNumber);
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"OUT"))
					{
						CLEAR_BIT(PM[PORT_TYPE][GroupNumber], PortNumber);
					}
					else
					{
						write_log(logFile, "[%3d,I]	error出现错误！\n", Row + 1);
					}

					//printf("line X 0x%08x\n", PM[PORT_TYPE][GroupNumber]);

					/* 第J列 */
					cell = xlSheetReadStr(sheet, Row, L('J'), 0);
					write_log(logFile, "[%3d,J]	%ls\n", Row + 1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
					{
						SET_BIT(PIBC[PORT_TYPE][GroupNumber], PortNumber);
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
					{
						CLEAR_BIT(PIBC[PORT_TYPE][GroupNumber], PortNumber);
					}
					else
					{
						write_log(logFile, "[%3d,J]	error出现错误！\n", Row + 1);
					}

					//printf("line X 0x%08x\n", PIBC[PORT_TYPE][GroupNumber]);

					/* 第K列 */
					cell = xlSheetReadStr(sheet, Row, L('K'), 0);
					write_log(logFile, "[%3d,K]	%ls\n", Row + 1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
					{
						SET_BIT(PU[PORT_TYPE][GroupNumber], PortNumber);
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
					{
						CLEAR_BIT(PU[PORT_TYPE][GroupNumber], PortNumber);
					}
					else
					{
						write_log(logFile, "[%3d,K]	error出现错误！\n", Row + 1);
					}

					//printf("pullup:PU:0x%08x\n", PU[PORT_TYPE][GroupNumber]);

					/* 第L列 */
					cell = xlSheetReadStr(sheet, Row, L('L'), 0);
					write_log(logFile, "[%3d,L]	%ls\n", Row + 1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
					{
						SET_BIT(PD[PORT_TYPE][GroupNumber], PortNumber);
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
					{
						CLEAR_BIT(PD[PORT_TYPE][GroupNumber], PortNumber);
					}
					else
					{
						write_log(logFile, "[%3d,L]	error出现错误！\n", Row + 1);
					}

					//printf("pulldown:PD:0x%08x\n", PD[PORT_TYPE][GroupNumber]);

					/* 第M列 */
					cell = xlSheetReadStr(sheet, Row, L('M'), 0);
					write_log(logFile, "[%3d,M]	%ls\n", Row + 1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
					{
						SET_BIT(PBDC[PORT_TYPE][GroupNumber], PortNumber);
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
					{
						CLEAR_BIT(PBDC[PORT_TYPE][GroupNumber], PortNumber);
					}
					else
					{
						write_log(logFile, "[%3d,M]	error出现错误！\n", Row + 1);
					}

					//printf("pulldown:PBDC:0x%08x\n", PBDC[PORT_TYPE][GroupNumber]);

					/* 第N列 */
					cell = xlSheetReadStr(sheet, Row, L('N'), 0);
					write_log(logFile, "[%3d,N]	%ls\n", Row + 1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
					{
						SET_BIT(PDSC[PORT_TYPE][GroupNumber], PortNumber);
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
					{
						CLEAR_BIT(PDSC[PORT_TYPE][GroupNumber], PortNumber);
					}
					else
					{
						write_log(logFile, "[%3d,N]	error出现错误！\n", Row + 1);
					}

					//printf("pulldown:PDSC:0x%08x\n", PDSC[PORT_TYPE][GroupNumber]);

					/* 第O列 */
					cell = xlSheetReadStr(sheet, Row, L('O'), 0);
					write_log(logFile, "[%3d,O]	%ls\n", Row + 1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
					{
						SET_BIT(PDSC[PORT_TYPE][GroupNumber], PortNumber);
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
					{
						CLEAR_BIT(PDSC[PORT_TYPE][GroupNumber], PortNumber);
					}
					else
					{
						write_log(logFile, "[%3d,O]	error出现错误！\n", Row + 1);
					}

					//printf("pulldown:PDSC:0x%08x\n", PDSC[PORT_TYPE][GroupNumber]);

					/* 第P列 */
					cell = xlSheetReadStr(sheet, Row, L('P'), 0);
					write_log(logFile, "[%3d,P]	%ls\n", Row + 1, cell);

					if (NULL != cell && 0 == wcscmp(cell, L"High_Level"))
					{
						SET_BIT(P[PORT_TYPE][GroupNumber], PortNumber);
					}
					else if (NULL != cell && 0 == wcscmp(cell, L"Low-Level"))
					{
						CLEAR_BIT(P[PORT_TYPE][GroupNumber], PortNumber);
					}
					else
					{
						write_log(logFile, "[%3d,P]	error出现错误！\n", Row + 1);
					}

					//printf("pulldown:P:0x%08x\n", P[PORT_TYPE][GroupNumber]);
				}

				//printf("ACTIVE len is %d %d\n", sizeof(unsigned int), wcscmp(s, L"ACTIVE"));
				//printf("%f\n", d);
				//printf("%ls\n", s);

				//WideCharToMultiByte(CP_ACP, 0, s, wcslen(s) + 1, hh, 256, NULL, NULL);

				//printf("ACTIVE len is %d\n", wcslen(s));

				//xlSheetWriteNum(sheet, 3, 1, d * 2, 0);
				//xlSheetWriteStr(sheet, 4, 1, L"1new string", 0);
			}

			//if (xlBookSave(book, L"Pin100.xlsx")) printf("\nFile example.xls has been modified.\n");
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
U8 SearchAlternativNum(wchar_t* cell, U16 Row)
{
	S8 tmp[255] = {0};
	S8 tmp_num[50] = {0};
	U8 num = 0xFF;

	if (wcslen(cell) >= 100) printf("请检查字符串的长度\n");

	WideCharToMultiByte(CP_ACP, 0, cell, wcslen(cell) + 1, tmp, 256, NULL, NULL);

	printf("###########################string len is %d\n",strlen(tmp));
	write_log(logFile, "[H]	%d！++++++++++++++++++++++\n", strlen(tmp));

	if (0 == wcscmp(cell, L"NONE"))
	{
		num = 0xFF;
	}
	else
	{
		for (i = 0; i < strlen(tmp); i++)
		{
			if (tmp[0] == '<' && tmp[1] == 'I' && tmp[2] == 'n')
			{
				if (tmp[i + 3] != '>')
				{
					tmp_num[i] = tmp[i + 3];
				}
				
			}
			else
			{
				write_log(logFile, "[%3d,H]	error出现错误！\n", Row + 1);
				break;
			}
		}

	}
	
}

