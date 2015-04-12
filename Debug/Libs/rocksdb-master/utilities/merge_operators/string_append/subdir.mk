################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Libs/rocksdb-master/utilities/merge_operators/string_append/stringappend.o \
../Libs/rocksdb-master/utilities/merge_operators/string_append/stringappend2.o 

CC_SRCS += \
../Libs/rocksdb-master/utilities/merge_operators/string_append/stringappend.cc \
../Libs/rocksdb-master/utilities/merge_operators/string_append/stringappend2.cc \
../Libs/rocksdb-master/utilities/merge_operators/string_append/stringappend_test.cc 

OBJS += \
./Libs/rocksdb-master/utilities/merge_operators/string_append/stringappend.o \
./Libs/rocksdb-master/utilities/merge_operators/string_append/stringappend2.o \
./Libs/rocksdb-master/utilities/merge_operators/string_append/stringappend_test.o 

CC_DEPS += \
./Libs/rocksdb-master/utilities/merge_operators/string_append/stringappend.d \
./Libs/rocksdb-master/utilities/merge_operators/string_append/stringappend2.d \
./Libs/rocksdb-master/utilities/merge_operators/string_append/stringappend_test.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/utilities/merge_operators/string_append/%.o: ../Libs/rocksdb-master/utilities/merge_operators/string_append/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


