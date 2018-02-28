################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../algorithms/minimax/heuristic_functions/AlwaysZero.cpp \
../algorithms/minimax/heuristic_functions/CanWin.cpp \
../algorithms/minimax/heuristic_functions/Disjoint.cpp \
../algorithms/minimax/heuristic_functions/Doubles.cpp \
../algorithms/minimax/heuristic_functions/DoublesAndTriples.cpp \
../algorithms/minimax/heuristic_functions/JakesHeuristic.cpp \
../algorithms/minimax/heuristic_functions/JakesHeuristic2.cpp \
../algorithms/minimax/heuristic_functions/KillerMove1.cpp \
../algorithms/minimax/heuristic_functions/KillerMove2.cpp \
../algorithms/minimax/heuristic_functions/OneAway.cpp \
../algorithms/minimax/heuristic_functions/ToddHeuristic.cpp \
../algorithms/minimax/heuristic_functions/TwoAway.cpp \
../algorithms/minimax/heuristic_functions/WinnerOrLoser.cpp 

OBJS += \
./algorithms/minimax/heuristic_functions/AlwaysZero.o \
./algorithms/minimax/heuristic_functions/CanWin.o \
./algorithms/minimax/heuristic_functions/Disjoint.o \
./algorithms/minimax/heuristic_functions/Doubles.o \
./algorithms/minimax/heuristic_functions/DoublesAndTriples.o \
./algorithms/minimax/heuristic_functions/JakesHeuristic.o \
./algorithms/minimax/heuristic_functions/JakesHeuristic2.o \
./algorithms/minimax/heuristic_functions/KillerMove1.o \
./algorithms/minimax/heuristic_functions/KillerMove2.o \
./algorithms/minimax/heuristic_functions/OneAway.o \
./algorithms/minimax/heuristic_functions/ToddHeuristic.o \
./algorithms/minimax/heuristic_functions/TwoAway.o \
./algorithms/minimax/heuristic_functions/WinnerOrLoser.o 

CPP_DEPS += \
./algorithms/minimax/heuristic_functions/AlwaysZero.d \
./algorithms/minimax/heuristic_functions/CanWin.d \
./algorithms/minimax/heuristic_functions/Disjoint.d \
./algorithms/minimax/heuristic_functions/Doubles.d \
./algorithms/minimax/heuristic_functions/DoublesAndTriples.d \
./algorithms/minimax/heuristic_functions/JakesHeuristic.d \
./algorithms/minimax/heuristic_functions/JakesHeuristic2.d \
./algorithms/minimax/heuristic_functions/KillerMove1.d \
./algorithms/minimax/heuristic_functions/KillerMove2.d \
./algorithms/minimax/heuristic_functions/OneAway.d \
./algorithms/minimax/heuristic_functions/ToddHeuristic.d \
./algorithms/minimax/heuristic_functions/TwoAway.d \
./algorithms/minimax/heuristic_functions/WinnerOrLoser.d 


# Each subdirectory must supply rules for building sources it contributes
algorithms/minimax/heuristic_functions/%.o: ../algorithms/minimax/heuristic_functions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


