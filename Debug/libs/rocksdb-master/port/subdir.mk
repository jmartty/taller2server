################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../libs/rocksdb-master/port/port_posix.o \
../libs/rocksdb-master/port/stack_trace.o 

CC_SRCS += \
../libs/rocksdb-master/port/port_posix.cc \
../libs/rocksdb-master/port/stack_trace.cc 

OBJS += \
./libs/rocksdb-master/port/port_posix.o \
./libs/rocksdb-master/port/stack_trace.o 

CC_DEPS += \
./libs/rocksdb-master/port/port_posix.d \
./libs/rocksdb-master/port/stack_trace.d 


# Each subdirectory must supply rules for building sources it contributes
libs/rocksdb-master/port/%.o: ../libs/rocksdb-master/port/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


