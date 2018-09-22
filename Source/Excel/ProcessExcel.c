/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: ����Excel���
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


/* pinmux ���õļĴ�����ֵ */
U16 PMC[MODE_NUM][PORT_NUM];		/* port mode */
U16 PIPC[MODE_NUM][PORT_NUM];		/* Port IP Control */
U16 PM[MODE_NUM][PORT_NUM];			/* output/Iinput */
U16 PIBC[MODE_NUM][PORT_NUM];		/* Port InputBuffer Control */

U16 PFC[MODE_NUM][PORT_NUM];		/* alternative mode */
U16 PFCE[MODE_NUM][PORT_NUM];
U16 PFCAE[MODE_NUM][PORT_NUM];

U16 PBDC[MODE_NUM][PORT_NUM];		/* Port Bidirection Control */
U16 PU[MODE_NUM][PORT_NUM];			/* PullUp Control */
U16 PD[MODE_NUM][PORT_NUM];			/* PullDown Control */
U16 PDSC[MODE_NUM][PORT_NUM];		/* Port Driver Strength */
U16 PODC[MODE_NUM][PORT_NUM];		/* output mode */
U16 P[MODE_NUM][PORT_NUM];			/* Port Value */

U16 R_START_Pin;
U16 R_END_Pin;
U16 R_START_INT;
U16 R_END_INT;


/* F1L 100pin�ж�������� */
_ExcelResultInterrupt ExcelResultInterrupt = 
{
	{0},
	{0},
	{0},
	{NULL},
	{NULL}
};

BookHandle book;
/*****************************************************************************
 *  Name        : OpenExcel
 *  Description : ������Կ
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
S8 OpenExcel(wchar_t* ExcelName)
{
	book = xlCreateXMLBook();
	const wchar_t * x = L"Halil Kural";
	const wchar_t * y = L"windows-2723210a07c4e90162b26966a8jcdboe";
	S8 ret = -1;

	xlBookSetKey(book, x, y);

	if (book)
	{
		if (xlBookLoad(book, ExcelName))
		{
			ret = 0;
		}
	}
	
	return ret;
}

/*****************************************************************************
 *  Name        : CloseExcel
 *  Description : ������Կ
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void CloseExcel(BookHandle book)
{
	xlBookRelease(book);
}


/*****************************************************************************
 *  Name        : Pinmux_Config
 *  Description : �궨���������Ҫ�õ��Ĳ���
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void Pinmux_Config(U8 PinType)
{
    
    if (PinType == Pin_100)
    {
        R_START_Pin =  R(2);		/* 100pin�п�ʼ���� */
        R_END_Pin = R(301);		/* 100pin�м������� */
        R_START_INT = R(2);		/* 100pin�ж��п�ʼ���� */
        R_END_INT =	R(225);		/* 100pin�ж��м������� */
    }

    else if (PinType == Pin_144)
    {
        R_START_Pin = R(2);		/* 144pin�п�ʼ���� */
        R_END_Pin = R(433);		/* 144pin�м������� */
        R_START_INT = R(2);		/* 144pin�ж��п�ʼ���� */
        R_END_INT =	R(359);		/* 144pin�ж��м������� */
    }
}
/*****************************************************************************
 *  Name        : ProcessExcelInterrupt
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void ProcessExcelInterrupt(BookHandle book)
{
	wchar_t* cell;
	_ExcelResultInterrupt* p = &ExcelResultInterrupt;

	/* �򿪵ڶ���sheet */
	SheetHandle sheet = xlBookGetSheet(book, 1);

	if (sheet)
	{
		/* 2C -> 255C */
		for (U16 Row = R_START_INT; Row <= R_END_INT; Row++)
		{
			/* �ж��Ƿ����� */
			cell = xlSheetReadStr(sheet, Row, L('C'), 0);
			write_log(logFile, "[%3d,C]	Interrupt Config Status: %ls\n", Row+1, cell);

			if (NULL != cell && 0 == wcscmp(cell, L"Yes"))
			{

				/* ��ȡ�ж�Դ���� */
				cell = xlSheetReadStr(sheet, Row, L('D'), 0);
				if (NULL != cell)
				{
					wcscpy(p->IntName[p->IntNum], cell);
				}
				
				write_log(logFile, "[%3d,D]	Interrupt Source Name: %ls\n", Row+1, p->IntName[p->IntNum]);
				//printf("%ls\n", p->IntName[p->IntNum]);
				if (NULL == cell)
				{
					write_log(logFile, "[%3d,D]	Error���ִ���: %ls\n", Row + 1, cell);
				}
				
				/* ��ȡ�жϺ������� */
				cell = xlSheetReadStr(sheet, Row, L('E'), 0);
				if (NULL != cell)
				{
					wcscpy(p->IntFunName[p->IntNum], cell);
				}
				else
				{
					//p->IntFunName[p->IntNum] = {0};
					// ��ʾ����
					//printf("%d\n", sizeof(p->IntFunName[p->IntNum]));
				}
				
				write_log(logFile, "[%3d,E]	Interrupt Function Name: %ls\n", Row+1, p->IntFunName[p->IntNum]);

				if (NULL == cell)
				{
					write_log(logFile, "[%3d,E]	Error���ִ���: %ls\n", Row+1, cell);
				}

				/* ��ȡ�жϺ� */
				p->IntNumber[p->IntNum] = xlSheetReadNum(sheet, Row, L('A'), NULL);

				write_log(logFile, "[%3d,A]	%d\n", Row + 1, p->IntNumber[p->IntNum]);

				if (p->IntNumber[p->IntNum] > Intrrupt_Num )
				{
					write_log(logFile, "[%3d,A]	error p->IntNumber����\n", Row + 1);
				}
				
				p->IntConfigEnable[Row - 1] = 1;
				p->IntNum++;
			}
			else
			{
				p->IntConfigEnable[Row - 1] = 0;
			}
		}
		write_log(logFile, "+++++++ InterruptNum: %d\n", p->IntNum);
	}
}

