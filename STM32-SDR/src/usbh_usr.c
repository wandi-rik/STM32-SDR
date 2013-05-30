/**
 ******************************************************************************
 * @file    usbh_usr.c
 * @author  MCD Application Team
 * @version V2.1.0
 * @date    19-March-2012
 * @brief   This file includes the user application layer
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
 *
 * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *        http://www.st.com/software_license_agreement_liberty_v2
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
//#include "lcd_log.h"
#include "usbh_usr.h"
#include "usbh_hid_mouse.h"
#include "usbh_hid_keybd.h"

//extern USB_OTG_CORE_HANDLE           USB_OTG_Core_dev;
/*  Points to the DEVICE_PROP structure of current device */
/*  The purpose of this register is to speed up the execution */

USBH_Usr_cb_TypeDef USR_Callbacks =
{
		USBH_USR_Init,
		USBH_USR_DeInit,
		USBH_USR_DeviceAttached,
		USBH_USR_ResetDevice,
		USBH_USR_DeviceDisconnected,
		USBH_USR_OverCurrentDetected,
		USBH_USR_DeviceSpeedDetected,
		USBH_USR_Device_DescAvailable,
		USBH_USR_DeviceAddressAssigned,
		USBH_USR_Configuration_DescAvailable,
		USBH_USR_Manufacturer_String,
		USBH_USR_Product_String,
		USBH_USR_SerialNum_String,
		USBH_USR_EnumerationDone,
		USBH_USR_UserInput,
		NULL,
		USBH_USR_DeviceNotSupported,
		USBH_USR_UnrecoveredError
};




/**
 * @brief  USBH_USR_Init
 *         Displays the message on LCD for host lib initialization
 * @param  None
 * @retval None
 */
void USBH_USR_Init(void)
{
	static uint8_t startup = 0;

	if(startup == 0 )
	{
		startup = 1;
		/* Configure the LEDs */
		STM_EVAL_LEDInit(LED_Green);
		STM_EVAL_LEDInit(LED_Orange);
		STM_EVAL_LEDInit(LED_Red);
		STM_EVAL_LEDInit(LED_Blue);

		STM_EVAL_LEDOn(LED_Green);
		STM_EVAL_LEDOn(LED_Orange);
		STM_EVAL_LEDOn(LED_Red);
		STM_EVAL_LEDOn(LED_Blue);

		STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);
	}
}

/**
 * @brief  USBH_USR_DeviceAttached
 *         Displays the message on LCD on device attached
 * @param  None
 * @retval None
 */
void USBH_USR_DeviceAttached(void)
{  
}

/**
 * @brief  USBH_USR_UnrecoveredError
 * @param  None
 * @retval None
 */
void USBH_USR_UnrecoveredError (void)
{
}

/**
 * @brief  USBH_DisconnectEvent
 *         Device disconnect event
 * @param  None
 * @retval None
 */
void USBH_USR_DeviceDisconnected (void)
{
}

/**
 * @brief  USBH_USR_ResetUSBDevice
 *         Reset USB Device
 * @param  None
 * @retval None
 */
void USBH_USR_ResetDevice(void)
{
	/* Users can do their application actions here for the USB-Reset */
}


/**
 * @brief  USBH_USR_DeviceSpeedDetected
 *         Displays the message on LCD for device speed
 * @param  Devicespeed : Device Speed
 * @retval None
 */
void USBH_USR_DeviceSpeedDetected(uint8_t DeviceSpeed)
{
	//  if(DeviceSpeed == HPRT0_PRTSPD_HIGH_SPEED)
	//  {
	////   LCD_UsrLog((void *)MSG_DEV_HIGHSPEED);
	//  }
	//  else if(DeviceSpeed == HPRT0_PRTSPD_FULL_SPEED)
	//  {
	////LCD_UsrLog((void *)MSG_DEV_FULLSPEED);
	//  }
	//  else if(DeviceSpeed == HPRT0_PRTSPD_LOW_SPEED)
	//  {
	////    LCD_UsrLog((void *)MSG_DEV_LOWSPEED);
	//  }
	//  else
	//  {
	////    LCD_UsrLog((void *)MSG_DEV_ERROR);
	//  }
}

/**
 * @brief  USBH_USR_Device_DescAvailable
 *         Displays the message on LCD for device descriptor
 * @param  DeviceDesc : device descriptor
 * @retval None
 */
void USBH_USR_Device_DescAvailable(void *DeviceDesc)
{
	//  uint8_t temp[50];
	//  USBH_DevDesc_TypeDef *hs;
	//  hs = DeviceDesc;
	//
	//
	//  sprintf((char *)temp , "VID : %04Xh\n" , (uint32_t)(*hs).idVendor); /
	//  //LCD_UsrLog((void *)temp);
	//
	//
	//  sprintf((char *)temp , "PID : %04Xh\n" , (uint32_t)(*hs).idProduct);
	//  //LCD_UsrLog((void *)temp);
}

