################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Libs/rocksdb-master/db/builder.o \
../Libs/rocksdb-master/db/c.o \
../Libs/rocksdb-master/db/column_family.o \
../Libs/rocksdb-master/db/compaction.o \
../Libs/rocksdb-master/db/compaction_job.o \
../Libs/rocksdb-master/db/compaction_picker.o \
../Libs/rocksdb-master/db/db_filesnapshot.o \
../Libs/rocksdb-master/db/db_impl.o \
../Libs/rocksdb-master/db/db_impl_debug.o \
../Libs/rocksdb-master/db/db_impl_readonly.o \
../Libs/rocksdb-master/db/db_iter.o \
../Libs/rocksdb-master/db/dbformat.o \
../Libs/rocksdb-master/db/file_indexer.o \
../Libs/rocksdb-master/db/filename.o \
../Libs/rocksdb-master/db/flush_job.o \
../Libs/rocksdb-master/db/flush_scheduler.o \
../Libs/rocksdb-master/db/forward_iterator.o \
../Libs/rocksdb-master/db/internal_stats.o \
../Libs/rocksdb-master/db/log_reader.o \
../Libs/rocksdb-master/db/log_writer.o \
../Libs/rocksdb-master/db/managed_iterator.o \
../Libs/rocksdb-master/db/memtable.o \
../Libs/rocksdb-master/db/memtable_allocator.o \
../Libs/rocksdb-master/db/memtable_list.o \
../Libs/rocksdb-master/db/merge_helper.o \
../Libs/rocksdb-master/db/merge_operator.o \
../Libs/rocksdb-master/db/repair.o \
../Libs/rocksdb-master/db/slice.o \
../Libs/rocksdb-master/db/table_cache.o \
../Libs/rocksdb-master/db/table_properties_collector.o \
../Libs/rocksdb-master/db/transaction_log_impl.o \
../Libs/rocksdb-master/db/version_builder.o \
../Libs/rocksdb-master/db/version_edit.o \
../Libs/rocksdb-master/db/version_set.o \
../Libs/rocksdb-master/db/wal_manager.o \
../Libs/rocksdb-master/db/write_batch.o \
../Libs/rocksdb-master/db/write_batch_base.o \
../Libs/rocksdb-master/db/write_controller.o \
../Libs/rocksdb-master/db/write_thread.o 

C_SRCS += \
../Libs/rocksdb-master/db/c_test.c 

