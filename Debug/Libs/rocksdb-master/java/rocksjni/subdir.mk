################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Libs/rocksdb-master/java/rocksjni/backupablejni.cc \
../Libs/rocksdb-master/java/rocksjni/checkpoint.cc \
../Libs/rocksdb-master/java/rocksjni/columnfamilyhandle.cc \
../Libs/rocksdb-master/java/rocksjni/comparator.cc \
../Libs/rocksdb-master/java/rocksjni/comparatorjnicallback.cc \
../Libs/rocksdb-master/java/rocksjni/env.cc \
../Libs/rocksdb-master/java/rocksjni/filter.cc \
../Libs/rocksdb-master/java/rocksjni/iterator.cc \
../Libs/rocksdb-master/java/rocksjni/loggerjnicallback.cc \
../Libs/rocksdb-master/java/rocksjni/memtablejni.cc \
../Libs/rocksdb-master/java/rocksjni/merge_operator.cc \
../Libs/rocksdb-master/java/rocksjni/options.cc \
../Libs/rocksdb-master/java/rocksjni/ratelimiterjni.cc \
../Libs/rocksdb-master/java/rocksjni/restorejni.cc \
../Libs/rocksdb-master/java/rocksjni/rocksjni.cc \
../Libs/rocksdb-master/java/rocksjni/slice.cc \
../Libs/rocksdb-master/java/rocksjni/snapshot.cc \
../Libs/rocksdb-master/java/rocksjni/statistics.cc \
../Libs/rocksdb-master/java/rocksjni/table.cc \
../Libs/rocksdb-master/java/rocksjni/transaction_log.cc \
../Libs/rocksdb-master/java/rocksjni/ttl.cc \
../Libs/rocksdb-master/java/rocksjni/write_batch.cc \
../Libs/rocksdb-master/java/rocksjni/write_batch_test.cc \
../Libs/rocksdb-master/java/rocksjni/write_batch_with_index.cc \
../Libs/rocksdb-master/java/rocksjni/writebatchhandlerjnicallback.cc 

OBJS += \
./Libs/rocksdb-master/java/rocksjni/backupablejni.o \
./Libs/rocksdb-master/java/rocksjni/checkpoint.o \
./Libs/rocksdb-master/java/rocksjni/columnfamilyhandle.o \
./Libs/rocksdb-master/java/rocksjni/comparator.o \
./Libs/rocksdb-master/java/rocksjni/comparatorjnicallback.o \
./Libs/rocksdb-master/java/rocksjni/env.o \
./Libs/rocksdb-master/java/rocksjni/filter.o \
./Libs/rocksdb-master/java/rocksjni/iterator.o \
./Libs/rocksdb-master/java/rocksjni/loggerjnicallback.o \
./Libs/rocksdb-master/java/rocksjni/memtablejni.o \
./Libs/rocksdb-master/java/rocksjni/merge_operator.o \
./Libs/rocksdb-master/java/rocksjni/options.o \
./Libs/rocksdb-master/java/rocksjni/ratelimiterjni.o \
./Libs/rocksdb-master/java/rocksjni/restorejni.o \
./Libs/rocksdb-master/java/rocksjni/rocksjni.o \
./Libs/rocksdb-master/java/rocksjni/slice.o \
./Libs/rocksdb-master/java/rocksjni/snapshot.o \
./Libs/rocksdb-master/java/rocksjni/statistics.o \
./Libs/rocksdb-master/java/rocksjni/table.o \
./Libs/rocksdb-master/java/rocksjni/transaction_log.o \
./Libs/rocksdb-master/java/rocksjni/ttl.o \
./Libs/rocksdb-master/java/rocksjni/write_batch.o \
./Libs/rocksdb-master/java/rocksjni/write_batch_test.o \
./Libs/rocksdb-master/java/rocksjni/write_batch_with_index.o \
./Libs/rocksdb-master/java/rocksjni/writebatchhandlerjnicallback.o 

CC_DEPS += \
./Libs/rocksdb-master/java/rocksjni/backupablejni.d \
./Libs/rocksdb-master/java/rocksjni/checkpoint.d \
./Libs/rocksdb-master/java/rocksjni/columnfamilyhandle.d \
./Libs/rocksdb-master/java/rocksjni/comparator.d \
./Libs/rocksdb-master/java/rocksjni/comparatorjnicallback.d \
./Libs/rocksdb-master/java/rocksjni/env.d \
./Libs/rocksdb-master/java/rocksjni/filter.d \
./Libs/rocksdb-master/java/rocksjni/iterator.d \
./Libs/rocksdb-master/java/rocksjni/loggerjnicallback.d \
./Libs/rocksdb-master/java/rocksjni/memtablejni.d \
./Libs/rocksdb-master/java/rocksjni/merge_operator.d \
./Libs/rocksdb-master/java/rocksjni/options.d \
./Libs/rocksdb-master/java/rocksjni/ratelimiterjni.d \
./Libs/rocksdb-master/java/rocksjni/restorejni.d \
./Libs/rocksdb-master/java/rocksjni/rocksjni.d \
./Libs/rocksdb-master/java/rocksjni/slice.d \
./Libs/rocksdb-master/java/rocksjni/snapshot.d \
./Libs/rocksdb-master/java/rocksjni/statistics.d \
./Libs/rocksdb-master/java/rocksjni/table.d \
./Libs/rocksdb-master/java/rocksjni/transaction_log.d \
./Libs/rocksdb-master/java/rocksjni/ttl.d \
./Libs/rocksdb-master/java/rocksjni/write_batch.d \
./Libs/rocksdb-master/java/rocksjni/write_batch_test.d \
./Libs/rocksdb-master/java/rocksjni/write_batch_with_index.d \
./Libs/rocksdb-master/java/rocksjni/writebatchhandlerjnicallback.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/java/rocksjni/%.o: ../Libs/rocksdb-master/java/rocksjni/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


