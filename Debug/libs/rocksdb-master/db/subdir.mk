################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../libs/rocksdb-master/db/builder.o \
../libs/rocksdb-master/db/c.o \
../libs/rocksdb-master/db/column_family.o \
../libs/rocksdb-master/db/compaction.o \
../libs/rocksdb-master/db/compaction_job.o \
../libs/rocksdb-master/db/compaction_picker.o \
../libs/rocksdb-master/db/db_filesnapshot.o \
../libs/rocksdb-master/db/db_impl.o \
../libs/rocksdb-master/db/db_impl_debug.o \
../libs/rocksdb-master/db/db_impl_readonly.o \
../libs/rocksdb-master/db/db_iter.o \
../libs/rocksdb-master/db/dbformat.o \
../libs/rocksdb-master/db/file_indexer.o \
../libs/rocksdb-master/db/filename.o \
../libs/rocksdb-master/db/flush_job.o \
../libs/rocksdb-master/db/flush_scheduler.o \
../libs/rocksdb-master/db/forward_iterator.o \
../libs/rocksdb-master/db/internal_stats.o \
../libs/rocksdb-master/db/log_reader.o \
../libs/rocksdb-master/db/log_writer.o \
../libs/rocksdb-master/db/managed_iterator.o \
../libs/rocksdb-master/db/memtable.o \
../libs/rocksdb-master/db/memtable_allocator.o \
../libs/rocksdb-master/db/memtable_list.o \
../libs/rocksdb-master/db/merge_helper.o \
../libs/rocksdb-master/db/merge_operator.o \
../libs/rocksdb-master/db/repair.o \
../libs/rocksdb-master/db/slice.o \
../libs/rocksdb-master/db/table_cache.o \
../libs/rocksdb-master/db/table_properties_collector.o \
../libs/rocksdb-master/db/transaction_log_impl.o \
../libs/rocksdb-master/db/version_builder.o \
../libs/rocksdb-master/db/version_edit.o \
../libs/rocksdb-master/db/version_set.o \
../libs/rocksdb-master/db/wal_manager.o \
../libs/rocksdb-master/db/write_batch.o \
../libs/rocksdb-master/db/write_batch_base.o \
../libs/rocksdb-master/db/write_controller.o \
../libs/rocksdb-master/db/write_thread.o 

C_SRCS += \
../libs/rocksdb-master/db/c_test.c 

