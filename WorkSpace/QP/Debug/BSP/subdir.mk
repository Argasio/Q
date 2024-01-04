################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BSP/BSP_AoFactory.cpp \
../BSP/BSP_Callbacks.cpp \
../BSP/BSP_HandlerFactory.cpp \
../BSP/BSP_McalFactory.cpp \
../BSP/BSP_QP.cpp 

OBJS += \
./BSP/BSP_AoFactory.o \
./BSP/BSP_Callbacks.o \
./BSP/BSP_HandlerFactory.o \
./BSP/BSP_McalFactory.o \
./BSP/BSP_QP.o 

CPP_DEPS += \
./BSP/BSP_AoFactory.d \
./BSP/BSP_Callbacks.d \
./BSP/BSP_HandlerFactory.d \
./BSP/BSP_McalFactory.d \
./BSP/BSP_QP.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/%.o BSP/%.su BSP/%.cyclo: ../BSP/%.cpp BSP/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++20 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -DQP_CONFIG=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Repos/Q/WorkSpace/QP/Code" -I"C:/Repos/Q/WorkSpace/QP/BSP" -I"C:/Repos/Q/WorkSpace/QP/ThirdParty/qpcpp/include" -I"C:/Repos/Q/WorkSpace/QP/ThirdParty/qpcpp/ports/arm-cm/qk/gnu" -I"C:/Repos/Q/WorkSpace/QP/Models" -I"C:/Repos/Q/WorkSpace/QP/MCAL" -I"C:/Repos/Q/WorkSpace/QP/MCAL/stm32h5xx" -I"C:/Repos/Q/WorkSpace/QP/APP/TRACER" -I"C:/Repos/Q/WorkSpace/QP/Models/ButtonPressHandler" -I"C:/Repos/Q/WorkSpace/QP/Models/Blinker" -I"C:/Repos/Q/WorkSpace/QP/COMPONENTS" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -save-temps -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSP

clean-BSP:
	-$(RM) ./BSP/BSP_AoFactory.cyclo ./BSP/BSP_AoFactory.d ./BSP/BSP_AoFactory.o ./BSP/BSP_AoFactory.su ./BSP/BSP_Callbacks.cyclo ./BSP/BSP_Callbacks.d ./BSP/BSP_Callbacks.o ./BSP/BSP_Callbacks.su ./BSP/BSP_HandlerFactory.cyclo ./BSP/BSP_HandlerFactory.d ./BSP/BSP_HandlerFactory.o ./BSP/BSP_HandlerFactory.su ./BSP/BSP_McalFactory.cyclo ./BSP/BSP_McalFactory.d ./BSP/BSP_McalFactory.o ./BSP/BSP_McalFactory.su ./BSP/BSP_QP.cyclo ./BSP/BSP_QP.d ./BSP/BSP_QP.o ./BSP/BSP_QP.su

.PHONY: clean-BSP

