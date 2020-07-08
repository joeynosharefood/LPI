#include <stdio.h>
#include <stdlib.h>

int particiona(int *V, int inicio, int final) {
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while (esq < dir) {
        while(V[esq] <= pivo)
            esq++;
        while(V[dir] > pivo)
            dir--;
        if (esq < dir) {
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}
void quickSorted(int *V, int inicio, int fim) {
    int pivo;
    if(fim > inicio) {
        pivo = particiona(V, inicio, fim);
        quickSorted(V, inicio, pivo-1);
        quickSorted(V, pivo+1, fim);
    }
}


int main() {
    int x[5] = {5, 6, 9, 10, 1};
    quickSorted(x, 0, 4);
    for (int i = 0; i < 5; i++) {
        printf("%i ", x[i]);
    }
    return 0;
}
