################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Libs/rocksdb-master/utilities/ttl/db_ttl_impl.o 

CC_SRCS += \
../Libs/rocksdb-master/utilities/ttl/db_ttl_impl.cc \
../Libs/rocksdb-master/utilities/ttl/ttl_test.cc 

OBJS += \
./Libs/rocksdb-master/utilities/ttl/db_ttl_impl.o \
./Libs/rocksdb-master/utilities/ttl/ttl_test.o 

CC_DEPS += \
./Libs/rocksdb-master/utilities/ttl/db_ttl_impl.d \
./Libs/rocksdb-master/utilities/ttl/ttl_test.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/utilities/ttl/%.o: ../Libs/rocksdb-master/utilities/ttl/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


