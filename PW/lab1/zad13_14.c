#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	printf("\n[zad13] ID procesu: %d\n", getpid());
	printf("[zad13] ID procesu macierzystego: %d\n\n", getppid());
	printf("[zad13] Test funkcji getpgrp(): %d\n", getpgrp());
	printf("------------------------------------\n");
	printf("[zad14] ID uzytkownika: %d\n", getuid());
	printf("[zad14] ID grupy: %d\n\n", getgid());
	printf("[zad14] Test funkcji geteuid(): %d\n", geteuid());
	printf("[zad14] Test funkcji getegid(): %d\n\n", getegid());	
	return 0;
}