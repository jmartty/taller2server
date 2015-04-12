################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../libs/rocksdb-master/table/adaptive_table_factory.o \
../libs/rocksdb-master/table/block.o \
../libs/rocksdb-master/table/block_based_filter_block.o \
../libs/rocksdb-master/table/block_based_table_builder.o \
../libs/rocksdb-master/table/block_based_table_factory.o \
../libs/rocksdb-master/table/block_based_table_reader.o \
../libs/rocksdb-master/table/block_builder.o \
../libs/rocksdb-master/table/block_hash_index.o \
../libs/rocksdb-master/table/block_prefix_index.o \
../libs/rocksdb-master/table/bloom_block.o \
../libs/rocksdb-master/table/cuckoo_table_builder.o \
../libs/rocksdb-master/table/cuckoo_table_factory.o \
../libs/rocksdb-master/table/cuckoo_table_reader.o \
../libs/rocksdb-master/table/flush_block_policy.o \
../libs/rocksdb-master/table/format.o \
../libs/rocksdb-master/table/full_filter_block.o \
../libs/rocksdb-master/table/get_context.o \
../libs/rocksdb-master/table/iterator.o \
../libs/rocksdb-master/table/merger.o \
../libs/rocksdb-master/table/meta_blocks.o \
../libs/rocksdb-master/table/plain_table_builder.o \
../libs/rocksdb-master/table/plain_table_factory.o \
../libs/rocksdb-master/table/plain_table_index.o \
../libs/rocksdb-master/table/plain_table_key_coding.o \
../libs/rocksdb-master/table/plain_table_reader.o \
../libs/rocksdb-master/table/table_properties.o \
../libs/rocksdb-master/table/two_level_iterator.o 

CC_SRCS += \
../libs/rocksdb-master/table/adaptive_table_factory.cc \
../libs/rocksdb-master/table/block.cc \
../libs/rocksdb-master/table/block_based_filter_block.cc \
../libs/rocksdb-master/table/block_based_filter_block_test.cc \
../libs/rocksdb-master/table/block_based_table_builder.cc \
../libs/rocksdb-master/table/block_based_table_factory.cc \
../libs/rocksdb-master/table/block_based_table_reader.cc \
../libs/rocksdb-master/table/block_builder.cc \
../libs/rocksdb-master/table/block_hash_index.cc \
../libs/rocksdb-master/table/block_hash_index_test.cc \
../libs/rocksdb-master/table/block_prefix_index.cc \
../libs/rocksdb-master/table/block_test.cc \
../libs/rocksdb-master/table/bloom_block.cc \
../libs/rocksdb-master/table/cuckoo_table_builder.cc \
../libs/rocksdb-master/table/cuckoo_table_builder_test.cc \
../libs/rocksdb-master/table/cuckoo_table_factory.cc \
../libs/rocksdb-master/table/cuckoo_table_reader.cc \
../libs/rocksdb-master/table/cuckoo_table_reader_test.cc \
../libs/rocksdb-master/table/flush_block_policy.cc \
../libs/rocksdb-master/table/format.cc \
../libs/rocksdb-master/table/full_filter_block.cc \
../libs/rocksdb-master/table/full_filter_block_test.cc \
../libs/rocksdb-master/table/get_context.cc \
../libs/rocksdb-master/table/iterator.cc \
../libs/rocksdb-master/table/merger.cc \
../libs/rocksdb-master/table/merger_test.cc \
../libs/rocksdb-master/table/meta_blocks.cc \
../libs/rocksdb-master/table/mock_table.cc \
../libs/rocksdb-master/table/plain_table_builder.cc \
../libs/rocksdb-master/table/plain_table_factory.cc \
../libs/rocksdb-master/table/plain_table_index.cc \
../libs/rocksdb-master/table/plain_table_key_coding.cc \
../libs/rocksdb-master/table/plain_table_reader.cc \
../libs/rocksdb-master/table/table_properties.cc \
../libs/rocksdb-master/table/table_reader_bench.cc \
../libs/rocksdb-master/table/table_test.cc \
../libs/rocksdb-master/table/two_level_iterator.cc 

