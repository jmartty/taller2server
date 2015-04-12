################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Libs/rocksdb-master/table/adaptive_table_factory.o \
../Libs/rocksdb-master/table/block.o \
../Libs/rocksdb-master/table/block_based_filter_block.o \
../Libs/rocksdb-master/table/block_based_table_builder.o \
../Libs/rocksdb-master/table/block_based_table_factory.o \
../Libs/rocksdb-master/table/block_based_table_reader.o \
../Libs/rocksdb-master/table/block_builder.o \
../Libs/rocksdb-master/table/block_hash_index.o \
../Libs/rocksdb-master/table/block_prefix_index.o \
../Libs/rocksdb-master/table/bloom_block.o \
../Libs/rocksdb-master/table/cuckoo_table_builder.o \
../Libs/rocksdb-master/table/cuckoo_table_factory.o \
../Libs/rocksdb-master/table/cuckoo_table_reader.o \
../Libs/rocksdb-master/table/flush_block_policy.o \
../Libs/rocksdb-master/table/format.o \
../Libs/rocksdb-master/table/full_filter_block.o \
../Libs/rocksdb-master/table/get_context.o \
../Libs/rocksdb-master/table/iterator.o \
../Libs/rocksdb-master/table/merger.o \
../Libs/rocksdb-master/table/meta_blocks.o \
../Libs/rocksdb-master/table/plain_table_builder.o \
../Libs/rocksdb-master/table/plain_table_factory.o \
../Libs/rocksdb-master/table/plain_table_index.o \
../Libs/rocksdb-master/table/plain_table_key_coding.o \
../Libs/rocksdb-master/table/plain_table_reader.o \
../Libs/rocksdb-master/table/table_properties.o \
../Libs/rocksdb-master/table/two_level_iterator.o 

CC_SRCS += \
../Libs/rocksdb-master/table/adaptive_table_factory.cc \
../Libs/rocksdb-master/table/block.cc \
../Libs/rocksdb-master/table/block_based_filter_block.cc \
../Libs/rocksdb-master/table/block_based_filter_block_test.cc \
../Libs/rocksdb-master/table/block_based_table_builder.cc \
../Libs/rocksdb-master/table/block_based_table_factory.cc \
../Libs/rocksdb-master/table/block_based_table_reader.cc \
../Libs/rocksdb-master/table/block_builder.cc \
../Libs/rocksdb-master/table/block_hash_index.cc \
../Libs/rocksdb-master/table/block_hash_index_test.cc \
../Libs/rocksdb-master/table/block_prefix_index.cc \
../Libs/rocksdb-master/table/block_test.cc \
../Libs/rocksdb-master/table/bloom_block.cc \
../Libs/rocksdb-master/table/cuckoo_table_builder.cc \
../Libs/rocksdb-master/table/cuckoo_table_builder_test.cc \
../Libs/rocksdb-master/table/cuckoo_table_factory.cc \
../Libs/rocksdb-master/table/cuckoo_table_reader.cc \
../Libs/rocksdb-master/table/cuckoo_table_reader_test.cc \
../Libs/rocksdb-master/table/flush_block_policy.cc \
../Libs/rocksdb-master/table/format.cc \
../Libs/rocksdb-master/table/full_filter_block.cc \
../Libs/rocksdb-master/table/full_filter_block_test.cc \
../Libs/rocksdb-master/table/get_context.cc \
../Libs/rocksdb-master/table/iterator.cc \
../Libs/rocksdb-master/table/merger.cc \
../Libs/rocksdb-master/table/merger_test.cc \
../Libs/rocksdb-master/table/meta_blocks.cc \
../Libs/rocksdb-master/table/mock_table.cc \
../Libs/rocksdb-master/table/plain_table_builder.cc \
../Libs/rocksdb-master/table/plain_table_factory.cc \
../Libs/rocksdb-master/table/plain_table_index.cc \
../Libs/rocksdb-master/table/plain_table_key_coding.cc \
../Libs/rocksdb-master/table/plain_table_reader.cc \
../Libs/rocksdb-master/table/table_properties.cc \
../Libs/rocksdb-master/table/table_reader_bench.cc \
../Libs/rocksdb-master/table/table_test.cc \
../Libs/rocksdb-master/table/two_level_iterator.cc 