CC_SRCS += \
../Libs/rocksdb-master/db/builder.cc \
../Libs/rocksdb-master/db/c.cc \
../Libs/rocksdb-master/db/column_family.cc \
../Libs/rocksdb-master/db/column_family_test.cc \
../Libs/rocksdb-master/db/compact_files_test.cc \
../Libs/rocksdb-master/db/compaction.cc \
../Libs/rocksdb-master/db/compaction_job.cc \
../Libs/rocksdb-master/db/compaction_job_test.cc \
../Libs/rocksdb-master/db/compaction_picker.cc \
../Libs/rocksdb-master/db/compaction_picker_test.cc \
../Libs/rocksdb-master/db/comparator_db_test.cc \
../Libs/rocksdb-master/db/corruption_test.cc \
../Libs/rocksdb-master/db/cuckoo_table_db_test.cc \
../Libs/rocksdb-master/db/db_bench.cc \
../Libs/rocksdb-master/db/db_filesnapshot.cc \
../Libs/rocksdb-master/db/db_impl.cc \
../Libs/rocksdb-master/db/db_impl_debug.cc \
../Libs/rocksdb-master/db/db_impl_readonly.cc \
../Libs/rocksdb-master/db/db_iter.cc \
../Libs/rocksdb-master/db/db_iter_test.cc \
../Libs/rocksdb-master/db/db_test.cc \
../Libs/rocksdb-master/db/dbformat.cc \
../Libs/rocksdb-master/db/dbformat_test.cc \
../Libs/rocksdb-master/db/deletefile_test.cc \
../Libs/rocksdb-master/db/fault_injection_test.cc \
../Libs/rocksdb-master/db/file_indexer.cc \
../Libs/rocksdb-master/db/file_indexer_test.cc \
../Libs/rocksdb-master/db/filename.cc \
../Libs/rocksdb-master/db/filename_test.cc \
../Libs/rocksdb-master/db/flush_job.cc \
../Libs/rocksdb-master/db/flush_job_test.cc \
../Libs/rocksdb-master/db/flush_scheduler.cc \
../Libs/rocksdb-master/db/forward_iterator.cc \
../Libs/rocksdb-master/db/internal_stats.cc \
../Libs/rocksdb-master/db/listener_test.cc \
../Libs/rocksdb-master/db/log_and_apply_bench.cc \
../Libs/rocksdb-master/db/log_reader.cc \
../Libs/rocksdb-master/db/log_test.cc \
../Libs/rocksdb-master/db/log_writer.cc \
../Libs/rocksdb-master/db/managed_iterator.cc \
../Libs/rocksdb-master/db/memtable.cc \
../Libs/rocksdb-master/db/memtable_allocator.cc \
../Libs/rocksdb-master/db/memtable_list.cc \
../Libs/rocksdb-master/db/memtable_list_test.cc \
../Libs/rocksdb-master/db/memtablerep_bench.cc \
../Libs/rocksdb-master/db/merge_helper.cc \
../Libs/rocksdb-master/db/merge_operator.cc \
../Libs/rocksdb-master/db/merge_test.cc \
../Libs/rocksdb-master/db/perf_context_test.cc \
../Libs/rocksdb-master/db/plain_table_db_test.cc \
../Libs/rocksdb-master/db/prefix_test.cc \
../Libs/rocksdb-master/db/repair.cc \
../Libs/rocksdb-master/db/skiplist_test.cc \
../Libs/rocksdb-master/db/slice.cc \
../Libs/rocksdb-master/db/table_cache.cc \
../Libs/rocksdb-master/db/table_properties_collector.cc \
../Libs/rocksdb-master/db/table_properties_collector_test.cc \
../Libs/rocksdb-master/db/transaction_log_impl.cc \
../Libs/rocksdb-master/db/version_builder.cc \
../Libs/rocksdb-master/db/version_builder_test.cc \
../Libs/rocksdb-master/db/version_edit.cc \
../Libs/rocksdb-master/db/version_edit_test.cc \
../Libs/rocksdb-master/db/version_set.cc \
../Libs/rocksdb-master/db/version_set_test.cc \
../Libs/rocksdb-master/db/wal_manager.cc \
../Libs/rocksdb-master/db/wal_manager_test.cc \
../Libs/rocksdb-master/db/write_batch.cc \
../Libs/rocksdb-master/db/write_batch_base.cc \
../Libs/rocksdb-master/db/write_batch_test.cc \
../Libs/rocksdb-master/db/write_controller.cc \
../Libs/rocksdb-master/db/write_controller_test.cc \
../Libs/rocksdb-master/db/write_thread.cc 

