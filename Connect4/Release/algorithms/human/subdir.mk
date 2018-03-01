################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../algorithms/human/Human.cpp 

OBJS += \
./algorithms/human/Human.o 

CPP_DEPS += \
./algorithms/human/Human.d 


# Each subdirectory must supply rules for building sources it contributes
algorithms/human/%.o: ../algorithms/human/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