CC_SRCS += \
../libs/rocksdb-master/db/builder.cc \
../libs/rocksdb-master/db/c.cc \
../libs/rocksdb-master/db/column_family.cc \
../libs/rocksdb-master/db/column_family_test.cc \
../libs/rocksdb-master/db/compact_files_test.cc \
../libs/rocksdb-master/db/compaction.cc \
../libs/rocksdb-master/db/compaction_job.cc \
../libs/rocksdb-master/db/compaction_job_test.cc \
../libs/rocksdb-master/db/compaction_picker.cc \
../libs/rocksdb-master/db/compaction_picker_test.cc \
../libs/rocksdb-master/db/comparator_db_test.cc \
../libs/rocksdb-master/db/corruption_test.cc \
../libs/rocksdb-master/db/cuckoo_table_db_test.cc \
../libs/rocksdb-master/db/db_bench.cc \
../libs/rocksdb-master/db/db_filesnapshot.cc \
../libs/rocksdb-master/db/db_impl.cc \
../libs/rocksdb-master/db/db_impl_debug.cc \
../libs/rocksdb-master/db/db_impl_readonly.cc \
../libs/rocksdb-master/db/db_iter.cc \
../libs/rocksdb-master/db/db_iter_test.cc \
../libs/rocksdb-master/db/db_test.cc \
../libs/rocksdb-master/db/dbformat.cc \
../libs/rocksdb-master/db/dbformat_test.cc \
../libs/rocksdb-master/db/deletefile_test.cc \
../libs/rocksdb-master/db/fault_injection_test.cc \
../libs/rocksdb-master/db/file_indexer.cc \
../libs/rocksdb-master/db/file_indexer_test.cc \
../libs/rocksdb-master/db/filename.cc \
../libs/rocksdb-master/db/filename_test.cc \
../libs/rocksdb-master/db/flush_job.cc \
../libs/rocksdb-master/db/flush_job_test.cc \
../libs/rocksdb-master/db/flush_scheduler.cc \
../libs/rocksdb-master/db/forward_iterator.cc \
../libs/rocksdb-master/db/internal_stats.cc \
../libs/rocksdb-master/db/listener_test.cc \
../libs/rocksdb-master/db/log_and_apply_bench.cc \
../libs/rocksdb-master/db/log_reader.cc \
../libs/rocksdb-master/db/log_test.cc \
../libs/rocksdb-master/db/log_writer.cc \
../libs/rocksdb-master/db/managed_iterator.cc \
../libs/rocksdb-master/db/memtable.cc \
../libs/rocksdb-master/db/memtable_allocator.cc \
../libs/rocksdb-master/db/memtable_list.cc \
../libs/rocksdb-master/db/memtable_list_test.cc \
../libs/rocksdb-master/db/memtablerep_bench.cc \
../libs/rocksdb-master/db/merge_helper.cc \
../libs/rocksdb-master/db/merge_operator.cc \
../libs/rocksdb-master/db/merge_test.cc \
../libs/rocksdb-master/db/perf_context_test.cc \
../libs/rocksdb-master/db/plain_table_db_test.cc \
../libs/rocksdb-master/db/prefix_test.cc \
../libs/rocksdb-master/db/repair.cc \
../libs/rocksdb-master/db/skiplist_test.cc \
../libs/rocksdb-master/db/slice.cc \
../libs/rocksdb-master/db/table_cache.cc \
../libs/rocksdb-master/db/table_properties_collector.cc \
../libs/rocksdb-master/db/table_properties_collector_test.cc \
../libs/rocksdb-master/db/transaction_log_impl.cc \
../libs/rocksdb-master/db/version_builder.cc \
../libs/rocksdb-master/db/version_builder_test.cc \
../libs/rocksdb-master/db/version_edit.cc \
../libs/rocksdb-master/db/version_edit_test.cc \
../libs/rocksdb-master/db/version_set.cc \
../libs/rocksdb-master/db/version_set_test.cc \
../libs/rocksdb-master/db/wal_manager.cc \
../libs/rocksdb-master/db/wal_manager_test.cc \
../libs/rocksdb-master/db/write_batch.cc \
../libs/rocksdb-master/db/write_batch_base.cc \
../libs/rocksdb-master/db/write_batch_test.cc \
../libs/rocksdb-master/db/write_controller.cc \
../libs/rocksdb-master/db/write_controller_test.cc \
../libs/rocksdb-master/db/write_thread.cc 

