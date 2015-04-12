################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Libs/rocksdb-master/port/port_posix.o \
../Libs/rocksdb-master/port/stack_trace.o 

CC_SRCS += \
../Libs/rocksdb-master/port/port_posix.cc \
../Libs/rocksdb-master/port/stack_trace.cc 

OBJS += \
./Libs/rocksdb-master/port/port_posix.o \
./Libs/rocksdb-master/port/stack_trace.o 

CC_DEPS += \
./Libs/rocksdb-master/port/port_posix.d \
./Libs/rocksdb-master/port/stack_trace.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/port/%.o: ../Libs/rocksdb-master/port/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


