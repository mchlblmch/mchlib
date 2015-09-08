
/****************************************Copyright (c)**************************************************
**                           lcg_nc

**                             
********************************************************************************************************/
#include "config.h"
#include "stdio.h"
#include "string.h"

//PID "ИП"
unsigned char Rus_Pid[2]={0x88,0x8f};
//Sample Report  "Отчет по пробам"
unsigned char Rus_SampleReport[15]={0x8e,0xe2,0xe7,0xA5,0xe2,0x20,0xaf,0xae, 0x20,0xaf,0xe0,0xae,0xa1,0xa0,0xac};
//Sample Review "Просмотр проб"
unsigned char Rus_SampleReview[14]={0x8f,0xe0,0xae,0xe1,0xac,0xae,0xe2,0xe0,0xe0,0x20,0xaf,0xe0,0xae,0xa1};
//Time  "Время"
unsigned char Rus_Time[5]={0x82,0xe0,0xa5,0xac,0xef};
//Date","Дата"},
unsigned char Rus_Date[4]={0x84,0xa0,0xe2,0xa0};
//Type","Тип"},
unsigned char Rus_Type[3]={0x92,0xa8,0xaf};
//Barcode","Штрихкод"}
unsigned char Rus_Barcode[8]={0x98,0xe2,0xe0,0xa8,0xe5,0xaa,0xae,0xa4};
//{"Normal","Норма"},
unsigned char Rus_Normal[5]={0x8d,0xae,0xe0,0xac,0xa0};
//{"mmol/L","ммоль/Л "},
unsigned char Rus_mmol[7]={0xac,0xac,0xae,0xab,0xec,'/',0x8b};
//Electrode","Электрод"),
//Electrode A(mV)   B(mV)  Slope");
unsigned char Rus_ElectrodeSlope[31]={0x87,0xaf,0xa5,0xaa,0xe2,0xe0,0xae,0xa4,' ','A','(','m','V',')',' ',' ',' ','B','(','m','V',')',' ',' ',' ',0x8d,0xa0,0xaa,0xab,0xae,0xad};
//Slope","Наклон"),
unsigned char Rus_Slope[6]=	{0x8d,0xa0,0xaa,0xab,0xae,0xad};
//Calibration Data Report","Отчет по данным калибровки"},
unsigned char Rus_CalReport[26]={0x8e,0xe2,0xe7,0xa5,0xe2,0x20,0xaf,0xae,0x20,0xa4,0xa0,0xad,0xad,0xeb,0xac,0x20,0xaa,0xa0,0xab,0xa8,0xa1,0xe0,0xae,0xa2,0xaa,0xa8};
//CO2 Calibration Data","Калибровка CO2"},
unsigned char Rus_Co2CalData[14]={0x8a,0xa0,0xab,0xa8,0xa1,0xe0,0xae,0xa2,0xaa,0xa0,0x20,'C','O','2'};
//QC Report","Отчет КК"},
unsigned char Rus_QCReport[8]={0x8e,0xe2,0xe7,0xa5,0xe2,' ',0x8a,0x8a};
//Lot No.","Лот №:"},
unsigned char Rus_LotNo[5]={0x8b,0xae,0xe2,' ',0xfc};
	//Cup No.","Чашка №:",},
unsigned char Rus_CupNo[7]={0x97,0xa0,0x98,0xaa,0xa0,' ',0xfc};
unsigned char Rus_SampleType[9][9]=
{
	//Serum","Сыворотка"},
	{0x91,0xeb,0xa2,0xae,0xe0,0xae,0xe2,0xaa,0xa0},
	//"Urine","Моча"},
	{0x8c,0xae,0xe7,0xa0,0x20,0x20,0x20,0x20,0x20},
	//CSF","ЦСЖ"},
	{0x96,0x91,0x86,0x20,0x20,0x20,0x20,0x20,0x20},
	//Dog","Собака"},
	{0x91,0xae,0xa1,0xa0,0xaa,0xa0,0x20,0x20,0x20},
	//Cat","Кошка"},
	{0x8a,0xae,0xe8,0xaa,0xa0,0x20,0x20,0x20,0x20},
	//{"Rabbit","Кролик"},
	{0x8a,0xe0,0xae,0xab,0xa8,0xaa,0x20,0x20,0x20},
	//{"Monkey","Обезьяна"},
	{0x8e,0xa1,0xa5,0xed,0xec,0xef,0xad,0xa0,0x20},
	//Rat","Крыса"},
	{0x8a,0xe0,0xeb,0xe1,0xa0,0x20,0x20,0x20,0x20},
	//"Whole Blood","Кровь"},
	{0x8a,0xe0,0xae,0xa2,0xec,0x20,0x20,0x20,0x20},
};
//Mean","Среднее"},		setstr_yw("  -2SD        Mean        +2SD");
unsigned char Rus_Mean[7]={0x91,0xe0,0xa5,0xa4,0xad,0xa5,0xa5};
//"  -2SD        Mean        +2SD  "  -2СО        Среднее        +2  СО"
unsigned char Rus_SDMean[31]={' ','-','2',0x91,0x8e,' ',' ',' ',' ',' ',' ',' ',' ',0x91,0xe0,0xa5,0xa4,0xad,0xa5,0xa5,' ',' ',' ',' ',' ',' ',' ','+','2',0x91,0x8e};
//{"QC","КК"},
unsigned char Rus_QC[2]={0x8a,0x8a};
//{"Month","Месяц"},
unsigned char Rus_Month[5]={0x8c,0xa5,0xe1,0xef,0xe6};
//{"CO2 Monthly Calibration Graph",Месячный   график   калибровки   CO2},
unsigned char Rus_Co2Month[30]={0x8c,0xa5,0xe1,0xef,0xe7,0xad,0xeb,0xa9,0x20,0xa3,0xe0,0xa0,0xe4,0xa8,0xaa,0x20,0xaa,0xa0,0xab,0xa8,0xa1,0xe0,0xae,0xa2,0xaa,0xa8,0x20,'C','O','2'};

//{"QC Graph","График КК"},
unsigned char Rus_QCGraph[9]={0x83,0xe0,0xa0,0xe4,0xa8,0xaa,' ',0x8a,0x8a};
//{"Day   QC data    Day   QC data","День    Данн. КК День    Данн. КК },
unsigned char Rus_QCData[29]={0x84,0xa5,0xad,0xec,' ',' ',0x84,0xa0,0xad,0xad,' ',' ',' ',' ',' ',' ',0x84,0xa5,0xad,0xec,' ',' ',' ',0x84,0xa0,0xad,0xad,' ',' '};


void Sleepms (uint32 dly)
{
	uint32 i;
	
	for ( ; dly>0; dly--)
		for (i=0; i<11059; i++); 
}
void LIB_INT3TOSTR(uint16 t, char *str)
{
	
	int t1 = (t/100)%10;
	int t2 = (t/10)%10;
	int t3 = t%10;

	str[0] = t1+'0';
	str[1] = t2+'0';
	str[2] = t3+'0';
	str[3]='\0';
}
void LIB_INT4TOSTR(uint16 t, char *str)
{
	int t1 = (t/1000)%10;
	int t2 = (t/100)%10;
	int t3 = (t/10)%10;
	int t4 = t%10;

	str[0] = t1+'0';
	str[1] = t2+'0';
	str[2] = t3+'0';
	str[3] = t4+'0';
	str[4]='\0';
}


void LIB_FLOATTOSTR1(float temp,char *str)
{
	uint8 a,b,c,d;
	a=((uint32)temp)/100%10;
	b=((uint32)temp)/10%10;
	c=((uint32)temp)%10;
	d=(uint32)(temp*10)%10;

	if(temp>=100)
	{
		str[0]=a+'0';
		str[1]=b+'0';
		str[2]=c+'0';
	}
	else if(temp>=10)
	{
		str[0]=' ';
		str[1]=b+'0';
		str[2]=c+'0';
	}
	else
	{
		str[0]=c+'0';
		str[1]='.';
		str[2]=d+'0';	
	}
	str[3]='\0';
}

void setstr_yw(char * p)
{
	Uart0_SendStr(p);	
	Sleepms(3);
}

void setnext()
{
	Uart0_Sendbyte(0x0a);
	Sleepms(10);
}

//字体大小调整
//zoom_H:zommX,zoom_L:zoomY;
void ZoomXY(uint8 zoom)
{
	Uart0_Sendbyte(0x1b);
	Uart0_Sendbyte(0x57);
	Uart0_Sendbyte(zoom);
	Uart0_Sendbyte(0x0a);
}

void init_printer()
{
	IO2DIR=IO2DIR|0x03020000;	//P2.24,P2.25,P2.17
	IO2CLR=A_4052;		
	IO2CLR=B_4052;
	UART0_Init(9600);
	delay_1ms(500);
	setnext();
	setnext();
	setnext();
	
}
void PrinterFont()
{
	system_set_t *Cur_set;
	Cur_set=Get_system_set();

	if(Cur_set->pH_print==PRN_SZU)
	{
		//深大打印机置小字体
		ZoomXY(0x11);
		delay_1ms_precise(300);	
	}
	
}


void ChangePrinterFont()
{
	system_set_t *Cur_set;
	Cur_set=Get_system_set();

	if(Cur_set->pH_print==PRN_SZU)
	{
		//深大打印机置小字体
		ZoomXY(0x11);
		delay_1ms_precise(300);	
	}
}

void Print_Set_Russia()
{
#ifdef RUSSIA 
	Uart0_Sendbyte(0x1b);
	Uart0_Sendbyte(0x52);
	Uart0_Sendbyte(0x01);
	delay_1ms(2);
 #endif
}
void Print_Set_GB2312()
{
	//中文/俄文方式
#ifdef RUSSIA 
	Uart0_Sendbyte(0x1b);
	Uart0_Sendbyte(0x52);
	Uart0_Sendbyte(0x00);
	delay_1ms(2);
#endif
}

void Printer_Set()
{
	system_set_t *Cur_set;
	Cur_set=Get_system_set();

	if(Cur_set->pH_print==PRN_ESR)
	{
		//ESR打印机初始化
		Uart0_Sendbyte(0x1b);
		Uart0_Sendbyte(0x40);

		delay_1ms_precise(1000);
#ifdef RUSSIA 
		Uart0_Sendbyte(0x1b);
		Uart0_Sendbyte(0x52);
		Uart0_Sendbyte(0x01);
		delay_1ms(2);
#else
		Uart0_Sendbyte(0x1b);
		Uart0_Sendbyte(0x52);
		Uart0_Sendbyte(0x00);
		delay_1ms(2);
#endif
		//正向打印
		Uart0_Sendbyte(0x1b);
		Uart0_Sendbyte(0x63);
		Uart0_Sendbyte(0x00);
	}

}

//加热时间调整
void Tem_adj(uint8 PulseWidth)
{
	Uart0_Sendbyte(0x1b);
	Uart0_Sendbyte(0x63);
	Uart0_Sendbyte(PulseWidth);
	Uart0_Sendbyte(0x0a);
}

//打印位图
void Draw_bmp(uint8 *buf,uint8 length)
{
	uint16 i;
	system_set_t *Cur_set;
	Cur_set=Get_system_set();

	if(Cur_set->pH_print==PRN_SZU)
	{
		Uart0_Sendbyte(0x1b);
		Uart0_Sendbyte(0x2a);
		Uart0_Sendbyte(length);
		for(i=0;i<48;i++)
		{
			Uart0_Sendbyte(*buf++);
		}
		Uart0_Sendbyte(0x0a);
	}
	else
	{
		Uart0_Sendbyte(0x1b);
		Uart0_Sendbyte(0x2a);
		Uart0_Sendbyte(0x01);
		Uart0_Sendbyte(0x80);
		Uart0_Sendbyte(0x01);
		
		for(i=0;i<48*8;i++)
		{
			Uart0_Sendbyte(*buf++);
		}
		Uart0_Sendbyte(0x1b);
		Uart0_Sendbyte(0x4a);
		Uart0_Sendbyte(0x00);
		delay_1ms_precise(100);
	}	
}