OBJS += \
./Libs/rocksdb-master/db/builder.o \
./Libs/rocksdb-master/db/c.o \
./Libs/rocksdb-master/db/c_test.o \
./Libs/rocksdb-master/db/column_family.o \
./Libs/rocksdb-master/db/column_family_test.o \
./Libs/rocksdb-master/db/compact_files_test.o \
./Libs/rocksdb-master/db/compaction.o \
./Libs/rocksdb-master/db/compaction_job.o \
./Libs/rocksdb-master/db/compaction_job_test.o \
./Libs/rocksdb-master/db/compaction_picker.o \
./Libs/rocksdb-master/db/compaction_picker_test.o \
./Libs/rocksdb-master/db/comparator_db_test.o \
./Libs/rocksdb-master/db/corruption_test.o \
./Libs/rocksdb-master/db/cuckoo_table_db_test.o \
./Libs/rocksdb-master/db/db_bench.o \
./Libs/rocksdb-master/db/db_filesnapshot.o \
./Libs/rocksdb-master/db/db_impl.o \
./Libs/rocksdb-master/db/db_impl_debug.o \
./Libs/rocksdb-master/db/db_impl_readonly.o \
./Libs/rocksdb-master/db/db_iter.o \
./Libs/rocksdb-master/db/db_iter_test.o \
./Libs/rocksdb-master/db/db_test.o \
./Libs/rocksdb-master/db/dbformat.o \
./Libs/rocksdb-master/db/dbformat_test.o \
./Libs/rocksdb-master/db/deletefile_test.o \
./Libs/rocksdb-master/db/fault_injection_test.o \
./Libs/rocksdb-master/db/file_indexer.o \
./Libs/rocksdb-master/db/file_indexer_test.o \
./Libs/rocksdb-master/db/filename.o \
./Libs/rocksdb-master/db/filename_test.o \
./Libs/rocksdb-master/db/flush_job.o \
./Libs/rocksdb-master/db/flush_job_test.o \
./Libs/rocksdb-master/db/flush_scheduler.o \
./Libs/rocksdb-master/db/forward_iterator.o \
./Libs/rocksdb-master/db/internal_stats.o \
./Libs/rocksdb-master/db/listener_test.o \
./Libs/rocksdb-master/db/log_and_apply_bench.o \
./Libs/rocksdb-master/db/log_reader.o \
./Libs/rocksdb-master/db/log_test.o \
./Libs/rocksdb-master/db/log_writer.o \
./Libs/rocksdb-master/db/managed_iterator.o \
./Libs/rocksdb-master/db/memtable.o \
./Libs/rocksdb-master/db/memtable_allocator.o \
./Libs/rocksdb-master/db/memtable_list.o \
./Libs/rocksdb-master/db/memtable_list_test.o \
./Libs/rocksdb-master/db/memtablerep_bench.o \
./Libs/rocksdb-master/db/merge_helper.o \
./Libs/rocksdb-master/db/merge_operator.o \
./Libs/rocksdb-master/db/merge_test.o \
./Libs/rocksdb-master/db/perf_context_test.o \
./Libs/rocksdb-master/db/plain_table_db_test.o \
./Libs/rocksdb-master/db/prefix_test.o \
./Libs/rocksdb-master/db/repair.o \
./Libs/rocksdb-master/db/skiplist_test.o \
./Libs/rocksdb-master/db/slice.o \
./Libs/rocksdb-master/db/table_cache.o \
./Libs/rocksdb-master/db/table_properties_collector.o \
./Libs/rocksdb-master/db/table_properties_collector_test.o \
./Libs/rocksdb-master/db/transaction_log_impl.o \
./Libs/rocksdb-master/db/version_builder.o \
./Libs/rocksdb-master/db/version_builder_test.o \
./Libs/rocksdb-master/db/version_edit.o \
./Libs/rocksdb-master/db/version_edit_test.o \
./Libs/rocksdb-master/db/version_set.o \
./Libs/rocksdb-master/db/version_set_test.o \
./Libs/rocksdb-master/db/wal_manager.o \
./Libs/rocksdb-master/db/wal_manager_test.o \
./Libs/rocksdb-master/db/write_batch.o \
./Libs/rocksdb-master/db/write_batch_base.o \
./Libs/rocksdb-master/db/write_batch_test.o \
./Libs/rocksdb-master/db/write_controller.o \
./Libs/rocksdb-master/db/write_controller_test.o \
./Libs/rocksdb-master/db/write_thread.o 

C_DEPS += \
./Libs/rocksdb-master/db/c_test.d 

