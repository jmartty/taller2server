################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Libs/rocksdb-master/utilities/spatialdb/spatial_db.o 

CC_SRCS += \
../Libs/rocksdb-master/utilities/spatialdb/spatial_db.cc \
../Libs/rocksdb-master/utilities/spatialdb/spatial_db_test.cc 

OBJS += \
./Libs/rocksdb-master/utilities/spatialdb/spatial_db.o \
./Libs/rocksdb-master/utilities/spatialdb/spatial_db_test.o 

CC_DEPS += \
./Libs/rocksdb-master/utilities/spatialdb/spatial_db.d \
./Libs/rocksdb-master/utilities/spatialdb/spatial_db_test.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/rocksdb-master/utilities/spatialdb/%.o: ../Libs/rocksdb-master/utilities/spatialdb/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


