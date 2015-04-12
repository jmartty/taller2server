################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Libs/rocksdb-master/utilities/leveldb_options/leveldb_options.o 

CC_SRCS += \
../Libs/rocksdb-master/utilities/leveldb_options/leveldb_options.cc 

OBJS += \
./Libs/rocksdb-master/utilities/leveldb_options/leveldb_options.o 

CC_DEPS += \
./Libs/rocksdb-master/utilities/leveldb_options/leveldb_options.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/utilities/leveldb_options/%.o: ../Libs/rocksdb-master/utilities/leveldb_options/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


