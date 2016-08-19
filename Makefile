CC=g++
CFLAGS=-I. -g
DEPS = *.hh
OBJ = BinarySearchTree.o BinaryTree.o Node.o main.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *.o main
