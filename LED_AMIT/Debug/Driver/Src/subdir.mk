################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/Src/STM32F407xx_gpio_driver.c 

OBJS += \
./Driver/Src/STM32F407xx_gpio_driver.o 

C_DEPS += \
./Driver/Src/STM32F407xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Src/STM32F407xx_gpio_driver.o: ../Driver/Src/STM32F407xx_gpio_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"D:/embedded/LED_AMIT/Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Driver/Src/STM32F407xx_gpio_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

