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
Project_5_Sun_Glasses_For_Blind_People.lss \

FLASH_IMAGE += \
Project_5_Sun_Glasses_For_Blind_People.hex \

EEPROM_IMAGE += \
Project_5_Sun_Glasses_For_Blind_People.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Project_5_Sun_Glasses_For_Blind_People.elf secondary-outputs

# Tool invocations
Project_5_Sun_Glasses_For_Blind_People.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Project_5_Sun_Glasses_For_Blind_People.map -mmcu=atmega32 -o "Project_5_Sun_Glasses_For_Blind_People.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Project_5_Sun_Glasses_For_Blind_People.lss: Project_5_Sun_Glasses_For_Blind_People.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Project_5_Sun_Glasses_For_Blind_People.elf  >"Project_5_Sun_Glasses_For_Blind_People.lss"
	@echo 'Finished building: $@'
	@echo ' '

Project_5_Sun_Glasses_For_Blind_People.hex: Project_5_Sun_Glasses_For_Blind_People.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Project_5_Sun_Glasses_For_Blind_People.elf  "Project_5_Sun_Glasses_For_Blind_People.hex"
	@echo 'Finished building: $@'
	@echo ' '

Project_5_Sun_Glasses_For_Blind_People.eep: Project_5_Sun_Glasses_For_Blind_People.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Project_5_Sun_Glasses_For_Blind_People.elf  "Project_5_Sun_Glasses_For_Blind_People.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Project_5_Sun_Glasses_For_Blind_People.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Project_5_Sun_Glasses_For_Blind_People.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Project_5_Sun_Glasses_For_Blind_People.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:Project_5_Sun_Glasses_For_Blind_People.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Project_5_Sun_Glasses_For_Blind_People.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
