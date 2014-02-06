
RM := rm -rf

-include sources.mk
-include src/Utils/subdir.mk
-include src/Parser/subdir.mk
-include src/Map/subdir.mk
-include src/Character/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs
CXXFLAGS+= -std=c++11
all: OpenRpgCreatorEngine 


OpenRpgCreatorEngine: $(OBJS) $(USER_OBJS)
	g++  -o "OpenRpgCreatorEngine" $(OBJS) $(USER_OBJS) $(LIBS) 

clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) OpenRpgCreatorEngine

.PHONY: all clean dependents
