################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../libs/rocksdb-master/java/rocksjni/backupablejni.cc \
../libs/rocksdb-master/java/rocksjni/checkpoint.cc \
../libs/rocksdb-master/java/rocksjni/columnfamilyhandle.cc \
../libs/rocksdb-master/java/rocksjni/comparator.cc \
../libs/rocksdb-master/java/rocksjni/comparatorjnicallback.cc \
../libs/rocksdb-master/java/rocksjni/env.cc \
../libs/rocksdb-master/java/rocksjni/filter.cc \
../libs/rocksdb-master/java/rocksjni/iterator.cc \
../libs/rocksdb-master/java/rocksjni/loggerjnicallback.cc \
../libs/rocksdb-master/java/rocksjni/memtablejni.cc \
../libs/rocksdb-master/java/rocksjni/merge_operator.cc \
../libs/rocksdb-master/java/rocksjni/options.cc \
../libs/rocksdb-master/java/rocksjni/ratelimiterjni.cc \
../libs/rocksdb-master/java/rocksjni/restorejni.cc \
../libs/rocksdb-master/java/rocksjni/rocksjni.cc \
../libs/rocksdb-master/java/rocksjni/slice.cc \
../libs/rocksdb-master/java/rocksjni/snapshot.cc \
../libs/rocksdb-master/java/rocksjni/statistics.cc \
../libs/rocksdb-master/java/rocksjni/table.cc \
../libs/rocksdb-master/java/rocksjni/transaction_log.cc \
../libs/rocksdb-master/java/rocksjni/ttl.cc \
../libs/rocksdb-master/java/rocksjni/write_batch.cc \
../libs/rocksdb-master/java/rocksjni/write_batch_test.cc \
../libs/rocksdb-master/java/rocksjni/write_batch_with_index.cc \
../libs/rocksdb-master/java/rocksjni/writebatchhandlerjnicallback.cc 

OBJS += \
./libs/rocksdb-master/java/rocksjni/backupablejni.o \
./libs/rocksdb-master/java/rocksjni/checkpoint.o \
./libs/rocksdb-master/java/rocksjni/columnfamilyhandle.o \
./libs/rocksdb-master/java/rocksjni/comparator.o \
./libs/rocksdb-master/java/rocksjni/comparatorjnicallback.o \
./libs/rocksdb-master/java/rocksjni/env.o \
./libs/rocksdb-master/java/rocksjni/filter.o \
./libs/rocksdb-master/java/rocksjni/iterator.o \
./libs/rocksdb-master/java/rocksjni/loggerjnicallback.o \
./libs/rocksdb-master/java/rocksjni/memtablejni.o \
./libs/rocksdb-master/java/rocksjni/merge_operator.o \
./libs/rocksdb-master/java/rocksjni/options.o \
./libs/rocksdb-master/java/rocksjni/ratelimiterjni.o \
./libs/rocksdb-master/java/rocksjni/restorejni.o \
./libs/rocksdb-master/java/rocksjni/rocksjni.o \
./libs/rocksdb-master/java/rocksjni/slice.o \
./libs/rocksdb-master/java/rocksjni/snapshot.o \
./libs/rocksdb-master/java/rocksjni/statistics.o \
./libs/rocksdb-master/java/rocksjni/table.o \
./libs/rocksdb-master/java/rocksjni/transaction_log.o \
./libs/rocksdb-master/java/rocksjni/ttl.o \
./libs/rocksdb-master/java/rocksjni/write_batch.o \
./libs/rocksdb-master/java/rocksjni/write_batch_test.o \
./libs/rocksdb-master/java/rocksjni/write_batch_with_index.o \
./libs/rocksdb-master/java/rocksjni/writebatchhandlerjnicallback.o 

CC_DEPS += \
./libs/rocksdb-master/java/rocksjni/backupablejni.d \
./libs/rocksdb-master/java/rocksjni/checkpoint.d \
./libs/rocksdb-master/java/rocksjni/columnfamilyhandle.d \
./libs/rocksdb-master/java/rocksjni/comparator.d \
./libs/rocksdb-master/java/rocksjni/comparatorjnicallback.d \
./libs/rocksdb-master/java/rocksjni/env.d \
./libs/rocksdb-master/java/rocksjni/filter.d \
./libs/rocksdb-master/java/rocksjni/iterator.d \
./libs/rocksdb-master/java/rocksjni/loggerjnicallback.d \
./libs/rocksdb-master/java/rocksjni/memtablejni.d \
./libs/rocksdb-master/java/rocksjni/merge_operator.d \
./libs/rocksdb-master/java/rocksjni/options.d \
./libs/rocksdb-master/java/rocksjni/ratelimiterjni.d \
./libs/rocksdb-master/java/rocksjni/restorejni.d \
./libs/rocksdb-master/java/rocksjni/rocksjni.d \
./libs/rocksdb-master/java/rocksjni/slice.d \
./libs/rocksdb-master/java/rocksjni/snapshot.d \
./libs/rocksdb-master/java/rocksjni/statistics.d \
./libs/rocksdb-master/java/rocksjni/table.d \
./libs/rocksdb-master/java/rocksjni/transaction_log.d \
./libs/rocksdb-master/java/rocksjni/ttl.d \
./libs/rocksdb-master/java/rocksjni/write_batch.d \
./libs/rocksdb-master/java/rocksjni/write_batch_test.d \
./libs/rocksdb-master/java/rocksjni/write_batch_with_index.d \
./libs/rocksdb-master/java/rocksjni/writebatchhandlerjnicallback.d 


# Each subdirectory must supply rules for building sources it contributes
libs/rocksdb-master/java/rocksjni/%.o: ../libs/rocksdb-master/java/rocksjni/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


