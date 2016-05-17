/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#ifndef TOUCHPANEL_H__
#define TOUCHPANEL_H__

/* Pre-defined definition */
#define TPD_TYPE_CAPACITIVE
#define TPD_TYPE_RESISTIVE
#define TPD_POWER_SOURCE         MT6575_POWER_VGP2
#define TPD_I2C_NUMBER           0
#define TPD_WAKEUP_TRIAL         60
#define TPD_WAKEUP_DELAY         100

#define TPD_DELAY                (2*HZ/100)
// LuckAs try enable
//#define TPD_RES_X                480
//#define TPD_RES_Y                800
// FIXME!!!
// if enable the button buttons not work
//#define GN_MTK_BSP
// LuckAs end
#define TPD_CALIBRATION_MATRIX  {962,0,0,0,1600,0,0,0};

#define TPD_HAVE_CALIBRATION
#define TPD_HAVE_BUTTON
#define TPD_HAVE_TREMBLE_ELIMINATION

#define TPD_NO_GPIO
#define TPD_RESET_PIN_ADDR   (PERICFG_BASE + 0xC000)
#define TPD_DITO_SENSOR
//#define TPD_CONDITION_SWITCH
#define TPD_RESET_ISSUE_WORKAROUND
#define TPD_MAX_RESET_COUNT 3
#define TPD_X_RES (480)
#define TPD_Y_RES (800)
#define TPD_WARP_X(x) ( x )
#define TPD_WARP_Y(y) ( y )

#define TPD_KEY_COUNT   3
#define key_1 	80,850              //auto define  
#define key_2	280,850
#define key_3 	440,850

//#define TPD_KEYS                {KEY_BACK, KEY_HOME, KEY_MENU}
#define TPD_KEYS                {KEY_MENU, KEY_HOMEPAGE, KEY_BACK}
#define TPD_KEYS_DIM    {{80,850,80,60},{280,850,80,60},{440,850,80,60}}

//chiva
#define TPD_MULTI_SUPPORT
#if defined(TPD_MULTI_SUPPORT)
//OFILM/BIEL config file
static u8 cfg_data_version_b_ofilm[] =
{
#ifdef GN_MTK_BSP_TP_SUPPORT_BIEL
//OFILM/BIEL config file
#include "003037_GT818_W6803_biel_Config_20120808_094655.cfg"
#else
#include "003073_GT818x_ofilm_Gionee_W6803_0x48_no_stretch_Config_20120808_094655.cfg"
#endif
};
static u8 *cfg_data_with_charger_version_b_ofilm = cfg_data_version_b_ofilm;
static u8 *cfg_data_version_d_ofilm = cfg_data_version_b_ofilm;
static u8 *cfg_data_with_charger_version_d_ofilm = cfg_data_version_b_ofilm;
//TRULY config file
static u8 cfg_data_version_b_truly[] =
{
#include "003037_GT818_W6803_truly_Config_9_04_2012131755.cfg"
};
static u8 *cfg_data_with_charger_version_b_truly = cfg_data_version_b_truly;
static u8 *cfg_data_version_d_truly = cfg_data_version_b_truly;
static u8 *cfg_data_with_charger_version_d_truly = cfg_data_version_b_truly;
//WINTEK config file
static u8 cfg_data_version_b_wintek[] =
{
#include "003037_GT818_W6803_wintek_Config_20120808_094655.cfg"
};
static u8 *cfg_data_with_charger_version_b_wintek = cfg_data_version_b_wintek;
static u8 *cfg_data_version_d_wintek = cfg_data_version_b_wintek;
static u8 *cfg_data_with_charger_version_d_wintek = cfg_data_version_b_wintek;

//Defult config file: wintek
u8* cfg_data_version_b		 			= cfg_data_version_b_wintek;
u8 *cfg_data_with_charger_version_b 	= cfg_data_version_b_wintek;
u8 *cfg_data_version_d 					= cfg_data_version_b_wintek;
u8 *cfg_data_with_charger_version_d 	= cfg_data_version_b_wintek;
//\\

