################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_Party/FreeRTOS/portable/MemMang/heap_1.c 

OBJS += \
./Third_Party/FreeRTOS/portable/MemMang/heap_1.o 

C_DEPS += \
./Third_Party/FreeRTOS/portable/MemMang/heap_1.d 


# Each subdirectory must supply rules for building sources it contributes
Third_Party/FreeRTOS/portable/MemMang/%.o Third_Party/FreeRTOS/portable/MemMang/%.su Third_Party/FreeRTOS/portable/MemMang/%.cyclo: ../Third_Party/FreeRTOS/portable/MemMang/%.c Third_Party/FreeRTOS/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/Anas_Embedded system/STM32_Activities/Codes/RTOS1_2_Task_with_differant_timings/App/inc" -I"D:/Anas_Embedded system/STM32_Activities/Codes/RTOS1_2_Task_with_differant_timings/Services/inc" -I"D:/Anas_Embedded system/STM32_Activities/Codes/RTOS1_2_Task_with_differant_timings/Third_Party/BMP280/inc" -I"D:/Anas_Embedded system/STM32_Activities/Codes/RTOS1_2_Task_with_differant_timings/Third_Party/FreeRTOS/include" -I"D:/Anas_Embedded system/STM32_Activities/Codes/RTOS1_2_Task_with_differant_timings/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third_Party-2f-FreeRTOS-2f-portable-2f-MemMang

clean-Third_Party-2f-FreeRTOS-2f-portable-2f-MemMang:
	-$(RM) ./Third_Party/FreeRTOS/portable/MemMang/heap_1.cyclo ./Third_Party/FreeRTOS/portable/MemMang/heap_1.d ./Third_Party/FreeRTOS/portable/MemMang/heap_1.o ./Third_Party/FreeRTOS/portable/MemMang/heap_1.su

.PHONY: clean-Third_Party-2f-FreeRTOS-2f-portable-2f-MemMang

