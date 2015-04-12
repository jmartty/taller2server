################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../libs/rocksdb-master/utilities/document/document_db.o \
../libs/rocksdb-master/utilities/document/json_document.o \
../libs/rocksdb-master/utilities/document/json_document_builder.o 

CC_SRCS += \
../libs/rocksdb-master/utilities/document/document_db.cc \
../libs/rocksdb-master/utilities/document/document_db_test.cc \
../libs/rocksdb-master/utilities/document/json_document.cc \
../libs/rocksdb-master/utilities/document/json_document_builder.cc \
../libs/rocksdb-master/utilities/document/json_document_test.cc 

OBJS += \
./libs/rocksdb-master/utilities/document/document_db.o \
./libs/rocksdb-master/utilities/document/document_db_test.o \
./libs/rocksdb-master/utilities/document/json_document.o \
./libs/rocksdb-master/utilities/document/json_document_builder.o \
./libs/rocksdb-master/utilities/document/json_document_test.o 

CC_DEPS += \
./libs/rocksdb-master/utilities/document/document_db.d \
./libs/rocksdb-master/utilities/document/document_db_test.d \
./libs/rocksdb-master/utilities/document/json_document.d \
./libs/rocksdb-master/utilities/document/json_document_builder.d \
./libs/rocksdb-master/utilities/document/json_document_test.d 


# Each subdirectory must supply rules for building sources it contributes
libs/rocksdb-master/utilities/document/%.o: ../libs/rocksdb-master/utilities/document/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


