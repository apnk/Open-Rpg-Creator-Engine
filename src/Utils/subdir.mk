CPP_SRCS += \
../src/Utils/Timer.cpp \
../src/Utils/draw.cpp \
../src/Utils/other.cpp 

OBJS += \
./src/Utils/Timer.o \
./src/Utils/draw.o \
./src/Utils/other.o 

CPP_DEPS += \
./src/Utils/Timer.d \
./src/Utils/draw.d \
./src/Utils/other.d 


src/Utils/%.o: ../src/Utils/%.cpp
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"


