################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MiniMax/MiniMax_DFS.cpp \
../MiniMax/MiniMax_IDS.cpp \
../MiniMax/MiniMax_MaxDepth.cpp 

OBJS += \
./MiniMax/MiniMax_DFS.o \
./MiniMax/MiniMax_IDS.o \
./MiniMax/MiniMax_MaxDepth.o 

CPP_DEPS += \
./MiniMax/MiniMax_DFS.d \
./MiniMax/MiniMax_IDS.d \
./MiniMax/MiniMax_MaxDepth.d 


# Each subdirectory must supply rules for building sources it contributes
MiniMax/%.o: ../MiniMax/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


