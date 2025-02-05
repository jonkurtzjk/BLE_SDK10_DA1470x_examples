/**
 ****************************************************************************************
 *
 * @file platform_devices.c
 *
 * @brief Configuration of devices connected to board
 *
 * Copyright (C) 2021-2022 Dialog Semiconductor.
 * This computer program includes Confidential, Proprietary Information
 * of Dialog Semiconductor. All Rights Reserved.
 *
 ****************************************************************************************
 */
#include "ad_i2c.h"
#include "ad_spi.h"
#include "ad_lcdc.h"
#include "peripheral_setup.h"
#include "platform_devices.h"

/*
 * PLATFORM PERIPHERALS GPIO CONFIGURATION
 *****************************************************************************************
 */

#if dg_configLCDC_ADAPTER

#if (DEVICE_FAMILY == DA1470X)
#define HW_GPIO_FUNC_LCD_SPI_DC         HW_GPIO_FUNC_LCD
#define HW_GPIO_FUNC_LCD_SPI_DO         HW_GPIO_FUNC_LCD
#define HW_GPIO_FUNC_LCD_SPI_CLK        HW_GPIO_FUNC_LCD
#define HW_GPIO_FUNC_LCD_SPI_EN         HW_GPIO_FUNC_LCD
#endif

#if dg_configUSE_H13TB18A
static const ad_io_conf_t h13tb18a_gpio_cfg[] = {
        { H13TB18A_SPI_CLK_PORT, H13TB18A_SPI_CLK_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { H13TB18A_SPI_SDA_PORT, H13TB18A_SPI_SDA_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { H13TB18A_SPI_CS_PORT,  H13TB18A_SPI_CS_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { H13TB18A_DCX_PORT,     H13TB18A_DCX_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { H13TB18A_TE_PORT,      H13TB18A_TE_PIN,      { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,         true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
        { H13TB18A_RST_PORT,     H13TB18A_RST_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t h13tb18a_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(h13tb18a_gpio_cfg) / sizeof(h13tb18a_gpio_cfg[0]),
        .io_list = h13tb18a_gpio_cfg,
};
#endif /* dg_configUSE_H13TB18A */

#if dg_configUSE_TFT12864_57_E
static const ad_io_conf_t tft12864_57_e_gpio_cfg[] = {
        { TFT12864_57_E_SCL_PORT,      TFT12864_57_E_SCL_PIN,      { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { TFT12864_57_E_MOSI_PORT,     TFT12864_57_E_MOSI_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { TFT12864_57_E_CSB_PORT,      TFT12864_57_E_CSB_PIN,      { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { TFT12864_57_E_DCX_PORT,      TFT12864_57_E_DCX_PIN,      { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { TFT12864_57_E_RESB_PORT,     TFT12864_57_E_RESB_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { TFT12864_57_E_SPI4_SEL_PORT, TFT12864_57_E_SPI4_SEL_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t tft12864_57_e_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(tft12864_57_e_gpio_cfg) / sizeof(tft12864_57_e_gpio_cfg[0]),
        .io_list = tft12864_57_e_gpio_cfg,
};
#endif /* dg_configUSE_TFT12864_57_E */

#if dg_configUSE_LPM010M297B
static const ad_io_conf_t lpm010m297b_gpio_cfg[] = {
        { LPM010M297B_SCLK_PORT,     LPM010M297B_SCLK_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { LPM010M297B_SI_PORT,       LPM010M297B_SI_PIN,       { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { LPM010M297B_SCS_PORT,      LPM010M297B_SCS_PIN,      { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { LPM010M297B_EXTCOMIN_PORT, LPM010M297B_EXTCOMIN_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,         true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { LPM010M297B_DISP_PORT,     LPM010M297B_DISP_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t lpm010m297b_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(lpm010m297b_gpio_cfg) / sizeof(lpm010m297b_gpio_cfg[0]),
        .io_list = lpm010m297b_gpio_cfg,
};
#endif /* dg_configUSE_LPM010M297B */

#if dg_configUSE_HM80160A090
static const ad_io_conf_t hm80160a090_gpio_cfg[] = {
        { HM80160A090_SCK_PORT, HM80160A090_SCK_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { HM80160A090_SDA_PORT, HM80160A090_SDA_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { HM80160A090_RST_PORT, HM80160A090_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { HM80160A090_DC_PORT,  HM80160A090_DC_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { HM80160A090_CS_PORT,  HM80160A090_CS_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t hm80160a090_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(hm80160a090_gpio_cfg) / sizeof(hm80160a090_gpio_cfg[0]),
        .io_list = hm80160a090_gpio_cfg,
};
#endif /* dg_configUSE_HM80160A090 */

#if dg_configUSE_ILI9341
static const ad_io_conf_t ili9341_gpio_cfg[] = {
        { ILI9341_SCK_PORT, ILI9341_SCK_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { ILI9341_DO_PORT,  ILI9341_DO_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { ILI9341_RST_PORT, ILI9341_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { ILI9341_DC_PORT,  ILI9341_DC_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { ILI9341_CS_PORT,  ILI9341_CS_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t ili9341_io = {
        .voltage_level = HW_GPIO_POWER_V33,
        .io_cnt = sizeof(ili9341_gpio_cfg) / sizeof(ili9341_gpio_cfg[0]),
        .io_list = ili9341_gpio_cfg,
};
#endif /* dg_configUSE_ILI9341 */

#if dg_configUSE_E1394AA65A
static const ad_io_conf_t e1394aa65a_gpio_cfg[] = {
        { E1394AA65A_SCK_PORT, E1394AA65A_SCK_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { E1394AA65A_DO_PORT,  E1394AA65A_DO_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { E1394AA65A_DC_PORT,  E1394AA65A_DC_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { E1394AA65A_CS_PORT,  E1394AA65A_CS_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { E1394AA65A_RST_PORT, E1394AA65A_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { E1394AA65A_TE_PORT,  E1394AA65A_TE_PIN,  { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,         true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
/*CS*/  { HW_GPIO_PORT_0,      HW_GPIO_PIN_16,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t e1394aa65a_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(e1394aa65a_gpio_cfg) / sizeof(e1394aa65a_gpio_cfg[0]),
        .io_list = e1394aa65a_gpio_cfg,
};
#endif /* dg_configUSE_E1394AA65A */

#if dg_configUSE_E1394AA65A_DSPI
static const ad_io_conf_t e1394aa65a_dspi_gpio_cfg[] = {
        { E1394AA65A_SCK_PORT, E1394AA65A_SCK_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { E1394AA65A_DO_PORT,  E1394AA65A_DO_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { E1394AA65A_DC_PORT,  E1394AA65A_DC_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { E1394AA65A_CS_PORT,  E1394AA65A_CS_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { E1394AA65A_RST_PORT, E1394AA65A_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { E1394AA65A_TE_PORT,  E1394AA65A_TE_PIN,  { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,         true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
/*CS*/  { HW_GPIO_PORT_0,      HW_GPIO_PIN_16,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t e1394aa65a_dspi_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(e1394aa65a_dspi_gpio_cfg) / sizeof(e1394aa65a_dspi_gpio_cfg[0]),
        .io_list = e1394aa65a_dspi_gpio_cfg,
};
#endif /* dg_configUSE_E1394AA65A_DSPI */

#if dg_configUSE_LPM012M134B
static const ad_io_conf_t lpm012m134b_gpio_cfg[] = {
        { LPM012M134B_GREEN_0_PORT, LPM012M134B_GREEN_0_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_GREEN_1_PORT, LPM012M134B_GREEN_1_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_RED_0_PORT,   LPM012M134B_RED_0_PIN,   { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_RED_1_PORT,   LPM012M134B_RED_1_PIN,   { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_BLUE_0_PORT,  LPM012M134B_BLUE_0_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_BLUE_1_PORT,  LPM012M134B_BLUE_1_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_XRST_PORT,    LPM012M134B_XRST_PIN,    { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_HST_PORT,     LPM012M134B_HST_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_HCK_PORT,     LPM012M134B_HCK_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_VST_PORT,     LPM012M134B_VST_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_VCK_PORT,     LPM012M134B_VCK_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_ENB_PORT,     LPM012M134B_ENB_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_FRP_PORT,     LPM012M134B_FRP_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_XFRP_PORT,    LPM012M134B_XFRP_PIN,    { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { LPM012M134B_PEN_PORT,     LPM012M134B_PEN_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
};

const ad_lcdc_io_conf_t lpm012m134b_io = {
        .voltage_level = HW_GPIO_POWER_V33,
        .io_cnt = sizeof(lpm012m134b_gpio_cfg) / sizeof(lpm012m134b_gpio_cfg[0]),
        .io_list = lpm012m134b_gpio_cfg,
};
#endif /* dg_configUSE_LPM012M134B */

#if dg_configUSE_NHD43480272EFASXN
static const ad_io_conf_t nhd43480272efasxn_gpio_cfg[] = {
        { NHD43480272EFASXN_GREEN_0_PORT, NHD43480272EFASXN_GREEN_0_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { NHD43480272EFASXN_GREEN_1_PORT, NHD43480272EFASXN_GREEN_1_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { NHD43480272EFASXN_RED_0_PORT,   NHD43480272EFASXN_RED_0_PIN,   { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { NHD43480272EFASXN_RED_1_PORT,   NHD43480272EFASXN_RED_1_PIN,   { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { NHD43480272EFASXN_BLUE_0_PORT,  NHD43480272EFASXN_BLUE_0_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { NHD43480272EFASXN_BLUE_1_PORT,  NHD43480272EFASXN_BLUE_1_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { NHD43480272EFASXN_VSYNC_PORT,   NHD43480272EFASXN_VSYNC_PIN,   { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  } },
        { NHD43480272EFASXN_HSYNC_PORT,   NHD43480272EFASXN_HSYNC_PIN,   { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  } },
        { NHD43480272EFASXN_DEN_PORT,     NHD43480272EFASXN_DEN_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { NHD43480272EFASXN_CLK_PORT,     NHD43480272EFASXN_CLK_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { NHD43480272EFASXN_DISP_PORT,    NHD43480272EFASXN_DISP_PIN,    { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { NHD43480272EFASXN_READY_PORT,   NHD43480272EFASXN_READY_PIN,   { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, false } },
        { NHD43480272EFASXN_CM_PORT,      NHD43480272EFASXN_CM_PIN,      { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
        { NHD43480272EFASXN_SD_PORT,      NHD43480272EFASXN_SD_PIN,      { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,  false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false } },
};

const ad_lcdc_io_conf_t nhd43480272efasxn_io = {
        .voltage_level = HW_GPIO_POWER_V33,
        .io_cnt = sizeof(nhd43480272efasxn_gpio_cfg) / sizeof(nhd43480272efasxn_gpio_cfg[0]),
        .io_list = nhd43480272efasxn_gpio_cfg,
};

#if dg_configUSE_FT5306
/* I2C I/O pins configurations */
const ad_i2c_io_conf_t ft5306_io = {
        .scl = {
              .port = FT5306_SCL_PORT, .pin = FT5306_SCL_PIN,
              .on  = { HW_GPIO_MODE_OUTPUT_OPEN_DRAIN, HW_GPIO_FUNC_I2C_SCL, false },
              .off = { HW_GPIO_MODE_INPUT,             HW_GPIO_FUNC_GPIO,    true  },
        },
        .sda = {
             .port = FT5306_SDA_PORT, .pin = FT5306_SDA_PIN,
             .on   = { HW_GPIO_MODE_OUTPUT_OPEN_DRAIN, HW_GPIO_FUNC_I2C_SDA, false },
             .off  = { HW_GPIO_MODE_INPUT,             HW_GPIO_FUNC_GPIO,    true  },
        },
        .voltage_level = HW_GPIO_POWER_V33
};
#endif /* dg_configUSE_FT5306 */
#endif /* dg_configUSE_NHD43480272EFASXN */

#if dg_configUSE_LS013B7DH06
static const ad_io_conf_t ls013b7dh06_gpio_cfg[] = {
        { LS013B7DH06_SCK_PORT,      LS013B7DH06_SCK_PIN,      { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { LS013B7DH06_SDA_PORT,      LS013B7DH06_SDA_PIN,      { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { LS013B7DH06_CS_PORT,       LS013B7DH06_CS_PIN,       { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { LS013B7DH06_EXTCOMIN_PORT, LS013B7DH06_EXTCOMIN_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, false        }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false }},
        { LS013B7DH06_DISP_PORT,     LS013B7DH06_DISP_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false       }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false }},
};

const ad_lcdc_io_conf_t ls013b7dh06_io = {
        .voltage_level = HW_GPIO_POWER_V33,
        .io_cnt = sizeof(ls013b7dh06_gpio_cfg) / sizeof(ls013b7dh06_gpio_cfg[0]),
        .io_list = ls013b7dh06_gpio_cfg,
};
#endif /* dg_configUSE_LS013B7DH06 */

#if dg_configUSE_LS013B7DH03
static const ad_io_conf_t ls013b7dh03_gpio_cfg[] = {
        { LS013B7DH03_SCK_PORT,      LS013B7DH03_SCK_PIN,      { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { LS013B7DH03_SDA_PORT,      LS013B7DH03_SDA_PIN,      { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { LS013B7DH03_CS_PORT,       LS013B7DH03_CS_PIN,       { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { LS013B7DH03_EXTCOMIN_PORT, LS013B7DH03_EXTCOMIN_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,         false}, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false }},
        { LS013B7DH03_DISP_PORT,     LS013B7DH03_DISP_PIN,     { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        false}, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false }},
};

const ad_lcdc_io_conf_t ls013b7dh03_io = {
        .voltage_level = HW_GPIO_POWER_V33,
        .io_cnt = sizeof(ls013b7dh03_gpio_cfg) / sizeof(ls013b7dh03_gpio_cfg[0]),
        .io_list = ls013b7dh03_gpio_cfg,
};
#endif /* dg_configUSE_LS013B7DH03 */

#if dg_configUSE_DT280QV10CT
static const ad_io_conf_t dt280qv10ct_gpio_cfg[] = {
        { DT280QV10CT_SCK_PORT, DT280QV10CT_SCK_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { DT280QV10CT_SDA_PORT, DT280QV10CT_SDA_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
#if (DEVICE_FAMILY == DA1470X)
        { DT280QV10CT_SI_PORT,  DT280QV10CT_SI_PIN,  { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,         true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
#endif
        { DT280QV10CT_RST_PORT, DT280QV10CT_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { DT280QV10CT_DC_PORT,  DT280QV10CT_DC_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { DT280QV10CT_CS_PORT,  DT280QV10CT_CS_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { DT280QV10CT_TE_PORT,  DT280QV10CT_TE_PIN,  { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,         true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
        { DT280QV10CT_BL_PORT,  DT280QV10CT_BL_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        false}, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false}},
};

const ad_lcdc_io_conf_t dt280qv10ct_io = {
        .voltage_level = HW_GPIO_POWER_V33,
        .io_cnt = sizeof(dt280qv10ct_gpio_cfg) / sizeof(dt280qv10ct_gpio_cfg[0]),
        .io_list = dt280qv10ct_gpio_cfg,
};

#endif /* dg_configUSE_DT280QV10CT */

#if dg_configUSE_T1D3BP006 || dg_configUSE_T1D3BP006_DSPI
static const ad_io_conf_t t1d3bp006_gpio_cfg[] = {
        { T1D3BP006_SCK_PORT, T1D3BP006_SCK_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { T1D3BP006_SDA_PORT, T1D3BP006_SDA_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { T1D3BP006_RST_PORT, T1D3BP006_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { T1D3BP006_DC_PORT,  T1D3BP006_DC_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { T1D3BP006_CS_PORT,  T1D3BP006_CS_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { T1D3BP006_TE_PORT,  T1D3BP006_TE_PIN,  { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,         true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
/*DC*/  { HW_GPIO_PORT_0,     HW_GPIO_PIN_16,    { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t t1d3bp006_io = {
        .voltage_level = HW_GPIO_POWER_V33,
        .io_cnt = sizeof(t1d3bp006_gpio_cfg) / sizeof(t1d3bp006_gpio_cfg[0]),
        .io_list = t1d3bp006_gpio_cfg,
};
#endif /* dg_configUSE_T1D3BP006 */

#if dg_configUSE_T1D54BP002
static const ad_io_conf_t t1d54bp002_gpio_cfg[] = {
        { T1D54BP002_SCK_PORT, T1D54BP002_SCK_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { T1D54BP002_SDA_PORT, T1D54BP002_SDA_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { T1D54BP002_RST_PORT, T1D54BP002_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { T1D54BP002_CS_PORT,  T1D54BP002_CS_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t t1d54bp002_io = {
        .voltage_level = HW_GPIO_POWER_V33,
        .io_cnt = sizeof(t1d54bp002_gpio_cfg) / sizeof(t1d54bp002_gpio_cfg[0]),
        .io_list = t1d54bp002_gpio_cfg,
};
#endif /* dg_configUSE_T1D54BP002 */

#if dg_configUSE_PSP27801
static const ad_io_conf_t psp27801_gpio_cfg[] = {
        {PSP27801_SDI_PORT, PSP27801_SDI_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        {PSP27801_SCK_PORT, PSP27801_SCK_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        {PSP27801_CS_PORT,  PSP27801_CS_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        {PSP27801_DC_PORT,  PSP27801_DC_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        {PSP27801_EN_PORT,  PSP27801_EN_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        false}, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false}},
        {PSP27801_RST_PORT, PSP27801_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        {PSP27801_RW_PORT,  PSP27801_RW_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        false}, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false}},
};

const ad_lcdc_io_conf_t psp27801_io = {
        .voltage_level = HW_GPIO_POWER_V33,
        .io_cnt = sizeof(psp27801_gpio_cfg) / sizeof(psp27801_gpio_cfg[0]),
        .io_list = psp27801_gpio_cfg,
};
#endif /* dg_configUSE_PSP27801 */

#if dg_configUSE_MCT024L6W240320PML
static const ad_io_conf_t mct024l6w240320pml_gpio_cfg[] = {
        {MCT024L6W240320PML_SDA_PORT, MCT024L6W240320PML_SDA_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true}, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        {MCT024L6W240320PML_SCK_PORT, MCT024L6W240320PML_SCK_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true}, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        {MCT024L6W240320PML_CS_PORT,  MCT024L6W240320PML_CS_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true}, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        {MCT024L6W240320PML_DC_PORT,  MCT024L6W240320PML_DC_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true}, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        {MCT024L6W240320PML_RST_PORT, MCT024L6W240320PML_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true}, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t mct024l6w240320pml_io = {
        .voltage_level = HW_GPIO_POWER_V33,
        .io_cnt = sizeof(mct024l6w240320pml_gpio_cfg) / sizeof(mct024l6w240320pml_gpio_cfg[0]),
        .io_list = mct024l6w240320pml_gpio_cfg,
};
#endif /* dg_configUSE_MCT024L6W240320PML */

#if dg_configUSE_LPM013M091A
static const ad_io_conf_t lpm013m091a_gpio_cfg[] = {
        { LPM013M091A_SCL_PORT, LPM013M091A_SCL_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { LPM013M091A_SDI_PORT, LPM013M091A_SDI_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { LPM013M091A_RST_PORT, LPM013M091A_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { LPM013M091A_DCX_PORT, LPM013M091A_DCX_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { LPM013M091A_IM0_PORT, LPM013M091A_IM0_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { LPM013M091A_CSX_PORT, LPM013M091A_CSX_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { LPM013M091A_TE_PORT,  LPM013M091A_TE_PIN,  { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,         true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t lpm013m091a_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(lpm013m091a_gpio_cfg) / sizeof(lpm013m091a_gpio_cfg[0]),
        .io_list = lpm013m091a_gpio_cfg,
};
#endif /* dg_configUSE_LPM013M091A */

#if dg_configUSE_XSJ120TY2401_QSPI || dg_configUSE_XSJ120TY2401_DSPI || dg_configUSE_XSJ120TY2401_SPI3 || dg_configUSE_XSJ120TY2401_SPI4
static const ad_io_conf_t xsj120ty2401_spi_gpio_cfg[] = {
        { XSJ120TY2401_SPI_SCL_PORT, XSJ120TY2401_SPI_SCL_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { XSJ120TY2401_SPI_SD0_PORT, XSJ120TY2401_SPI_SD0_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { XSJ120TY2401_SPI_SD1_PORT, XSJ120TY2401_SPI_SD1_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true },  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
#if (DEVICE_FAMILY == DA1470X)
        { XSJ120TY2401_SPI_SD2_PORT, XSJ120TY2401_SPI_SD2_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,         true },  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { XSJ120TY2401_SPI_SD3_PORT, XSJ120TY2401_SPI_SD3_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,         true },  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { XSJ120TY2401_SPI_SI_PORT,  XSJ120TY2401_SPI_SI_PIN,  { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,         true  }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true  }},
#endif
        { XSJ120TY2401_SPI_RST_PORT, XSJ120TY2401_SPI_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { XSJ120TY2401_SPI_CSX_PORT, XSJ120TY2401_SPI_CSX_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { XSJ120TY2401_SPI_TE_PORT,  XSJ120TY2401_SPI_TE_PIN,  { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,         true  }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true  }},
        { XSJ120TY2401_SPI_IM0_PORT, XSJ120TY2401_SPI_IM0_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { XSJ120TY2401_SPI_IM1_PORT, XSJ120TY2401_SPI_IM1_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false }},
};

const ad_lcdc_io_conf_t xsj120ty2401_spi_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(xsj120ty2401_spi_gpio_cfg) / sizeof(xsj120ty2401_spi_gpio_cfg[0]),
        .io_list = xsj120ty2401_spi_gpio_cfg,
};
#endif /* dg_configUSE_XSJ120TY2401_QSPI || dg_configUSE_XSJ120TY2401_DSPI || dg_configUSE_XSJ120TY2401_SPI3 || dg_configUSE_XSJ120TY2401_SPI4 */

#if dg_configUSE_XSJ120TY2401_DBIB
static const ad_io_conf_t xsj120ty2401_dbib_gpio_cfg[] = {
        { XSJ120TY2401_DBIB_DB0_PORT,  XSJ120TY2401_DBIB_DB0_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_DB1_PORT,  XSJ120TY2401_DBIB_DB1_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_DB2_PORT,  XSJ120TY2401_DBIB_DB2_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_DB3_PORT,  XSJ120TY2401_DBIB_DB3_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_DB4_PORT,  XSJ120TY2401_DBIB_DB4_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_DB5_PORT,  XSJ120TY2401_DBIB_DB5_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_DB6_PORT,  XSJ120TY2401_DBIB_DB6_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_DB7_PORT,  XSJ120TY2401_DBIB_DB7_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_CS_PORT,   XSJ120TY2401_DBIB_CS_PIN,   { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_RESX_PORT, XSJ120TY2401_DBIB_RESX_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_DCX_PORT,  XSJ120TY2401_DBIB_DCX_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_WRX_PORT,  XSJ120TY2401_DBIB_WRX_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_RDX_PORT,  XSJ120TY2401_DBIB_RDX_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { XSJ120TY2401_DBIB_TE_PORT,   XSJ120TY2401_DBIB_TE_PIN,   { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t xsj120ty2401_dbib_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(xsj120ty2401_dbib_gpio_cfg) / sizeof(xsj120ty2401_dbib_gpio_cfg[0]),
        .io_list = xsj120ty2401_dbib_gpio_cfg,
};
#endif /* dg_configUSE_XSJ120TY2401_DBIB */

#if dg_configUSE_ONOC40108_SPI4
static const ad_io_conf_t onoc40108_spi4_gpio_cfg[] = {
        { ONOC40108_SPI4_SCL_PORT, ONOC40108_SPI4_SCL_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { ONOC40108_SPI4_SD0_PORT, ONOC40108_SPI4_SD0_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { ONOC40108_SPI4_RST_PORT, ONOC40108_SPI4_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { ONOC40108_SPI4_CSX_PORT, ONOC40108_SPI4_CSX_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { ONOC40108_SPI4_DCX_PORT, ONOC40108_SPI4_DCX_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { ONOC40108_SPI4_TE_PORT,  ONOC40108_SPI4_TE_PIN,  { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,         true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t onoc40108_spi4_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(onoc40108_spi4_gpio_cfg) / sizeof(onoc40108_spi4_gpio_cfg[0]),
        .io_list = onoc40108_spi4_gpio_cfg,
};
#endif

#if dg_configUSE_MRB3973_DBIB
static const ad_io_conf_t mrb3973_dbib_gpio_cfg[] = {
        { MRB3973_DBIB_DB0_PORT,  MRB3973_DBIB_DB0_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_DB1_PORT,  MRB3973_DBIB_DB1_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_DB2_PORT,  MRB3973_DBIB_DB2_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_DB3_PORT,  MRB3973_DBIB_DB3_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_DB4_PORT,  MRB3973_DBIB_DB4_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_DB5_PORT,  MRB3973_DBIB_DB5_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_DB6_PORT,  MRB3973_DBIB_DB6_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_DB7_PORT,  MRB3973_DBIB_DB7_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_CS_PORT,   MRB3973_DBIB_CS_PIN,   { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_RESX_PORT, MRB3973_DBIB_RESX_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_DCX_PORT,  MRB3973_DBIB_DCX_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_WRX_PORT,  MRB3973_DBIB_WRX_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_RDX_PORT,  MRB3973_DBIB_RDX_PIN,  { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { MRB3973_DBIB_TE_PORT,   MRB3973_DBIB_TE_PIN,   { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD, true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t mrb3973_dbib_io = {
        .voltage_level = HW_GPIO_POWER_V33,
        .io_cnt = sizeof(mrb3973_dbib_gpio_cfg) / sizeof(mrb3973_dbib_gpio_cfg[0]),
        .io_list = mrb3973_dbib_gpio_cfg,
};
#endif

#if dg_configUSE_BOE139F454SM
static const ad_io_conf_t boe139f454sm_gpio_cfg[] = {
        { BOE139F454SM_RESX_PORT, BOE139F454SM_RESX_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true }},
        { BOE139F454SM_TE_PORT,   BOE139F454SM_TE_PIN,   { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,  true }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true }},
};

const ad_lcdc_io_conf_t boe139f454sm_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(boe139f454sm_gpio_cfg) / sizeof(boe139f454sm_gpio_cfg[0]),
        .io_list = boe139f454sm_gpio_cfg,
};
#endif

#if dg_configUSE_E120A390QSR
static const ad_io_conf_t e120a390qsr_gpio_cfg[] = {
        { E120A390QSR_SCL_PORT, E120A390QSR_SCL_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_CLK, true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { E120A390QSR_SD0_PORT, E120A390QSR_SD0_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DO,  true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { E120A390QSR_SD1_PORT, E120A390QSR_SD1_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_DC,  true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
#if (DEVICE_FAMILY == DA1470X)
        { E120A390QSR_SD2_PORT, E120A390QSR_SD2_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,         true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { E120A390QSR_SD3_PORT, E120A390QSR_SD3_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD,         true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
#endif
        { E120A390QSR_RST_PORT, E120A390QSR_RST_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { E120A390QSR_CSX_PORT, E120A390QSR_CSX_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_LCD_SPI_EN,  true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { E120A390QSR_TE_PORT,  E120A390QSR_TE_PIN,  { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_LCD,         true  }, { HW_GPIO_MODE_INPUT,  HW_GPIO_FUNC_GPIO, true  }},
        { E120A390QSR_IM0_PORT, E120A390QSR_IM0_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        true  }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, true  }},
        { E120A390QSR_IM1_PORT, E120A390QSR_IM1_PIN, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO,        false }, { HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO, false }},
};

const ad_lcdc_io_conf_t e120a390qsr_io = {
        .voltage_level = HW_GPIO_POWER_VDD1V8P,
        .io_cnt = sizeof(e120a390qsr_gpio_cfg) / sizeof(e120a390qsr_gpio_cfg[0]),
        .io_list = e120a390qsr_gpio_cfg,
};
#endif /* dg_configUSE_E120A390QSR */
#endif /* dg_configLCDC_ADAPTER */

#if dg_configUSE_FT6206
/* I2C I/O pins configurations */
const ad_i2c_io_conf_t ft6206_io = {
        { FT6206_SCL_PORT, FT6206_SCL_PIN, { HW_GPIO_MODE_OUTPUT_OPEN_DRAIN, HW_GPIO_FUNC_I2C_SCL, false }, { HW_GPIO_MODE_INPUT, HW_GPIO_FUNC_GPIO, true }},
        { FT6206_SDA_PORT, FT6206_SDA_PIN, { HW_GPIO_MODE_OUTPUT_OPEN_DRAIN, HW_GPIO_FUNC_I2C_SDA, false }, { HW_GPIO_MODE_INPUT, HW_GPIO_FUNC_GPIO, true }},
        .voltage_level = HW_GPIO_POWER_V33
};
#endif /* dg_configUSE_FT6206 */

#if dg_configUSE_ZT2628
const ad_i2c_io_conf_t zt2628_io = {
        { ZT2628_SCL_PORT, ZT2628_SCL_PIN, { HW_GPIO_MODE_OUTPUT_OPEN_DRAIN, HW_GPIO_FUNC_I2C_SCL, false }, { HW_GPIO_MODE_INPUT, HW_GPIO_FUNC_GPIO, true }},
        { ZT2628_SDA_PORT, ZT2628_SDA_PIN, { HW_GPIO_MODE_OUTPUT_OPEN_DRAIN, HW_GPIO_FUNC_I2C_SDA, false }, { HW_GPIO_MODE_INPUT, HW_GPIO_FUNC_GPIO, true }},
        .voltage_level = HW_GPIO_POWER_V33
};
#endif /* dg_configUSE_ZT2628 */

/*
 * PLATFORM PERIPHERALS CONTROLLER CONFIGURATION
 *****************************************************************************************
 */


