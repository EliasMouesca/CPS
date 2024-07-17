CC = gcc
CFLAGS = -Wall -Wextra -ggdb
LDFLAGS =

OBJDIR = obj
SRCDIR = src

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

EXEC = parser

$(EXEC): $(OBJ)
	$(CC) -o $@ $(LDFLAGS) $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm $(OBJDIR)/*

.PHONY: clean



