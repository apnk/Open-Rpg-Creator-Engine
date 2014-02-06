CPP_SRCS += \
../src/Game.cpp \
../src/main.cpp 

OBJS += \
./src/Game.o \
./src/main.o 

CPP_DEPS += \
./src/Game.d \
./src/main.d 


src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


