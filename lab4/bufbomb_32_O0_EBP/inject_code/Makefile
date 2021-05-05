S2O = gcc -Wall -Wextra -m32 -c

bang: bang_inject.s
	$(S2O) bang_inject.s -o bang_inject.o
	objdump -d bang_inject.o > bang_inject_disass.txt

boom: boom_inject.s
	$(S2O) boom_inject.s -o boom_inject.o
	objdump -d boom_inject.o > boom_inject_disass.txt

nitro: nitro_inject.s
	$(S2O) nitro_inject.s -o nitro_inject.o
	objdump -d nitro_inject.o > nitro_inject_disass.txt

clean:
	rm *.o *.txt