#elif defined(TPD_DITO_SENSOR)
static u8 cfg_data_version_d[] =
{
0x0A,0x0C,0x0E,0x10,0x12,0x00,0x02,0x04,
0x06,0x08,0x31,0x11,0x21,0x11,0x11,0x11,
0x01,0x11,0x71,0x11,0x61,0x11,0x51,0x11,
0x41,0x11,0x81,0x11,0x91,0x11,0xA1,0x11,
0xB1,0x11,0xF1,0x11,0xE1,0x11,0xD1,0x11,
0xC1,0x11,0x07,0x03,0x70,0x70,0x70,0x28,
0x28,0x28,0x10,0x0F,0x0A,0x40,0x30,0x07,
0x03,0x00,0x05,0xE0,0x01,0x20,0x03,0x00,
0x00,0x50,0x48,0x54,0x4B,0x00,0x00,0x23,
0x14,0x02,0x05,0x80,0x00,0x00,0x00,0x00,
0x14,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x20,0x5F,0x90,0x00,0x0D,0x40,
0x30,0x25,0x20,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

static u8 cfg_data_with_charger_version_d[] =
{
0x0A,0x0C,0x0E,0x10,0x12,0x00,0x02,0x04,
0x06,0x08,0x31,0x11,0x21,0x11,0x11,0x11,
0x01,0x11,0x71,0x11,0x61,0x11,0x51,0x11,
0x41,0x11,0x81,0x11,0x91,0x11,0xA1,0x11,
0xB1,0x11,0xF1,0x11,0xE1,0x11,0xD1,0x11,
0xC1,0x11,0x07,0x03,0x70,0x70,0x70,0x28,
0x28,0x28,0x10,0x0F,0x0A,0x40,0x30,0x07,
0x03,0x00,0x05,0xE0,0x01,0x20,0x03,0x00,
0x00,0x50,0x48,0x54,0x4B,0x00,0x00,0x23,
0x14,0x02,0x05,0x80,0x00,0x00,0x00,0x00,
0x14,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x20,0x5F,0x90,0x00,0x0D,0x40,
0x30,0x25,0x20,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

//GT818_6573_DITO_config.gtx
static u8 cfg_data_version_b[] =
{
0x0A,0x0C,0x0E,0x10,0x12,0x00,0x02,0x04,
0x06,0x08,0x31,0x11,0x21,0x11,0x11,0x11,
0x01,0x11,0x71,0x11,0x61,0x11,0x51,0x11,
0x41,0x11,0x81,0x11,0x91,0x11,0xA1,0x11,
0xB1,0x11,0xF1,0x11,0xE1,0x11,0xD1,0x11,
0xC1,0x11,0x07,0x03,0x70,0x70,0x70,0x28,
0x28,0x28,0x10,0x0F,0x0A,0x40,0x30,0x07,
0x03,0x00,0x05,0xE0,0x01,0x20,0x03,0x00,
0x00,0x50,0x48,0x54,0x4B,0x00,0x00,0x23,
0x14,0x02,0x05,0x80,0x00,0x00,0x00,0x00,
0x14,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x20,0x5F,0x90,0x00,0x0D,0x40,
0x30,0x25,0x20,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

// GT818_6573_DITO_charger_577K.gtx
static u8 cfg_data_with_charger_version_b[] =
{
0x0A,0x0C,0x0E,0x10,0x12,0x00,0x02,0x04,
0x06,0x08,0x31,0x11,0x21,0x11,0x11,0x11,
0x01,0x11,0x71,0x11,0x61,0x11,0x51,0x11,
0x41,0x11,0x81,0x11,0x91,0x11,0xA1,0x11,
0xB1,0x11,0xF1,0x11,0xE1,0x11,0xD1,0x11,
0xC1,0x11,0x07,0x03,0x70,0x70,0x70,0x28,
0x28,0x28,0x10,0x0F,0x0A,0x40,0x30,0x07,
0x03,0x00,0x05,0xE0,0x01,0x20,0x03,0x00,
0x00,0x50,0x48,0x54,0x4B,0x00,0x00,0x23,
0x14,0x02,0x05,0x80,0x00,0x00,0x00,0x00,
0x14,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x20,0x5F,0x90,0x00,0x0D,0x40,
0x30,0x25,0x20,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

#else //SITO
// 6573_SITO_config.gtx
static u8 cfg_data_version_b[] =
{
0x0A,0x0C,0x0E,0x10,0x12,0x00,0x02,0x04,
0x06,0x08,0x31,0x11,0x21,0x11,0x11,0x11,
0x01,0x11,0x71,0x11,0x61,0x11,0x51,0x11,
0x41,0x11,0x81,0x11,0x91,0x11,0xA1,0x11,
0xB1,0x11,0xF1,0x11,0xE1,0x11,0xD1,0x11,
0xC1,0x11,0x07,0x03,0x70,0x70,0x70,0x28,
0x28,0x28,0x10,0x0F,0x0A,0x40,0x30,0x07,
0x03,0x00,0x05,0xE0,0x01,0x20,0x03,0x00,
0x00,0x50,0x48,0x54,0x4B,0x00,0x00,0x23,
0x14,0x02,0x05,0x80,0x00,0x00,0x00,0x00,
0x14,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x20,0x5F,0x90,0x00,0x0D,0x40,
0x30,0x25,0x20,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

//6573_SITO_charger.gtx
static u8 cfg_data_with_charger_version_b[] =
{
0x0A,0x0C,0x0E,0x10,0x12,0x00,0x02,0x04,
0x06,0x08,0x31,0x11,0x21,0x11,0x11,0x11,
0x01,0x11,0x71,0x11,0x61,0x11,0x51,0x11,
0x41,0x11,0x81,0x11,0x91,0x11,0xA1,0x11,
0xB1,0x11,0xF1,0x11,0xE1,0x11,0xD1,0x11,
0xC1,0x11,0x07,0x03,0x70,0x70,0x70,0x28,
0x28,0x28,0x10,0x0F,0x0A,0x40,0x30,0x07,
0x03,0x00,0x05,0xE0,0x01,0x20,0x03,0x00,
0x00,0x50,0x48,0x54,0x4B,0x00,0x00,0x23,
0x14,0x02,0x05,0x80,0x00,0x00,0x00,0x00,
0x14,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x20,0x5F,0x90,0x00,0x0D,0x40,
0x30,0x25,0x20,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};
#endif
#endif /* TOUCHPANEL_H__ */


