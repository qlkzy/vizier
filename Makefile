CFLAGS += -g -Wall -Wextra -Werror -std=c99

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

vizier: $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

deps.mk:
	$(CC) $(CPPFLAGS) $(CFLAGS) -MM $(SRC) > deps.mk

.PHONY: clean
clean:
	-rm -f *.o
	-rm -f deps.mk
	-rm -f vizier

-include deps.mk
