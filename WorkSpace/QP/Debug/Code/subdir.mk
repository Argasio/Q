################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Code/AO_Callbacks.cpp \
../Code/Main.cpp 

C_SRCS += \
../Code/Modules.c 

C_DEPS += \
./Code/Modules.d 

OBJS += \
./Code/AO_Callbacks.o \
./Code/Main.o \
./Code/Modules.o 

CPP_DEPS += \
./Code/AO_Callbacks.d \
./Code/Main.d 


# Each subdirectory must supply rules for building sources it contributes
Code/%.o Code/%.su Code/%.cyclo: ../Code/%.cpp Code/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -DQP_CONFIG=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Code" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/BSP" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/ThirdParty/qpcpp/include" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/ThirdParty/qpcpp/ports/arm-cm/qk/gnu" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/MCAL" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/MCAL/stm32h5xx" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/APP/TRACER" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/APP" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models/ButtonPressHandler" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models/Blinker" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -save-temps -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Code/%.o Code/%.su Code/%.cyclo: ../Code/%.c Code/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu99 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -DQP_CONFIG=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Code" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/BSP" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/ThirdParty/qpcpp/include" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/ThirdParty/qpcpp/ports/arm-cm/qk/gnu" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/MCAL" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/MCAL/stm32h5xx" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/APP/TRACER" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/APP" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models/ButtonPressHandler" -I"C:/Users/Argasio/Documents/GitHub/Q/WorkSpace/QP/Models/Blinker" -O0 -ffunction-sections -fdata-sections -Wall -save-temps -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Code

clean-Code:
	-$(RM) ./Code/AO_Callbacks.cyclo ./Code/AO_Callbacks.d ./Code/AO_Callbacks.o ./Code/AO_Callbacks.su ./Code/Main.cyclo ./Code/Main.d ./Code/Main.o ./Code/Main.su ./Code/Modules.cyclo ./Code/Modules.d ./Code/Modules.o ./Code/Modules.su

.PHONY: clean-Code