void djzfxbgd()
{
	Uart0_Sendbyte(0x80);
	Uart0_Sendbyte(0x00);
	Uart0_Sendbyte(0x80);
	Uart0_Sendbyte(0x01);
	Uart0_Sendbyte(0x80);
	Uart0_Sendbyte(0x02);
	Uart0_Sendbyte(0x80);
	Uart0_Sendbyte(0x03);
	Uart0_Sendbyte(0x80);
	Uart0_Sendbyte(0x04);
	Uart0_Sendbyte(0x80);
	Uart0_Sendbyte(0x05);
	Uart0_Sendbyte(0x80);
	Uart0_Sendbyte(0x06);
	Uart0_Sendbyte(0x80);
	Uart0_Sendbyte(0x07);
}

void DrawArrow( Value_C_t *val,	Normal_value_t *normal, int index, float coin, float ca)
{
	char str[30];
	system_set_t *Cur_set;
	Cur_set=Get_system_set();

	setstr_yw("  (");
	LIB_FLOATTOSTR1(coin*normal->fval[index*2+0],str);
	setstr_yw(str);
	setstr_yw("---");
	LIB_FLOATTOSTR1(coin*normal->fval[index*2+1],str);
	setstr_yw(str);
	setstr_yw(")");

	if(Cur_set->pH_print==PRN_SZU)
	{
		if(index==3||index==6)
		{
			//ca
			if(ca>coin*normal->fval[index*2+1])
			{
				Uart0_Sendbyte(0x83);
				Uart0_Sendbyte(0x09);
			}
			else if(ca<coin*normal->fval[index*2+0])
			{
				Uart0_Sendbyte(0x84);
				Uart0_Sendbyte(0x00);
			}
		}
		else
		{
			if(val->fval[index]>normal->fval[index*2+1])
			{
				Uart0_Sendbyte(0x83);
				Uart0_Sendbyte(0x09);
			}
			else if(val->fval[index]<normal->fval[index*2+0])
			{
				Uart0_Sendbyte(0x84);
				Uart0_Sendbyte(0x00);
			}
		}
	}
	else
	{
		if(index==3||index==6)
		{
			//ca
			if(ca>coin*normal->fval[index*2+1])
			{
				setstr_yw("↑");
			}
			else if(ca<coin*normal->fval[index*2+0])
			{
				setstr_yw("↓");
			}
		}
		else
		{
			if(val->fval[index]>normal->fval[index*2+1])
			{
				setstr_yw("↑");
			}
			else if(val->fval[index]<normal->fval[index*2+0])
			{
				setstr_yw("↓");
			}
		}

	}
	setnext();

}

void TrimDeviceInformation()
{
	int i;
	int len;

	if(gPrintHospitalInfo)
	{
		len=strlen(gHospitalStr);
		if(len<32)
		{
			len=(32-len)/2;
			for(i=0;i<len;i++)
				setstr_yw(" ");
			setstr_yw(gHospitalStr);
			
		}
		else
			setstr_yw(gHospitalStr);
		setnext();
		
	}	
	if(gPrintDeviceInfo)
	{
		len=strlen(gDeviceStr);
		if(len<32)
		{
			len=(32-len)/2;
			for(i=0;i<len;i++)
				setstr_yw(" ");
			setstr_yw(gDeviceStr);
			
		}
		else
			setstr_yw(gDeviceStr);
		setnext();
	}	
	if(gPrintCompanyInfo)
	{
		len=strlen(gCompanyStr);
		if(len<32)
		{
			len=(32-len)/2;
			for(i=0;i<len;i++)
				setstr_yw(" ");
			setstr_yw(gCompanyStr);
			
		}
		else
			setstr_yw(gCompanyStr);
		setnext();
	}	
}