OBJS += \
./libs/rocksdb-master/db/builder.o \
./libs/rocksdb-master/db/c.o \
./libs/rocksdb-master/db/c_test.o \
./libs/rocksdb-master/db/column_family.o \
./libs/rocksdb-master/db/column_family_test.o \
./libs/rocksdb-master/db/compact_files_test.o \
./libs/rocksdb-master/db/compaction.o \
./libs/rocksdb-master/db/compaction_job.o \
./libs/rocksdb-master/db/compaction_job_test.o \
./libs/rocksdb-master/db/compaction_picker.o \
./libs/rocksdb-master/db/compaction_picker_test.o \
./libs/rocksdb-master/db/comparator_db_test.o \
./libs/rocksdb-master/db/corruption_test.o \
./libs/rocksdb-master/db/cuckoo_table_db_test.o \
./libs/rocksdb-master/db/db_bench.o \
./libs/rocksdb-master/db/db_filesnapshot.o \
./libs/rocksdb-master/db/db_impl.o \
./libs/rocksdb-master/db/db_impl_debug.o \
./libs/rocksdb-master/db/db_impl_readonly.o \
./libs/rocksdb-master/db/db_iter.o \
./libs/rocksdb-master/db/db_iter_test.o \
./libs/rocksdb-master/db/db_test.o \
./libs/rocksdb-master/db/dbformat.o \
./libs/rocksdb-master/db/dbformat_test.o \
./libs/rocksdb-master/db/deletefile_test.o \
./libs/rocksdb-master/db/fault_injection_test.o \
./libs/rocksdb-master/db/file_indexer.o \
./libs/rocksdb-master/db/file_indexer_test.o \
./libs/rocksdb-master/db/filename.o \
./libs/rocksdb-master/db/filename_test.o \
./libs/rocksdb-master/db/flush_job.o \
./libs/rocksdb-master/db/flush_job_test.o \
./libs/rocksdb-master/db/flush_scheduler.o \
./libs/rocksdb-master/db/forward_iterator.o \
./libs/rocksdb-master/db/internal_stats.o \
./libs/rocksdb-master/db/listener_test.o \
./libs/rocksdb-master/db/log_and_apply_bench.o \
./libs/rocksdb-master/db/log_reader.o \
./libs/rocksdb-master/db/log_test.o \
./libs/rocksdb-master/db/log_writer.o \
./libs/rocksdb-master/db/managed_iterator.o \
./libs/rocksdb-master/db/memtable.o \
./libs/rocksdb-master/db/memtable_allocator.o \
./libs/rocksdb-master/db/memtable_list.o \
./libs/rocksdb-master/db/memtable_list_test.o \
./libs/rocksdb-master/db/memtablerep_bench.o \
./libs/rocksdb-master/db/merge_helper.o \
./libs/rocksdb-master/db/merge_operator.o \
./libs/rocksdb-master/db/merge_test.o \
./libs/rocksdb-master/db/perf_context_test.o \
./libs/rocksdb-master/db/plain_table_db_test.o \
./libs/rocksdb-master/db/prefix_test.o \
./libs/rocksdb-master/db/repair.o \
./libs/rocksdb-master/db/skiplist_test.o \
./libs/rocksdb-master/db/slice.o \
./libs/rocksdb-master/db/table_cache.o \
./libs/rocksdb-master/db/table_properties_collector.o \
./libs/rocksdb-master/db/table_properties_collector_test.o \
./libs/rocksdb-master/db/transaction_log_impl.o \
./libs/rocksdb-master/db/version_builder.o \
./libs/rocksdb-master/db/version_builder_test.o \
./libs/rocksdb-master/db/version_edit.o \
./libs/rocksdb-master/db/version_edit_test.o \
./libs/rocksdb-master/db/version_set.o \
./libs/rocksdb-master/db/version_set_test.o \
./libs/rocksdb-master/db/wal_manager.o \
./libs/rocksdb-master/db/wal_manager_test.o \
./libs/rocksdb-master/db/write_batch.o \
./libs/rocksdb-master/db/write_batch_base.o \
./libs/rocksdb-master/db/write_batch_test.o \
./libs/rocksdb-master/db/write_controller.o \
./libs/rocksdb-master/db/write_controller_test.o \
./libs/rocksdb-master/db/write_thread.o 

C_DEPS += \
./libs/rocksdb-master/db/c_test.d 

