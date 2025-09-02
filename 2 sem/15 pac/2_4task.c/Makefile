# Компилятор
CC = gcc
CFLAGS = -Wall -O2

# Исполняемый файл
TARGET = solution

# Исходные файлы
SRCS = main.c sum.c query.c
OBJS = $(SRCS:.c=.o)

# Сборка программы
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Компиляция каждого .c в .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка скомпилированных файлов
clean:
	rm -f $(OBJS) $(TARGET)