void Print_Report(uint8 type)
{
	float temp;
	Value_C_t TData;
	Value_C_t *Cur_Cx;
	Date_Time *Curdate;
	system_set_t *Cur_set;
	Normal_value_t *me_normal;
	Test_Info_t *me_data;
	Item_t *me;
	char str[30];
	char *TestObjective[9]={"Serum","Urine","CSF","Dog","Cat","Rabbit","Monkey","Rat","Whole Blood"};
	char *TestObjective_chn[9]={"血清","尿液","脑脊液","  狗  ","  猫  "," 兔子 "," 猴子 "," 鼠类 "," 全血"};
	int i,len;
	Advance_Setup_t *me2 ;
	me2=Get_Advance_Setup();

	Curdate=Get_Cur_DateTime();		 //得到当前日期
	Cur_set=Get_system_set();
	
	me_normal=Get_NormalValue();
	me=Get_item_settings();

	Read_Normal_Value();
	Cur_Cx=Get_Cx_Value();			 //得到测试值

	#if 0
	me->k=1;
	me->na=1;
	me->cl=1;
	me->ca=1;
	me->ag=1;
	me->li=1;
	me->ph=1;
	me->co2=1;
	me->mg=1;

	TData.fval[0]=3.01;
	TData.fval[1]=148.1;
	TData.fval[2]=68.2;
	TData.fval[3]=0.25;
	TData.fval[4]=0.35;
	TData.fval[6]=7.30;
	TData.fval[7]=0.1;
	TData.fval[5]=1.02;
	Cur_Cx=&TData;

	#endif
	ChangePrinterFont();

	if(Cur_set->printer_s==1)
	{
		TrimDeviceInformation();
	}
	switch(Cur_set->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef RUSSIA
			for(i=0;i<9;i++)
				Uart0_Sendbyte(' ');
			for(i=0;i<15;i++)
				Uart0_Sendbyte(Rus_SampleReport[i]);
#else
			setstr_yw("        ");
			if(Cur_set->pH_print==PRN_SZU)
				djzfxbgd();
			else
				setstr_yw("电解质分析报告单");				
#endif
			break;
		case 0x00:
		//英文模式
			setstr_yw("         Sample Report");
			break;
		default:
			break;
	}
	setnext();

	if(type==0)
	{
		//实测结果
		me_data=Get_SaveSample();
		setnext();

		switch(Cur_set->print_lan)
		{
			//非英文模式
			case 0x01:
#ifdef 		RUSSIA
				for(i=0;i<5;i++)
					Uart0_Sendbyte(Rus_Time[i]);
				Uart0_Sendbyte(':');
#else
				if(Cur_set->pH_print==PRN_ESR)
					setstr_yw("时间:   ");
				else
					setstr_yw("Time:   ");
#endif		
				break;
			case 0x00:
				setstr_yw("Time:   ");
				break;
		}
		
		
#ifdef CHINESE	
		str[0]=((Curdate->Year>>4)&0x0f)+'0';
		str[1]=(Curdate->Year&0x0f)+'0';

		str[2]='-';
		str[3]=((Curdate->Month>>4)&0x0f)+'0';
		str[4]=(Curdate->Month&0x0f)+'0';

		str[5]='-';
		str[6]=((Curdate->Date>>4)&0x0f)+'0';
		str[7]=(Curdate->Date&0x0f)+'0';
		str[8]='\0';
#else
		str[0]=((Curdate->Date>>4)&0x0f)+'0';
		str[1]=(Curdate->Date&0x0f)+'0';

		str[2]='-';
		str[3]=((Curdate->Month>>4)&0x0f)+'0';
		str[4]=(Curdate->Month&0x0f)+'0';

		str[5]='-';
		str[6]=((Curdate->Year>>4)&0x0f)+'0';
		str[7]=(Curdate->Year&0x0f)+'0';
		str[8]='\0';
#endif
		setstr_yw(str);

		setstr_yw("  ");
		str[0]=((Curdate->Hour>>4)&0x0f)+'0';
		str[1]=(Curdate->Hour&0x0f)+'0';
		str[2]=':';
		str[3]=((Curdate->Minute>>4)&0x0f)+'0';
		str[4]=(Curdate->Minute&0x0f)+'0';
		str[5]=':';
		str[6]=((Curdate->Second>>4)&0x0f)+'0';
		str[7]=(Curdate->Second&0x0f)+'0';
		str[8]='\0';
		setstr_yw(str);
		setnext();


		switch(Cur_set->print_lan)
		{
			//非英文模式
			case 0x01:
#ifdef 		RUSSIA
				for(i=0;i<3;i++)
					Uart0_Sendbyte(Rus_Type[i]);
				for(i=0;i<3;i++)
					Uart0_Sendbyte(' ');
				Uart0_Sendbyte(':');
				for(i=0;i<9;i++)
					Uart0_Sendbyte(Rus_SampleType[me_data->Type][i]);
#else
				if(Cur_set->pH_print==PRN_ESR)
				{
					setstr_yw("样本:   ");
					setstr_yw(TestObjective_chn[me_data->Type]);
				}
				else
				{
					setstr_yw("Type:   ");
					setstr_yw(TestObjective[me_data->Type]);
				}
#endif		
				break;
			case 0x00:
				setstr_yw("Type:   ");
				setstr_yw(TestObjective[me_data->Type]);
				break;
		}
		
		setnext();

	}
	else
	{
		//历史数据
		me_data=Get_ReadSample();
		for(i=0;i<8;i++)
			TData.fval[i]=me_data->fval[i];
		Cur_Cx=&TData;

		setnext();

		switch(Cur_set->print_lan)
		{
			//非英文模式
			case 0x01:
#ifdef 		RUSSIA
				for(i=0;i<5;i++)
					Uart0_Sendbyte(Rus_Time[i]);
				Uart0_Sendbyte(':');
#else
				if(Cur_set->pH_print==PRN_ESR)
					setstr_yw("时间:   ");
				else
					setstr_yw("Time:   ");
#endif		
				break;
			case 0x00:
				setstr_yw("Time:   ");
				break;
		}

#ifdef CHINESE	
		str[0]=((me_data->Test_Data>>20)&0x0f)+'0';
		str[1]=((me_data->Test_Data>>16)&0x0f)+'0';

		str[2]='-';
		str[3]=((me_data->Test_Data>>12)&0x0f)+'0';
		str[4]=((me_data->Test_Data>>8)&0x0f)+'0';

		str[5]='-';
		str[6]=((me_data->Test_Data>>4)&0x0f)+'0';
		str[7]=(me_data->Test_Data&0x0f)+'0';
		str[8]='\0';
#else
		str[0]=((me_data->Test_Data>>4)&0x0f)+'0';
		str[1]=(me_data->Test_Data&0x0f)+'0';

		str[2]='-';
		str[3]=((me_data->Test_Data>>12)&0x0f)+'0';
		str[4]=((me_data->Test_Data>>8)&0x0f)+'0';

		str[5]='-';
		str[6]=((me_data->Test_Data>>20)&0x0f)+'0';
		str[7]=((me_data->Test_Data>>16)&0x0f)+'0';
		str[8]='\0';
#endif
		setstr_yw(str);

		setstr_yw("  ");
		str[0]=((me_data->Test_time>>20)&0x0f)+'0';
		str[1]=((me_data->Test_time>>16)&0x0f)+'0';
		str[2]=':';
		str[3]=((me_data->Test_time>>12)&0x0f)+'0';
		str[4]=((me_data->Test_time>>8)&0x0f)+'0';
		str[5]=':';
		str[6]=((me_data->Test_time>>4)&0x0f)+'0';
		str[7]=(me_data->Test_time&0x0f)+'0';
		str[8]='\0';
		setstr_yw(str);
		setnext();

		switch(Cur_set->print_lan)
		{
			//非英文模式
			case 0x01:
#ifdef 		RUSSIA
				for(i=0;i<3;i++)
					Uart0_Sendbyte(Rus_Type[i]);
				for(i=0;i<3;i++)
					Uart0_Sendbyte(' ');
				Uart0_Sendbyte(':');
				for(i=0;i<9;i++)
					Uart0_Sendbyte(Rus_SampleType[me_data->Type][i]);
#else
				if(Cur_set->pH_print==PRN_ESR)
				{
					setstr_yw("样本:   ");
					setstr_yw(TestObjective_chn[me_data->Type]);
				}
				else
				{
					setstr_yw("Type:   ");
					setstr_yw(TestObjective[me_data->Type]);
				}
#endif		
				break;
			case 0x00:
				setstr_yw("Type:   ");
				setstr_yw(TestObjective[me_data->Type]);
				break;
		}
		setnext();
		
		
	}

	if( gSystemMode==0)
	{
		if((me_data->Item_flag&0x7f)<6)
		{
			str[0]='*';
			str[1]='0'+(me_data->Item_flag&0x7f)%10;
		}
		else
		{
			str[0]='0'+((me_data->Item_flag&0x7f)-5)/10;
			str[1]='0'+((me_data->Item_flag&0x7f)-5)%10;
		}
		str[2]=0;

		switch(Cur_set->print_lan)
		{
			//非英文模式
			case 0x01:
#ifdef 		RUSSIA
				for(i=0;i<7;i++)
					Uart0_Sendbyte(Rus_CupNo[i]);
				Uart0_Sendbyte(':');
#else
				if(Cur_set->pH_print==PRN_ESR)
					setstr_yw("杯号:   ");
				else
					setstr_yw("Cup No.:   ");
#endif		
				break;
			case 0x00:
				setstr_yw("Cup No.:   ");
				break;
		}
		
		setstr_yw(str);
		if(me_data->BarCode[0]!=0x20&&me_data->BarCode[0]!=0)
		{
			setstr_yw("(");
			setstr_yw(me_data->BarCode);
			setstr_yw(")");
		}
		setnext();
	}
	else
	{
		if(me_data->BarCode[0]!=0x20&&me_data->BarCode[0]!=0)
		{

			switch(Cur_set->print_lan)
			{
				//非英文模式
				case 0x01:
#ifdef 		RUSSIA
					for(i=0;i<8;i++)
						Uart0_Sendbyte(Rus_Barcode[i]);
					Uart0_Sendbyte(':');
#else
					if(Cur_set->pH_print==PRN_ESR)
						setstr_yw("条码号:   ");
					else
						setstr_yw("Barcode:   ");
#endif		
					break;
				case 0x00:
					setstr_yw("Barcode:   ");
					break;
			}
			setstr_yw(me_data->BarCode);
		}
		setnext();
	}	

	switch(Cur_set->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef 		RUSSIA
			for(i=0;i<2;i++)
				Uart0_Sendbyte(Rus_Pid[i]);
			Uart0_Sendbyte(':');
#else
			if(Cur_set->pH_print==PRN_ESR)
				setstr_yw("病例");
			else
				setstr_yw("PID ");
#endif		
			break;
		case 0x00:
			setstr_yw("PID ");
			break;
	}
	

	if((me_data->Item_flag&0x80)==0x80)
		setstr_yw("*");
	else
		setstr_yw(" ");
		
	LIB_INT4TOSTR(me_data->Sample_No,str);
		
	setstr_yw(str);

	switch(Cur_set->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef 		RUSSIA
			for(i=0;i<3;i++)
				Uart0_Sendbyte(' ');
			for(i=0;i<7;i++)
				Uart0_Sendbyte(Rus_mmol[i]);
			for(i=0;i<3;i++)
				Uart0_Sendbyte(' ');
			for(i=0;i<5;i++)
				Uart0_Sendbyte(Rus_Normal[i]);		
#else
			if(Cur_set->pH_print==PRN_ESR)
				setstr_yw("   mmol/L   正常范围");
			else
				setstr_yw("   mmol/L   Normal");
#endif		
			break;
		case 0x00:
			setstr_yw("   mmol/L   Normal");
			break;
	}

	
	setnext();

	Print_Set_GB2312();

#ifdef TESTFAST
	return;
#endif

	if(Cur_set->pH_print==PRN_SZU)
	{
		switch(Cur_set->print_lan)
		{
			case 0x01:
				if(me->k==1)
				{
					setstr_yw("    ");
					Uart0_Sendbyte(0x80);
					Uart0_Sendbyte(0x08);
					setstr_yw(":     ");
					float_to_char(str,Cur_Cx->fval[0]);
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 0, 1.0,0);
				}

				if(me->na==1)
				{
					setstr_yw("    ");
					Uart0_Sendbyte(0x80);
					Uart0_Sendbyte(0x09);
					setstr_yw(":     ");
					float_to_char(str,Cur_Cx->fval[1]);;
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 1, 1.0,0);
				}

				if(me->cl==1)
				{
					setstr_yw("    ");
					Uart0_Sendbyte(0x81);
					Uart0_Sendbyte(0x00);
					setstr_yw(":     ");
					float_to_char(str,Cur_Cx->fval[2]);
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 2, 1.0,0);
				}

				if(me2->TestObjective!=1)
				{

					if(me->li==1)
					{
						setstr_yw("    ");
						Uart0_Sendbyte(0x83);
						Uart0_Sendbyte(0x08);
						setstr_yw(":     ");
						float_to_char(str,Cur_Cx->fval[4]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 4, 1.0,0);
					}
					if(me->mg==1)
					{
						setstr_yw("    ");
						Uart0_Sendbyte(0x83);
						Uart0_Sendbyte(0x01);
						setstr_yw(":     ");
						float_to_char(str,Cur_Cx->fval[5]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 5, 1.0,0);
					}

					if(me->ca==1)
					{
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x02);
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x03);
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x01);
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x07);
						Uart0_Sendbyte(0x81);
						Uart0_Sendbyte(0x01);
						setstr_yw(": ");
						float_to_char(str,Cur_Cx->fval[3]);
						setstr_yw(str);
						setstr_yw("  ");
						setnext();

						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x04);
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x05);
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x01);
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x07);
						Uart0_Sendbyte(0x81);
						Uart0_Sendbyte(0x01);
						setstr_yw(": ");
						temp=Cur_Cx->fval[3]+0.28*(Cur_Cx->fval[6]-7.4);
						if(temp<0)
							temp=0;					
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 3, 1.0,temp);

						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x09);
						Uart0_Sendbyte(0x81);
						Uart0_Sendbyte(0x01);
						setstr_yw("  ");
						Uart0_Sendbyte(0x85);
						Uart0_Sendbyte(0x04);
						setstr_yw("    ");
						
						temp=1.95*temp;
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 3, 1.95,temp);
					}
					if(me->co2==1)
					{
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x09);
						Uart0_Sendbyte(0x85);
						Uart0_Sendbyte(0x00);
						Uart0_Sendbyte(0x85);
						Uart0_Sendbyte(0x01);
						Uart0_Sendbyte(0x85);
						Uart0_Sendbyte(0x02);
						Uart0_Sendbyte(0x85);
						Uart0_Sendbyte(0x03);
						setstr_yw(": ");
						float_to_char(str,Cur_Cx->fval[7]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 7, 1.0,0);
					}
					if(me->ag==1&&me->co2==1)
					{
						temp=Cur_Cx->fval[1]-(Cur_Cx->fval[2]+Cur_Cx->fval[7])-2;
						if(temp<0)
							temp=-temp;
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x06);
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x01);
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x07);
						Uart0_Sendbyte(0x84);
						Uart0_Sendbyte(0x08);
						setstr_yw(":   ");
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 6, 1.0,temp);
					}
				}
				break;
			case 0x0:
				if(me->k==1)
				{
					setstr_yw("     K:     ");
					float_to_char(str,Cur_Cx->fval[0]);
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 0, 1.0,0);
				}

				if(me->na==1)
				{
					setstr_yw("    Na:     ");
					float_to_char(str,Cur_Cx->fval[1]);
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 1, 1.0,0);
				}

				if(me->cl==1)
				{
					setstr_yw("    Cl:     ");
					float_to_char(str,Cur_Cx->fval[2]);
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 2, 1.0,0);
				}
				if(me2->TestObjective!=1)
				{
				
					if(me->li==1)
					{
						setstr_yw("    Li:     ");
						float_to_char(str,Cur_Cx->fval[4]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 4, 1.0,0);
					}
					if(me->mg==1)
					{
						setstr_yw("    Mg:     ");
						float_to_char(str,Cur_Cx->fval[5]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 5, 1.0,0);
					}
					if(me->ca==1)
					{
						setstr_yw("   iCa:     ");
						float_to_char(str,Cur_Cx->fval[3]);
						setstr_yw(str);
						setstr_yw("  ");
						
						setnext();

						temp=Cur_Cx->fval[3]+0.28*(Cur_Cx->fval[6]-7.4);
						if(temp<0)
							temp=0;
						setstr_yw("   nCa:     ");
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 3, 1.0,temp);

						temp=1.95*temp;
						setstr_yw("   TCa:     ");
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 3, 1.95,temp);
					}
					if(me->co2==1)
					{
						setstr_yw("  TCO2:     ");
						float_to_char(str,Cur_Cx->fval[7]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 7, 1.0,0);
					}
					if(me->ag==1&&me->co2==1)
					{
						temp=Cur_Cx->fval[1]-(Cur_Cx->fval[2]+Cur_Cx->fval[7])-2;
						if(temp<0)
							temp=-temp;
						setstr_yw("    AG:     ");
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 6, 1.0,temp);
					}
				}
				break;
			default:
				break;
		}
	}
	else
	{
#ifdef  CHINESE
		switch(Cur_set->print_lan)
		{
			case 0x01:
				if(me->k==1)
				{
					setstr_yw("    钾:     ");
					float_to_char(str,Cur_Cx->fval[0]);
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 0, 1.0,0);
				}

				if(me->na==1)
				{
					setstr_yw("    钠:     ");
					float_to_char(str,Cur_Cx->fval[1]);;
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 1, 1.0,0);
				}

				if(me->cl==1)
				{
					setstr_yw("    氯:     ");
					float_to_char(str,Cur_Cx->fval[2]);
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 2, 1.0,0);
				}

				if(me2->TestObjective!=1)
				{

					if(me->li==1)
					{
						setstr_yw("    锂:     ");
						float_to_char(str,Cur_Cx->fval[4]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 4, 1.0,0);
					}
					if(me->mg==1)
					{
						setstr_yw("    镁:     ");
						float_to_char(str,Cur_Cx->fval[5]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 5, 1.0,0);
					}

					if(me->ca==1)
					{
						setstr_yw("实测离子钙: ");
						float_to_char(str,Cur_Cx->fval[3]);
						setstr_yw(str);
						setstr_yw("  ");
						setnext();

						setstr_yw("标准离子钙: ");
						temp=Cur_Cx->fval[3]+0.28*(Cur_Cx->fval[6]-7.4);
						if(temp<0)
							temp=0;					
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 3, 1.0,temp);

						setstr_yw("    总钙:   ");
						
						temp=1.95*temp;
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 3, 1.95,temp);
					}
					if(me->co2==1)
					{
						setstr_yw("总二氧化碳: ");
						float_to_char(str,Cur_Cx->fval[7]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 7, 1.0,0);
					}
					if(me->ag==1&&me->co2==1)
					{
						temp=Cur_Cx->fval[1]-(Cur_Cx->fval[2]+Cur_Cx->fval[7])-2;
						if(temp<0)
							temp=-temp;
						setstr_yw("阴离子间隙: ");
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 6, 1.0,temp);
					}
				}
				break;
			case 0x0:
#endif
				if(me->k==1)
				{
					setstr_yw("     K:     ");
					float_to_char(str,Cur_Cx->fval[0]);
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 0, 1.0,0);
				}

				if(me->na==1)
				{
					setstr_yw("    Na:     ");
					float_to_char(str,Cur_Cx->fval[1]);
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 1, 1.0,0);
				}

				if(me->cl==1)
				{
					setstr_yw("    Cl:     ");
					float_to_char(str,Cur_Cx->fval[2]);
					setstr_yw(str);
					DrawArrow( Cur_Cx,	me_normal, 2, 1.0,0);
				}
				if(me2->TestObjective!=1)
				{
				
					if(me->li==1)
					{
						setstr_yw("    Li:     ");
						float_to_char(str,Cur_Cx->fval[4]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 4, 1.0,0);
					}
					if(me->mg==1)
					{
						setstr_yw("    Mg:     ");
						float_to_char(str,Cur_Cx->fval[5]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 5, 1.0,0);
					}
					if(me->ca==1)
					{
						setstr_yw("   iCa:     ");
						float_to_char(str,Cur_Cx->fval[3]);
						setstr_yw(str);
						setstr_yw("  ");
						
						setnext();

						temp=Cur_Cx->fval[3]+0.28*(Cur_Cx->fval[6]-7.4);
						if(temp<0)
							temp=0;
						setstr_yw("   nCa:     ");
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 3, 1.0,temp);

						temp=1.95*temp;
						setstr_yw("   TCa:     ");
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 3, 1.95,temp);
					}
					if(me->co2==1)
					{
						setstr_yw("  TCO2:     ");
						float_to_char(str,Cur_Cx->fval[7]);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 7, 1.0,0);
					}
					if(me->ag==1&&me->co2==1)
					{
						temp=Cur_Cx->fval[1]-(Cur_Cx->fval[2]+Cur_Cx->fval[7])-2;
						if(temp<0)
							temp=-temp;
						setstr_yw("    AG:     ");
						float_to_char(str,temp);
						setstr_yw(str);
						DrawArrow( Cur_Cx,	me_normal, 6, 1.0,temp);
					}
				}
