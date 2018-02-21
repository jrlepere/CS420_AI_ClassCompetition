################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../algorithms/minimax/successor_functions/RowByRow.cpp \
../algorithms/minimax/successor_functions/Spiral.cpp 

OBJS += \
./algorithms/minimax/successor_functions/RowByRow.o \
./algorithms/minimax/successor_functions/Spiral.o 

CPP_DEPS += \
./algorithms/minimax/successor_functions/RowByRow.d \
./algorithms/minimax/successor_functions/Spiral.d 


# Each subdirectory must supply rules for building sources it contributes
algorithms/minimax/successor_functions/%.o: ../algorithms/minimax/successor_functions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


