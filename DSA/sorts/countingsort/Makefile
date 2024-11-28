all: output/countingsort.out
	./output/countingsort.out

output/countingsort.out: countingsort.c
	mkdir -p output/
	gcc countingsort.c -o output/countingsort.out

clean:
	rm output/*
