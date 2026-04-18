################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Third_Party/FreeRTOS/portable/MemMang/subdir.mk
-include Third_Party/FreeRTOS/portable/GCC/ARM_CM4F/subdir.mk
-include Third_Party/FreeRTOS/subdir.mk
-include Third_Party/BMP280/src/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Services/src/subdir.mk
-include App/src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := RTOS1_2_Task_with_differant_timings
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
RTOS1_2_Task_with_differant_timings.elf \

MAP_FILES += \
RTOS1_2_Task_with_differant_timings.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
RTOS1_2_Task_with_differant_timings.list \


# All Target
all: main-build

# Main-build Target
main-build: RTOS1_2_Task_with_differant_timings.elf secondary-outputs

# Tool invocations
RTOS1_2_Task_with_differant_timings.elf RTOS1_2_Task_with_differant_timings.map: $(OBJS) $(USER_OBJS) D:\Anas_Embedded\ system\STM32_Activities\Codes\RTOS1_2_Task_with_differant_timings\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "RTOS1_2_Task_with_differant_timings.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\Anas_Embedded system\STM32_Activities\Codes\RTOS1_2_Task_with_differant_timings\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="RTOS1_2_Task_with_differant_timings.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

RTOS1_2_Task_with_differant_timings.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "RTOS1_2_Task_with_differant_timings.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) RTOS1_2_Task_with_differant_timings.elf RTOS1_2_Task_with_differant_timings.list RTOS1_2_Task_with_differant_timings.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
