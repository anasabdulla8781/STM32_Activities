################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Services/src/STM32_ADC.c \
../Services/src/STM32_GPIO.c \
../Services/src/STM32_GPT.c \
../Services/src/STM32_NVIC.c \
../Services/src/STM32_RCC.c 

OBJS += \
./Services/src/STM32_ADC.o \
./Services/src/STM32_GPIO.o \
./Services/src/STM32_GPT.o \
./Services/src/STM32_NVIC.o \
./Services/src/STM32_RCC.o 

C_DEPS += \
./Services/src/STM32_ADC.d \
./Services/src/STM32_GPIO.d \
./Services/src/STM32_GPT.d \
./Services/src/STM32_NVIC.d \
./Services/src/STM32_RCC.d 


# Each subdirectory must supply rules for building sources it contributes
Services/src/%.o Services/src/%.su Services/src/%.cyclo: ../Services/src/%.c Services/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/Anas_Embedded system/STM32_Activities/Codes/ADC_Temperature_sensor/App/inc" -I"D:/Anas_Embedded system/STM32_Activities/Codes/ADC_Temperature_sensor/Services/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Services-2f-src

clean-Services-2f-src:
	-$(RM) ./Services/src/STM32_ADC.cyclo ./Services/src/STM32_ADC.d ./Services/src/STM32_ADC.o ./Services/src/STM32_ADC.su ./Services/src/STM32_GPIO.cyclo ./Services/src/STM32_GPIO.d ./Services/src/STM32_GPIO.o ./Services/src/STM32_GPIO.su ./Services/src/STM32_GPT.cyclo ./Services/src/STM32_GPT.d ./Services/src/STM32_GPT.o ./Services/src/STM32_GPT.su ./Services/src/STM32_NVIC.cyclo ./Services/src/STM32_NVIC.d ./Services/src/STM32_NVIC.o ./Services/src/STM32_NVIC.su ./Services/src/STM32_RCC.cyclo ./Services/src/STM32_RCC.d ./Services/src/STM32_RCC.o ./Services/src/STM32_RCC.su

.PHONY: clean-Services-2f-src

