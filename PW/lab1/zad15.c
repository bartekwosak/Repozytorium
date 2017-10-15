#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	if(argc < 2) {
		perror("Wymagany jest parametr sciezki plikow, ktorego nie podano. Nastapi zamkniecie programu.\n");
		return 0;
	}

	struct stat sb;
	int i;

	for(i = 1; i < argc; i++) {
		if(stat(argv[i], &sb) == -1) {
			perror("\nBlad struktury plikow.\n");
			return 0;
		}

		printf("\n");
		printf("Informacje o pliku: %s.", argv[i]);
		printf("\n\n");

		printf("- Typ pliku: ");
		switch(sb.st_mode & S_IFMT) {
			case S_IFBLK: 
				printf("Urzadzenie blokowe\n");
		      		break;
			case S_IFCHR: 
				printf("Urzadzenie znakowe\n");
				break;
			case S_IFDIR:
				printf("Katalog\n");
				break;
			case S_IFIFO:
				printf("FIFO/potok\n");
				break;
			case S_IFLNK: 
				printf("Link symboliczny\n");
				break;
			case S_IFREG: 
				printf("Plik regularny\n");
				break;
			case S_IFSOCK:
			       	printf("Socket\n");
				break;
			default: 
				printf("Nieznany\n");
				break;		
		}

		printf("- Prawa dostepu: ");
		if (sb.st_mode & S_IRUSR)
			printf("r");
		else
			printf("-");
		if (sb.st_mode & S_IWUSR)
			printf("w");
		else
			printf("-");
		if (sb.st_mode & S_IXUSR)
			printf("x");
		else
			printf("-");

		if (sb.st_mode & S_IRGRP)
			printf("r");
		else
			printf("-");
		if (sb.st_mode & S_IWGRP)
			printf("w");
		else
			printf("-");
		if (sb.st_mode & S_IXGRP)
			printf("x");
		else
			printf("-");

		if (sb.st_mode & S_IROTH)
			printf("r");
		else
			printf("-");
		if (sb.st_mode & S_IWOTH)
			printf("w");
		else
			printf("-");
		if (sb.st_mode & S_IXOTH) 
			printf("x\n"); 
		else
			printf("-\n");	

		printf("- Typ pliku / Prawa dostepu [OCT]: %o\n", sb.st_mode);
		printf("- Numer i-wezla: %ld\n", (long)sb.st_ino);
		printf("- ID urzadzenia zawierającego plik: %ld\n", (long)sb.st_dev);
		printf("- Liczba dowiazan: %ld\n", (long)sb.st_nlink);
		printf("- ID uzytkownika: %hu\n", sb.st_uid);
		printf("- ID grupy: %hu\n", sb.st_gid);
		printf("- ID urzadzenia dla plikow specjalnych: %ld\n", (long)sb.st_rdev);
		printf("- Rozmiar pliku [B]: %ld\n", sb.st_size);
		printf("- Czas ostatniego dostepu: %s", ctime(&sb.st_atime));
		printf("- Czas ostatniej modyfikacji: %s", ctime(&sb.st_mtime));
		printf("- Czas ostatniej zmiany: %s", ctime(&sb.st_ctime));
		printf("- Rozmiar bloku systemu plików [B]: %ld\n", sb.st_blksize);
		printf("- Liczba przydzielonych blokow 512B: %ld\n", sb.st_blocks);
		
	}
	return 0;
}