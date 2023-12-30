################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../APP/LedHandler.cpp \
../APP/Qp_Tracer.cpp 

OBJS += \
./APP/LedHandler.o \
./APP/Qp_Tracer.o 

CPP_DEPS += \
./APP/LedHandler.d \
./APP/Qp_Tracer.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o APP/%.su APP/%.cyclo: ../APP/%.cpp APP/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -DQP_CONFIG=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Code" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/BSP" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/ThirdParty/qpcpp/include" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/ThirdParty/qpcpp/ports/arm-cm/qk/gnu" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/MCAL" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/MCAL/stm32h5xx" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/APP/TRACER" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/APP" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models/ButtonPressHandler" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models/Blinker" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -save-temps -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-APP

clean-APP:
	-$(RM) ./APP/LedHandler.cyclo ./APP/LedHandler.d ./APP/LedHandler.o ./APP/LedHandler.su ./APP/Qp_Tracer.cyclo ./APP/Qp_Tracer.d ./APP/Qp_Tracer.o ./APP/Qp_Tracer.su

.PHONY: clean-APP

