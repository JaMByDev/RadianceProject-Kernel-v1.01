#include <cust_leds.h>
#include <cust_leds_def.h>
#include <mach/mt_pwm.h>

#include <linux/kernel.h>
#include <mach/pmic_mt6329_hw_bank1.h> 
#include <mach/pmic_mt6329_sw_bank1.h> 
#include <mach/pmic_mt6329_hw.h>
#include <mach/pmic_mt6329_sw.h>
#include <mach/upmu_common_sw.h>
#include <mach/upmu_hw.h>

#include <mach/mt_gpio.h>
#include "cust_gpio_usage.h"
#include <asm/delay.h>

#include <linux/semaphore.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/version.h>
#include <linux/delay.h>
extern int mtkfb_set_backlight_level(unsigned int level);
extern int mtkfb_set_backlight_pwm(int div);

#define ERROR_BL_LEVEL 0xFFFFFFFF
//#if 1

unsigned int brightness_mapping(unsigned int level)
{

	//hupeng 0105, map level to 64 levels
	if(level>=14 && level<=255) { // user changable by using Setting->Display->Brightness
	//	#if defined(HQ_PROJECT_A61P_HUAWEI)
	//	return (level+1)/4;		/* lcd-backlight setting for A61 */
	//	#else
		//return (level-12)/4; //-22
		return level/4;
	}
	else if(level>=14 && level<30) { // used to fade out for 7 seconds before shut down backlight

		return (level-15)/2;//1;
	}
	else if(level>0 && level<20) { // used to fade out for 7 seconds before shut down backlight

		return 1;
	}
	else
	{
		return 0;
	}

	return ERROR_BL_LEVEL;
}

//static unsigned int back_level = 0;

int chr_det_led_control(int level,int div){
	if(level)
		upmu_chr_chrind_on(0x01);
	else
		upmu_chr_chrind_on(0);
}

static struct cust_mt65xx_led cust_led_list[MT65XX_LED_TYPE_TOTAL] = {
	{"red",               MT65XX_LED_MODE_NONE, -1,{0}},
	{"green",             MT65XX_LED_MODE_NONE, -1,{0}},
	{"blue",              MT65XX_LED_MODE_NONE, -1,{0}},
	{"jogball-backlight", MT65XX_LED_MODE_NONE, -1,{0}},
	{"keyboard-backlight",MT65XX_LED_MODE_NONE, -1,{0}},
	{"button-backlight",  MT65XX_LED_MODE_PMIC, MT65XX_LED_PMIC_BUTTON,{0}},
	{"lcd-backlight",     MT65XX_LED_MODE_PWM, PWM1,{0}},
};


struct cust_mt65xx_led *get_cust_led_list(void)
{
   return cust_led_list;
}
