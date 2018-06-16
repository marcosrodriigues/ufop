#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
using namespace std;

#define ORDEM_ASCE 			1
#define ORDEM_DESC 			2
#define ORDEM_RAND 			3

#define SEQUENTIAL_INDEX	1
#define BINARY_TREE		 	2
#define B_TREE           	3
#define B_STAR_TREE		   	4

#define MAX_REGISTER 1000000
#define FILE_EXT ".bin"
#define FILE_NAME "REGISTRO_"

typedef struct {
	int chave;
	long dado1;
	char dado2[500];
}TRegistro;

void shuffle(int *array) {

    int i, j, tmp, upper_bound;

    srand(time(NULL));

    for (i = MAX_REGISTER - 1; i > 0; i--) {

        upper_bound = RAND_MAX - ((RAND_MAX % (i + 1)) + 1);

        do {
            j = rand() % (i + 1);
        } while (j > upper_bound);

        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
    }
}

FILE* makeFile (int situation) {
	char fileName[50];
	sprintf(fileName, "%s%d%s", FILE_NAME, situation, FILE_EXT);
	FILE *file = fopen(fileName, "wb");

	if (file == NULL) {
		cout << "ERROR CODE 587X09KUJ, IMPOSSIBLE TO OPEN THE FILE" << endl;
		return NULL;
	}

	switch(situation) {
		case ORDEM_ASCE:
			for (int i = 0; i < MAX_REGISTER; ++i) {
				TRegistro reg;
				reg.chave = i;
				fwrite(&reg, sizeof(TRegistro), 1, file);
			}
			break;
		case ORDEM_DESC:
			for (int i = MAX_REGISTER; i > 0; --i)	{
				TRegistro reg;
				reg.chave = i;
				fwrite(&reg, sizeof(TRegistro), 1, file);
			}
			break;
		case ORDEM_RAND:
			int *keys = new int[MAX_REGISTER];
			for (int i = 0; i < MAX_REGISTER; ++i) {
				keys[i] = rand() % MAX_REGISTER + 1;	
			}

			shuffle(keys);

            for (int i = 0; i < MAX_REGISTER; i++) {
                TRegistro reg;
                reg.chave = keys[i];
                fwrite(&reg, sizeof(TRegistro), 1, file);
            }
            free (keys);

			break;
	}

	return file;
}

int main(int argc, char const *argv[]) {

	makeFile(1);
	makeFile(2);
	makeFile(3);
	
	return 0;
}