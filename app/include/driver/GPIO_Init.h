#ifndef __GPIO_INIT__
#define __GPIO_INIT__
#include "c_types.h"
#include "driver/gpio16.h"
#include "../../include/eagle_soc.h"

#define RELAY_PIN_1        12
#define RELAY_FUNC_1 FUNC_GPIO12
#define RELAY_MUX_1  PERIPHS_IO_MUX_MTDI_U

#define RELAY_PIN_2        13
#define RELAY_FUNC_2 FUNC_GPIO13
#define RELAY_MUX_2  PERIPHS_IO_MUX_MTCK_U

#define RELAY_PIN_3        14
#define RELAY_FUNC_3 FUNC_GPIO14
#define RELAY_MUX_3  PERIPHS_IO_MUX_MTMS_U

#define RELAY_ONE    0x01
#define RELAY_TWO    0x02
#define RELAY_THREE  0x04
#define RELAY_FOUR   0x08

void ICACHE_FLASH_ATTR RELAY_Init(void);
void ICACHE_FLASH_ATTR RELAY_ON(int  RELAY_NUM);
void ICACHE_FLASH_ATTR RELAY_OFF(int RELAY_NUM);



#endif
