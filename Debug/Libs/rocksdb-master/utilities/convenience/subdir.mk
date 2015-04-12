################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Libs/rocksdb-master/utilities/convenience/convenience.o 

CC_SRCS += \
../Libs/rocksdb-master/utilities/convenience/convenience.cc 

OBJS += \
./Libs/rocksdb-master/utilities/convenience/convenience.o 

CC_DEPS += \
./Libs/rocksdb-master/utilities/convenience/convenience.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/utilities/convenience/%.o: ../Libs/rocksdb-master/utilities/convenience/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