#ifdef CHINESE
				break;
			default:
				break;
		}
#endif


	}
	if(me2->TestObjective!=1)
	{
		if(me->ph==1)
		{
			setstr_yw("    pH:     ");
			float_to_char(str,Cur_Cx->fval[6]);
			setstr_yw(str);
			setnext();
		}		
	}
	setnext();
	setnext();
	setnext();

	Print_Set_Russia();

}

void Send_testvalue(int histroy)
{
	float temp;
	Value_C_t *Cur_Cx;
	Date_Time *Curdate;
	Value_C_t TData;
	Test_Info_t *Save_result;
	Normal_value_t *me_normal;
	Item_t *me;
	uint8 i,j;
	char str[30],pad[30];
	
	me_normal=Get_NormalValue();
	me=Get_item_settings();

#ifdef OLDLIS
		#if 0
		me->k=1;
		me->na=1;
		me->cl=1;
		me->ca=1;
		me->ag=1;
		me->li=1;
		me->ph=1;
		me->co2=1;
		me->mg=1;

		TData.k=3.01;
		TData.na=148.1;
		TData.cl=68.2;
		TData.ca=0.25;
		TData.li=0.35;
		TData.ph=7.30;
		TData.co2=0.1;
		TData.mg=1.21;
		Cur_Cx=&TData;

		#endif

		if(histroy==0)
		{
			Cur_Cx=Get_Cx_Value();			 //得到测试值
			Curdate=Get_Cur_DateTime();		 //得到当前日期

			Read_Cur_Time();//读取当前日期
		
			Save_result=Get_SaveSample();//得到存储测量结果的地址
		
			Uart0_SendStr("                               ");
			Uart0_SendStr("         Sample Report        ");
			Uart0_SendStr("Date     ");
			str[0]=((Curdate->Year>>4)&0x0f)+'0';
			str[1]=(Curdate->Year&0x0f)+'0';
			str[2]='-';
			str[3]=((Curdate->Month>>4)&0x0f)+'0';
			str[4]=(Curdate->Month&0x0f)+'0';
			str[5]='-';
			str[6]=((Curdate->Date>>4)&0x0f)+'0';
			str[7]=(Curdate->Date&0x0f)+'0';
			str[8]='\0';
			Uart0_SendStr(str);
			Uart0_SendStr("             ");
			Uart0_SendStr("Time     ");
			str[0]=((Curdate->Hour>>4)&0x0f)+'0';
			str[1]=(Curdate->Hour&0x0f)+'0';
			str[2]=':';
			str[3]=((Curdate->Minute>>4)&0x0f)+'0';
			str[4]=(Curdate->Minute&0x0f)+'0';
			str[5]=':';
			str[6]=((Curdate->Second>>4)&0x0f)+'0';
			str[7]=(Curdate->Second&0x0f)+'0';
			str[8]='\0';
			Uart0_SendStr(str);
			Uart0_SendStr("             ");
			
		}
		else
		{

			Save_result=Get_ReadSample();
			Cur_Cx=Get_Cx_Value();			 //得到测试值

			Uart0_SendStr("                               ");
			Uart0_SendStr("         Sample Report        ");
			Uart0_SendStr("Date     ");
			Uart0_Sendbyte(((Save_result->Test_Data>>20)&0x0f)+'0');//year
			Uart0_Sendbyte(((Save_result->Test_Data>>16)&0x0f)+'0');
			Uart0_Sendbyte('-');
			Uart0_Sendbyte(((Save_result->Test_Data>>12)&0x0f)+'0');//month
			Uart0_Sendbyte(((Save_result->Test_Data>>8)&0x0f)+'0');
			Uart0_Sendbyte('-');
			Uart0_Sendbyte(((Save_result->Test_Data>>4)&0x0f)+'0');//date
			Uart0_Sendbyte((Save_result->Test_Data&0x0f)+'0');
			Uart0_SendStr("             ");
			Uart0_SendStr("Time     ");	

			Uart0_Sendbyte(((Save_result->Test_time>>20)&0x0f)+'0');//
			Uart0_Sendbyte(((Save_result->Test_time>>16)&0x0f)+'0');
			Uart0_Sendbyte(':');
			Uart0_Sendbyte(((Save_result->Test_time>>12)&0x0f)+'0');//
			Uart0_Sendbyte(((Save_result->Test_time>>8)&0x0f)+'0');
			Uart0_Sendbyte(':');
			Uart0_Sendbyte(((Save_result->Test_time>>4)&0x0f)+'0');//
			Uart0_Sendbyte((Save_result->Test_time&0x0f)+'0');
			Uart0_SendStr("             ");

			for(i=0;i<8;i++)
				TData.fval[i]=Save_result->fval[i];
		
			Cur_Cx=&TData;
		
		}

		Uart0_SendStr("PAT<-ID  ");
		LIB_INT4TOSTR(Save_result->Sample_No,str);
		Uart0_SendStr(str);
		Uart0_SendStr("      Normal (mM)");
		Uart0_SendStr("   ");
		if(me->k==1)
		{
			Uart0_SendStr("K    ");
			float_to_char(str,Cur_Cx->fval[0]);
			Uart0_SendStr(str);
			Uart0_SendStr("  mmol/L (");
			LIB_FLOATTOSTR1(me_normal->fval[0*2+0],str);
			Uart0_SendStr(str);
			Uart0_SendStr("--");
			LIB_FLOATTOSTR1(me_normal->fval[0*2+1],str);
			Uart0_SendStr(str);
			Uart0_SendStr(")");
			Uart0_SendStr("   ");
		}
		if(me->na==1)
		{
			Uart0_SendStr("Na   ");
			float_to_char(str,Cur_Cx->fval[1]);;
			Uart0_SendStr(str);
			Uart0_SendStr("  mmol/L (");
			LIB_FLOATTOSTR1(me_normal->fval[1*2+0],str);
			Uart0_SendStr(str);
			Uart0_SendStr("--");
			LIB_FLOATTOSTR1(me_normal->fval[1*2+1],str);
			Uart0_SendStr(str);
			Uart0_SendStr(")");
			Uart0_SendStr("   ");
		}

		if(me->cl==1)
		{
			Uart0_SendStr("Cl   ");
			float_to_char(str,Cur_Cx->fval[2]);
			Uart0_SendStr(str);
			Uart0_SendStr("  mmol/L (");
			LIB_FLOATTOSTR1(me_normal->fval[2*2+0],str);
			Uart0_SendStr(str);
			Uart0_SendStr("--");
			LIB_FLOATTOSTR1(me_normal->fval[2*2+1],str);
			Uart0_SendStr(str);
			Uart0_SendStr(")");
			Uart0_SendStr("   ");
		}
		if(me->ca==1)
		{
			Uart0_SendStr("iCa  ");
			float_to_char(str,Cur_Cx->fval[3]);
			Uart0_SendStr(str);
			Uart0_SendStr("  mmol/L (");
			LIB_FLOATTOSTR1(me_normal->fval[3*2+0],str);
			Uart0_SendStr(str);
			Uart0_SendStr("--");
			LIB_FLOATTOSTR1(me_normal->fval[3*2+1],str);
			Uart0_SendStr(str);
			Uart0_SendStr(")");
			Uart0_SendStr("   ");
			
			Uart0_SendStr("TCa  ");
			float_to_char(str,1.95*(Cur_Cx->fval[3]+0.28*(Cur_Cx->fval[6]-7.4)));
			Uart0_SendStr(str);
			Uart0_SendStr("  mmol/L (");
			LIB_FLOATTOSTR1(1.95*me_normal->fval[3*2+0],str);
			Uart0_SendStr(str);
			Uart0_SendStr("--");
			LIB_FLOATTOSTR1(1.95*me_normal->fval[3*2+1],str);
			Uart0_SendStr(str);
			Uart0_SendStr(")");
			Uart0_SendStr("   ");
		
			Uart0_SendStr("nCa  ");
			float_to_char(str,Cur_Cx->fval[3]+0.28*(Cur_Cx->fval[6]-7.4));
			Uart0_SendStr(str);
			Uart0_SendStr("  mmol/L ");
			Uart0_SendStr("            ");
		}
		if(me->co2==1)
		{
			Uart0_SendStr("TCO2 ");
			float_to_char(str,Cur_Cx->fval[7]);
			Uart0_SendStr(str);
			Uart0_SendStr("  mmol/L (");
			LIB_FLOATTOSTR1(me_normal->fval[7*2+0],str);
			Uart0_SendStr(str);
			Uart0_SendStr("--");
			LIB_FLOATTOSTR1(me_normal->fval[7*2+1],str);
			Uart0_SendStr(str);
			Uart0_SendStr(")");
			Uart0_SendStr("   ");
		}
		if(me->ph==1)
		{
			Uart0_SendStr("pH   ");
			float_to_char(str,Cur_Cx->fval[6]);
			Uart0_SendStr(str);
			Uart0_SendStr("         (");
			LIB_FLOATTOSTR1(7.00,str);
			Uart0_SendStr(str);
			Uart0_SendStr("--");
			LIB_FLOATTOSTR1(8.00,str);
			Uart0_SendStr(str);
			Uart0_SendStr(")");
			Uart0_SendStr("   ");
		}
		if(me->li==1)
		{
			Uart0_SendStr("Li   ");
			float_to_char(str,Cur_Cx->fval[4]);
			Uart0_SendStr(str);
			Uart0_SendStr("  mmol/L             ");
		}
		if(me->ag==1)
		{
			temp=Cur_Cx->fval[1]-(Cur_Cx->fval[2]+Cur_Cx->fval[7])-2;
			if(temp<0)
				temp=-temp;
			else if(temp>100)
			{
				temp=100;
			}
			Uart0_SendStr("AG   ");
			float_to_char(str,temp);
			Uart0_SendStr(str);
			Uart0_SendStr("  mmol/L             ");
		}
#else
		#if 0
		me->k=1;
		me->na=1;
		me->cl=1;
		me->ca=1;
		me->ag=1;
		me->li=1;
		me->ph=1;
		me->co2=1;
		me->mg=1;

		TData.k=3.01;
		TData.na=148.1;
		TData.cl=68.2;
		TData.ca=0.25;
		TData.li=0.35;
		TData.ph=7.30;
		TData.co2=0.1;
		TData.mg=1.21;
		Cur_Cx=&TData;

		#endif

		if(histroy==0)
		{
			Cur_Cx=Get_Cx_Value();			 //得到测试值
			Curdate=Get_Cur_DateTime();		 //得到当前日期

			Read_Cur_Time();//读取当前日期
		
			Save_result=Get_SaveSample();//得到存储测量结果的地址
		
			Uart0_SendStr("Sample Report  ");
			Uart0_SendStr("Date  ");
			str[0]=((Curdate->Year>>4)&0x0f)+'0';
			str[1]=(Curdate->Year&0x0f)+'0';
			str[2]='-';
			str[3]=((Curdate->Month>>4)&0x0f)+'0';
			str[4]=(Curdate->Month&0x0f)+'0';
			str[5]='-';
			str[6]=((Curdate->Date>>4)&0x0f)+'0';
			str[7]=(Curdate->Date&0x0f)+'0';
			str[8]=' ';
			str[9]=' ';
			str[10]='\0';
			Uart0_SendStr(str);
			Uart0_SendStr("Time  ");
			str[0]=((Curdate->Hour>>4)&0x0f)+'0';
			str[1]=(Curdate->Hour&0x0f)+'0';
			str[2]=':';
			str[3]=((Curdate->Minute>>4)&0x0f)+'0';
			str[4]=(Curdate->Minute&0x0f)+'0';
			str[5]=':';
			str[6]=((Curdate->Second>>4)&0x0f)+'0';
			str[7]=(Curdate->Second&0x0f)+'0';
			str[8]=' ';
			str[9]=' ';
			str[10]='\0';
			Uart0_SendStr(str);
			
		}
		else
		{

			Save_result=Get_ReadSample();
			Cur_Cx=Get_Cx_Value();			 //得到测试值

			Uart0_SendStr("Sample Review  ");
			Uart0_SendStr("Date  ");
			Uart0_Sendbyte(((Save_result->Test_Data>>20)&0x0f)+'0');//year
			Uart0_Sendbyte(((Save_result->Test_Data>>16)&0x0f)+'0');
			Uart0_Sendbyte('-');
			Uart0_Sendbyte(((Save_result->Test_Data>>12)&0x0f)+'0');//month
			Uart0_Sendbyte(((Save_result->Test_Data>>8)&0x0f)+'0');
			Uart0_Sendbyte('-');
			Uart0_Sendbyte(((Save_result->Test_Data>>4)&0x0f)+'0');//date
			Uart0_Sendbyte((Save_result->Test_Data&0x0f)+'0');
			Uart0_Sendbyte(' ');		
			Uart0_Sendbyte(' ');		

			Uart0_SendStr("Time  ");
			Uart0_Sendbyte(((Save_result->Test_time>>20)&0x0f)+'0');//
			Uart0_Sendbyte(((Save_result->Test_time>>16)&0x0f)+'0');
			Uart0_Sendbyte(':');
			Uart0_Sendbyte(((Save_result->Test_time>>12)&0x0f)+'0');//
			Uart0_Sendbyte(((Save_result->Test_time>>8)&0x0f)+'0');
			Uart0_Sendbyte(':');
			Uart0_Sendbyte(((Save_result->Test_time>>4)&0x0f)+'0');//
			Uart0_Sendbyte((Save_result->Test_time&0x0f)+'0');
			Uart0_Sendbyte(' ');
			Uart0_Sendbyte(' ');

			for(i=0;i<8;i++)
				TData.fval[i]=Save_result->fval[i];
			
			Cur_Cx=&TData;
		
		}

		Uart0_SendStr("PAT       ");
		LIB_INT4TOSTR(Save_result->Sample_No,str);
		Uart0_SendStr(str);
		Uart0_SendStr("  ");
		Uart0_SendStr("Reel       ");
		str[0]='0';
		str[1]='0';
		str[2]='1';
		str[3]='\0';
		Uart0_SendStr(str);
		Uart0_SendStr("  ");
		Uart0_SendStr("Cup       ");
		str[0]='0';
		str[1]='0';
		str[2]='1';
		str[3]='\0';
		Uart0_SendStr(str);
		Uart0_SendStr("  ");
		Uart0_SendStr("Barcode   ");

		for(i=0;i<20;i++)
			str[i]=Save_result->BarCode[i];
				
		for(i=strlen(str);i<20;i++)
			str[i]=' ';
		str[19]=0;
		
		Uart0_SendStr(str);
		Uart0_SendStr("  ");


		if(me->k==1)
		{
			Uart0_SendStr("K ");
			float_to_char(str,Cur_Cx->fval[0]);
			Uart0_SendStr(str);
			j=0;
			for(i=strlen(str)+1;i<12;i++)
				pad[j++]=' ';
			pad[j]='\0';
			Uart0_SendStr(pad);
		}
		else
		{
			Uart0_SendStr("K      0.00  ");
		}

		if(me->na==1)
		{
			Uart0_SendStr("Na ");
			float_to_char(str,Cur_Cx->fval[1]);
			Uart0_SendStr(str);
			j=0;
			for(i=strlen(str)+1;i<12;i++)
				pad[j++]=' ';
			pad[j]='\0';
			Uart0_SendStr(pad);
		}
		else
		{
			Uart0_SendStr("Na      0.00  ");
		}

		if(me->cl==1)
		{
			Uart0_SendStr("Cl ");
			float_to_char(str,Cur_Cx->fval[2]);
			Uart0_SendStr(str);
			j=0;
			for(i=strlen(str)+1;i<12;i++)
				pad[j++]=' ';
			pad[j]='\0';
			Uart0_SendStr(pad);
		}
		else
		{
			Uart0_SendStr("Cl      0.00  ");
		}

		
		if(me->ca==1)
		{
			Uart0_SendStr("iCa ");
			float_to_char(str,Cur_Cx->fval[3]);
			Uart0_SendStr(str);
			j=0;
			for(i=strlen(str)+1;i<12;i++)
				pad[j++]=' ';
			pad[j]='\0';
			Uart0_SendStr(pad);
		}
		else
		{
			Uart0_SendStr("iCa      0.00  ");
		}


		if(me->ca==1)
		{
			Uart0_SendStr("TCa ");
			float_to_char(str,1.95*(Cur_Cx->fval[3]+0.28*(Cur_Cx->fval[6]-7.4)));
			Uart0_SendStr(str);
			j=0;
			for(i=strlen(str)+1;i<12;i++)
				pad[j++]=' ';
			pad[j]='\0';
			Uart0_SendStr(pad);

			Uart0_SendStr("nCa ");
			float_to_char(str,Cur_Cx->fval[3]+0.28*(Cur_Cx->fval[6]-7.4));
			Uart0_SendStr(str);
			j=0;
			for(i=strlen(str)+1;i<12;i++)
				pad[j++]=' ';
			pad[j]='\0';
			Uart0_SendStr(pad);
			
		}
		else
		{
			Uart0_SendStr("TCa      0.00  ");
			Uart0_SendStr("nCa      0.00  ");
		}

		if(me->co2==1)
		{
			Uart0_SendStr("TCO2 ");
			float_to_char(str,Cur_Cx->fval[7]);
			Uart0_SendStr(str);
			j=0;
			for(i=strlen(str)+1;i<12;i++)
				pad[j++]=' ';
			pad[j]='\0';
			Uart0_SendStr(pad);
		}
		else
		{
			Uart0_SendStr("TCO2      0.00  ");
		}
			
		if(me->ph==1)
		{
			Uart0_SendStr("pH ");
			float_to_char(str,Cur_Cx->fval[6]);
			Uart0_SendStr(str);
			j=0;
			for(i=strlen(str)+1;i<12;i++)
				pad[j++]=' ';
			pad[j]='\0';
			Uart0_SendStr(pad);
		}
		else
		{
			Uart0_SendStr("pH      0.00  ");
		}


		if(me->ag==1&&me->co2==1)
		{
			Uart0_SendStr("AG ");

			temp=Cur_Cx->fval[1]-(Cur_Cx->fval[2]+Cur_Cx->fval[7])-2;
			if(temp<0)
				temp=-temp;
			float_to_char(str,temp);
			Uart0_SendStr(str);
			j=0;
			for(i=strlen(str)+1;i<12;i++)
				pad[j++]=' ';
			pad[j]='\0';
			Uart0_SendStr(pad);
		}
		else
		{
			Uart0_SendStr("AG      0.00  ");
		}

		if( me->mg==1)
		{
			Uart0_SendStr("Mg ");
			float_to_char(str,Cur_Cx->fval[5]);
			Uart0_SendStr(str);
			j=0;
			for(i=strlen(str)+1;i<12;i++)
				pad[j++]=' ';
			pad[j]='\0';
			Uart0_SendStr(pad);
		}
		else
		{
			Uart0_SendStr("Mg      0.00  ");
		}
			
		if( me->li==1)
		{
			Uart0_SendStr("Li ");
			float_to_char(str,Cur_Cx->fval[4]);
			Uart0_SendStr(str);
			j=0;
			for(i=strlen(str)+1;i<12;i++)
				pad[j++]=' ';
			pad[j]='\0';
			Uart0_SendStr(pad);
		}
		else
		{
			Uart0_SendStr("Li      0.00  ");
		}
			
		Uart0_SendStr("End");

#endif

}

