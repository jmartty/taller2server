################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../modules/database.o \
../modules/logger.o 

CPP_SRCS += \
../modules/database.cpp \
../modules/ejemplo.cpp \
../modules/logger.cpp 

OBJS += \
./modules/database.o \
./modules/ejemplo.o \
./modules/logger.o 

CPP_DEPS += \
./modules/database.d \
./modules/ejemplo.d \
./modules/logger.d 


# Each subdirectory must supply rules for building sources it contributes
modules/%.o: ../modules/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


