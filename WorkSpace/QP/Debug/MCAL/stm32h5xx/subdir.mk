################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MCAL/stm32h5xx/MCAL_Gpio.cpp 

OBJS += \
./MCAL/stm32h5xx/MCAL_Gpio.o 

CPP_DEPS += \
./MCAL/stm32h5xx/MCAL_Gpio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/stm32h5xx/%.o MCAL/stm32h5xx/%.su MCAL/stm32h5xx/%.cyclo: ../MCAL/stm32h5xx/%.cpp MCAL/stm32h5xx/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -DQP_CONFIG=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Code" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/BSP" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/ThirdParty/qpcpp/include" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/ThirdParty/qpcpp/ports/arm-cm/qk/gnu" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/MCAL" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/MCAL/stm32h5xx" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/APP/TRACER" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/APP" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models/ButtonPressHandler" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models/Blinker" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -save-temps -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCAL-2f-stm32h5xx

clean-MCAL-2f-stm32h5xx:
	-$(RM) ./MCAL/stm32h5xx/MCAL_Gpio.cyclo ./MCAL/stm32h5xx/MCAL_Gpio.d ./MCAL/stm32h5xx/MCAL_Gpio.o ./MCAL/stm32h5xx/MCAL_Gpio.su

.PHONY: clean-MCAL-2f-stm32h5xx

