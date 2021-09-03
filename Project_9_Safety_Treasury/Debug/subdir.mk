################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EEPROM_Driver.c \
../GSM_Sender.c \
../LCD.c \
../TWI.c \
../USART.c \
../keybad.c \
../main.c \
../password.c 

OBJS += \
./EEPROM_Driver.o \
./GSM_Sender.o \
./LCD.o \
./TWI.o \
./USART.o \
./keybad.o \
./main.o \
./password.o 

C_DEPS += \
./EEPROM_Driver.d \
./GSM_Sender.d \
./LCD.d \
./TWI.d \
./USART.d \
./keybad.d \
./main.d \
./password.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


