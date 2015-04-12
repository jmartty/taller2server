################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/rocksdb-master/examples/c_simple_example.c 

CC_SRCS += \
../Libs/rocksdb-master/examples/column_families_example.cc \
../Libs/rocksdb-master/examples/compact_files_example.cc \
../Libs/rocksdb-master/examples/simple_example.cc 

OBJS += \
./Libs/rocksdb-master/examples/c_simple_example.o \
./Libs/rocksdb-master/examples/column_families_example.o \
./Libs/rocksdb-master/examples/compact_files_example.o \
./Libs/rocksdb-master/examples/simple_example.o 

C_DEPS += \
./Libs/rocksdb-master/examples/c_simple_example.d 

CC_DEPS += \
./Libs/rocksdb-master/examples/column_families_example.d \
./Libs/rocksdb-master/examples/compact_files_example.d \
./Libs/rocksdb-master/examples/simple_example.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/examples/%.o: ../Libs/rocksdb-master/examples/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Libs/rocksdb-master/examples/%.o: ../Libs/rocksdb-master/examples/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


