CC = gcc -m32

disass: phase1.o phase2.o phase3.o phase4.o phase5.o
	mkdir -p asm/
	objdump -d phase1.o > asm/phase1.s
	objdump -d phase2.o > asm/phase2.s
	objdump -d phase3.o > asm/phase3.s
	objdump -d phase4.o > asm/phase4.s
	objdump -d phase5.o > asm/phase5.s

clean:
	rm ans/*