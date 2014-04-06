CFLAGS += -g -Wall -Wextra -Werror -std=c99

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

qlkzy-ai: $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

deps.mk:
	$(CC) $(CPPFLAGS) $(CFLAGS) -MM $(SRC) > deps.mk

-include deps.mk
