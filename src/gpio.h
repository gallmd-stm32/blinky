/*
 * gpio.h
 *
 *  Created on: Oct 11, 2018
 *      Author: matt
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "reg_access.h"
#include "reg_access_dynamic.h"
#include "registers.h"


typedef uint8_t AlternateFunctionType;
typedef uint8_t PinType;
typedef uint32_t GpioModeType;
typedef uint8_t OutputType;
typedef uint8_t OutputSpeedType;
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

	constexpr GpioModeType Input = 0x00000000U;
	constexpr GpioModeType Output = 0x00000001U;
	constexpr GpioModeType AlternateFunction = 0x00000002U;
	constexpr GpioModeType AnalogMode = 0x00000003U;

}

namespace OutputTypes{

	constexpr OutputType PushPull = 0x00U;
	constexpr OutputType OpenDrain = 0x01U;

}

namespace OutputSpeed{

	constexpr OutputSpeedType LowSpeed = 0x00U;
	constexpr OutputSpeedType MediumSpeed = 0x01U;
	constexpr OutputSpeedType HighSpeed = 0x02U;
	constexpr OutputSpeedType VeryHighSpeeed = 0x03U;

}

namespace PullUpPullDown {

	constexpr PullUpPullDownType NoPullUpPullDown = 0x00U;
	constexpr PullUpPullDownType PullUp = 0x01U;
	constexpr PullUpPullDownType PullDown = 0x02U;

}

namespace RegisterOffsets{

	constexpr GPIOxRegisterType ModeRegisterOffset = 0x00U;
	constexpr GPIOxRegisterType OutputTypeRegisterOffset = 0x04U;
	constexpr GPIOxRegisterType OutputSpeedRegisterOffset = 0x08U;
	constexpr GPIOxRegisterType PullUpPullDownRegisterOffset = 0x0CU;
	constexpr GPIOxRegisterType InputDataRegisterOffset = 0x10U;
	constexpr GPIOxRegisterType OutputDataRegisterOffset = 0x14U;
	constexpr GPIOxRegisterType BitSetResetLowRegisterOffset = 0x18U;
	constexpr GPIOxRegisterType BitSetResetHighRegisterOffset = 0x1AU;
	constexpr GPIOxRegisterType LockRegisterOffset = 0x1CU;
	constexpr GPIOxRegisterType AlternateFunctionLowRegisterOffset = 0x20U;
	constexpr GPIOxRegisterType AlternateFunctionHighRegisterOffset = 0x24U;

}

template<
	const GPIOxRegisterType gpio_bank,
	const PinType pinNumber,
	const GpioModeType mode,
	const OutputType outputType,
	const OutputSpeedType outputSpeed,
	const AlternateFunctionType alternateFunction>
class GPIO{


public:

	GPIO(){

		//set mode register
		uint32_t modeMask = 0x00U;
		modeMask = mode << ((pinNumber-1) * 2);

		dynamic_access<GPIOxRegisterType, uint32_t>::reg_or(GPIOxModeRegister, modeMask);

		//set ouput type register
		reg_access<GPIOxRegisterType, OutputType, GPIOxOutputTypeRegister, (outputType << (pinNumber-1))>::reg_or();

		//set output speed register

		//set pull-up/pull-down register

		//Set Alternate Function Register


	}

private:

	static constexpr GPIOxRegisterType GPIOxBaseRegister = gpio_bank;
	static constexpr GPIOxRegisterType GPIOxModeRegister = gpio_bank + RegisterOffsets::ModeRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxOutputTypeRegister = gpio_bank + RegisterOffsets::OutputTypeRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxOuputSpeedRegister = gpio_bank + RegisterOffsets::OutputSpeedRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxPullUpPullDownRegister = gpio_bank + RegisterOffsets::PullUpPullDownRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxInputDataRegister = gpio_bank + RegisterOffsets::InputDataRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxOutputDataRegister = gpio_bank + RegisterOffsets::OutputDataRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxBitSetResetLowRegister = gpio_bank + RegisterOffsets::BitSetResetLowRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxBitSetResetHighRegister = gpio_bank + RegisterOffsets::BitSetResetHighRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxLockRegister = gpio_bank + RegisterOffsets::LockRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxAlternateFunctionHighRegister = gpio_bank + RegisterOffsets::AlternateFunctionHighRegisterOffset;
	static constexpr GPIOxRegisterType GPIOxAlternateFunctionLowRegister = gpio_bank + RegisterOffsets::AlternateFunctionLowRegisterOffset;




};


#endif /* GPIO_H_ */
