/*
 * gpio.h
 *
 *  Created on: Oct 11, 2018
 *      Author: matt
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "reg_access.h"
#include "registers.h"


typedef uint8_t AlternateFunctionType;
typedef uint8_t PinType;
typedef uint8_t GpioModeType;
typedef uint8_t OutputType;
typedef uint8_t OutputSpeed;
typedef uint8_t PullUpPullDownType;
typedef uint32_t GPIOxRegisterType;

namespace GPIOxBaseRegisters{


	constexpr GPIOxRegisterType GPIO_A = 0x40020000U;
	constexpr GPIOxRegisterType GPIO_B = 0x40020400U;
	constexpr GPIOxRegisterType GPIO_C = 0x40020800U;
	constexpr GPIOxRegisterType GPIO_D = 0x40020C00U;
	constexpr GPIOxRegisterType GPIO_E = 0x40021000U;
	constexpr GPIOxRegisterType GPIO_F = 0x40021400U;
	constexpr GPIOxRegisterType GPIO_G = 0x40021800U;
	constexpr GPIOxRegisterType GPIO_H = 0x40021C00U;
	constexpr GPIOxRegisterType GPIO_I = 0x40022000U;


}

namespace AlternateFunction{

	//GPIO Alternate functions
	constexpr AlternateFunctionType AF0 	= 0x00U;
	constexpr AlternateFunctionType AF1 	= 0x01U;
	constexpr AlternateFunctionType AF2 	= 0x02U;
	constexpr AlternateFunctionType AF3 	= 0x03U;
	constexpr AlternateFunctionType AF4 	= 0x04U;
	constexpr AlternateFunctionType AF5 	= 0x05U;
	constexpr AlternateFunctionType AF6 	= 0x06U;
	constexpr AlternateFunctionType AF7 	= 0x07U;
	constexpr AlternateFunctionType AF8 	= 0x08U;
	constexpr AlternateFunctionType AF9 	= 0x09U;
	constexpr AlternateFunctionType AF10 	= 0x0AU;
	constexpr AlternateFunctionType AF11 	= 0x0BU;
	constexpr AlternateFunctionType AF12 	= 0x0CU;
	constexpr AlternateFunctionType AF13 	= 0x0DU;
	constexpr AlternateFunctionType AF14 	= 0x0EU;
	constexpr AlternateFunctionType AF15 	= 0x0FU;

}

namespace PINS {

	constexpr PinType PIN0 		= 1U;
	constexpr PinType PIN1 		= 2U;
	constexpr PinType PIN2 		= 3U;
	constexpr PinType PIN3 		= 4U;
	constexpr PinType PIN4 		= 5U;
	constexpr PinType PIN5 		= 6U;
	constexpr PinType PIN6 		= 7U;
	constexpr PinType PIN7 		= 8U;
	constexpr PinType PIN8 		= 9U;
	constexpr PinType PIN9 		= 10U;
	constexpr PinType PIN10 	= 11U;
	constexpr PinType PIN11 	= 12U;
	constexpr PinType PIN12 	= 13U;
	constexpr PinType PIN13 	= 14U;
	constexpr PinType PIN14 	= 15U;
	constexpr PinType PIN15 	= 16U;

}

	namespace GpioModes{

	constexpr GpioModeType Input = 0x00U;
	constexpr GpioModeType Output = 0x01U;
	constexpr GpioModeType AlternateFunction = 0x02U;
	constexpr GpioModeType AnalogMode = 0x03U;

}

namespace OutputTypes{

	constexpr OutputType PushPull = 0x00U;
	constexpr OutputType OpenDrain = 0x01U;

}

namespace OutputSpeed{

	constexpr OutputSpeed LowSpeed = 0x00U;
	constexpr OutputSpeed MediumSpeed = 0x01U;
	constexpr OutputSpeed HighSpeed = 0x02U;
	constexpr OutputSpeed VeryHighSpeeed = 0x03U;

}

namespace PullUpPullDown {

	constexpr PullUpPullDownType NoPullUpPullDown = 0x00U;
	constexpr PullUpPullDownType PullUp = 0x01U;
	constexpr PullUpPullDownType PullDown = 0x02U;

}
class GPIO{


public:

	GPIO(GPIOxRegisterType gpioBank,
			PinType pin_number,
			GpioModeType mode,
			OutputType outputType,
			OutputSpeed outputSpeed,
			AlternateFunctionType alernateFunction);

private:

	GPIOxRegisterType GPIOxBaseRegister;
	GPIOxRegisterType GPIOxModeRegister;
	GPIOxRegisterType GPIOxOutputTypeRegister;
	GPIOxRegisterType GPIOxOuputSpeedRegister;
	GPIOxRegisterType GPIOxPullUpPullDownRegister;
	GPIOxRegisterType GPIOxInputDataRegister;
	GPIOxRegisterType GPIOxOutputDataRegister;
	GPIOxRegisterType GPIOxBitSetResetRegister;
	GPIOxRegisterType GPIOxLockRegister;
	GPIOxRegisterType GPIOxAlternateFunctionHighRegister;
	GPIOxRegisterType GPIOxAlternateFunctionLowRegister;


};


#endif /* GPIO_H_ */
