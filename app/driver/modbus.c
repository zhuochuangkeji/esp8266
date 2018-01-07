/*
 * modbus.c
 *
 *  Created on: 2017年7月12日
 *      Author: Administrator
 */
#include "driver/modbus.h"
//#include "include/spi_flash.h"

void COIL_STATUS(unsigned int HEAD,unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER)
{
	unsigned char SEND[8];
	unsigned char Rcvbuf[2];
	unsigned int  CRC;
	SEND[0]=HEAD;
	SEND[1]=READ_COIL_STATUS;
	SEND[2]=(*MODBUS_ADD)/255;
	SEND[3]=*MODBUS_ADD%255;
	SEND[4]=*MODBUS_NUMBER/255;
	SEND[5]=*MODBUS_NUMBER%255;
	CRC=crc_16(SEND,Rcvbuf,6);
	SEND[6]=CRC/255;
	SEND[7]=CRC%255;

	uart0_sendStr(&SEND);
}
unsigned short crc_16(unsigned char  *Array, unsigned char *Rcvbuf,unsigned char Len)
{
        unsigned int  IX,IY,CRC;
        CRC=0xFFFF;//set all 1

        if (Len<=0)
                CRC = 0;
        else
        {
                Len--;
                for (IX=0;IX<=Len;IX++)
                {
                        CRC=CRC^(unsigned int)(Array[IX]);
                        for(IY=0;IY<=7;IY++)
                        {
                                if ((CRC&1)!=0 )
                                        CRC=(CRC>>1)^0xA001;
                                else
                                        CRC=CRC>>1;    //
                        }
                }

        }
        Rcvbuf[0] = (CRC & 0xff00)>>8;//高位置
        Rcvbuf[1] = (CRC & 0x00ff);  //低位置

        CRC= Rcvbuf[0]<<8;
        CRC+= Rcvbuf[1];
        return CRC;
}

//uint32 DEC2HEX(uint32 DATA)
//{
//	int a[10];
//	int i=0;
//	int m=0;
//	int yushu;
//	int RESULT[];
//	char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
//	while(DATA>0)
//	{
//	yushu=DATA%16;
//	a[i++]=yushu;
//	DATA=DATA/16;
//
//	}
//	//printf("转化为十六进制的数为：0x");
//	for(i=i-1;i>=0;i--)//倒序输出
//	{
//	m=a[i];
//	printf("%c",hex[m]);
//	=hex[m]
//	}
//
//}



