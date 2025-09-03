CC := cc
CFLAGS := -std=c2x -Wall -Wextra -Werror -O2
CPPFLAGS := -Iinclude

SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)
BIN := csh

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

src/%.o: src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean run
clean:
	rm -f $(OBJ) $(BIN)

run: $(BIN)
	./$(BIN)
