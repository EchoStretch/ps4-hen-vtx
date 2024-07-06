CC	:= gcc
OBJCOPY	:= objcopy
ODIR	:= build
SDIR	:= source
IDIR	:= include
MAPFILE := $(shell basename $(CURDIR)).map
CFLAGS	:= -I$(IDIR) -Os -std=gnu11 -fno-builtin -nostartfiles -nostdlib -Wall -masm=intel -march=btver2 -mtune=btver2 -m64 -mabi=sysv -mcmodel=small -fpie
LFLAGS	:= -Xlinker -T ./linker.x -Xlinker -Map=$(MAPFILE) -Wl,--build-id=none
CFILES	:= $(wildcard $(SDIR)/*.c)
OBJS	:= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(CFILES))

TARGET = $(shell basename $(CURDIR)).bin

# Default value for FW if not set
FW ?= 0
CFLAGS += -DFW=$(FW)

$(TARGET): $(ODIR) $(OBJS)
	$(CC) $(ODIR)/*.o -o temp.t $(CFLAGS) $(LFLAGS)
	$(OBJCOPY) -R .payload_bss temp.t temp.u
	$(OBJCOPY) -O binary temp.u $(TARGET)
	rm -f temp.t temp.u

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR):
	@mkdir $@

.PHONY: clean

clean:
	rm -rf $(TARGET) $(MAPFILE) $(ODIR)
