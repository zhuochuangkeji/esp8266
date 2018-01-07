/*
 * modbus.h

 *
 *  Created on: 2017年7月12日
 *      Author: Administrator
 */
#ifndef _MODBUS_
#define _MODBUS_

static unsigned int MODBUS_HEAD =1	;			//定义modbus 初始化地址
#define Frequency_converter  2      //变频器地址

#define Y0_ADDRESS    3000			//定义Y0 的地址是
#define X0_ADD_RESS	  2000

static unsigned int OPEN =0xFF00;
static unsigned int CLOSE =0x0000;

//uint32 MODBUS_ADD=MODBUS_HEAD;
//
//typedef struct
//{															//所有的MODBUS输出格式
//	    uint8_t                 head;                     ///<modbus 地址 默认为一
//	    uint8_t                function;                 ///<modbus 命令
//	    uint8_t                 CRC[2];
//}MODBUS_fixed;
//typedef struct
//{				//PLC 1.3.5.6支持//15.16暂不支持
//	uint8       ADDRESS[2];
//	uint8       NUMBER_FLAG[2];
//};
typedef enum
{
	Y0=Y0_ADDRESS,
	Y1,Y2,Y3,Y4,Y5,Y6,Y7,
	Y10,Y11,Y12,Y13,Y14,Y15,Y16,Y17,
	Y20,Y21,Y22,Y23,Y24,Y25,Y26,Y27,
}Y;
typedef enum
{
	X0=X0_ADD_RESS,
	X1,X2,X3,X4,X5,X6,X7,
	X10,X11,X12,X13,X14,X15,X16,X17,
	X20,X21,X22,X23,X24,X25,X26,X27,
}x;

typedef enum
{
        READ_COIL_STATUS=1,        	//01      功能码:0x01      读取线圈状态
	    READ_INPUT_STATUS,   		//02      功能码:0x02  	 读输入位状态
	    READ_HOLDING_REGISTERS,    	//03      功能码:0x03       读保持寄存器
        READ_INPUT_REGISTERS,   	//04      功能码:0x04        读输入寄存器
        FORCE_SINGLE_COIL,      	//05      功能码:0x05         强制单个线圈
        PRESET_SINGLE_REGISTER,		//06      功能码:0x06        预置单个寄存器
        FORCE_MULTIPLE_COILS,      	//07      功能码:0x0F   设置多个线圈
        FORCE_MULTIPLE_REGISTERS,  	//08      功能码:0x10        设置多个保持寄存器
        READ_FILE_RECORD,    		//09      功能码:0x14/0X06          读取文件记录
		WRITE_FILE_RECORD,    		//10      功能码:0x15/0X06        写文件记录
		READ_FIFO_QUEUE,     		//11      功能码:0x18            读取FIFO队列
}MODBUS_CMD;



unsigned short  crc_16(unsigned char  *Array, unsigned char *Rcvbuf,unsigned char  Len);//CRC效验
void COIL_STATUS(unsigned int HEAD,unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER);//读取线圈状态
void INPUT_STATUS(unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER);//读取输入状态
void HOLDING_REGISTERS(unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER);//读取保存器状态
void INPUT_REGISTERS(unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER);//读输入寄存器
void SINGLE_COIL(unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER);//强制单个线圈开关
void SINGLE_REGISTER(unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER);//预置单个寄存器
void MULTIPLE_COILS(unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER);//设置多个线圈
void MULTIPLE_REGISTERS(unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER);//设置多个寄存器
void READ_FILE(unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER);//读文件记录
void WRITE_FILE(unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER);//写文件记录
void FIFO_QUEUE(unsigned int *MODBUS_ADD,unsigned int *MODBUS_NUMBER);//读取fifo队列

//uint32 DEC2HEX(uint32 DATA);

#endif