OBJS += \
./libs/rocksdb-master/table/adaptive_table_factory.o \
./libs/rocksdb-master/table/block.o \
./libs/rocksdb-master/table/block_based_filter_block.o \
./libs/rocksdb-master/table/block_based_filter_block_test.o \
./libs/rocksdb-master/table/block_based_table_builder.o \
./libs/rocksdb-master/table/block_based_table_factory.o \
./libs/rocksdb-master/table/block_based_table_reader.o \
./libs/rocksdb-master/table/block_builder.o \
./libs/rocksdb-master/table/block_hash_index.o \
./libs/rocksdb-master/table/block_hash_index_test.o \
./libs/rocksdb-master/table/block_prefix_index.o \
./libs/rocksdb-master/table/block_test.o \
./libs/rocksdb-master/table/bloom_block.o \
./libs/rocksdb-master/table/cuckoo_table_builder.o \
./libs/rocksdb-master/table/cuckoo_table_builder_test.o \
./libs/rocksdb-master/table/cuckoo_table_factory.o \
./libs/rocksdb-master/table/cuckoo_table_reader.o \
./libs/rocksdb-master/table/cuckoo_table_reader_test.o \
./libs/rocksdb-master/table/flush_block_policy.o \
./libs/rocksdb-master/table/format.o \
./libs/rocksdb-master/table/full_filter_block.o \
./libs/rocksdb-master/table/full_filter_block_test.o \
./libs/rocksdb-master/table/get_context.o \
./libs/rocksdb-master/table/iterator.o \
./libs/rocksdb-master/table/merger.o \
./libs/rocksdb-master/table/merger_test.o \
./libs/rocksdb-master/table/meta_blocks.o \
./libs/rocksdb-master/table/mock_table.o \
./libs/rocksdb-master/table/plain_table_builder.o \
./libs/rocksdb-master/table/plain_table_factory.o \
./libs/rocksdb-master/table/plain_table_index.o \
./libs/rocksdb-master/table/plain_table_key_coding.o \
./libs/rocksdb-master/table/plain_table_reader.o \
./libs/rocksdb-master/table/table_properties.o \
./libs/rocksdb-master/table/table_reader_bench.o \
./libs/rocksdb-master/table/table_test.o \
./libs/rocksdb-master/table/two_level_iterator.o 

CC_DEPS += \
./libs/rocksdb-master/table/adaptive_table_factory.d \
./libs/rocksdb-master/table/block.d \
./libs/rocksdb-master/table/block_based_filter_block.d \
./libs/rocksdb-master/table/block_based_filter_block_test.d \
./libs/rocksdb-master/table/block_based_table_builder.d \
./libs/rocksdb-master/table/block_based_table_factory.d \
./libs/rocksdb-master/table/block_based_table_reader.d \
./libs/rocksdb-master/table/block_builder.d \
./libs/rocksdb-master/table/block_hash_index.d \
./libs/rocksdb-master/table/block_hash_index_test.d \
./libs/rocksdb-master/table/block_prefix_index.d \
./libs/rocksdb-master/table/block_test.d \
./libs/rocksdb-master/table/bloom_block.d \
./libs/rocksdb-master/table/cuckoo_table_builder.d \
./libs/rocksdb-master/table/cuckoo_table_builder_test.d \
./libs/rocksdb-master/table/cuckoo_table_factory.d \
./libs/rocksdb-master/table/cuckoo_table_reader.d \
./libs/rocksdb-master/table/cuckoo_table_reader_test.d \
./libs/rocksdb-master/table/flush_block_policy.d \
./libs/rocksdb-master/table/format.d \
./libs/rocksdb-master/table/full_filter_block.d \
./libs/rocksdb-master/table/full_filter_block_test.d \
./libs/rocksdb-master/table/get_context.d \
./libs/rocksdb-master/table/iterator.d \
./libs/rocksdb-master/table/merger.d \
./libs/rocksdb-master/table/merger_test.d \
./libs/rocksdb-master/table/meta_blocks.d \
./libs/rocksdb-master/table/mock_table.d \
./libs/rocksdb-master/table/plain_table_builder.d \
./libs/rocksdb-master/table/plain_table_factory.d \
./libs/rocksdb-master/table/plain_table_index.d \
./libs/rocksdb-master/table/plain_table_key_coding.d \
./libs/rocksdb-master/table/plain_table_reader.d \
./libs/rocksdb-master/table/table_properties.d \
./libs/rocksdb-master/table/table_reader_bench.d \
./libs/rocksdb-master/table/table_test.d \
./libs/rocksdb-master/table/two_level_iterator.d 


# Each subdirectory must supply rules for building sources it contributes
libs/rocksdb-master/table/%.o: ../libs/rocksdb-master/table/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


