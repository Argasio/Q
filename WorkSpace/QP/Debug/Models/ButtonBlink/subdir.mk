################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Models/ButtonBlink/AO_ButtonBlink.cpp 

OBJS += \
./Models/ButtonBlink/AO_ButtonBlink.o 

CPP_DEPS += \
./Models/ButtonBlink/AO_ButtonBlink.d 


# Each subdirectory must supply rules for building sources it contributes
Models/ButtonBlink/%.o Models/ButtonBlink/%.su Models/ButtonBlink/%.cyclo: ../Models/ButtonBlink/%.cpp Models/ButtonBlink/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -DQP_CONFIG=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Repos/Q/WorkSpace/QP/Code" -I"C:/Repos/Q/WorkSpace/QP/BSP" -I"C:/Repos/Q/WorkSpace/QP/ThirdParty/qpcpp/include" -I"C:/Repos/Q/WorkSpace/QP/ThirdParty/qpcpp/ports/arm-cm/qk/gnu" -I"C:/Repos/Q/WorkSpace/QP/Models" -I"C:/Repos/Q/WorkSpace/QP/Models/ButtonBlink" -I"C:/Repos/Q/WorkSpace/QP/MCAL" -I"C:/Repos/Q/WorkSpace/QP/MCAL/stm32h5xx" -I"C:/Repos/Q/WorkSpace/QP/APP" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Models-2f-ButtonBlink

clean-Models-2f-ButtonBlink:
	-$(RM) ./Models/ButtonBlink/AO_ButtonBlink.cyclo ./Models/ButtonBlink/AO_ButtonBlink.d ./Models/ButtonBlink/AO_ButtonBlink.o ./Models/ButtonBlink/AO_ButtonBlink.su

.PHONY: clean-Models-2f-ButtonBlink

