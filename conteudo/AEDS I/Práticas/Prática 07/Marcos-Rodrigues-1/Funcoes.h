//typedef int TChave;

typedef struct {
	int chave;
}TItem;

void BubbleSort(TItem *vetor, int n, int *c, int *m);
void SelectionSort(TItem *vetor, int n, int *c, int *m);
void InsertionSort(TItem *vetor, int n, int *c, int *m);
void MergeSort(TItem *vetor, int n, int *c, int *m);
void mergeSort_ordena(TItem *vetor, int esq, int dir, int *c, int *m);
void mergeSort_intercala(TItem *vetor, int esq, int meio, int dir, int *c, int *m);
void QuickSort(TItem *vetor, int n, int *c, int *m);
void QuickSort_ordena(TItem *vetor, int esq, int dir, int *c, int *m);
void QuickSort_particao(TItem *vetor, int esq, int dir, int *i, int *j, int *c, int *m);
void CopiarVetor(TItem *vetorCopiar, TItem *vetorCopiado, int n);