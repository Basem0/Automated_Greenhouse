################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD.c \
../HAL/MOTOR.c \
../HAL/SPI_EEPROM.c \
../HAL/TFT.c 

OBJS += \
./HAL/LCD.o \
./HAL/MOTOR.o \
./HAL/SPI_EEPROM.o \
./HAL/TFT.o 

C_DEPS += \
./HAL/LCD.d \
./HAL/MOTOR.d \
./HAL/SPI_EEPROM.d \
./HAL/TFT.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103CBTx -DSTM32F1 -c -I../Inc -I"E:/GitHubRepo/Automated_Greenhouse/MCU2/HAL/inc" -I"E:/GitHubRepo/Automated_Greenhouse/MCU2/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/MOTOR.o: ../HAL/MOTOR.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103CBTx -DSTM32F1 -c -I../Inc -I"E:/GitHubRepo/Automated_Greenhouse/MCU2/HAL/inc" -I"E:/GitHubRepo/Automated_Greenhouse/MCU2/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/MOTOR.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/SPI_EEPROM.o: ../HAL/SPI_EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103CBTx -DSTM32F1 -c -I../Inc -I"E:/GitHubRepo/Automated_Greenhouse/MCU2/HAL/inc" -I"E:/GitHubRepo/Automated_Greenhouse/MCU2/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/SPI_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/TFT.o: ../HAL/TFT.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103CBTx -DSTM32F1 -c -I../Inc -I"E:/GitHubRepo/Automated_Greenhouse/MCU2/HAL/inc" -I"E:/GitHubRepo/Automated_Greenhouse/MCU2/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/TFT.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

