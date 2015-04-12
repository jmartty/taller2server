################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include tests/database/subdir.mk
-include src/subdir.mk
-include modules/subdir.mk
-include libs/rocksdb-master/utilities/write_batch_with_index/subdir.mk
-include libs/rocksdb-master/utilities/ttl/subdir.mk
-include libs/rocksdb-master/utilities/spatialdb/subdir.mk
-include libs/rocksdb-master/utilities/redis/subdir.mk
-include libs/rocksdb-master/utilities/merge_operators/string_append/subdir.mk
-include libs/rocksdb-master/utilities/merge_operators/subdir.mk
-include libs/rocksdb-master/utilities/leveldb_options/subdir.mk
-include libs/rocksdb-master/utilities/geodb/subdir.mk
-include libs/rocksdb-master/utilities/flashcache/subdir.mk
-include libs/rocksdb-master/utilities/document/subdir.mk
-include libs/rocksdb-master/utilities/convenience/subdir.mk
-include libs/rocksdb-master/utilities/compacted_db/subdir.mk
-include libs/rocksdb-master/utilities/checkpoint/subdir.mk
-include libs/rocksdb-master/utilities/backupable/subdir.mk
-include libs/rocksdb-master/util/subdir.mk
-include libs/rocksdb-master/tools/rdb/subdir.mk
-include libs/rocksdb-master/tools/subdir.mk
-include libs/rocksdb-master/third-party/gtest-1.7.0/fused-src/gtest/subdir.mk
-include libs/rocksdb-master/table/subdir.mk
-include libs/rocksdb-master/port/subdir.mk
-include libs/rocksdb-master/java/rocksjni/subdir.mk
-include libs/rocksdb-master/examples/subdir.mk
-include libs/rocksdb-master/db/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: taller2server

# Tool invocations
taller2server: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++ -L/home/maxi/git/taller2server/libs/rocksdb-master/include -o "taller2server" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) taller2server
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
