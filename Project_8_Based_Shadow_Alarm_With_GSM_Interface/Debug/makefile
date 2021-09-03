################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Project_8_Based_Shadow_Alarm_With_GSM_Interface.lss \

FLASH_IMAGE += \
Project_8_Based_Shadow_Alarm_With_GSM_Interface.hex \

EEPROM_IMAGE += \
Project_8_Based_Shadow_Alarm_With_GSM_Interface.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf secondary-outputs

# Tool invocations
Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Project_8_Based_Shadow_Alarm_With_GSM_Interface.map -mmcu=atmega32 -o "Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Project_8_Based_Shadow_Alarm_With_GSM_Interface.lss: Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf  >"Project_8_Based_Shadow_Alarm_With_GSM_Interface.lss"
	@echo 'Finished building: $@'
	@echo ' '

Project_8_Based_Shadow_Alarm_With_GSM_Interface.hex: Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf  "Project_8_Based_Shadow_Alarm_With_GSM_Interface.hex"
	@echo 'Finished building: $@'
	@echo ' '

Project_8_Based_Shadow_Alarm_With_GSM_Interface.eep: Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf  "Project_8_Based_Shadow_Alarm_With_GSM_Interface.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Project_8_Based_Shadow_Alarm_With_GSM_Interface.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
