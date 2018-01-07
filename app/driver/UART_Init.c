/*
 * UART_Init.c
 *
 *  Created on: 2017年4月21日
 *      Author: Administrator
 */
#include "driver/uart_init.h"
#include "driver/uart.h"
void
Uart_init(void)
{
	uart_reattach();
    uart0_sendStr("chushihoualuanma");

}
