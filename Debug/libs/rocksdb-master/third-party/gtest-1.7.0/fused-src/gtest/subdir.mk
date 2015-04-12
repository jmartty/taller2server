################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../libs/rocksdb-master/third-party/gtest-1.7.0/fused-src/gtest/gtest-all.cc 

OBJS += \
./libs/rocksdb-master/third-party/gtest-1.7.0/fused-src/gtest/gtest-all.o 

CC_DEPS += \
./libs/rocksdb-master/third-party/gtest-1.7.0/fused-src/gtest/gtest-all.d 


# Each subdirectory must supply rules for building sources it contributes
libs/rocksdb-master/third-party/gtest-1.7.0/fused-src/gtest/%.o: ../libs/rocksdb-master/third-party/gtest-1.7.0/fused-src/gtest/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


