# Definindo variáveis
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = treeSuper
OBJS = main.o treeSuper.o

# Regra padrão para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regras para compilar os arquivos .c em .o
main.o: main.c treeSuper.h
	$(CC) $(CFLAGS) -c main.c

treeSuper.o: treeSuper.c treeSuper.h
	$(CC) $(CFLAGS) -c treeSuper.c

# Regra de limpeza para remover arquivos objeto e executável
clean:
	rm -f $(TARGET) $(OBJS)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)
