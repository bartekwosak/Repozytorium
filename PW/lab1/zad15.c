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

		printf("- Typ pliku / Prawa dostepu: ");
		printf((S_ISDIR(sb.st_mode)) ? "d" : "-");

		printf((sb.st_mode & S_IRUSR) ? "r" : "-");
		printf((sb.st_mode & S_IWUSR) ? "w" : "-");
		printf((sb.st_mode & S_IXUSR) ? "x" : "-");
	 
		printf((sb.st_mode & S_IRGRP) ? "r" : "-");
		printf((sb.st_mode & S_IWGRP) ? "w" : "-");
		printf((sb.st_mode & S_IXGRP) ? "x" : "-");
	 
		printf((sb.st_mode & S_IROTH) ? "r" : "-");
		printf((sb.st_mode & S_IWOTH) ? "w" : "-");
		printf((sb.st_mode & S_IXOTH) ? "x" : "-");

		printf("- Typ pliku / Prawa dostepu [OCT]: %o\n", sb.st_mode);
		printf("- Numer i-wezla: %lu\n", sb.st_ino);
		printf("- ID urzadzenia zawierającego plik: %lu\n", sb.st_dev);
		printf("- Liczba dowiazan: %lu\n", sb.st_nlink);
		printf("- ID uzytkownika: %hu\n", sb.st_uid);
		printf("- ID grupy: %hu\n", sb.st_gid);
		printf("- ID urzadzenia dla plikow specjalnych: %lu\n", (long)sb.st_rdev);
		printf("- Rozmiar pliku [B]: %ld\n", sb.st_size);
		printf("- Czas ostatniego dostepu: %s", ctime(&sb.st_atime));
		printf("- Czas ostatniej modyfikacji: %s", ctime(&sb.st_mtime));
		printf("- Czas ostatniej zmiany: %s", ctime(&sb.st_ctime));
		printf("- Rozmiar bloku systemu plików [B]: %ld\n", sb.st_blksize);
		printf("- Liczba przydzielonych blokow 512B: %ld\n", sb.st_blocks);
		
	}
	return 0;
}