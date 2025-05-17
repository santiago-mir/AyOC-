CC = gcc
CFLAGS = -Wall -Wextra -pedantic -MMD -MP -g

T ?= binario
T_SRC := $(T).c type.c list.c

# Verificar que el archivo principal existe
ifeq ($(wildcard $(T_SRC)),)
$(error El archivo "$(T_SRC)" no existe)
endif

T_OBJ := $(T_SRC:.c=.o)

all: $(T)

$(T): $(T_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(T_OBJ:.o=.d)

clean:
	rm -f *.o *.d $(T)

.PHONY: all clean

