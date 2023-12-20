################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ThirdParty/qpcpp/src/qk/qk.cpp 

OBJS += \
./ThirdParty/qpcpp/src/qk/qk.o 

CPP_DEPS += \
./ThirdParty/qpcpp/src/qk/qk.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/qpcpp/src/qk/%.o ThirdParty/qpcpp/src/qk/%.su ThirdParty/qpcpp/src/qk/%.cyclo: ../ThirdParty/qpcpp/src/qk/%.cpp ThirdParty/qpcpp/src/qk/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -DQP_CONFIG=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Repos/Q/WorkSpace/QP/Code" -I"C:/Repos/Q/WorkSpace/QP/BSP" -I"C:/Repos/Q/WorkSpace/QP/ThirdParty/qpcpp/include" -I"C:/Repos/Q/WorkSpace/QP/ThirdParty/qpcpp/ports/arm-cm/qk/gnu" -I"C:/Repos/Q/WorkSpace/QP/Models" -I"C:/Repos/Q/WorkSpace/QP/Models/ButtonBlink" -I"C:/Repos/Q/WorkSpace/QP/MCAL" -I"C:/Repos/Q/WorkSpace/QP/MCAL/stm32h5xx" -I"C:/Repos/Q/WorkSpace/QP/APP/TRACER" -I"C:/Repos/Q/WorkSpace/QP/APP" -I"C:/Repos/Q/WorkSpace/QP/Models/ButtonPressHandler" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-qpcpp-2f-src-2f-qk

clean-ThirdParty-2f-qpcpp-2f-src-2f-qk:
	-$(RM) ./ThirdParty/qpcpp/src/qk/qk.cyclo ./ThirdParty/qpcpp/src/qk/qk.d ./ThirdParty/qpcpp/src/qk/qk.o ./ThirdParty/qpcpp/src/qk/qk.su

.PHONY: clean-ThirdParty-2f-qpcpp-2f-src-2f-qk

