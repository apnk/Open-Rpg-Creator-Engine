CPP_SRCS += \
../src/Map/Map.cpp \
../src/Map/Wall.cpp 

OBJS += \
./src/Map/Map.o \
./src/Map/Wall.o 

CPP_DEPS += \
./src/Map/Map.d \
./src/Map/Wall.d 


src/Map/%.o: ../src/Map/%.cpp
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"


