################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Libs/rocksdb-master/tools/db_repl_stress.cc \
../Libs/rocksdb-master/tools/db_sanity_test.cc \
../Libs/rocksdb-master/tools/db_stress.cc \
../Libs/rocksdb-master/tools/ldb.cc \
../Libs/rocksdb-master/tools/reduce_levels_test.cc \
../Libs/rocksdb-master/tools/sst_dump.cc 

OBJS += \
./Libs/rocksdb-master/tools/db_repl_stress.o \
./Libs/rocksdb-master/tools/db_sanity_test.o \
./Libs/rocksdb-master/tools/db_stress.o \
./Libs/rocksdb-master/tools/ldb.o \
./Libs/rocksdb-master/tools/reduce_levels_test.o \
./Libs/rocksdb-master/tools/sst_dump.o 

CC_DEPS += \
./Libs/rocksdb-master/tools/db_repl_stress.d \
./Libs/rocksdb-master/tools/db_sanity_test.d \
./Libs/rocksdb-master/tools/db_stress.d \
./Libs/rocksdb-master/tools/ldb.d \
./Libs/rocksdb-master/tools/reduce_levels_test.d \
./Libs/rocksdb-master/tools/sst_dump.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/tools/%.o: ../Libs/rocksdb-master/tools/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


