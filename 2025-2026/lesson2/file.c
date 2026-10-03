#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100
#define MAX_WORD_LENGTH 100

int strInArr(char* str, char** str_arr, int str_arr_l) {
	int cnt = 1;

	for (int i = 0; i < str_arr_l - 1; i++) {
		cnt *= strcmp(str, str_arr[i]);
	}
	
	return !cnt;
}

int main() {
	
	FILE* pif;
	FILE* pof;

	char ifname[MAX_FILENAME_SIZE];
	char ofname[MAX_FILENAME_SIZE];

	char* p;
	char c;
	char err;
	int cnt;

	int maxw_len = -1;
	int minw_len = -1;

	char** max_arr;
	char** min_arr;

	int mina_len = 0;
	int maxa_len = 0;
	
	char word[MAX_WORD_LENGTH];
	
	char cur_w_len;

	do {
		err = 0;
		cnt = 0;

		printf("Введите название файла ввода\n> ");
		
		while (((c = getchar()) != '\n') && (cnt < MAX_FILENAME_SIZE))
			ifname[cnt++] = c;
		ifname[cnt] = '\0';
		
		pif = fopen(ifname, "r");
		if (pif == NULL) {
			printf("Ошибка открытия файла %s\n", ifname);
			err = 1;
		}
	} while (err);

	do {
		err = 0;
		cnt = 0;

		printf("Введите названия файла вывода\n> ");

		while (((c = getchar()) != '\n') && (cnt < MAX_FILENAME_SIZE))
			ofname[cnt++] = c;
		ofname[cnt] = '\0';

		pof = fopen(ofname, "w");
		if (pof == NULL) {
			printf("Ошибка открытия файла %s\n", ofname);
			err = 1;
		}
	} while (err);
	
	
	while (fscanf(pif, "%s", word) == 1) {
		cur_w_len = strlen(word);
		
		if ((cur_w_len > maxw_len) || (maxw_len == -1)) {
			maxw_len = cur_w_len;
			
			max_arr = (char**)malloc(sizeof(char*));
			maxa_len = 1;

			max_arr[0] = (char*)malloc(cur_w_len + 1);
			strcpy(max_arr[0], word);
		}
		if ((cur_w_len < minw_len) || (minw_len == -1)) {
			minw_len = cur_w_len;

			min_arr = (char**)malloc(sizeof(char*));
			mina_len = 1;

			min_arr[0] = (char*)malloc(cur_w_len + 1);
			strcpy(min_arr[0], word);
		}

		if (cur_w_len == maxw_len) {
			if (!strInArr(word, max_arr, maxa_len)) {
				max_arr = (char**)realloc(max_arr, sizeof(char*) * (maxa_len + 1));
				max_arr[maxa_len - 1] = (char*)malloc(sizeof(char) * (cur_w_len + 1));
				strcpy(max_arr[maxa_len - 1], word);
				maxa_len++;
			}
		}
		if (cur_w_len == minw_len) {
			if (!strInArr(word, min_arr, mina_len)) {
				min_arr = (char**)realloc(min_arr, sizeof(char*) * (mina_len + 1));
				min_arr[mina_len - 1] = (char*)malloc(sizeof(char) * (cur_w_len + 1));
				strcpy(min_arr[mina_len - 1], word);
				mina_len++;
			}
		}
		
	}
	
	for (c = 0; c < maxa_len - 1; c++) {
		fprintf(pof, "%s ", max_arr[c]);
		free(max_arr[c]);
	}

	fputc('\n', pof);

	for (c = 0; c < mina_len - 1; c++) {
		fprintf(pof, "%s ", min_arr[c]);
		free(min_arr[c]);
	}
	
	free(max_arr);
	free(min_arr);

	fclose(pif);
	fclose(pof);

	printf("Результат работы программы доступен в файле %s\n", ofname);
	return 0;
}