/*****************************************************************************
 *  Name        : ProcessExcelPinmux
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void ProcessExcelPinmux(BookHandle book)
{
	
	wchar_t* cell;

	_ExcelResultPinmux ExcelResultPinmux;
	_ExcelResultPinmux* p = &ExcelResultPinmux;

	/* �򿪵�һ��sheet */
	SheetHandle sheet = xlBookGetSheet(book, 0);

	if (sheet)
	{
		double d = xlSheetReadNum(sheet, 3, 1, 0);
		U16 Row;
		
		for (Row = R_START_Pin; Row <= R_END_Pin; Row++)
		{
			memset(p, 0xFF, sizeof(_ExcelResultPinmux));
			
			/* ��F�� */
			cell = xlSheetReadStr(sheet, Row, L('F'), 0);
			
			write_log(logFile, "[%3d,F]	%ls\n", Row+1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"Yes"))
			{
				//printf("line if yes\n");
				p->whether = YES;
			}
			else if(NULL != cell && 0 == wcscmp(cell, L"No"))
			{
				p->whether = NO;
				continue;
			}
			else
			{
				write_log(logFile, "[%3d,F]	error ���ĵ�һ�е�ֵ����ΪYes����No,����Ϊ�ջ�������ֵ��Ҳ�п����Ƕ�ȡ����\n", Row + 1);
				continue;
			}
			
			/* ��C�� */		
            cell = xlSheetReadStr(sheet, Row, L('C'), 0);
			
			write_log(logFile, "[%3d,C]	%ls\n", Row+1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"0"))
			{
			    p->GroupNumber = P0;
			}
            else if (NULL != cell && 0 == wcscmp(cell, L"8"))
			{
				p->GroupNumber = P8;
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"9"))
		    {
				p->GroupNumber = P9;
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"10"))
			{
				p->GroupNumber = P10;
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"11"))
			{
				p->GroupNumber = P11;
			}
            else if (NULL != cell && 0 == wcscmp(cell, L"30"))
			{
			    p->GroupNumber = JP0;
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"40"))
		    {
				p->GroupNumber = AP0;
			}
            else if (Pin_Type == Pin_144)
            {
                if (NULL != cell && 0 == wcscmp(cell, L"1"))
			    {
				    p->GroupNumber = P1;
			    }
                else if (NULL != cell && 0 == wcscmp(cell, L"12"))
			    {
				    p->GroupNumber = P12;
			    }
                else if (NULL != cell && 0 == wcscmp(cell, L"18"))
			    {
				    p->GroupNumber = P18;
			    }
                else if (NULL != cell && 0 == wcscmp(cell, L"20"))
			    {
				    p->GroupNumber = P20;
			    }
                else if (NULL != cell && 0 == wcscmp(cell, L"50"))
			    {
				    p->GroupNumber = AP1;
			    }
            }
			else if (NULL != cell && 0 != wcscmp(cell, L"NA"))
			{
				write_log(logFile, "[%3d,C]	error�õ�Ԫ�����Ҳ�п����Ƕ�ȡ����\n", Row + 1);
				continue;
			}

			
			/* ��D�� */
			p->PortNumber = xlSheetReadNum(sheet, Row, L('D'), NULL);
			write_log(logFile, "[%3d,D]	%d\n", Row + 1, p->PortNumber);
			
			if (p->PortNumber < 0 || p->PortNumber > 15)
			{
				write_log(logFile, "[%3d,D]	error PortNumber����\n", Row + 1);
				continue;
			}
			
			/* ��E�� */
			cell = xlSheetReadStr(sheet, Row, L('E'), 0);
			write_log(logFile, "[%3d,E]	%ls\n", Row + 1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"ACTIVE"))
			{
				p->PORT_TYPE = ACTIVE;
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"STANDBY"))
			{
				p->PORT_TYPE = STANDBY;
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"RESET"))
			{
				p->PORT_TYPE = RESET;
			}
			else if(NULL != cell && 0 != wcscmp(cell, L"NA"))
			{
				write_log(logFile, "[%3d,E]	error���ִ���\n", Row + 1);
				continue;
			}
			
			/* ��G�� */
			cell = xlSheetReadStr(sheet, Row, L('G'), 0);
			write_log(logFile, "[%3d,G]	%ls\n", Row + 1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"GPIO"))
			{
				p->gpio_alt = GPIO;
				CLEAR_BIT(PMC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"ALT"))
			{
				p->gpio_alt = ALT;
				SET_BIT(PMC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else
			{
				write_log(logFile, "[%3d,G]	error���ִ���\n", Row + 1);
				continue;
			}
			
			printf("line X 0x%08x\n", PMC[p->PORT_TYPE][p->GroupNumber]);
			
			/* ��I�� */
			cell = xlSheetReadStr(sheet, Row, L('I'), 0);
			write_log(logFile, "[%3d,I]	%ls\n", Row + 1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"IN"))
			{
				p->RegType = PIN_IN;
				SET_BIT(PM[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                write_log(logFile, "[%3d,I]	%d\n", Row + 1, p->RegType);
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"OUT"))
			{
				p->RegType = PIN_OUT;
				CLEAR_BIT(PM[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else
			{
				write_log(logFile, "[%3d,I]	error���ִ���\n", Row + 1);
				continue;
			}
			
			//printf("line X 0x%08x\n", PM[PORT_TYPE][GroupNumber]);
			
			/* ��H�� */
            cell = xlSheetReadStr(sheet, Row, L('H'), 0);
            write_log(logFile, "[%3d,H] %ls\n", Row + 1, cell);
            if (NULL != cell)
            {
                p->AltNum = SearchAlternativNum(cell, Row, &p->AltType);
                if (p->AltType != p->RegType && p->gpio_alt == ALT)
                {
                    //����������ʾ���󣬸���
                    wchar_t p[20];
                    wchar_t q[200] = L"����Excel���ĵ�";
                    wsprintf(p, L"%d", Row+1);
                    wcscat(q,p);
                    wcscat(q,L"�У���H�е�����/��������Ƿ���ȷ������");
                    MessageBox(NULL, q, TEXT("��ܰ��ʾ��������������ã�����"), MB_OK | MB_ICONWARNING);
                }
                else
                {
                    if (Pin_Type == Pin_100)
                    {
                    switch (p->AltNum)
                    {
                        case 0xFF:  /* NONE */
                            CLEAR_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                        case 1: /* 1st */
                            CLEAR_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                       case 2: /* 2nd */
                            SET_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                       case 3: /* 3rd */
                            CLEAR_BIT(PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            SET_BIT(PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT(PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                       case 4: /* 4th */
                            SET_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            SET_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                       case 5: /* 5th */
                            CLEAR_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            SET_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                      default:
                            write_log(logFile, "[%3d,H] error���ܿ�ʶ�����\n", Row + 1);
                            break;  
                            }
                    }
                    else if (Pin_Type == Pin_144)
                    {
                    switch (p->AltNum)
                    {
                        case 0xFF:  /* NONE */
                            CLEAR_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                        case 1: /* 1st */
                            CLEAR_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                        case 2: /* 2nd */
                            SET_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                        case 3: /* 3rd */
                            CLEAR_BIT(PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            SET_BIT(PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT(PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                        case 4: /* 4th */
                            SET_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            SET_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                        case 5: /* 5th */
                            CLEAR_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            SET_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                        case 6:
                            CLEAR_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            SET_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                        case 7: 
                            CLEAR_BIT( PFC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            CLEAR_BIT( PFCE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            SET_BIT( PFCAE[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
                            break;
                        default:
                            write_log(logFile, "[%3d,H] error���ܿ�ʶ�����\n", Row + 1);
                            break;  
                            }
                      }
                      }
                     }
           else
           {
               write_log(logFile, "[%3d,H] error���ִ���\n", Row + 1);
           }

            
			
			/* ��J�� */
			cell = xlSheetReadStr(sheet, Row, L('J'), 0);
			write_log(logFile, "[%3d,J]	%ls\n", Row + 1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
			{
				p->InputBuffer = ENABLE;
				SET_BIT( PIBC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
			{
				p->InputBuffer = DISABLE;
				CLEAR_BIT( PIBC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else
			{
				write_log(logFile, "[%3d,J]	error���ִ���\n", Row + 1);
			}
			
			//printf("line X 0x%08x\n", PIBC[PORT_TYPE][GroupNumber]);
			
			/* ��K�� */
			cell = xlSheetReadStr(sheet, Row, L('K'), 0);
			write_log(logFile, "[%3d,K]	%ls\n", Row + 1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
			{
				p->PullUp = ENABLE;
				SET_BIT( PU[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
			{
				p->PullUp = DISABLE;
				CLEAR_BIT( PU[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else
			{
				write_log(logFile, "[%3d,K]	error���ִ���\n", Row + 1);
			}
			
			//printf("pullup:PU:0x%08x\n", PU[PORT_TYPE][GroupNumber]);
			
			/* ��L�� */
			cell = xlSheetReadStr(sheet, Row, L('L'), 0);
			write_log(logFile, "[%3d,L]	%ls\n", Row + 1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
			{
				p->PullDown = ENABLE;
				SET_BIT( PD[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
			{
				p->PullDown = DISABLE;
				CLEAR_BIT( PD[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else
			{
				write_log(logFile, "[%3d,L]	error���ִ���\n", Row + 1);
			}
			
			//printf("pulldown:PD:0x%08x\n", PD[PORT_TYPE][GroupNumber]);
			
			/* ��M�� */
			cell = xlSheetReadStr(sheet, Row, L('M'), 0);
			write_log(logFile, "[%3d,M]	%ls\n", Row + 1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
			{
				p->bidMode = ENABLE;
				SET_BIT( PBDC [p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
			{
				p->bidMode = DISABLE;
				CLEAR_BIT( PBDC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else
			{
				write_log(logFile, "[%3d,M]	error���ִ���\n", Row + 1);
			}
			
			//printf("pulldown:PBDC:0x%08x\n", PBDC[PORT_TYPE][GroupNumber]);
			
			/* ��N�� */
			cell = xlSheetReadStr(sheet, Row, L('N'), 0);
			write_log(logFile, "[%3d,N]	%ls\n", Row + 1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
			{
				p->DriverStrength = ENABLE;
				SET_BIT( PDSC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
			{
				p->DriverStrength = DISABLE;
				CLEAR_BIT( PDSC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else
			{
				write_log(logFile, "[%3d,N]	error���ִ���\n", Row + 1);
			}
			
			//printf("pulldown:PDSC:0x%08x\n", PDSC[PORT_TYPE][GroupNumber]);
			
			/* ��O�� */
			cell = xlSheetReadStr(sheet, Row, L('O'), 0);
			write_log(logFile, "[%3d,O]	%ls\n", Row + 1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"Enable"))
			{
				p->OutputMode = ENABLE;
				SET_BIT( PDSC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"Disable"))
			{
				p->OutputMode = DISABLE;
				CLEAR_BIT( PDSC[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else
			{
				write_log(logFile, "[%3d,O]	error���ִ���\n", Row + 1);
			}
			
			//printf("pulldown:PDSC:0x%08x\n", PDSC[PORT_TYPE][GroupNumber]);
			
			/* ��P�� */
			cell = xlSheetReadStr(sheet, Row, L('P'), 0);
			write_log(logFile, "[%3d,P]	%ls\n", Row + 1, cell);
			
			if (NULL != cell && 0 == wcscmp(cell, L"High_Level"))
			{
				p->PortValue = ENABLE;
				SET_BIT( P[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else if (NULL != cell && 0 == wcscmp(cell, L"Low_Level"))
			{
				p->PortValue = DISABLE;
				CLEAR_BIT( P[p->PORT_TYPE][p->GroupNumber], p->PortNumber);
			}
			else
			{
				write_log(logFile, "[%3d,P]	error���ִ���\n", Row + 1);
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
}

/*****************************************************************************
*  Name        : SearchAlternativNum
*  Description :
*  Parameter   :
*  Returns     : None
*****************************************************************************/
U8 SearchAlternativNum(wchar_t* cell, U16 Row,U8* type)
{
	S8 tmp[255] = {0};
	S8 tmp_num[50] = {0};
	U8 num = 0xFF;

	if (wcslen(cell) >= 100) printf("�����ַ����ĳ���\n");

	WideCharToMultiByte(CP_ACP, 0, cell, wcslen(cell) + 1, tmp, 256, NULL, NULL);

	//printf("###########################string len is %d\n",strlen(tmp));
	//write_log(logFile, "[H]	%d++++++++++++++++++++++\n", strlen(tmp));

	if (0 == wcscmp(cell, L"NONE"))
	{
		num = 0xFF;
	}
	else
	{
		for (U8 i = 0; i < strlen(tmp); i++)
		{
			if (tmp[0] == '<' && tmp[1] == 'I' && tmp[2] == 'n')
			{
				if (tmp[i + 3] != '>')
				{
					tmp_num[i] = tmp[i + 3];
				}
				if(NULL != type)
				{ 
					*type = PIN_IN;
				}	
			}
			else if (tmp[0] == '<' && tmp[1] == 'O' && tmp[2] == 'u' && tmp[3] == 't')
			{
				if (tmp[i + 4] != '>')
				{
					tmp_num[i] = tmp[i + 4];
				}

				if (NULL != type)
				{
					*type = PIN_OUT;
				}
			}
			else
			{
				write_log(logFile, "[%3d,H]	error���ִ���\n", Row + 1);
				break;
			}
		}
		num = atoi(tmp_num);
	}
	write_log(logFile, "[%3d,H]	%dst Alternative\n",Row + 1, num);
	return num;
}



