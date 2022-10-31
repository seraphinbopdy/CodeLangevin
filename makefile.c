

CFLAGS = -Wall -g 

prog.exe : ProtectionDati.o Fonction.o File.o 

gcc $(CFLAGS) Fonction.o File.o 

ProtectionDati.o : ProtectionDati.c

> gcc $(CFLAGS) -c Fonction.c
Fonction.o Fonction.c

> gcc $(CFLAGS) -c ProtectionDati.c

> make
