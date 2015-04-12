################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libs/rocksdb-master/examples/c_simple_example.c 

CC_SRCS += \
../libs/rocksdb-master/examples/column_families_example.cc \
../libs/rocksdb-master/examples/compact_files_example.cc \
../libs/rocksdb-master/examples/simple_example.cc 

OBJS += \
./libs/rocksdb-master/examples/c_simple_example.o \
./libs/rocksdb-master/examples/column_families_example.o \
./libs/rocksdb-master/examples/compact_files_example.o \
./libs/rocksdb-master/examples/simple_example.o 

C_DEPS += \
./libs/rocksdb-master/examples/c_simple_example.d 

CC_DEPS += \
./libs/rocksdb-master/examples/column_families_example.d \
./libs/rocksdb-master/examples/compact_files_example.d \
./libs/rocksdb-master/examples/simple_example.d 


# Each subdirectory must supply rules for building sources it contributes
libs/rocksdb-master/examples/%.o: ../libs/rocksdb-master/examples/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

libs/rocksdb-master/examples/%.o: ../libs/rocksdb-master/examples/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


