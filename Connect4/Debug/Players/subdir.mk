################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Players/PlayerA.cpp \
../Players/PlayerB.cpp 

OBJS += \
./Players/PlayerA.o \
./Players/PlayerB.o 

CPP_DEPS += \
./Players/PlayerA.d \
./Players/PlayerB.d 


# Each subdirectory must supply rules for building sources it contributes
Players/%.o: ../Players/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


