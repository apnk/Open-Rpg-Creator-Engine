CPP_SRCS += \
../src/Character/Character.cpp \
../src/Character/CharacterAnimation.cpp \
../src/Character/CharacterBoundingBox.cpp \
../src/Character/CharacterCoordinates.cpp \
../src/Character/Npc.cpp \
../src/Character/NpcNormal.cpp \
../src/Character/Player.cpp 

OBJS += \
./src/Character/Character.o \
./src/Character/CharacterAnimation.o \
./src/Character/CharacterBoundingBox.o \
./src/Character/CharacterCoordinates.o \
./src/Character/Npc.o \
./src/Character/NpcNormal.o \
./src/Character/Player.o 

CPP_DEPS += \
./src/Character/Character.d \
./src/Character/CharacterAnimation.d \
./src/Character/CharacterBoundingBox.d \
./src/Character/CharacterCoordinates.d \
./src/Character/Npc.d \
./src/Character/NpcNormal.d \
./src/Character/Player.d 


src/Character/%.o: ../src/Character/%.cpp
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"


