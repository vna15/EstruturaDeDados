#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>

void selectionSortOP(int** v, int tamanho){
    int* ordenado = (int*) malloc(sizeof(int)*tamanho);
    for(int j = 0; j < tamanho; j++){
        int iMenor = 0;
        for(int i = 0; i < tamanho; i++){
            if((*v)[i] < (*v)[iMenor]){
                iMenor = i;
            }
        }
        ordenado[j] = (*v)[iMenor];
        (*v)[iMenor] = INT_MAX;
    }
    (*v) = ordenado;
}

void selectionSortIP(int* v, int tamanho){
    int i, j;
    for(j = 0; j < tamanho-1; j++){
        int iMenor = j;
        for(i = j+1; i < tamanho; i++){
            if(v[i] < v[iMenor]){
                iMenor = i;
            }
        }
        //troca(v, j, iMenor);
        int temp = v[j];
        v[j] = v[iMenor];
        v[iMenor] = temp;
    }

}

void insertionSortIPV5(int* v, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int valor = v[i];
        int j;
        for (j = i; j > 0 && v[j - 1] > valor; j--) {
            v[j] = v[j - 1];
        }
        v[j] = valor;
    }
}

void bubbleSort(int* v, int n){
    for(int varredura = 0; varredura < n-1; varredura++){
        bool trocou = false;
        for(int i = 0; i < n-varredura-1; i++){
            if(v[i]>v[i+1]){
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                trocou = true;
            }
        }
        if(trocou==false)
            return;
    }
}

void merge(int* v, int* e, int tamE, int* d, int tamD){
    int indexV = 0;
    int indexE = 0;
    int indexD = 0;
    while(indexE < tamE && indexD < tamD){
        if(e[indexE] <= d[indexD]){
            v[indexV] = e[indexE];
            indexE++;
        } else{
            v[indexV] = d[indexD];
            indexD++;
        }
        indexV++;
    }
    //ainda poderíamos ter elementos no vetor E que não foram copiados para V
    while(indexE < tamE){
        v[indexV] = e[indexE];
        indexE++;
        indexV++;
    }
    //ainda poderíamos ter elementos no vetor D que não foram copiados para V
    while(indexD < tamD){
        v[indexV] = d[indexD];
        indexD++;
        indexV++;
    }
}

void mergeSort(int* v, int tamV){
    if(tamV>1){
        //primeiro quebramos o vetor em 2 vetores menores
        int meio = tamV/2;

        int tamV1 = meio;
        int* v1 = (int*)malloc(tamV1*sizeof(int));
        for(int i = 0; i < meio; i++){
            v1[i] = v[i];
        }

        int tamV2 = tamV-meio;
        int* v2 = (int*)malloc(tamV2*sizeof(int));
        for(int i = meio; i < tamV; i++){
            v2[i-meio] = v[i];
        }

        mergeSort(v1,tamV1);
        mergeSort(v2,tamV2);
        merge(v,v1,tamV1,v2,tamV2);

        free(v1);
        free(v2);
    }
}

void swap(int* v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int particiona(int* v, int ini, int fim){
    int sorteado = ini + (rand()%(fim-ini));
    swap(v, sorteado, fim);
    int pIndex = ini;
    int pivo = v[fim];
    for(int i = ini; i < fim; i++){
        if(v[i] <= pivo){
            swap(v,i,pIndex);
            pIndex++;
        }
    }
    swap(v,pIndex,fim);
    return pIndex;
}

void quickSort(int* v, int ini, int fim){
    if(fim>ini){
        int indexPivo = particiona(v,ini,fim);
        quickSort(v,ini,indexPivo-1);
        quickSort(v,indexPivo+1,fim);
    }
}

#endif // SELECTIONSORT_H
