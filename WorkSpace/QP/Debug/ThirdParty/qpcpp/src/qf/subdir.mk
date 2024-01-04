################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ThirdParty/qpcpp/src/qf/qep_hsm.cpp \
../ThirdParty/qpcpp/src/qf/qep_msm.cpp \
../ThirdParty/qpcpp/src/qf/qf_act.cpp \
../ThirdParty/qpcpp/src/qf/qf_actq.cpp \
../ThirdParty/qpcpp/src/qf/qf_defer.cpp \
../ThirdParty/qpcpp/src/qf/qf_dyn.cpp \
../ThirdParty/qpcpp/src/qf/qf_mem.cpp \
../ThirdParty/qpcpp/src/qf/qf_ps.cpp \
../ThirdParty/qpcpp/src/qf/qf_qact.cpp \
../ThirdParty/qpcpp/src/qf/qf_qeq.cpp \
../ThirdParty/qpcpp/src/qf/qf_qmact.cpp \
../ThirdParty/qpcpp/src/qf/qf_time.cpp 

OBJS += \
./ThirdParty/qpcpp/src/qf/qep_hsm.o \
./ThirdParty/qpcpp/src/qf/qep_msm.o \
./ThirdParty/qpcpp/src/qf/qf_act.o \
./ThirdParty/qpcpp/src/qf/qf_actq.o \
./ThirdParty/qpcpp/src/qf/qf_defer.o \
./ThirdParty/qpcpp/src/qf/qf_dyn.o \
./ThirdParty/qpcpp/src/qf/qf_mem.o \
./ThirdParty/qpcpp/src/qf/qf_ps.o \
./ThirdParty/qpcpp/src/qf/qf_qact.o \
./ThirdParty/qpcpp/src/qf/qf_qeq.o \
./ThirdParty/qpcpp/src/qf/qf_qmact.o \
./ThirdParty/qpcpp/src/qf/qf_time.o 

CPP_DEPS += \
./ThirdParty/qpcpp/src/qf/qep_hsm.d \
./ThirdParty/qpcpp/src/qf/qep_msm.d \
./ThirdParty/qpcpp/src/qf/qf_act.d \
./ThirdParty/qpcpp/src/qf/qf_actq.d \
./ThirdParty/qpcpp/src/qf/qf_defer.d \
./ThirdParty/qpcpp/src/qf/qf_dyn.d \
./ThirdParty/qpcpp/src/qf/qf_mem.d \
./ThirdParty/qpcpp/src/qf/qf_ps.d \
./ThirdParty/qpcpp/src/qf/qf_qact.d \
./ThirdParty/qpcpp/src/qf/qf_qeq.d \
./ThirdParty/qpcpp/src/qf/qf_qmact.d \
./ThirdParty/qpcpp/src/qf/qf_time.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/qpcpp/src/qf/%.o ThirdParty/qpcpp/src/qf/%.su ThirdParty/qpcpp/src/qf/%.cyclo: ../ThirdParty/qpcpp/src/qf/%.cpp ThirdParty/qpcpp/src/qf/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++20 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -DQP_CONFIG=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I"C:/Repos/Q/WorkSpace/QP/Code" -I"C:/Repos/Q/WorkSpace/QP/BSP" -I"C:/Repos/Q/WorkSpace/QP/ThirdParty/qpcpp/include" -I"C:/Repos/Q/WorkSpace/QP/ThirdParty/qpcpp/ports/arm-cm/qk/gnu" -I"C:/Repos/Q/WorkSpace/QP/Models" -I"C:/Repos/Q/WorkSpace/QP/MCAL" -I"C:/Repos/Q/WorkSpace/QP/MCAL/stm32h5xx" -I"C:/Repos/Q/WorkSpace/QP/APP/TRACER" -I"C:/Repos/Q/WorkSpace/QP/Models/ButtonPressHandler" -I"C:/Repos/Q/WorkSpace/QP/Models/Blinker" -I"C:/Repos/Q/WorkSpace/QP/COMPONENTS" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -save-temps -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-qpcpp-2f-src-2f-qf

clean-ThirdParty-2f-qpcpp-2f-src-2f-qf:
	-$(RM) ./ThirdParty/qpcpp/src/qf/qep_hsm.cyclo ./ThirdParty/qpcpp/src/qf/qep_hsm.d ./ThirdParty/qpcpp/src/qf/qep_hsm.o ./ThirdParty/qpcpp/src/qf/qep_hsm.su ./ThirdParty/qpcpp/src/qf/qep_msm.cyclo ./ThirdParty/qpcpp/src/qf/qep_msm.d ./ThirdParty/qpcpp/src/qf/qep_msm.o ./ThirdParty/qpcpp/src/qf/qep_msm.su ./ThirdParty/qpcpp/src/qf/qf_act.cyclo ./ThirdParty/qpcpp/src/qf/qf_act.d ./ThirdParty/qpcpp/src/qf/qf_act.o ./ThirdParty/qpcpp/src/qf/qf_act.su ./ThirdParty/qpcpp/src/qf/qf_actq.cyclo ./ThirdParty/qpcpp/src/qf/qf_actq.d ./ThirdParty/qpcpp/src/qf/qf_actq.o ./ThirdParty/qpcpp/src/qf/qf_actq.su ./ThirdParty/qpcpp/src/qf/qf_defer.cyclo ./ThirdParty/qpcpp/src/qf/qf_defer.d ./ThirdParty/qpcpp/src/qf/qf_defer.o ./ThirdParty/qpcpp/src/qf/qf_defer.su ./ThirdParty/qpcpp/src/qf/qf_dyn.cyclo ./ThirdParty/qpcpp/src/qf/qf_dyn.d ./ThirdParty/qpcpp/src/qf/qf_dyn.o ./ThirdParty/qpcpp/src/qf/qf_dyn.su ./ThirdParty/qpcpp/src/qf/qf_mem.cyclo ./ThirdParty/qpcpp/src/qf/qf_mem.d ./ThirdParty/qpcpp/src/qf/qf_mem.o ./ThirdParty/qpcpp/src/qf/qf_mem.su ./ThirdParty/qpcpp/src/qf/qf_ps.cyclo ./ThirdParty/qpcpp/src/qf/qf_ps.d ./ThirdParty/qpcpp/src/qf/qf_ps.o ./ThirdParty/qpcpp/src/qf/qf_ps.su ./ThirdParty/qpcpp/src/qf/qf_qact.cyclo ./ThirdParty/qpcpp/src/qf/qf_qact.d ./ThirdParty/qpcpp/src/qf/qf_qact.o ./ThirdParty/qpcpp/src/qf/qf_qact.su ./ThirdParty/qpcpp/src/qf/qf_qeq.cyclo ./ThirdParty/qpcpp/src/qf/qf_qeq.d ./ThirdParty/qpcpp/src/qf/qf_qeq.o ./ThirdParty/qpcpp/src/qf/qf_qeq.su ./ThirdParty/qpcpp/src/qf/qf_qmact.cyclo ./ThirdParty/qpcpp/src/qf/qf_qmact.d ./ThirdParty/qpcpp/src/qf/qf_qmact.o ./ThirdParty/qpcpp/src/qf/qf_qmact.su ./ThirdParty/qpcpp/src/qf/qf_time.cyclo ./ThirdParty/qpcpp/src/qf/qf_time.d ./ThirdParty/qpcpp/src/qf/qf_time.o ./ThirdParty/qpcpp/src/qf/qf_time.su

.PHONY: clean-ThirdParty-2f-qpcpp-2f-src-2f-qf

