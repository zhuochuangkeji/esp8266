#include "driver/GPIO_Init.h"
#include "stdio.h"
#include "c_types.h"
#include "driver/gpio16.h"
#include "../../include/eagle_soc.h"
#include "gpio.h"

void ICACHE_FLASH_ATTR
RELAY_Init(void)
{
	PIN_FUNC_SELECT(RELAY_MUX_1,RELAY_FUNC_1);
	PIN_FUNC_SELECT(RELAY_MUX_2,RELAY_FUNC_2);
	PIN_FUNC_SELECT(RELAY_MUX_3,RELAY_FUNC_3);
	gpio16_output_conf();
}
void ICACHE_FLASH_ATTR
RELAY_ON(int  RELAY_NUM)
{
	switch(RELAY_NUM)
	{
	case RELAY_ONE:
	GPIO_OUTPUT_SET(GPIO_ID_PIN(RELAY_PIN_1),1);
	break;
	case RELAY_TWO:
	GPIO_OUTPUT_SET(GPIO_ID_PIN(RELAY_PIN_2),1);
	break;
	case RELAY_THREE:
	GPIO_OUTPUT_SET(GPIO_ID_PIN(RELAY_PIN_3),1);
	break;
	case RELAY_FOUR:
	gpio16_output_set(1);
	break;
	}
}
void ICACHE_FLASH_ATTR
RELAY_OFF(int RELAY_NUM)
{
	switch(RELAY_NUM)
	{
	case RELAY_ONE:
	GPIO_OUTPUT_SET(GPIO_ID_PIN(RELAY_PIN_1),0);
	break;
	case RELAY_TWO:
	GPIO_OUTPUT_SET(GPIO_ID_PIN(RELAY_PIN_2),0);
	break;
	case RELAY_THREE:
	GPIO_OUTPUT_SET(GPIO_ID_PIN(RELAY_PIN_3),0);
	break;
	case RELAY_FOUR:
	gpio16_output_set(0);
	break;
	}
}