void SendUart_qc_analysis_value(uint16 qc_sel,uint32 lot_no)
{
	char str[20];
	Date_Time *me;
	Qc_actual_t *Cur_actual;
	system_set_t *Cur_set;
	Cur_set=Get_system_set();
	Cur_actual=Get_QcActual();
	me=Get_Cur_DateTime();
	Read_Cur_Time();//读取当前日期
	
	Uart0_SendStr("QC Report ");

	Uart0_SendStr("Date:");
	Uart0_Sendbyte(((me->Year>>4)&0x0f)+'0');//year
	Uart0_Sendbyte((me->Year&0x0f)+'0');
	Uart0_Sendbyte('-');
	Uart0_Sendbyte(((me->Month>>4)&0x0f)+'0');//month
	Uart0_Sendbyte((me->Month&0x0f)+'0');
	Uart0_Sendbyte('-');
	Uart0_Sendbyte(((me->Date>>4)&0x0f)+'0');//date
	Uart0_Sendbyte((me->Date&0x0f)+'0');
	Uart0_Sendbyte(' ');

	Uart0_SendStr("QC");
	Uart0_Sendbyte(qc_sel+'0');
	Uart0_Sendbyte(' ');

	Uart0_SendStr("Lot No:");	
	int6_to_char(str,lot_no,6);
	Uart0_SendStr(str);
	Uart0_Sendbyte(' ');

	Uart0_SendStr("K :");
	float_to_char(str, Cur_actual->fval[0]);
	Uart0_SendStr(str);
	Uart0_Sendbyte(' ');

	Uart0_SendStr("Na:");
	float_to_char(str, Cur_actual->fval[1]);
	Uart0_SendStr(str);
	Uart0_Sendbyte(' ');

	Uart0_SendStr("Cl:");
	float_to_char(str, Cur_actual->fval[2]);
	Uart0_SendStr(str);
	Uart0_Sendbyte(' ');

	Uart0_SendStr("iCa:");
	float_to_char(str, Cur_actual->fval[3]);
	Uart0_SendStr(str);
	Uart0_Sendbyte(' ');

#ifdef OLDLIS	
	Uart0_SendStr("Li:");
	float_to_char(str, Cur_actual->fval[4]);
	Uart0_SendStr(str);
#else
	if(isMgMachine(Cur_set)&&!isLiMachine(Cur_set))
		Uart0_SendStr("Mg:");
	else
		Uart0_SendStr("Li:");
		
	float_to_char(str, Cur_actual->fval[4]);
	Uart0_SendStr(str);
	Uart0_Sendbyte(' ');

	Uart0_SendStr("CO2:");
	float_to_char(str, Cur_actual->fval[5]);
	Uart0_SendStr(str);
	Uart0_Sendbyte(' ');

	Uart0_SendStr("End");
#endif
	
}

