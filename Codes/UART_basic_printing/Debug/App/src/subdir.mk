################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/src/APP_feature.c \
../App/src/app_main.c 

OBJS += \
./App/src/APP_feature.o \
./App/src/app_main.o 

C_DEPS += \
./App/src/APP_feature.d \
./App/src/app_main.d 


# Each subdirectory must supply rules for building sources it contributes
App/src/%.o App/src/%.su App/src/%.cyclo: ../App/src/%.c App/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/Anas_Embedded system/STM32_Activities/Codes/UART_basic_printing/Services/inc" -I"D:/Anas_Embedded system/STM32_Activities/Codes/UART_basic_printing/App/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-src

clean-App-2f-src:
	-$(RM) ./App/src/APP_feature.cyclo ./App/src/APP_feature.d ./App/src/APP_feature.o ./App/src/APP_feature.su ./App/src/app_main.cyclo ./App/src/app_main.d ./App/src/app_main.o ./App/src/app_main.su

.PHONY: clean-App-2f-src