CC_DEPS += \
./libs/rocksdb-master/db/builder.d \
./libs/rocksdb-master/db/c.d \
./libs/rocksdb-master/db/column_family.d \
./libs/rocksdb-master/db/column_family_test.d \
./libs/rocksdb-master/db/compact_files_test.d \
./libs/rocksdb-master/db/compaction.d \
./libs/rocksdb-master/db/compaction_job.d \
./libs/rocksdb-master/db/compaction_job_test.d \
./libs/rocksdb-master/db/compaction_picker.d \
./libs/rocksdb-master/db/compaction_picker_test.d \
./libs/rocksdb-master/db/comparator_db_test.d \
./libs/rocksdb-master/db/corruption_test.d \
./libs/rocksdb-master/db/cuckoo_table_db_test.d \
./libs/rocksdb-master/db/db_bench.d \
./libs/rocksdb-master/db/db_filesnapshot.d \
./libs/rocksdb-master/db/db_impl.d \
./libs/rocksdb-master/db/db_impl_debug.d \
./libs/rocksdb-master/db/db_impl_readonly.d \
./libs/rocksdb-master/db/db_iter.d \
./libs/rocksdb-master/db/db_iter_test.d \
./libs/rocksdb-master/db/db_test.d \
./libs/rocksdb-master/db/dbformat.d \
./libs/rocksdb-master/db/dbformat_test.d \
./libs/rocksdb-master/db/deletefile_test.d \
./libs/rocksdb-master/db/fault_injection_test.d \
./libs/rocksdb-master/db/file_indexer.d \
./libs/rocksdb-master/db/file_indexer_test.d \
./libs/rocksdb-master/db/filename.d \
./libs/rocksdb-master/db/filename_test.d \
./libs/rocksdb-master/db/flush_job.d \
./libs/rocksdb-master/db/flush_job_test.d \
./libs/rocksdb-master/db/flush_scheduler.d \
./libs/rocksdb-master/db/forward_iterator.d \
./libs/rocksdb-master/db/internal_stats.d \
./libs/rocksdb-master/db/listener_test.d \
./libs/rocksdb-master/db/log_and_apply_bench.d \
./libs/rocksdb-master/db/log_reader.d \
./libs/rocksdb-master/db/log_test.d \
./libs/rocksdb-master/db/log_writer.d \
./libs/rocksdb-master/db/managed_iterator.d \
./libs/rocksdb-master/db/memtable.d \
./libs/rocksdb-master/db/memtable_allocator.d \
./libs/rocksdb-master/db/memtable_list.d \
./libs/rocksdb-master/db/memtable_list_test.d \
./libs/rocksdb-master/db/memtablerep_bench.d \
./libs/rocksdb-master/db/merge_helper.d \
./libs/rocksdb-master/db/merge_operator.d \
./libs/rocksdb-master/db/merge_test.d \
./libs/rocksdb-master/db/perf_context_test.d \
./libs/rocksdb-master/db/plain_table_db_test.d \
./libs/rocksdb-master/db/prefix_test.d \
./libs/rocksdb-master/db/repair.d \
./libs/rocksdb-master/db/skiplist_test.d \
./libs/rocksdb-master/db/slice.d \
./libs/rocksdb-master/db/table_cache.d \
./libs/rocksdb-master/db/table_properties_collector.d \
./libs/rocksdb-master/db/table_properties_collector_test.d \
./libs/rocksdb-master/db/transaction_log_impl.d \
./libs/rocksdb-master/db/version_builder.d \
./libs/rocksdb-master/db/version_builder_test.d \
./libs/rocksdb-master/db/version_edit.d \
./libs/rocksdb-master/db/version_edit_test.d \
./libs/rocksdb-master/db/version_set.d \
./libs/rocksdb-master/db/version_set_test.d \
./libs/rocksdb-master/db/wal_manager.d \
./libs/rocksdb-master/db/wal_manager_test.d \
./libs/rocksdb-master/db/write_batch.d \
./libs/rocksdb-master/db/write_batch_base.d \
./libs/rocksdb-master/db/write_batch_test.d \
./libs/rocksdb-master/db/write_controller.d \
./libs/rocksdb-master/db/write_controller_test.d \
./libs/rocksdb-master/db/write_thread.d 


# Each subdirectory must supply rules for building sources it contributes
libs/rocksdb-master/db/%.o: ../libs/rocksdb-master/db/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

libs/rocksdb-master/db/%.o: ../libs/rocksdb-master/db/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


