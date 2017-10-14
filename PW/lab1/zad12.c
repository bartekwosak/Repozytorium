#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
	int i;
	for(i = 0; envp[i] != (char*)0; i++){
		printf("%s\n", envp[i]);
	}
	return 0;
}