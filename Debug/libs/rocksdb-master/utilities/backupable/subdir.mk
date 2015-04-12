################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../libs/rocksdb-master/utilities/backupable/backupable_db.o 

CC_SRCS += \
../libs/rocksdb-master/utilities/backupable/backupable_db.cc \
../libs/rocksdb-master/utilities/backupable/backupable_db_test.cc 

OBJS += \
./libs/rocksdb-master/utilities/backupable/backupable_db.o \
./libs/rocksdb-master/utilities/backupable/backupable_db_test.o 

CC_DEPS += \
./libs/rocksdb-master/utilities/backupable/backupable_db.d \
./libs/rocksdb-master/utilities/backupable/backupable_db_test.d 


# Each subdirectory must supply rules for building sources it contributes
libs/rocksdb-master/utilities/backupable/%.o: ../libs/rocksdb-master/utilities/backupable/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