/**
 * @brief  USBH_USR_DeviceAddressAssigned
 *         USB device is successfully assigned the Address
 * @param  None
 * @retval None
 */
void USBH_USR_DeviceAddressAssigned(void)
{

}


/**
 * @brief  USBH_USR_Conf_Desc
 *         Displays the message on LCD for configuration descriptor
 * @param  ConfDesc : Configuration descriptor
 * @retval None
 */
void USBH_USR_Configuration_DescAvailable(USBH_CfgDesc_TypeDef * cfgDesc,
		USBH_InterfaceDesc_TypeDef *itfDesc,
		USBH_EpDesc_TypeDef *epDesc)
{
	//  USBH_InterfaceDesc_TypeDef *id;
	//
	//  id = itfDesc;
	//
	//  if((*id).bInterfaceClass  == 0x08)
	//  {
	////    LCD_UsrLog((void *)MSG_MSC_CLASS);
	//  }
	//  else if((*id).bInterfaceClass  == 0x03)
	//  {
	////    LCD_UsrLog((void *)MSG_HID_CLASS);
	//  }
}

/**
 * @brief  USBH_USR_Manufacturer_String
 *         Displays the message on LCD for Manufacturer String
 * @param  ManufacturerString : Manufacturer String of Device
 * @retval None
 */
void USBH_USR_Manufacturer_String(void *ManufacturerString)
{
}

/**
 * @brief  USBH_USR_Product_String
 *         Displays the message on LCD for Product String
 * @param  ProductString : Product String of Device
 * @retval None
 */
void USBH_USR_Product_String(void *ProductString)
{
}

/**
 * @brief  USBH_USR_SerialNum_String
 *         Displays the message on LCD for SerialNum_String
 * @param  SerialNumString : SerialNum_String of device
 * @retval None
 */
void USBH_USR_SerialNum_String(void *SerialNumString)
{
} 

/**
 * @brief  EnumerationDone
 *         User response request is displayed to ask for
 *         application jump to class
 * @param  None
 * @retval None
 */
void USBH_USR_EnumerationDone(void)
{
} 

/**
 * @brief  USBH_USR_DeviceNotSupported
 *         Device is not supported
 * @param  None
 * @retval None
 */
void USBH_USR_DeviceNotSupported(void)
{
}  


/**
 * @brief  USBH_USR_UserInput
 *         User Action for application state entry
 * @param  None
 * @retval USBH_USR_Status : User response for key button
 */
USBH_USR_Status USBH_USR_UserInput(void)
{

	USBH_USR_Status usbh_usr_status;

	usbh_usr_status = USBH_USR_NO_RESP;

	STM_EVAL_LEDOn(LED_Blue); // added by "STM32"

	// commented by "STM32"
	//  /*Key B3 is in polling mode to detect user action */
	//  if(STM_EVAL_PBGetState(Button_WAKEUP) == SET)
	//  {

	usbh_usr_status = USBH_USR_RESP_OK;

	//  }


	return usbh_usr_status;

} 

/**
 * @brief  USBH_USR_OverCurrentDetected
 *         Device Overcurrent detection event
 * @param  None
 * @retval None
 */
void USBH_USR_OverCurrentDetected (void)
{
	//   LCD_ErrLog ("Overcurrent detected.\n");

}

/**
 * @brief  USR_MOUSE_Init
 *         Init Mouse window
 * @param  None
 * @retval None
 */
void USR_MOUSE_Init	(void)
{

}

/**
 * @brief  USR_MOUSE_ProcessData
 *         Process Mouse data
 * @param  data : Mouse data to be displayed
 * @retval None
 */
void USR_MOUSE_ProcessData(HID_MOUSE_Data_TypeDef *data)
{
}

/**
 * @brief  USR_KEYBRD_Init
 *         Init Keyboard window
 * @param  None
 * @retval None
 */
void  USR_KEYBRD_Init (void)
{
}


/**
 * @brief  USR_KEYBRD_ProcessData
 *         Process Keyboard data
 * @param  data : Keyboard data to be displayed
 * @retval None
 */
void  USR_KEYBRD_ProcessData (uint8_t data)
{
	// TODO: Handle the character.
	STM_EVAL_LEDToggle(LED_Green);  // added by "STM32"

}

/**
 * @brief  USBH_USR_DeInit
 *         Deint User state and associated variables
 * @param  None
 * @retval None
 */
void USBH_USR_DeInit(void)
{
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
