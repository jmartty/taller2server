################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Libs/rocksdb-master/utilities/checkpoint/checkpoint.o 

CC_SRCS += \
../Libs/rocksdb-master/utilities/checkpoint/checkpoint.cc 

OBJS += \
./Libs/rocksdb-master/utilities/checkpoint/checkpoint.o 

CC_DEPS += \
./Libs/rocksdb-master/utilities/checkpoint/checkpoint.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/utilities/checkpoint/%.o: ../Libs/rocksdb-master/utilities/checkpoint/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


