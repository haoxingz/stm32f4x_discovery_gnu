###### Toolchain ######
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
AR = arm-none-eabi-ar
AS = arm-none-eabi-as
CP = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump



###### Define building flags ######
PROCESSOR = -mthumb -mcpu=cortex-m4
DFLAGS = -DUSE_STDPERIPH_DRIVER
CFLAGS = -Wall $(PROCESSOR) $(INCLUDE)  
ASFLAGS = $(PROCESSOR)
LDFLAGS = -Wl,--gc-sections $(PROCESSOR) -T$(LINKER_SCRIPT)



###### Frequently used paths ######
PATH_CM4 = ../lib/CMSIS/CM4/
PATH_PERIPH = ../lib/STM32F4xx_StdPeriph_Driver
PATH_DRIVER = ../driver/
PATH_OBJ = ./obj
PATH_BIN = ./bin


###### VPATH is the default seach path for source files ######
SRC_CM4 = $(PATH_CM4)/src
SRC_PERIPH = $(PATH_PERIPH)/src
SRC_DRIVER = $(PATH_DRIVER)/src
SRC_APP = .

VPATH = $(SRC_APP) $(SRC_CM4) $(SRC_PERIPH) $(SRC_DRIVER) 



###### Search paths for header files ######
HEADER_ST = -I$(PATH_CM4)/inc -I$(PATH_PERIPH)/inc
HEADER_DR = -I$(PATH_DRIVER)/inc
HEADER_APP = -I.

INCLUDE = $(HEADER_ST) $(HEADER_DR) $(HEADER_APP)


###### All the scripts ######
LINKER_SCRIPT = ../script/stm32_flash.ld



###### List of object files ######
OBJ_ST = stm32f4xx_gpio.o stm32f4xx_rcc.o system_stm32f4xx.o startup_stm32f4xx.o
OBJ_APP = led.o main.o

OBJ += $(patsubst %, $(PATH_OBJ)/%, $(OBJ_ST))
OBJ += $(patsubst %, $(PATH_OBJ)/%, $(OBJ_APP))

###### Target name #####
IMAGE_NAME = ioToggle
TARGET_HEX = $(PATH_BIN)/$(IMAGE_NAME).hex
TARGET_ELF = $(PATH_BIN)/$(IMAGE_NAME).elf



###### Recipes ######
all: build_directory $(TARGET_HEX)

build_directory: 
	mkdir -p $(PATH_OBJ)
	mkdir -p $(PATH_BIN)


clean:
	rm -rf ./bin ./obj


HEX_CMD = $(CP) $< -O ihex $@
$(TARGET_HEX): $(TARGET_ELF)
	$(HEX_CMD)


LD_CMD = $(CC) $(LDFLAGS) $^ -o $@
$(TARGET_ELF): $(OBJ)
	$(LD_CMD)


AS_CMD = $(AS) $(ASFLAGS) $< -o $@
$(PATH_OBJ)/%.o: %.s
	$(AS_CMD)


CC_CMD = $(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@
$(PATH_OBJ)/%.o: %.c 
	$(CC_CMD)



