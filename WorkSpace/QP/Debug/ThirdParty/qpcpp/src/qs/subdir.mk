################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ThirdParty/qpcpp/src/qs/qs.cpp \
../ThirdParty/qpcpp/src/qs/qs_64bit.cpp \
../ThirdParty/qpcpp/src/qs/qs_fp.cpp \
../ThirdParty/qpcpp/src/qs/qs_rx.cpp \
../ThirdParty/qpcpp/src/qs/qstamp.cpp \
../ThirdParty/qpcpp/src/qs/qutest.cpp 

OBJS += \
./ThirdParty/qpcpp/src/qs/qs.o \
./ThirdParty/qpcpp/src/qs/qs_64bit.o \
./ThirdParty/qpcpp/src/qs/qs_fp.o \
./ThirdParty/qpcpp/src/qs/qs_rx.o \
./ThirdParty/qpcpp/src/qs/qstamp.o \
./ThirdParty/qpcpp/src/qs/qutest.o 

CPP_DEPS += \
./ThirdParty/qpcpp/src/qs/qs.d \
./ThirdParty/qpcpp/src/qs/qs_64bit.d \
./ThirdParty/qpcpp/src/qs/qs_fp.d \
./ThirdParty/qpcpp/src/qs/qs_rx.d \
./ThirdParty/qpcpp/src/qs/qstamp.d \
./ThirdParty/qpcpp/src/qs/qutest.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/qpcpp/src/qs/%.o ThirdParty/qpcpp/src/qs/%.su ThirdParty/qpcpp/src/qs/%.cyclo: ../ThirdParty/qpcpp/src/qs/%.cpp ThirdParty/qpcpp/src/qs/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -DQP_CONFIG=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Repos/Q/WorkSpace/QP/Code" -I"C:/Repos/Q/WorkSpace/QP/BSP" -I"C:/Repos/Q/WorkSpace/QP/ThirdParty/qpcpp/include" -I"C:/Repos/Q/WorkSpace/QP/ThirdParty/qpcpp/ports/arm-cm/qk/gnu" -I"C:/Repos/Q/WorkSpace/QP/Models" -I"C:/Repos/Q/WorkSpace/QP/Models/ButtonBlink" -I"C:/Repos/Q/WorkSpace/QP/MCAL" -I"C:/Repos/Q/WorkSpace/QP/MCAL/stm32h5xx" -I"C:/Repos/Q/WorkSpace/QP/APP" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-qpcpp-2f-src-2f-qs

clean-ThirdParty-2f-qpcpp-2f-src-2f-qs:
	-$(RM) ./ThirdParty/qpcpp/src/qs/qs.cyclo ./ThirdParty/qpcpp/src/qs/qs.d ./ThirdParty/qpcpp/src/qs/qs.o ./ThirdParty/qpcpp/src/qs/qs.su ./ThirdParty/qpcpp/src/qs/qs_64bit.cyclo ./ThirdParty/qpcpp/src/qs/qs_64bit.d ./ThirdParty/qpcpp/src/qs/qs_64bit.o ./ThirdParty/qpcpp/src/qs/qs_64bit.su ./ThirdParty/qpcpp/src/qs/qs_fp.cyclo ./ThirdParty/qpcpp/src/qs/qs_fp.d ./ThirdParty/qpcpp/src/qs/qs_fp.o ./ThirdParty/qpcpp/src/qs/qs_fp.su ./ThirdParty/qpcpp/src/qs/qs_rx.cyclo ./ThirdParty/qpcpp/src/qs/qs_rx.d ./ThirdParty/qpcpp/src/qs/qs_rx.o ./ThirdParty/qpcpp/src/qs/qs_rx.su ./ThirdParty/qpcpp/src/qs/qstamp.cyclo ./ThirdParty/qpcpp/src/qs/qstamp.d ./ThirdParty/qpcpp/src/qs/qstamp.o ./ThirdParty/qpcpp/src/qs/qstamp.su ./ThirdParty/qpcpp/src/qs/qutest.cyclo ./ThirdParty/qpcpp/src/qs/qutest.d ./ThirdParty/qpcpp/src/qs/qutest.o ./ThirdParty/qpcpp/src/qs/qutest.su

.PHONY: clean-ThirdParty-2f-qpcpp-2f-src-2f-qs

