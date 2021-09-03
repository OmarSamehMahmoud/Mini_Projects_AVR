################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prog.c \
../Flame_Sensor.c \
../GSM_Sender.c \
../LCD_prg.c \
../USART.c \
../main.c 

OBJS += \
./DIO_prog.o \
./Flame_Sensor.o \
./GSM_Sender.o \
./LCD_prg.o \
./USART.o \
./main.o 

C_DEPS += \
./DIO_prog.d \
./Flame_Sensor.d \
./GSM_Sender.d \
./LCD_prg.d \
./USART.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


