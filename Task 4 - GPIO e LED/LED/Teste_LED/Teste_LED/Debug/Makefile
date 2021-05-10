################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../src/ \
../src/ASF/ \
../src/ASF/avr32/ \
../src/ASF/avr32/boards/ \
../src/ASF/avr32/boards/evk1100/ \
../src/ASF/avr32/drivers/ \
../src/ASF/avr32/drivers/gpio/ \
../src/ASF/avr32/drivers/intc/ \
../src/ASF/avr32/utils/ \
../src/ASF/avr32/utils/header_files/ \
../src/ASF/avr32/utils/linker_scripts/ \
../src/ASF/avr32/utils/linker_scripts/at32uc3a/ \
../src/ASF/avr32/utils/linker_scripts/at32uc3a/0512/ \
../src/ASF/avr32/utils/linker_scripts/at32uc3a/0512/gcc/ \
../src/ASF/avr32/utils/make/ \
../src/ASF/avr32/utils/preprocessor/ \
../src/ASF/avr32/utils/startup/ \
../src/ASF/common/ \
../src/ASF/common/boards/ \
../src/ASF/common/utils/ \
../src/ASF/common/utils/interrupt/ \
../src/config/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../src/config/led-driver.c \
../src/ASF/avr32/boards/evk1100/init.c \
../src/ASF/avr32/boards/evk1100/led.c \
../src/ASF/avr32/drivers/gpio/gpio.c \
../src/ASF/avr32/drivers/intc/intc.c \
../src/main.c


PREPROCESSING_SRCS +=  \
../src/ASF/avr32/drivers/intc/exception.S \
../src/ASF/avr32/utils/startup/startup_uc3.S \
../src/ASF/avr32/utils/startup/trampoline_uc3.S


ASM_SRCS += 


OBJS +=  \
src/config/led-driver.o \
src/ASF/avr32/boards/evk1100/init.o \
src/ASF/avr32/boards/evk1100/led.o \
src/ASF/avr32/drivers/gpio/gpio.o \
src/ASF/avr32/drivers/intc/exception.o \
src/ASF/avr32/drivers/intc/intc.o \
src/ASF/avr32/utils/startup/startup_uc3.o \
src/ASF/avr32/utils/startup/trampoline_uc3.o \
src/main.o

OBJS_AS_ARGS +=  \
src/config/led-driver.o \
src/ASF/avr32/boards/evk1100/init.o \
src/ASF/avr32/boards/evk1100/led.o \
src/ASF/avr32/drivers/gpio/gpio.o \
src/ASF/avr32/drivers/intc/exception.o \
src/ASF/avr32/drivers/intc/intc.o \
src/ASF/avr32/utils/startup/startup_uc3.o \
src/ASF/avr32/utils/startup/trampoline_uc3.o \
src/main.o

C_DEPS +=  \
src/config/led-driver.d \
src/ASF/avr32/boards/evk1100/init.d \
src/ASF/avr32/boards/evk1100/led.d \
src/ASF/avr32/drivers/gpio/gpio.d \
src/ASF/avr32/drivers/intc/exception.d \
src/ASF/avr32/drivers/intc/intc.d \
src/ASF/avr32/utils/startup/startup_uc3.d \
src/ASF/avr32/utils/startup/trampoline_uc3.d \
src/main.d

C_DEPS_AS_ARGS +=  \
src/config/led-driver.d \
src/ASF/avr32/boards/evk1100/init.d \
src/ASF/avr32/boards/evk1100/led.d \
src/ASF/avr32/drivers/gpio/gpio.d \
src/ASF/avr32/drivers/intc/exception.d \
src/ASF/avr32/drivers/intc/intc.d \
src/ASF/avr32/utils/startup/startup_uc3.d \
src/ASF/avr32/utils/startup/trampoline_uc3.d \
src/main.d

OUTPUT_FILE_PATH +=Teste_LED.elf

OUTPUT_FILE_PATH_AS_ARGS +=Teste_LED.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+=  \
../src/ASF/avr32/utils/linker_scripts/at32uc3a/0512/gcc/link_uc3a0512.lds


# AVR32/GNU C Compiler