OBJS += \
./Libs/rocksdb-master/table/adaptive_table_factory.o \
./Libs/rocksdb-master/table/block.o \
./Libs/rocksdb-master/table/block_based_filter_block.o \
./Libs/rocksdb-master/table/block_based_filter_block_test.o \
./Libs/rocksdb-master/table/block_based_table_builder.o \
./Libs/rocksdb-master/table/block_based_table_factory.o \
./Libs/rocksdb-master/table/block_based_table_reader.o \
./Libs/rocksdb-master/table/block_builder.o \
./Libs/rocksdb-master/table/block_hash_index.o \
./Libs/rocksdb-master/table/block_hash_index_test.o \
./Libs/rocksdb-master/table/block_prefix_index.o \
./Libs/rocksdb-master/table/block_test.o \
./Libs/rocksdb-master/table/bloom_block.o \
./Libs/rocksdb-master/table/cuckoo_table_builder.o \
./Libs/rocksdb-master/table/cuckoo_table_builder_test.o \
./Libs/rocksdb-master/table/cuckoo_table_factory.o \
./Libs/rocksdb-master/table/cuckoo_table_reader.o \
./Libs/rocksdb-master/table/cuckoo_table_reader_test.o \
./Libs/rocksdb-master/table/flush_block_policy.o \
./Libs/rocksdb-master/table/format.o \
./Libs/rocksdb-master/table/full_filter_block.o \
./Libs/rocksdb-master/table/full_filter_block_test.o \
./Libs/rocksdb-master/table/get_context.o \
./Libs/rocksdb-master/table/iterator.o \
./Libs/rocksdb-master/table/merger.o \
./Libs/rocksdb-master/table/merger_test.o \
./Libs/rocksdb-master/table/meta_blocks.o \
./Libs/rocksdb-master/table/mock_table.o \
./Libs/rocksdb-master/table/plain_table_builder.o \
./Libs/rocksdb-master/table/plain_table_factory.o \
./Libs/rocksdb-master/table/plain_table_index.o \
./Libs/rocksdb-master/table/plain_table_key_coding.o \
./Libs/rocksdb-master/table/plain_table_reader.o \
./Libs/rocksdb-master/table/table_properties.o \
./Libs/rocksdb-master/table/table_reader_bench.o \
./Libs/rocksdb-master/table/table_test.o \
./Libs/rocksdb-master/table/two_level_iterator.o 

CC_DEPS += \
./Libs/rocksdb-master/table/adaptive_table_factory.d \
./Libs/rocksdb-master/table/block.d \
./Libs/rocksdb-master/table/block_based_filter_block.d \
./Libs/rocksdb-master/table/block_based_filter_block_test.d \
./Libs/rocksdb-master/table/block_based_table_builder.d \
./Libs/rocksdb-master/table/block_based_table_factory.d \
./Libs/rocksdb-master/table/block_based_table_reader.d \
./Libs/rocksdb-master/table/block_builder.d \
./Libs/rocksdb-master/table/block_hash_index.d \
./Libs/rocksdb-master/table/block_hash_index_test.d \
./Libs/rocksdb-master/table/block_prefix_index.d \
./Libs/rocksdb-master/table/block_test.d \
./Libs/rocksdb-master/table/bloom_block.d \
./Libs/rocksdb-master/table/cuckoo_table_builder.d \
./Libs/rocksdb-master/table/cuckoo_table_builder_test.d \
./Libs/rocksdb-master/table/cuckoo_table_factory.d \
./Libs/rocksdb-master/table/cuckoo_table_reader.d \
./Libs/rocksdb-master/table/cuckoo_table_reader_test.d \
./Libs/rocksdb-master/table/flush_block_policy.d \
./Libs/rocksdb-master/table/format.d \
./Libs/rocksdb-master/table/full_filter_block.d \
./Libs/rocksdb-master/table/full_filter_block_test.d \
./Libs/rocksdb-master/table/get_context.d \
./Libs/rocksdb-master/table/iterator.d \
./Libs/rocksdb-master/table/merger.d \
./Libs/rocksdb-master/table/merger_test.d \
./Libs/rocksdb-master/table/meta_blocks.d \
./Libs/rocksdb-master/table/mock_table.d \
./Libs/rocksdb-master/table/plain_table_builder.d \
./Libs/rocksdb-master/table/plain_table_factory.d \
./Libs/rocksdb-master/table/plain_table_index.d \
./Libs/rocksdb-master/table/plain_table_key_coding.d \
./Libs/rocksdb-master/table/plain_table_reader.d \
./Libs/rocksdb-master/table/table_properties.d \
./Libs/rocksdb-master/table/table_reader_bench.d \
./Libs/rocksdb-master/table/table_test.d \
./Libs/rocksdb-master/table/two_level_iterator.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/table/%.o: ../Libs/rocksdb-master/table/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


