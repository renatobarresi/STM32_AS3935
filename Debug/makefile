################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
AS3935_Interface.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
AS3935_Interface.list \


# All Target
all: AS3935_Interface.elf secondary-outputs

# Tool invocations
AS3935_Interface.elf: $(OBJS) $(USER_OBJS) D:\renato\Profesional\facultad\Tesis\Tesis\ Renato\ Barresi\Development\Thesis_workspace\AS3935_Interface\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "AS3935_Interface.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\renato\Profesional\facultad\Tesis\Tesis Renato Barresi\Development\Thesis_workspace\AS3935_Interface\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="AS3935_Interface.map" -Wl,--gc-sections -static -specs=rdimon.specs -lc -lrdimon --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

AS3935_Interface.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "AS3935_Interface.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
