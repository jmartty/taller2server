################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/database/dataget.cpp \
../tests/database/dataload.cpp 

OBJS += \
./tests/database/dataget.o \
./tests/database/dataload.o 

CPP_DEPS += \
./tests/database/dataget.d \
./tests/database/dataload.d 


# Each subdirectory must supply rules for building sources it contributes
tests/database/%.o: ../tests/database/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


