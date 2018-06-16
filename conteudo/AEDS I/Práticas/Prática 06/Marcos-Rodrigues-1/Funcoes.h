//typedef int TChave;

typedef struct {
	int chave;
}TItem;

void BubbleSort(TItem *vetor, int n, int *c, int *m);
void SelectionSort(TItem *vetor, int n, int *c, int *m);
void InsertionSort(TItem *vetor, int n, int *c, int *m);