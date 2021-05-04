S2O = gcc -Wall -Wextra -m32 -c

bang: bang_inject.s
	$(S2O) bang_inject.s -o bang_inject.o
	objdump -d bang_inject.o > bang_inject_disass.txt

clean:
	rm *.o *.txt