src/config/%.o: ../src/config/%.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__32UC3A0512__ -DDEBUG -DBOARD=EVK1100  -I"../src/ASF/common/boards" -I"../src/ASF/avr32/utils/preprocessor" -I"../src/ASF/avr32/utils" -I"../src/ASF/common/utils" -I"../src/ASF/avr32/drivers/intc" -I"../src/ASF/avr32/boards/evk1100" -I"../src/ASF/avr32/boards" -I"../src/ASF/avr32/drivers/gpio" -I"../src" -I"../src/config"  -O1 -ffunction-sections -mlong-calls -g3 -Wall -mcpu=avr32_uc3 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/boards/evk1100/%.o: ../src/ASF/avr32/boards/evk1100/%.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__32UC3A0512__ -DDEBUG -DBOARD=EVK1100  -I"../src/ASF/common/boards" -I"../src/ASF/avr32/utils/preprocessor" -I"../src/ASF/avr32/utils" -I"../src/ASF/common/utils" -I"../src/ASF/avr32/drivers/intc" -I"../src/ASF/avr32/boards/evk1100" -I"../src/ASF/avr32/boards" -I"../src/ASF/avr32/drivers/gpio" -I"../src" -I"../src/config"  -O1 -ffunction-sections -mlong-calls -g3 -Wall -mcpu=avr32_uc3 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/drivers/gpio/%.o: ../src/ASF/avr32/drivers/gpio/%.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__32UC3A0512__ -DDEBUG -DBOARD=EVK1100  -I"../src/ASF/common/boards" -I"../src/ASF/avr32/utils/preprocessor" -I"../src/ASF/avr32/utils" -I"../src/ASF/common/utils" -I"../src/ASF/avr32/drivers/intc" -I"../src/ASF/avr32/boards/evk1100" -I"../src/ASF/avr32/boards" -I"../src/ASF/avr32/drivers/gpio" -I"../src" -I"../src/config"  -O1 -ffunction-sections -mlong-calls -g3 -Wall -mcpu=avr32_uc3 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/drivers/intc/%.o: ../src/ASF/avr32/drivers/intc/%.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__32UC3A0512__ -DDEBUG -DBOARD=EVK1100  -I"../src/ASF/common/boards" -I"../src/ASF/avr32/utils/preprocessor" -I"../src/ASF/avr32/utils" -I"../src/ASF/common/utils" -I"../src/ASF/avr32/drivers/intc" -I"../src/ASF/avr32/boards/evk1100" -I"../src/ASF/avr32/boards" -I"../src/ASF/avr32/drivers/gpio" -I"../src" -I"../src/config"  -O1 -ffunction-sections -mlong-calls -g3 -Wall -mcpu=avr32_uc3 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -mthumb -D__32UC3A0512__ -DDEBUG -DBOARD=EVK1100  -I"../src/ASF/common/boards" -I"../src/ASF/avr32/utils/preprocessor" -I"../src/ASF/avr32/utils" -I"../src/ASF/common/utils" -I"../src/ASF/avr32/drivers/intc" -I"../src/ASF/avr32/boards/evk1100" -I"../src/ASF/avr32/boards" -I"../src/ASF/avr32/drivers/gpio" -I"../src" -I"../src/config"  -O1 -ffunction-sections -mlong-calls -g3 -Wall -mcpu=avr32_uc3 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler

src/ASF/avr32/drivers/intc/%.o: ../src/ASF/avr32/drivers/intc/%.S
	@echo Building file: $<
	@echo Invoking: ARM/GNU Preprocessing Assembler : 6.3.1
	$(QUOTE)C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE) -mthumb -x assembler-with-cpp -c -mcpu=avr32_uc3 -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/boards/evk1100" -I "../src/ASF/avr32/boards" -I "../src/ASF/avr32/drivers/gpio" -I "../src" -I "../src/config"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -D__32UC3A0512__ -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/drivers/intc/%.o: ../src/ASF/avr32/drivers/intc/%.sx
	@echo Building file: $<
	@echo Invoking: ARM/GNU Preprocessing Assembler : 6.3.1
	$(QUOTE)C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE) -mthumb -x assembler-with-cpp -c -mcpu=avr32_uc3 -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/boards/evk1100" -I "../src/ASF/avr32/boards" -I "../src/ASF/avr32/drivers/gpio" -I "../src" -I "../src/config"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -D__32UC3A0512__ -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/utils/startup/%.o: ../src/ASF/avr32/utils/startup/%.S
	@echo Building file: $<
	@echo Invoking: ARM/GNU Preprocessing Assembler : 6.3.1
	$(QUOTE)C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE) -mthumb -x assembler-with-cpp -c -mcpu=avr32_uc3 -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/boards/evk1100" -I "../src/ASF/avr32/boards" -I "../src/ASF/avr32/drivers/gpio" -I "../src" -I "../src/config"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -D__32UC3A0512__ -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/utils/startup/%.o: ../src/ASF/avr32/utils/startup/%.sx
	@echo Building file: $<
	@echo Invoking: ARM/GNU Preprocessing Assembler : 6.3.1
	$(QUOTE)C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE) -mthumb -x assembler-with-cpp -c -mcpu=avr32_uc3 -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/boards/evk1100" -I "../src/ASF/avr32/boards" -I "../src/ASF/avr32/drivers/gpio" -I "../src" -I "../src/config"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -D__32UC3A0512__ -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Linker : 6.3.1
	$(QUOTE)C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -mthumb -Wl,-Map="Teste_LED.map" -Wl,--start-group -lm  -Wl,--end-group -Wl,--gc-sections -mcpu=avr32_uc3 ($LinkerScript)  
	@echo Finished building target: $@
	"C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O binary "Teste_LED.elf" "Teste_LED.bin"
	"C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "Teste_LED.elf" "Teste_LED.hex"
	"C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O binary "Teste_LED.elf" "Teste_LED.eep" || exit 0
	"C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objdump.exe" -h -S "Teste_LED.elf" > "Teste_LED.lss"
	"C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "Teste_LED.elf" "Teste_LED.srec"
	"C:\Program Files\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-size.exe" "Teste_LED.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Teste_LED.elf" "Teste_LED.a" "Teste_LED.hex" "Teste_LED.bin" "Teste_LED.lss" "Teste_LED.eep" "Teste_LED.map" "Teste_LED.srec"
	