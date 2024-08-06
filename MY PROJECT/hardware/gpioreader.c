#include "ti_msp_dl_config.h"

uint8_t readscare (void)
{
    if (DL_GPIO_readPins(GPIO_scare_PORT,GPIO_scare_L3_PIN))
    return 1;
    else if (DL_GPIO_readPins(GPIO_scare_PORT,GPIO_scare_L2_PIN))
    return 2;
    else if (DL_GPIO_readPins(GPIO_scare_PORT,GPIO_scare_L1_PIN))
    return 3;
    else if (DL_GPIO_readPins(GPIO_scare_PORT,GPIO_scare_M_PIN))
    return 4;
    else if (DL_GPIO_readPins(GPIO_scare_PORT,GPIO_scare_R1_PIN))
    return 5;
    else if (DL_GPIO_readPins(GPIO_scare_PORT,GPIO_scare_R2_PIN))
    return 6;
    else if (DL_GPIO_readPins(GPIO_scare_PORT,GPIO_scare_R3_PIN))
    return 7;
    else return 0;
}


