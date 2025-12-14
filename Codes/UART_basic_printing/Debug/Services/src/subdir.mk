################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Services/src/M4_FPU.c \
../Services/src/M4_SysTick.c \
../Services/src/STM32_ADC.c \
../Services/src/STM32_DBGMCU.c \
../Services/src/STM32_GPIO.c \
../Services/src/STM32_GPT.c \
../Services/src/STM32_IWDG.c \
../Services/src/STM32_NVIC.c \
../Services/src/STM32_RCC.c \
../Services/src/STM32_UART.c 

OBJS += \
./Services/src/M4_FPU.o \
./Services/src/M4_SysTick.o \
./Services/src/STM32_ADC.o \
./Services/src/STM32_DBGMCU.o \
./Services/src/STM32_GPIO.o \
./Services/src/STM32_GPT.o \
./Services/src/STM32_IWDG.o \
./Services/src/STM32_NVIC.o \
./Services/src/STM32_RCC.o \
./Services/src/STM32_UART.o 

C_DEPS += \
./Services/src/M4_FPU.d \
./Services/src/M4_SysTick.d \
./Services/src/STM32_ADC.d \
./Services/src/STM32_DBGMCU.d \
./Services/src/STM32_GPIO.d \
./Services/src/STM32_GPT.d \
./Services/src/STM32_IWDG.d \
./Services/src/STM32_NVIC.d \
./Services/src/STM32_RCC.d \
./Services/src/STM32_UART.d 


# Each subdirectory must supply rules for building sources it contributes
Services/src/%.o Services/src/%.su Services/src/%.cyclo: ../Services/src/%.c Services/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/Anas_Embedded system/STM32_Activities/Codes/UART_basic_printing/Services/inc" -I"D:/Anas_Embedded system/STM32_Activities/Codes/UART_basic_printing/App/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Services-2f-src

clean-Services-2f-src:
	-$(RM) ./Services/src/M4_FPU.cyclo ./Services/src/M4_FPU.d ./Services/src/M4_FPU.o ./Services/src/M4_FPU.su ./Services/src/M4_SysTick.cyclo ./Services/src/M4_SysTick.d ./Services/src/M4_SysTick.o ./Services/src/M4_SysTick.su ./Services/src/STM32_ADC.cyclo ./Services/src/STM32_ADC.d ./Services/src/STM32_ADC.o ./Services/src/STM32_ADC.su ./Services/src/STM32_DBGMCU.cyclo ./Services/src/STM32_DBGMCU.d ./Services/src/STM32_DBGMCU.o ./Services/src/STM32_DBGMCU.su ./Services/src/STM32_GPIO.cyclo ./Services/src/STM32_GPIO.d ./Services/src/STM32_GPIO.o ./Services/src/STM32_GPIO.su ./Services/src/STM32_GPT.cyclo ./Services/src/STM32_GPT.d ./Services/src/STM32_GPT.o ./Services/src/STM32_GPT.su ./Services/src/STM32_IWDG.cyclo ./Services/src/STM32_IWDG.d ./Services/src/STM32_IWDG.o ./Services/src/STM32_IWDG.su ./Services/src/STM32_NVIC.cyclo ./Services/src/STM32_NVIC.d ./Services/src/STM32_NVIC.o ./Services/src/STM32_NVIC.su ./Services/src/STM32_RCC.cyclo ./Services/src/STM32_RCC.d ./Services/src/STM32_RCC.o ./Services/src/STM32_RCC.su ./Services/src/STM32_UART.cyclo ./Services/src/STM32_UART.d ./Services/src/STM32_UART.o ./Services/src/STM32_UART.su

.PHONY: clean-Services-2f-src

