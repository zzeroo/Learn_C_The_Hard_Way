CC = gcc
CFLAGS =-Wall -g
LDFLAGS =

SOURCES = struct_members_in_structs.c
OBJECTS = $(SOURCES)

EXECUTEABLE = test_sensor

# Zusatzliche Konfig für libmodbus
CFLAGS += `pkg-config --cflags libmodbus`
LDFLAGS += `pkg-config --libs libmodbus`

all: $(SOURCES) $(EXECUTEABLE)

$(EXECUTEABLE): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(CFLAGS) $(LDFLAGS)

clean:
	rm $(OBJECTS) $(EXECUTEABLE)

