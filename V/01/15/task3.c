#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

int main() {
	occurance_t* occ_class = malloc(sizeof(occurance_t));
	int size = 1;
	char word[300];
	while(1) {
		scanf("%s", word);
		for(int i = 0; i < size; i++) {
			if(occ_class[i].hash == hash(word)) {
				int flag = 0;
				for(int j = 0; j < occ_class[i].times; j++) {
					if(!strcmp(occ_class[i].words[j], word)) {
						flag = 1;
						break;
					}
				}
				if(flag == 1)
					break;
				for(int j = 0; j < strlen(word); j++)
					occ_class[i].words[occ_class[i].times][j] = word[j];
                occ_class[i].words[occ_class[i].times][strlen(word)] = '\0';
				occ_class[i].times++;
				break;
			}
			else if(i == size - 1) {
				occ_class[size-1].times = 0;
				occ_class[size-1].hash = hash(word);
				memset(occ_class[size-1].words, 0, sizeof occ_class[size-1].words);
				for(int j = 0; j < strlen(word); j++)
					occ_class[i].words[occ_class[i].times][j] = word[j];
                occ_class[i].words[occ_class[i].times++][strlen(word)] = '\0';
				occ_class = (occurance_t*)realloc(occ_class, sizeof(occurance_t)*(++size));
				break;
			}
		}
		int break_int = 0;
		for(int i = 0; i < size; i++) {
			if(occ_class[i].times == 4)
				break_int = 1;
		}
		if(break_int == 1)
			break;
	}

	for(int i = 0; i < size - 1; i++) {
		for(int j = 0; j < size - i - 1; j++) {
			if(occ_class[j].hash > occ_class[j+1].hash) {
				occurance_t tmp = occ_class[j];
				occ_class[j] = occ_class[j+1];
				occ_class[j+1] = tmp;
			}
		}
	} 

	for(int i = 0; i < size-1; i++) {
		if(occ_class[i].times >= 2) {
			printf("%ld ", occ_class[i].hash);
			for(int j = 0; j < occ_class[i].times; j++)
				printf("%s ", occ_class[i].words[j]);
			//printf("\n");
		}
	}

	free(occ_class);

	return 0;
}