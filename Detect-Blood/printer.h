#ifndef PRINTER_H
#define PRINTER_H

#define A_4052 1<<25;
#define B_4052 1<<24;
#define UART0COMMON	1<<17

typedef enum
{
	PRN_ESR=0,
	PRN_SZU
}Print_Type;

typedef enum
{
	LAN_ENG=0,
	LAN_OTHER
}Print_Language;

extern void ChangePrinterFont(void);
extern void ZoomXY(uint8 zoom);
extern void init_printer(void);
extern void Print_Report(uint8);
extern void Print_queryvalue(void);
extern void Sleepms (uint32 dly);
extern void PrintALine(char type);
extern void LIB_INT3TOSTR(uint16 t, char *str);
extern void Print_QC_bmp(char electrode,float Mean_value,uint8 Cur_month);
extern void SendUart_qc_analysis_value(uint16 qc_sel,uint32 lot_no);
extern void Print_qc_analysis_value(uint16 qc_sel,uint32 lot_no);
extern void Send_testvalue(int);
extern void setnext(void);
extern void Print_CalibrationData(void);
extern void Print_Logo(void);
#endif

