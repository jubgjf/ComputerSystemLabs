CC = gcc -m32

disass1: phase1.o
	mkdir -p asm/
	objdump -rd phase1.o > asm/phase1.s

disass2: phase2.o
	mkdir -p asm/
	objdump -rd phase2.o > asm/phase2.s

link1: main.o phase1.o
	mkdir -p ans/
	$(CC) -o ans/linkbomb1 main.o phase1.o

link2: main.o phase2.o
	mkdir -p ans/
	$(CC) -o ans/linkbomb2 main.o phase2.o

run1: link1
	./ans/linkbomb1

run2: link2
	./ans/linkbomb2

inject2: inject/inject2.s
	$(CC) -c inject/inject2.s -o inject/inject2.o
	objdump -d inject/inject2.o > inject/inject2.txt

clean:
	rm ans/* asm/* 