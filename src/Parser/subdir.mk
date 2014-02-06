CPP_SRCS += \
../src/Parser/ResourceParser.cpp \
../src/Parser/XMLParserPugi.cpp \
../src/Parser/pugixml.cpp 

OBJS += \
./src/Parser/ResourceParser.o \
./src/Parser/XMLParserPugi.o \
./src/Parser/pugixml.o 

CPP_DEPS += \
./src/Parser/ResourceParser.d \
./src/Parser/XMLParserPugi.d \
./src/Parser/pugixml.d 


src/Parser/%.o: ../src/Parser/%.cpp
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"


