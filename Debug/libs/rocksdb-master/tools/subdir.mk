################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../libs/rocksdb-master/tools/db_repl_stress.cc \
../libs/rocksdb-master/tools/db_sanity_test.cc \
../libs/rocksdb-master/tools/db_stress.cc \
../libs/rocksdb-master/tools/ldb.cc \
../libs/rocksdb-master/tools/reduce_levels_test.cc \
../libs/rocksdb-master/tools/sst_dump.cc 

OBJS += \
./libs/rocksdb-master/tools/db_repl_stress.o \
./libs/rocksdb-master/tools/db_sanity_test.o \
./libs/rocksdb-master/tools/db_stress.o \
./libs/rocksdb-master/tools/ldb.o \
./libs/rocksdb-master/tools/reduce_levels_test.o \
./libs/rocksdb-master/tools/sst_dump.o 

CC_DEPS += \
./libs/rocksdb-master/tools/db_repl_stress.d \
./libs/rocksdb-master/tools/db_sanity_test.d \
./libs/rocksdb-master/tools/db_stress.d \
./libs/rocksdb-master/tools/ldb.d \
./libs/rocksdb-master/tools/reduce_levels_test.d \
./libs/rocksdb-master/tools/sst_dump.d 


# Each subdirectory must supply rules for building sources it contributes
libs/rocksdb-master/tools/%.o: ../libs/rocksdb-master/tools/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


