all: output/quicksort.out
	./output/quicksort.out

output/quicksort.out: quicksort.c
	mkdir -p output/
	gcc quicksort.c -o output/quicksort.out

clean:
	rm output/*
