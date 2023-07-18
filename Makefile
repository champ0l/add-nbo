CC = gcc
CFLAGS = -Wall -Wextra

TARGET = add-nbo

$(TARGET): add-nbo.c
	$(CC) $(CFLAGS) -o $(TARGET) add-nbo.c

.PHONY: clean
clean:
	rm -f $(TARGET)

