################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Libs/rocksdb-master/tools/rdb/db_wrapper.cc \
../Libs/rocksdb-master/tools/rdb/rdb.cc 

OBJS += \
./Libs/rocksdb-master/tools/rdb/db_wrapper.o \
./Libs/rocksdb-master/tools/rdb/rdb.o 

CC_DEPS += \
./Libs/rocksdb-master/tools/rdb/db_wrapper.d \
./Libs/rocksdb-master/tools/rdb/rdb.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/tools/rdb/%.o: ../Libs/rocksdb-master/tools/rdb/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


