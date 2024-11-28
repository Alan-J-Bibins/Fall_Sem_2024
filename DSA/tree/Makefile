all: output/tree.out
	./output/tree.out

output/tree.out: tree.c
	mkdir -p output/
	gcc tree.c -o output/tree.out

clean:
	rm output/*