void Print_mmol()
{
	int i;
	system_set_t *Cur_set;
	Cur_set=Get_system_set();

	switch(Cur_set->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef 		RUSSIA
			for(i=0;i<4;i++)
				Uart0_Sendbyte(' ');
			for(i=0;i<7;i++)
				Uart0_Sendbyte(Rus_mmol[i]);
#else
			setstr_yw("    mmol/L");
#endif		
			break;
		case 0x00:
			setstr_yw("    mmol/L");
			break;
	}
}
void Print_qc_analysis_value(uint16 qc_sel,uint32 lot_no)
{
	int i;
	char str[20];
	Date_Time *me;
	Qc_actual_t *Cur_actual;
	system_set_t *Cur_set;
	Cur_set=Get_system_set();
	Cur_actual=Get_QcActual();
	me=Get_Cur_DateTime();

	ChangePrinterFont();

	switch(Cur_set->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef 		RUSSIA
			for(i=0;i<12;i++)
				Uart0_Sendbyte(' ');
			for(i=0;i<8;i++)
				Uart0_Sendbyte(Rus_QCReport[i]);
#else
			if(Cur_set->pH_print==PRN_ESR)
				setstr_yw("           质控报告");
			else
				setstr_yw("          QC Report ");
#endif		
			break;
		case 0x00:
			setstr_yw("          QC Report ");
			break;
	}

	setnext();

	switch(Cur_set->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef 		RUSSIA
			for(i=0;i<3;i++)
				Uart0_Sendbyte(' ');
			for(i=0;i<4;i++)
				Uart0_Sendbyte(Rus_Date[i]);
			Uart0_Sendbyte(':');
#else
			if(Cur_set->pH_print==PRN_ESR)
				setstr_yw("   日期:   ");
			else
				setstr_yw("   Date:   ");
#endif		
			break;
		case 0x00:
			setstr_yw("   Date:   ");
			break;
	}

#ifdef CHINESE
	setstr_yw("20");
	Uart0_Sendbyte(((me->Year>>4)&0x0f)+'0');//year
	Uart0_Sendbyte((me->Year&0x0f)+'0');
	Uart0_Sendbyte('-');
	Uart0_Sendbyte(((me->Month>>4)&0x0f)+'0');//month
	Uart0_Sendbyte((me->Month&0x0f)+'0');
	Uart0_Sendbyte('-');
	Uart0_Sendbyte(((me->Date>>4)&0x0f)+'0');//date
	Uart0_Sendbyte((me->Date&0x0f)+'0');
#else
	Uart0_Sendbyte(((me->Date>>4)&0x0f)+'0');//date
	Uart0_Sendbyte((me->Date&0x0f)+'0');
	Uart0_Sendbyte('-');
	Uart0_Sendbyte(((me->Month>>4)&0x0f)+'0');//month
	Uart0_Sendbyte((me->Month&0x0f)+'0');
	Uart0_Sendbyte('-');
	Uart0_Sendbyte(((me->Year>>4)&0x0f)+'0');//year
	Uart0_Sendbyte((me->Year&0x0f)+'0');
#endif

	setnext();

	switch(Cur_set->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef 		RUSSIA
			for(i=0;i<3;i++)
				Uart0_Sendbyte(' ');
			for(i=0;i<5;i++)
				Uart0_Sendbyte(Rus_LotNo[i]);
			Uart0_Sendbyte(':');
#else
			if(Cur_set->pH_print==PRN_ESR)
				setstr_yw("   批号:   ");	
			else
				setstr_yw("   Lot No:   ");	
#endif		
			break;
		case 0x00:
			setstr_yw("   Lot No:   ");	
			break;
	}
	
	int6_to_char(str,lot_no,6);
	setstr_yw(str);

	switch(Cur_set->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef 		RUSSIA
			for(i=0;i<5;i++)
				Uart0_Sendbyte(' ');
			for(i=0;i<2;i++)
				Uart0_Sendbyte(Rus_QC[i]);
			Uart0_Sendbyte(':');
#else
			if(Cur_set->pH_print==PRN_ESR)
				setstr_yw("    质控:   ");	
			else
				setstr_yw("    QC");
#endif		
			break;
		case 0x00:
			setstr_yw("    QC");
			break;
	}
	
	Uart0_Sendbyte(qc_sel+'0');
	setnext();
	setnext();

	setstr_yw("   K   :    ");
	float_to_char(str,Cur_actual->fval[0]);
	setstr_yw(str);
	Print_mmol();
	
	setnext();

	setstr_yw("   Na  :    ");
	float_to_char(str,Cur_actual->fval[1]);
	setstr_yw(str);
	Print_mmol();
	setnext();

	setstr_yw("   Cl  :    ");
	float_to_char(str,Cur_actual->fval[2]);
	setstr_yw(str);
	Print_mmol();
	setnext();

	setstr_yw("   iCa :    ");
	float_to_char(str,Cur_actual->fval[3]);
	setstr_yw(str);
	Print_mmol();
	setnext();

	if(isMgMachine(Cur_set)&&!isLiMachine(Cur_set))
		setstr_yw("   Mg  :    ");
	else
		setstr_yw("   Li  :    ");
		
	float_to_char(str,Cur_actual->fval[4]);
	setstr_yw(str);
	Print_mmol();
	setnext();
	
	setstr_yw("   CO2 :    ");
	float_to_char(str,Cur_actual->fval[5]);
	setstr_yw(str);
	Print_mmol();
	setnext();
	
	setnext();
	setnext();
	setnext();
	setnext();
}

//s=1:print,s=0:not print
void Print_sd(float sd_01,float mean, uint8 type)
{
	int i;
	char str[32]="                               ";
	float temp;
	system_set_t *Cur_set;
	Cur_set=Get_system_set();

	if(type==1)
	{
		switch(Cur_set->print_lan)
		{
			//非英文模式
			case 0x01:
#ifdef 		RUSSIA
				for(i=0;i<31;i++)
					Uart0_Sendbyte(Rus_SDMean[i]);
#else
				setstr_yw("  -2SD        Mean        +2SD");
#endif		
				break;
			case 0x00:
				setstr_yw("  -2SD        Mean        +2SD");
				break;
		}
		Uart0_Sendbyte(0x0a);
		delay_1ms(3);
	}
	if(mean<10)
	{
		temp=mean-2*sd_01+0.005;
		//str[2]=((uint32)temp)/10%10+'0';
		str[2]=((uint32)temp)%10+'0';
		str[3]='.';
		str[4]=((uint32)(temp*10))%10+'0';
		str[5]=((uint32)(temp*100))%10+'0';

		str[14]=((uint32)mean)%10+'0';
		str[15]='.';
		str[16]=((uint32)(mean*10))%10+'0';
		str[17]=((uint32)(mean*100))%10+'0';

		temp=mean+2*sd_01+0.005;
		//str[2]=((uint32)temp)/10%10+'0';
		str[26]=((uint32)temp)%10+'0';
		str[27]='.';
		str[28]=((uint32)(temp*10))%10+'0';
		str[29]=((uint32)(temp*100))%10+'0';
		str[30]='\0';
	}
	else if(mean<100)
	{
		temp=mean-2*sd_01;
		str[2]=((uint32)temp)/10%10+'0';
		str[3]=((uint32)temp)%10+'0';
		str[4]='.';
		str[5]=((uint32)(temp*10))%10+'0';

		str[14]=((uint32)mean)/10%10+'0';
		str[15]=((uint32)mean)%10+'0';
		str[16]='.';
		str[17]=((uint32)(mean*10))%10+'0';

		temp=mean+2*sd_01;
		str[26]=((uint32)temp)/10%10+'0';
		str[27]=((uint32)temp)%10+'0';
		str[28]='.';
		str[29]=((uint32)(temp*10))%10+'0';
		str[30]='\0';
	}	
	else
	{
		temp=mean-2*sd_01;
		str[2]=((uint32)temp)/100%10+'0';
		str[3]=((uint32)temp)/10%10+'0';
		str[4]=((uint32)temp)%10+'0';
		str[5]='.';
		str[6]=((uint32)(temp*10))%10+'0';

		str[14]=((uint32)mean)/100%10+'0';
		str[15]=((uint32)mean)/10%10+'0';
		str[16]=((uint32)mean)%10+'0';
		str[17]='.';
		str[18]=((uint32)(mean*10))%10+'0';

		temp=mean+2*sd_01;
		str[26]=((uint32)temp)/100%10+'0';
		str[27]=((uint32)temp)/10%10+'0';
		str[28]=((uint32)temp)%10+'0';
		str[29]='.';
		str[30]=((uint32)(temp*10))%10+'0';
		str[31]='\0';
	}
	setstr_yw(str);
	Uart0_Sendbyte(0x0a);
	delay_1ms(3);
	
}

void fill_with_data(uint8 *buf,uint8 dat)
{
	uint16 i;
	system_set_t *Cur_set;
	Cur_set=Get_system_set();

	if(Cur_set->pH_print==PRN_SZU)
	{
		for(i=0;i<48;i++)
		{
			buf[i]=dat;
		}
	}
	else
	{
		for(i=0;i<48*8;i++)
		{
			buf[i]=dat;
		}
	}
}

void Print_qcmonth(uint8 month,char electrode,int type)
{
	int i;
	char str[10];
	system_set_t *Cur_set;
	Cur_set=Get_system_set();

	if(Cur_set->pH_print==PRN_SZU)
	{
		str[0]=month/10+'0';
		str[1]=month%10+'0';
		str[2]='\0';

		if(type==1)
		{
			setstr_yw("      ");
			setstr_yw(str);

			if(Cur_set->print_lan)
			{
				Uart0_Sendbyte(0x82);
				Uart0_Sendbyte(0x06);//月

				Uart0_Sendbyte(0x83);
				Uart0_Sendbyte(0x02);//份
			}
			else
			{
				setstr_yw(" ");
				setstr_yw("Month");
			}
		}
		else
		{
			setstr_yw("   CO2 Monthly Calibration Graph");
			Uart0_Sendbyte(0x0a);
			delay_1ms(3);
			return;
		}
		
		switch(electrode)
		{
			case 0:
				str[0]=' ';
				str[1]=' ';
				str[2]='K';
				break;
			case 1:
				str[0]=' ';
				str[1]='N';
				str[2]='a';
				break;
			case 2:
				str[0]=' ';
				str[1]='C';
				str[2]='l';
				break;
			case 3:
				str[0]=' ';
				str[1]='C';
				str[2]='a';
				break;
			case 4:
				if(isMgMachine(Cur_set)&&!isLiMachine(Cur_set))
				{
					str[0]=' ';
					str[1]='M';
					str[2]='g';
				}
				else
				{
					str[0]=' ';
					str[1]='L';
					str[2]='i';
				}
				break;
			case 5:
				str[0]='C';
				str[1]='o';
				str[2]='2';
				break;				
			default:
				break;
		}
		str[3]='\0';
		setstr_yw(str);

		if(Cur_set->print_lan)
		{
			Uart0_Sendbyte(0x83);
			Uart0_Sendbyte(0x03);//质

			Uart0_Sendbyte(0x83);
			Uart0_Sendbyte(0x04);//控
		
			Uart0_Sendbyte(0x83);
			Uart0_Sendbyte(0x05);//图

		}
		else
		{
			setstr_yw(" ");
			setstr_yw("QC Graph");
			setstr_yw(" ");
		}
		Uart0_Sendbyte(0x0a);
		delay_1ms(3);
	}
	else
	{
		str[0]=month/10+'0';
		str[1]=month%10+'0';
		str[2]='\0';

		if(type==1)
		{
			setstr_yw("     ");
			setstr_yw(str);


			switch(Cur_set->print_lan)
			{
				//非英文模式
				case 0x01:
#ifdef 		RUSSIA
					for(i=0;i<5;i++)
						Uart0_Sendbyte(Rus_Month[i]);
					for(i=0;i<2;i++)
						Uart0_Sendbyte(' ');
#else
					if(Cur_set->pH_print==PRN_ESR)
						setstr_yw("月份");
					else
						setstr_yw("  Month  ");
#endif		
					break;
				case 0x00:
					setstr_yw("  Month  ");
					break;
			}
	
		}
		else
		{
			switch(Cur_set->print_lan)
			{
				//非英文模式
				case 0x01:
#ifdef 		RUSSIA
				Uart0_Sendbyte(' ');
				for(i=0;i<30;i++)
					Uart0_Sendbyte(Rus_Co2Month[i]);
#else
					if(Cur_set->pH_print==PRN_ESR)
						setstr_yw("   CO2 月度定标曲线");
					else
						setstr_yw("  CO2 Monthly Calibration Graph");
#endif		
					break;
				case 0x00:
					setstr_yw("  CO2 Monthly Calibration Graph");
					break;
			}

			Uart0_Sendbyte(0x0a);
			delay_1ms(3);
			return;
		}

		switch(electrode)
		{
			case 0:
				str[0]=' ';
				str[1]=' ';
				str[2]='K';
				break;
			case 1:
				str[0]=' ';
				str[1]='N';
				str[2]='a';
				break;
			case 2:
				str[0]=' ';
				str[1]='C';
				str[2]='l';
				break;
			case 3:
				str[0]=' ';
				str[1]='C';
				str[2]='a';
				break;
			case 4:
				str[0]=' ';
				str[1]='L';
				str[2]='i';
				break;
			case 5:
				str[0]='C';
				str[1]='o';
				str[2]='2';
				break;
			default:
				break;
		}
		str[3]='\0';
		setstr_yw(str);


		switch(Cur_set->print_lan)
		{
			//非英文模式
			case 0x01:
#ifdef 		RUSSIA
				for(i=0;i<2;i++)
					Uart0_Sendbyte(' ');
				for(i=0;i<9;i++)
					Uart0_Sendbyte(Rus_QCGraph[i]);
				Uart0_Sendbyte(' ');
#else
				if(Cur_set->pH_print==PRN_ESR)
					setstr_yw("  质控图");
				else
					setstr_yw(" QC Graph ");
#endif		
				break;
			case 0x00:
				setstr_yw(" QC Graph ");
				break;
		}

		Uart0_Sendbyte(0x0a);
		delay_1ms(3);
	}	
}


