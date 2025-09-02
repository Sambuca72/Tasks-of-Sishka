# Компилятор
CC = gcc
CFLAGS = -Wall -O2

# Исполняемый файл
TARGET = solution

# Исходные файлы
SRCS = main.c derivative.c
OBJS = $(SRCS:.c=.o)

# Компиляция без `func.c`
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Компиляция с `func.c` (если он есть)
compile_with_func:
	if exist func.c ( $(CC) $(CFLAGS) $(OBJS) func.c -o $(TARGET) ) else \
	echo '#include <stdlib.h>\n double Function(double x) { return x * x - x; }' > func.c && \
	$(CC) $(CFLAGS) $(OBJS) func.c -o $(TARGET) && \
	del func.c

# Компиляция `.c` в `.o`
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка файлов
clean:
	rm -f $(OBJS) $(TARGET)
