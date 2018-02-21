################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../algorithms/minimax/heuristic_functions/HeuristicFunction.cpp \
../algorithms/minimax/heuristic_functions/WinnerOrLoser.cpp 

OBJS += \
./algorithms/minimax/heuristic_functions/HeuristicFunction.o \
./algorithms/minimax/heuristic_functions/WinnerOrLoser.o 

CPP_DEPS += \
./algorithms/minimax/heuristic_functions/HeuristicFunction.d \
./algorithms/minimax/heuristic_functions/WinnerOrLoser.d 


# Each subdirectory must supply rules for building sources it contributes
algorithms/minimax/heuristic_functions/%.o: ../algorithms/minimax/heuristic_functions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


