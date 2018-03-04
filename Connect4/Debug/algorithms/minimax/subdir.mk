################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../algorithms/minimax/MiniMax.cpp \
../algorithms/minimax/MiniMax_DFS.cpp \
../algorithms/minimax/MiniMax_EIDS.cpp \
../algorithms/minimax/MiniMax_IDS.cpp \
../algorithms/minimax/MiniMax_MaxDepth.cpp 

OBJS += \
./algorithms/minimax/MiniMax.o \
./algorithms/minimax/MiniMax_DFS.o \
./algorithms/minimax/MiniMax_EIDS.o \
./algorithms/minimax/MiniMax_IDS.o \
./algorithms/minimax/MiniMax_MaxDepth.o 

CPP_DEPS += \
./algorithms/minimax/MiniMax.d \
./algorithms/minimax/MiniMax_DFS.d \
./algorithms/minimax/MiniMax_EIDS.d \
./algorithms/minimax/MiniMax_IDS.d \
./algorithms/minimax/MiniMax_MaxDepth.d 


# Each subdirectory must supply rules for building sources it contributes
algorithms/minimax/%.o: ../algorithms/minimax/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