CC_DEPS += \
./Libs/rocksdb-master/db/builder.d \
./Libs/rocksdb-master/db/c.d \
./Libs/rocksdb-master/db/column_family.d \
./Libs/rocksdb-master/db/column_family_test.d \
./Libs/rocksdb-master/db/compact_files_test.d \
./Libs/rocksdb-master/db/compaction.d \
./Libs/rocksdb-master/db/compaction_job.d \
./Libs/rocksdb-master/db/compaction_job_test.d \
./Libs/rocksdb-master/db/compaction_picker.d \
./Libs/rocksdb-master/db/compaction_picker_test.d \
./Libs/rocksdb-master/db/comparator_db_test.d \
./Libs/rocksdb-master/db/corruption_test.d \
./Libs/rocksdb-master/db/cuckoo_table_db_test.d \
./Libs/rocksdb-master/db/db_bench.d \
./Libs/rocksdb-master/db/db_filesnapshot.d \
./Libs/rocksdb-master/db/db_impl.d \
./Libs/rocksdb-master/db/db_impl_debug.d \
./Libs/rocksdb-master/db/db_impl_readonly.d \
./Libs/rocksdb-master/db/db_iter.d \
./Libs/rocksdb-master/db/db_iter_test.d \
./Libs/rocksdb-master/db/db_test.d \
./Libs/rocksdb-master/db/dbformat.d \
./Libs/rocksdb-master/db/dbformat_test.d \
./Libs/rocksdb-master/db/deletefile_test.d \
./Libs/rocksdb-master/db/fault_injection_test.d \
./Libs/rocksdb-master/db/file_indexer.d \
./Libs/rocksdb-master/db/file_indexer_test.d \
./Libs/rocksdb-master/db/filename.d \
./Libs/rocksdb-master/db/filename_test.d \
./Libs/rocksdb-master/db/flush_job.d \
./Libs/rocksdb-master/db/flush_job_test.d \
./Libs/rocksdb-master/db/flush_scheduler.d \
./Libs/rocksdb-master/db/forward_iterator.d \
./Libs/rocksdb-master/db/internal_stats.d \
./Libs/rocksdb-master/db/listener_test.d \
./Libs/rocksdb-master/db/log_and_apply_bench.d \
./Libs/rocksdb-master/db/log_reader.d \
./Libs/rocksdb-master/db/log_test.d \
./Libs/rocksdb-master/db/log_writer.d \
./Libs/rocksdb-master/db/managed_iterator.d \
./Libs/rocksdb-master/db/memtable.d \
./Libs/rocksdb-master/db/memtable_allocator.d \
./Libs/rocksdb-master/db/memtable_list.d \
./Libs/rocksdb-master/db/memtable_list_test.d \
./Libs/rocksdb-master/db/memtablerep_bench.d \
./Libs/rocksdb-master/db/merge_helper.d \
./Libs/rocksdb-master/db/merge_operator.d \
./Libs/rocksdb-master/db/merge_test.d \
./Libs/rocksdb-master/db/perf_context_test.d \
./Libs/rocksdb-master/db/plain_table_db_test.d \
./Libs/rocksdb-master/db/prefix_test.d \
./Libs/rocksdb-master/db/repair.d \
./Libs/rocksdb-master/db/skiplist_test.d \
./Libs/rocksdb-master/db/slice.d \
./Libs/rocksdb-master/db/table_cache.d \
./Libs/rocksdb-master/db/table_properties_collector.d \
./Libs/rocksdb-master/db/table_properties_collector_test.d \
./Libs/rocksdb-master/db/transaction_log_impl.d \
./Libs/rocksdb-master/db/version_builder.d \
./Libs/rocksdb-master/db/version_builder_test.d \
./Libs/rocksdb-master/db/version_edit.d \
./Libs/rocksdb-master/db/version_edit_test.d \
./Libs/rocksdb-master/db/version_set.d \
./Libs/rocksdb-master/db/version_set_test.d \
./Libs/rocksdb-master/db/wal_manager.d \
./Libs/rocksdb-master/db/wal_manager_test.d \
./Libs/rocksdb-master/db/write_batch.d \
./Libs/rocksdb-master/db/write_batch_base.d \
./Libs/rocksdb-master/db/write_batch_test.d \
./Libs/rocksdb-master/db/write_controller.d \
./Libs/rocksdb-master/db/write_controller_test.d \
./Libs/rocksdb-master/db/write_thread.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/db/%.o: ../Libs/rocksdb-master/db/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libs/rocksdb-master/db/%.o: ../Libs/rocksdb-master/db/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