void Print_Single_Curve(char electrode,float Mean_value, float factor, uint8 type)
{
	uint16 m,i;
	char str[100],buf1[20],buf2[20];
	uint8 buf[48*8],j,dat_int,dat_rem,beyond;
	float sd_01,sd_24,temp,temp2;
	uint32 location;
	system_set_t *Cur_set;
	Cur_set=Get_system_set();

	if(Cur_set->pH_print==PRN_SZU)
	{
		sd_01=Mean_value*0.025;
		sd_24=Mean_value-2.4*sd_01;//坐标0时的值	float temp,factor;

		for(j=1;j<32;j++)
		{
			beyond=0;
			fill_with_data(buf,0);
			
			buf[0]=0xc0;
			buf[11]=0x01;
			buf[47]=0x03;
			buf[23]=0x3c;
			buf[35]=0x01;
			
			Draw_bmp(buf,0x10);
			delay_1ms(10);

			if(type==1)
			{
				if(actual_temp[j].Qc_amount==1)
					temp=actual_temp[j].fval[electrode];
				else
					temp=0;

				if(temp>sd_24)
				{
					temp=temp-sd_24;
					location=(uint32)(temp*factor);
					if(location>94)
					{	
						beyond=1;
						location=94;
					}
				}
				else
				{
					if(temp>=0.01)
						beyond=2;
					location=0;
				}
			}
			else
			{
			
				temp=cal_slope[j-1];

				if(temp>0)
				{
					location=(uint32)(temp*94/(2*Mean_value) );
					if(location>94)
					{
						beyond=1;
						location=94;
					}
				}
				else
				{
					if(temp>=0.01)
						beyond=2;
					location=0;
				}
			}

			if(beyond==0)
			{
				dat_int=location/2;
				dat_rem=location%2;
				if(dat_rem==1)
				{
					buf[dat_int]=0x0f;
				}
				else
				{
					buf[dat_int]=0xf0;
				}
				if((j!=0)&&((j%5)==0))
				{
					buf[24]=0xff;
				}
				buf[23]=0x3f;
				buf[47]=buf[47]|0x03;
			}
			else if(beyond==1)
			{
				if((j!=0)&&((j%5)==0))
				{
					buf[24]=0xff;
				}
				buf[23]=0x3f;

				buf[46]=0xff;
				buf[47]=0xff;

							
			}
			else
			{
				if((j!=0)&&((j%5)==0))
				{
					buf[24]=0xff;
				}
				buf[23]=0x3f;
				buf[0]=0xff;
				buf[1]=0xff;
			}
			Draw_bmp(buf,0x03);
			delay_1ms(10);
		}
		fill_with_data(buf,0);
		buf[0]=0xc0;
		buf[47]=0x03;
		buf[23]=0x3c;
		
		Draw_bmp(buf,0x10);
		delay_1ms(100);
		
		Tem_adj(100);
		setnext();
		setnext();
	}
	else
	{
		if(type==1)
		{
			sd_01=Mean_value*0.025;
			sd_24=Mean_value-2.0*sd_01;//坐标0时的值	float temp,factor;
		}
		else
		{
			sd_01=Mean_value*0.5;
			sd_24=Mean_value-2.0*sd_01;//坐标0时的值	float temp,factor;
		}

		for(j=1;j<32;j++)
		{
			fill_with_data(buf,0);
			
			if(type==1)
			{
				if(actual_temp[j].Qc_amount==1)
					temp=actual_temp[j].fval[electrode];
				else
					temp=0;
			}
			else
			{
				temp=cal_slope[j-1];
				if(temp<0)
					temp=0;
			}
			
			if(temp>sd_24)
			{
				temp=temp-sd_24;
				location=24+(uint32)(temp*factor);
				if(location>360)
					location=382;
				else if(location<24 )
					location=1;
			}
			else 
			{
				location=1;
			}

			for(i=location-1;i<=location+1;i++)
				buf[i]=0x01;
					
			if(j%5==0)
			{
				for(i=193;i<200;i++)
					buf[i]=0x01;	
			}
			else
			{
				for(i=193;i<196;i++)
					buf[i]=0x01;	
			}
				
			buf[24]=0xff;	
			buf[192]=0xff;	
			buf[383-24]=0xff;	

			
			Draw_bmp(buf,0x0);
		}

	}
	setnext();
	if((type==1)&&(QC_print[5]==1))
	{
		switch(Cur_set->print_lan)
		{
			//非英文模式
			case 0x01:
#ifdef 		RUSSIA
				for(m=0;m<29;m++)
					Uart0_Sendbyte(Rus_QCData[m]);
#else
				if(Cur_set->pH_print==PRN_ESR)
					setstr_yw("日期   质控数据    日期   质控数据");
				else
					setstr_yw("Day   QC data    Day   QC data");
#endif		
				break;
			case 0x00:
				setstr_yw("Day   QC data    Day   QC data");
				break;
		}

		setnext();
		for(j=1;j<32;j+=2)
		{
			i=j;
			if(actual_temp[i].Qc_amount==1)
				temp=actual_temp[i].fval[electrode];
			else
				temp=0;

			float_to_char(buf1,temp);
			i=j+1;
			if(i<32)
			{
				if(actual_temp[i].Qc_amount==1)
					temp2=actual_temp[i].fval[electrode];
				else
					temp2=0;

				float_to_char(buf2,temp2);
				sprintf(str,"%02d   %s       %02d   %s",i-1,buf1,i,buf2);
			}
			else
			{
				sprintf(str,"%02d   %s",j,buf1);
			}
			setstr_yw(str);
			setnext();
		}
			
			
	}
	setnext();
	setnext();
	setnext();
}



void Print_QC_bmp(char electrode,float Mean_value,uint8 Cur_month)
{
	system_set_t *Cur_set;
	uint8 buf[48*8];
	float sd_01,factor;

	Cur_set=Get_system_set();

	ChangePrinterFont();

	if(Cur_set->pH_print==PRN_SZU)
	{
		sd_01=Mean_value*0.025;
		delay_1ms(500);
		
		Tem_adj(150);
		Print_qcmonth(Cur_month,electrode,1);
		Print_sd(sd_01,Mean_value,1);
		fill_with_data(buf,0xff);//填充1
		Draw_bmp(buf,0x03);

		Print_Single_Curve(electrode,Mean_value,800/Mean_value,1);
	}
	else
	{
		sd_01=Mean_value*0.025;
		
		factor=(384-24*2)/(4.0*sd_01);
		delay_1ms(500);
		
		Print_qcmonth(Cur_month,electrode,1);
		Print_sd(sd_01,Mean_value,1);

		fill_with_data(buf,0x01);
		Draw_bmp(buf,0x0);

		Print_Single_Curve(electrode,Mean_value,factor,1);			
	}
}


void Print_InvalidData()
{
	setstr_yw(" ---     ---     ---");
	setnext();
}

void Print_Calibration_Curve(char electrode,float Mean_value)
{
	system_set_t *Cur_set;
	uint8 buf[48*8];
	float sd_01,factor;

	Cur_set=Get_system_set();

	if(Cur_set->pH_print==PRN_SZU)
	{
		sd_01=Mean_value*0.5;
		delay_1ms(500);
		Tem_adj(150);
		Print_qcmonth(2,electrode,2);
		Print_sd(sd_01,Mean_value,2);
		fill_with_data(buf,0xff);//填充1
		Draw_bmp(buf,0x03);

		Print_Single_Curve(electrode, Mean_value,800/Mean_value,2);
	}
	else
	{

		sd_01=Mean_value*0.5;
		
		factor=(384-24*2)/(4.0*sd_01);
		delay_1ms(500);
		
		Print_qcmonth(2,electrode,2);
		Print_sd(sd_01,Mean_value,1);

		fill_with_data(buf,0x01);
		Draw_bmp(buf,0x0);

		Print_Single_Curve(electrode,Mean_value,factor,2);			
	}

}

