CC = gcc
CFLAGS = -Wall -Wextra -ggdb
LDFLAGS =

OBJDIR = obj
SRCDIR = src

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

EXEC = cps

$(EXEC): $(OBJDIR) $(OBJ)
	$(CC) -o $@ $(LDFLAGS) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm $(OBJDIR)/*

.PHONY: clean $(OBJDIR)



