################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/BSP_Callbacks.c 

CPP_SRCS += \
../BSP/BSP_Init.cpp \
../BSP/BSP_QP.cpp 

C_DEPS += \
./BSP/BSP_Callbacks.d 

OBJS += \
./BSP/BSP_Callbacks.o \
./BSP/BSP_Init.o \
./BSP/BSP_QP.o 

CPP_DEPS += \
./BSP/BSP_Init.d \
./BSP/BSP_QP.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/%.o BSP/%.su BSP/%.cyclo: ../BSP/%.c BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -DQP_CONFIG=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Repos/Q_/WorkSpace/QP/Code" -I"C:/Repos/Q_/WorkSpace/QP/BSP" -I"C:/Repos/Q_/WorkSpace/QP/ThirdParty/qpcpp/include" -I"C:/Repos/Q_/WorkSpace/QP/ThirdParty/qpcpp/ports/arm-cm/qk/gnu" -I"C:/Repos/Q_/WorkSpace/QP/Models" -I"C:/Repos/Q_/WorkSpace/QP/Models/ButtonBlink" -I"C:/Repos/Q_/WorkSpace/QP/MCAL" -I"C:/Repos/Q_/WorkSpace/QP/MCAL/stm32h5xx" -I"C:/Repos/Q_/WorkSpace/QP/APP" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
BSP/%.o BSP/%.su BSP/%.cyclo: ../BSP/%.cpp BSP/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -DQP_CONFIG=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Repos/Q_/WorkSpace/QP/Code" -I"C:/Repos/Q_/WorkSpace/QP/BSP" -I"C:/Repos/Q_/WorkSpace/QP/ThirdParty/qpcpp/include" -I"C:/Repos/Q_/WorkSpace/QP/ThirdParty/qpcpp/ports/arm-cm/qk/gnu" -I"C:/Repos/Q_/WorkSpace/QP/Models" -I"C:/Repos/Q_/WorkSpace/QP/Models/ButtonBlink" -I"C:/Repos/Q_/WorkSpace/QP/MCAL" -I"C:/Repos/Q_/WorkSpace/QP/MCAL/stm32h5xx" -I"C:/Repos/Q_/WorkSpace/QP/APP" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSP

clean-BSP:
	-$(RM) ./BSP/BSP_Callbacks.cyclo ./BSP/BSP_Callbacks.d ./BSP/BSP_Callbacks.o ./BSP/BSP_Callbacks.su ./BSP/BSP_Init.cyclo ./BSP/BSP_Init.d ./BSP/BSP_Init.o ./BSP/BSP_Init.su ./BSP/BSP_QP.cyclo ./BSP/BSP_QP.d ./BSP/BSP_QP.o ./BSP/BSP_QP.su

.PHONY: clean-BSP

