################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../libs/rocksdb-master/utilities/compacted_db/compacted_db_impl.o 

CC_SRCS += \
../libs/rocksdb-master/utilities/compacted_db/compacted_db_impl.cc 

OBJS += \
./libs/rocksdb-master/utilities/compacted_db/compacted_db_impl.o 

CC_DEPS += \
./libs/rocksdb-master/utilities/compacted_db/compacted_db_impl.d 


# Each subdirectory must supply rules for building sources it contributes
libs/rocksdb-master/utilities/compacted_db/%.o: ../libs/rocksdb-master/utilities/compacted_db/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


