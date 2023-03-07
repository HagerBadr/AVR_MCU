################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LM35/LM35_PRG.c 

OBJS += \
./HAL/LM35/LM35_PRG.o 

C_DEPS += \
./HAL/LM35/LM35_PRG.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LM35/%.o: ../HAL/LM35/%.c HAL/LM35/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\hager\eclipse-workspace\finaaal\HAL\Buzzer" -I"C:\Users\hager\eclipse-workspace\finaaal\HAL\KeyPad" -I"C:\Users\hager\eclipse-workspace\finaaal\HAL\LCD" -I"C:\Users\hager\eclipse-workspace\finaaal\HAL\LED" -I"C:\Users\hager\eclipse-workspace\finaaal\HAL\LM35" -I"C:\Users\hager\eclipse-workspace\finaaal\HAL\PB" -I"C:\Users\hager\eclipse-workspace\finaaal\HAL\SSD" -I"C:\Users\hager\eclipse-workspace\finaaal\HAL\Ultrasonic" -I"C:\Users\hager\eclipse-workspace\finaaal\LIB" -I"C:\Users\hager\eclipse-workspace\finaaal\MCAL\DIO" -I"C:\Users\hager\eclipse-workspace\finaaal\MCAL\EXTI" -I"C:\Users\hager\eclipse-workspace\finaaal\MCAL\GIE" -I"C:\Users\hager\eclipse-workspace\finaaal\MCAL\TIMER" -I"C:\Users\hager\eclipse-workspace\finaaal\MCAL\TIMER1" -I"C:\Users\hager\eclipse-workspace\finaaal\MCAL\WTD" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


