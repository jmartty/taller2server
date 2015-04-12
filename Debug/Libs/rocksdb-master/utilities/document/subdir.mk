################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Libs/rocksdb-master/utilities/document/document_db.o \
../Libs/rocksdb-master/utilities/document/json_document.o \
../Libs/rocksdb-master/utilities/document/json_document_builder.o 

CC_SRCS += \
../Libs/rocksdb-master/utilities/document/document_db.cc \
../Libs/rocksdb-master/utilities/document/document_db_test.cc \
../Libs/rocksdb-master/utilities/document/json_document.cc \
../Libs/rocksdb-master/utilities/document/json_document_builder.cc \
../Libs/rocksdb-master/utilities/document/json_document_test.cc 

OBJS += \
./Libs/rocksdb-master/utilities/document/document_db.o \
./Libs/rocksdb-master/utilities/document/document_db_test.o \
./Libs/rocksdb-master/utilities/document/json_document.o \
./Libs/rocksdb-master/utilities/document/json_document_builder.o \
./Libs/rocksdb-master/utilities/document/json_document_test.o 

CC_DEPS += \
./Libs/rocksdb-master/utilities/document/document_db.d \
./Libs/rocksdb-master/utilities/document/document_db_test.d \
./Libs/rocksdb-master/utilities/document/json_document.d \
./Libs/rocksdb-master/utilities/document/json_document_builder.d \
./Libs/rocksdb-master/utilities/document/json_document_test.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/utilities/document/%.o: ../Libs/rocksdb-master/utilities/document/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