void Print_CalibrationData()
{
	system_set_t *Cur_syset;
	Value_C_t *Slope;
	Date_Time *Curdate;
	Item_t *me;
	char str[30];
	Value_C_t TData_A,TData_B;
	int i;
	Cur_syset=Get_system_set();
	Curdate=Get_Cur_DateTime();		 //得到当前日期
	me=Get_item_settings();
	Slope=Get_BiaoZhun();
	Read_cur_biaozhun('S');

	ChangePrinterFont();

	if(g_cali_page==2)
	{
		switch(Cur_syset->print_lan)
		{
			//非英文模式
			case 0x01:
#ifdef 		RUSSIA
				for(i=0;i<8;i++)
					Uart0_Sendbyte(' ');
				for(i=0;i<14;i++)
					Uart0_Sendbyte(Rus_Co2CalData[i]);
#else
				if(Cur_syset->pH_print==PRN_ESR)
					setstr_yw("         CO2 定标数据报告");
				else
					setstr_yw("     CO2 Calibration Data");
#endif
				break;
			case 0x00:
				setstr_yw("     CO2 Calibration Data");
				break;
		}
	
		setnext();
		if(me->co2==1)
		{
			setstr_yw("         A1:   ");
			float1_to_char(Co2_CaliData[0],str);
			setstr_yw(str);
			setnext();
			setstr_yw("         A2:   ");
			float1_to_char(Co2_CaliData[1],str);
			setstr_yw(str);
			setnext();
			setstr_yw("          S:   ");
			float1_to_char(Slope->fval[7]+adjust_coin[7],str);
			setstr_yw(str);
			setnext();
		}
		else
			Print_InvalidData();

		setnext();

		Print_Calibration_Curve(7,100);
		return ;
	}

	Read_Cal_Voltage('B',0);
	for(i=0;i<8;i++)
		TData_B.fval[i]=Cur_Cal_Voltage.fval[i];

	delay_1ms(20);

	Read_Cal_Voltage('A',0);
	for(i=0;i<8;i++)
		TData_A.fval[i]=Cur_Cal_Voltage.fval[i];

	switch(Cur_syset->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef 		RUSSIA
			for(i=0;i<3;i++)
				Uart0_Sendbyte(' ');
			for(i=0;i<26;i++)
				Uart0_Sendbyte(Rus_CalReport[i]);
#else
			if(Cur_syset->pH_print==PRN_ESR)
				setstr_yw("         ISE 定标数据报告");
			else
				setstr_yw("    Calibration Data Report");
#endif
			break;
		case 0x00:
			setstr_yw("    Calibration Data Report");
			break;
	}

	setnext();
	setnext();

	switch(Cur_syset->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef 		RUSSIA
			for(i=0;i<4;i++)
				Uart0_Sendbyte(Rus_Date[i]);
			Uart0_Sendbyte(':');
			for(i=0;i<4;i++)
				Uart0_Sendbyte(' ');
#else
			if(Cur_syset->pH_print==PRN_ESR)
				setstr_yw("日期:   ");
			else
				setstr_yw("Date:   ");
#endif
			break;
		case 0x00:
			setstr_yw("Date:   ");
			break;
	}

#ifdef CHINESE
	str[0]=((Curdate->Year>>4)&0x0f)+'0';
	str[1]=(Curdate->Year&0x0f)+'0';

	str[2]='-';
	str[3]=((Curdate->Month>>4)&0x0f)+'0';
	str[4]=(Curdate->Month&0x0f)+'0';

	str[5]='-';
	str[6]=((Curdate->Date>>4)&0x0f)+'0';
	str[7]=(Curdate->Date&0x0f)+'0';
	str[8]='\0';
#else
	str[0]=((Curdate->Date>>4)&0x0f)+'0';
	str[1]=(Curdate->Date&0x0f)+'0';
	str[2]='-';
	str[3]=((Curdate->Month>>4)&0x0f)+'0';
	str[4]=(Curdate->Month&0x0f)+'0';

	str[5]='-';
	str[6]=((Curdate->Year>>4)&0x0f)+'0';
	str[7]=(Curdate->Year&0x0f)+'0';
	str[8]='\0';
#endif

	setstr_yw(str);
	setnext();

	switch(Cur_syset->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef 		RUSSIA
			for(i=0;i<4;i++)
				Uart0_Sendbyte(Rus_Time[i]);
			Uart0_Sendbyte(':');
			for(i=0;i<4;i++)
				Uart0_Sendbyte(' ');
#else
			if(Cur_syset->pH_print==PRN_ESR)
				setstr_yw("时间:   ");
			else
				setstr_yw("Time:   ");
#endif
			break;
		case 0x00:
			setstr_yw("Time:   ");
			break;
	}

	str[0]=((Curdate->Hour>>4)&0x0f)+'0';
	str[1]=(Curdate->Hour&0x0f)+'0';
	str[2]=':';
	str[3]=((Curdate->Minute>>4)&0x0f)+'0';
	str[4]=(Curdate->Minute&0x0f)+'0';
	str[5]=':';
	str[6]=((Curdate->Second>>4)&0x0f)+'0';
	str[7]=(Curdate->Second&0x0f)+'0';
	str[8]='\0';
	setstr_yw(str);
	setnext();

	switch(Cur_syset->print_lan)
	{
		//非英文模式
		case 0x01:
#ifdef 		RUSSIA
			for(i=0;i<31;i++)
				Uart0_Sendbyte(Rus_ElectrodeSlope[i]);
#else
			if(Cur_syset->pH_print==PRN_ESR)
				setstr_yw("  电极   A(mV)   B(mV)    斜率");
			else
				setstr_yw("Electrode A(mV)   B(mV)  Slope");
#endif
			break;
		case 0x00:
			setstr_yw("Electrode A(mV)   B(mV)  Slope");
			break;
	}

	setnext();
	
	if(g_cali_page==1)
	{
		setstr_yw("   K:    ");
		if(me->k==1)
		{

			float1_to_char(TData_A.fval[0],str);
			setstr_yw(str);
			setstr_yw("   ");
			float1_to_char(TData_B.fval[0],str);
			setstr_yw(str);
			setstr_yw("   ");
			if(Slope->fval[0]+adjust_coin[0]>70)
				float1_to_char(70,str);
			else
				float1_to_char(Slope->fval[0]+adjust_coin[0],str);
			setstr_yw(str);
			setnext();
		}
		else
			Print_InvalidData();
		
		setstr_yw("   Na:   ");
		if(me->na==1)
		{
			float1_to_char(TData_A.fval[1],str);
			setstr_yw(str);
			setstr_yw("   ");
			float1_to_char(TData_B.fval[1],str);
			setstr_yw(str);
			setstr_yw("   ");
			if(Slope->fval[1]+adjust_coin[1]>70)
				float1_to_char(70,str);
			else
				float1_to_char(Slope->fval[1]+adjust_coin[1],str);
				
			setstr_yw(str);
			setnext();
		}
		else
			Print_InvalidData();
		
		setstr_yw("   Cl:   ");
		if(me->cl==1)
		{
			float1_to_char(TData_A.fval[2],str);
			setstr_yw(str);
			setstr_yw("   ");
			float1_to_char(TData_B.fval[2],str);
			setstr_yw(str);
			setstr_yw("   ");
			if(Slope->fval[2]+adjust_coin[2]>70)
				float1_to_char(70,str);
			else
				float1_to_char(Slope->fval[2]+adjust_coin[2],str);
			setstr_yw(str);
			setnext();
		}
		else
			Print_InvalidData();
		
		setstr_yw("   Ca:   ");
		if(me->ca==1)
		{
			float1_to_char(TData_A.fval[3],str);
			setstr_yw(str);
			setstr_yw("   ");
			float1_to_char(TData_B.fval[3],str);
			setstr_yw(str);
			setstr_yw("   ");
			if(Slope->fval[3]+adjust_coin[3]>50)
				float1_to_char(50,str);
			else
				float1_to_char(Slope->fval[3]+adjust_coin[3],str);
			setstr_yw(str);
			setnext();
		}
		else
			Print_InvalidData();

		setstr_yw("   pH:   ");
		if(me->ph==1)
		{
			float1_to_char(TData_A.fval[6],str);
			setstr_yw(str);
			setstr_yw("   ");
			float1_to_char(TData_B.fval[6],str);
			setstr_yw(str);
			setstr_yw("   ");
			if(Slope->fval[6]+adjust_coin[6]>70)
				float1_to_char(70,str);
			else
				float1_to_char(Slope->fval[6]+adjust_coin[6],str);
			setstr_yw(str);
			setnext();
		}
		else
			Print_InvalidData();

		setstr_yw("   Li:   ");
		if(me->li==1)
		{
			float1_to_char(TData_A.fval[4],str);
			setstr_yw(str);
			setstr_yw("   ");
			float1_to_char(TData_B.fval[4],str);
			setstr_yw(str);
			setstr_yw("   ");
			if(Slope->fval[4]+adjust_coin[4]>70)
				float1_to_char(70,str);
			else
				float1_to_char(Slope->fval[4]+adjust_coin[4],str);
			setstr_yw(str);
			setnext();
		}
		else
			Print_InvalidData();

		setstr_yw("   Mg:   ");
		if(me->mg==1)
		{
			float1_to_char(TData_A.fval[5],str);
			setstr_yw(str);
			setstr_yw("   ");
			float1_to_char(TData_B.fval[5],str);
			setstr_yw(str);
			setstr_yw("   ");
			if(Slope->fval[5]+adjust_coin[5]>50)
				float1_to_char(50,str);
			else
				float1_to_char(Slope->fval[5]+adjust_coin[5],str);
			setstr_yw(str);
			setnext();
		}
		else
			Print_InvalidData();
	}

	setnext();
	setnext();
	setnext();

}


void Print_Logo()
{
	system_set_t *Cur_syset;
	int len,i;
	Cur_syset=Get_system_set();

	Printer_Set();

	ChangePrinterFont();

	if(Cur_syset->pH_print==PRN_SZU)
	{
		//深大打印机置小字体
		ZoomXY(0x11);
		delay_1ms_precise(500);	
	}
	
	if(Cur_syset->printer_s==1)
	{
		TrimDeviceInformation();
	}

	setnext();
	setnext();
	setnext();
}



void PrintALine(char type)
{
	char str[100],str_item[20];
	Value_C_t *fdata;
	Item_t *me;
	me=Get_item_settings();

	memset(str,0,100);	

	if(!gAutoPrintCaliData)
		return ;
	
	if(type=='A'||type=='B')
	{
		if(type=='A')
		{
			fdata=&A_Voltage;
			strcat(str,"A:");
		}
		else
		{
			fdata=&B_Voltage;
			strcat(str,"B:");
		}
		if(me->k==1)
		{
			float1_to_char(fdata->fval[0],str_item);
			strcat(str,str_item);
			strcat(str," ");
		}
		if(me->na==1)
		{
			float1_to_char(fdata->fval[1],str_item);
			strcat(str,str_item);
			strcat(str," ");
		}
		if(me->cl==1)
		{
			float1_to_char(fdata->fval[2],str_item);
			strcat(str,str_item);
			strcat(str," ");
		}
		if(me->ca==1)
		{
			float1_to_char(fdata->fval[3],str_item);
			strcat(str,str_item);
			strcat(str," ");
		}
		if(me->ph==1)
		{
			float1_to_char(fdata->fval[6],str_item);
			strcat(str,str_item);
			strcat(str," ");
		}
		if(me->li==1)
		{
			float1_to_char(fdata->fval[4],str_item);
			strcat(str,str_item);
			strcat(str," ");
		}
		if(me->mg==1)
		{
			float1_to_char(fdata->fval[5],str_item);
			strcat(str,str_item);
			strcat(str," ");
		}

		setstr_yw(str);
		setnext();

	}

	else if(type=='S')
	{
		strcat(str,"S:");
		if(me->k==1)
		{
			if(Value_S.fval[0]+adjust_coin[0]>70)
				sprintf(str_item," 70.0");
			else
				float1_to_char(Value_S.fval[0]+adjust_coin[0],str_item);
			strcat(str,str_item);			
			strcat(str," ");
		}

		if(me->na==1)
		{
			if(Value_S.fval[1]+adjust_coin[1]>70)
				sprintf(str_item," 70.0");
			else
				float1_to_char(Value_S.fval[1]+adjust_coin[1],str_item);
			strcat(str,str_item);			
			strcat(str," ");
		}
		
		if(me->cl==1)
		{
			if(Value_S.fval[2]+adjust_coin[2]>70)
				sprintf(str_item," 70.0");
			else
				float1_to_char(Value_S.fval[2]+adjust_coin[2],str_item);
			strcat(str,str_item);			
			strcat(str," ");
		}

		if(me->ca==1)
		{
			if(Value_S.fval[3]+adjust_coin[3]>50)
				sprintf(str_item," 50.0");
			else
				float1_to_char(Value_S.fval[3]+adjust_coin[3],str_item);
			strcat(str,str_item);			
			strcat(str," ");
		}

		if(me->ph==1)
		{
			if(Value_S.fval[6]+adjust_coin[6]>70)
				sprintf(str_item," 70.0");
			else
				float1_to_char(Value_S.fval[6]+adjust_coin[6],str_item);
			strcat(str,str_item);			
			strcat(str," ");
		}

		if(me->li==1)
		{
			if(Value_S.fval[4]+adjust_coin[4]>70)
				sprintf(str_item," 70.0");
			else
				float1_to_char(Value_S.fval[4]+adjust_coin[4],str_item);
			strcat(str,str_item);			
			strcat(str," ");
		}

		if(me->mg==1)
		{
			if(Value_S.fval[5]+adjust_coin[5]>50)
				sprintf(str_item," 50.0");
			else
				float1_to_char(Value_S.fval[5]+adjust_coin[5],str_item);
			strcat(str,str_item);			
			strcat(str," ");
		}

		setstr_yw(str);
		setnext();
		
	}
	else if(type=='X')
	{
		strcat(str,"X:");
		if(me->k==1)
		{
			float_to_char(str_item,Value_CCXX.fval[0]);
			strcat(str,str_item);
			strcat(str," ");
		}
		if(me->na==1)
		{
			float_to_char(str_item,Value_CCXX.fval[1]);
			strcat(str,str_item);
			strcat(str," ");
		}
		
		if(me->cl==1)
		{
			float_to_char(str_item,Value_CCXX.fval[2]);
			strcat(str,str_item);
			strcat(str," ");
		}

		if(me->ca==1)
		{
			float_to_char(str_item,Value_CCXX.fval[3]);
			strcat(str,str_item);
			strcat(str," ");
		}

		if(me->ph==1)
		{
			float_to_char(str_item,Value_CCXX.fval[6]);
			strcat(str,str_item);
			strcat(str," ");
		}

		if(me->li==1)
		{
			float_to_char(str_item,Value_CCXX.fval[4]);
			strcat(str,str_item);
			strcat(str," ");
		}

		if(me->mg==1)
		{
			float_to_char(str_item,Value_CCXX.fval[5]);
			strcat(str,str_item);
			strcat(str," ");
		}

		setstr_yw(str);
		setnext();
		
	}
	else if(type=='H')
	{
		sprintf(str,"Item:");			

		if(me->k==1)
		{
			strcat(str," K  ");			
		}	
		if(me->na==1)
		{
			strcat(str,"Na  ");			
		}	
		if(me->cl==1)
		{
			strcat(str,"Cl  ");			
		}	
		if(me->ca==1)
		{
			strcat(str,"Ca  ");			
		}	
		if(me->ph==1)
		{
			strcat(str,"pH  ");			
		}	
		if(me->li==1)
		{
			strcat(str,"Li  ");			
		}	
		if(me->mg==1)
		{
			strcat(str,"Mg  ");			
		}	
		
		setstr_yw(str);
		setnext();
 	}
	else
	{
		setnext();
		setnext();
	}
	delay_1ms_precise(500);

}





