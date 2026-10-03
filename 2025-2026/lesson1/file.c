#include <stdio.h>

#define MAX_FILENAME_SIZE 100

int main() {
	
	FILE *pif;
	FILE *pof;
	char ifname[MAX_FILENAME_SIZE];
	char ofname[MAX_FILENAME_SIZE];
	char nl = 1;
	char c;
	char *p;
	char err = 0;
	int cnt;

	// Opening input file
	
	do {
		for (p = ifname; p - ifname < MAX_FILENAME_SIZE; *(p++) = 0);
		*p = '\0';
		printf("Введите имя входного файла\n> ");
		p = ifname;
		err = 0;
		cnt = 0;

		while ((c = getchar()) != '\n') {
			if (cnt++ >= MAX_FILENAME_SIZE) {
				printf("Размер названия файла превышает максимально допустимый\n");
				err = 1;
				break;
			}
			*p = c;
			p++;
		}

		pif = fopen(ifname, "r");
	
		if (pif == NULL) {
			printf("Ошибка открытия файла %s\n", ifname);
			err = 1;
		}

	} while (err);
		

	// Opening output file
	
	do {
		for (p = ofname; p - ofname < MAX_FILENAME_SIZE; *(p++) = 0);
		*p = '\0';
		printf("Введите имя файла для вывода\n> ");
		p = ofname;
		err = 0;
		cnt = 0;

		while ((c = getchar()) != '\n') {
			if (cnt++ >= MAX_FILENAME_SIZE) {
				printf("Размер названия файла превышает максимально допустимый\n");
				err = 1;
				break;
			}
			*p = c;
			p++;
		}

		pof = fopen(ofname, "w");
	
		if (pof == NULL) {
			printf("Ошибка открытия файла %s\n", ifname);
			err = 1;
		}

	} while (err);	

	
	while ((c = fgetc(pif)) != EOF) {
		
		if (c == '\n') {
			nl = 1;
		}
		else if (nl) {
			fputc(c, pof);
			nl = 0;
		}
	}

	printf("Результат записан в %s\n", ofname);

	// Closing files
	
	fclose(pif);
	fclose(pof);
	
	return 0;
}
