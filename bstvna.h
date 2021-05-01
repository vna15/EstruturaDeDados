#ifndef BST_H
#define BST_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct noBst {
    int val;
    struct noBst* esq;
    struct noBst* dir;
};

/**
 * Funcao que aloca um novo noBst, e
 * ajusta os ponteiros esq e dir para NULL.
 **/
struct noBst* alocarNovoNo(int val) {
    //IMPLEMENTAR
    struct noBst* no = (struct noBst*)malloc(sizeof (struct noBst));
    no->val = val;
    no->dir = NULL;
    no->esq = NULL;
    return no;
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * insere um novo valor na BST. Tamanho deve
 * ser incrementado.
 * Ambos tamanho e raiz são passados por referência.
 **/
void inserir(struct noBst** raiz, int val, int* tamanho) {
    //IMPLEMENTAR
    if((*raiz)==NULL){
        (*raiz) = alocarNovoNo(val);
        (*tamanho)++;
    }
    else{
        if(val <= (*raiz)->val){
            inserir(&((*raiz)->esq), val, tamanho);
        }
        else{
            inserir(&((*raiz)->dir), val, tamanho);
        }
    }
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * verifica se a mesma contém um dado valor.
 **/
bool buscar(struct noBst* raiz, int val) {
    //IMPLEMENTAR
        if(raiz != NULL){
            if(raiz->val == val){
                return true;
            }
            else{
                if(val > raiz->val){
                    return buscar(raiz->dir, val);
                }
                else{
                    return buscar(raiz->esq, val);
                }
            }
        }
        return false;
}

/**
 * Funcao que retorna o maior valor de uma BST.
 **/
int max(struct noBst* raiz) {
    //IMPLEMENTAR
    if(raiz != NULL){
            noBst *aux = raiz;
            while(aux->dir != NULL){
                aux = aux->dir;
            }
            return aux->val;
        }
        return NULL;
}

/**
 * Funcao que retorna o menor valor de uma BST.
 **/
int min(struct noBst* raiz) {
    //IMPLEMENTAR
    if(raiz != NULL){
            noBst *aux = raiz;
            while(aux->esq != NULL){
                aux = aux->esq;
            }
                return aux->val;
        }
        return NULL;
}

/**
 * Funcao que retorna a altura de uma BST.
 * A altura de uma BST é dada pela quantidade
 * de arestas entre a raiz e a folha mais distante.
 **/
int altura(struct noBst* raiz) {
    //IMPLEMENTAR
    if(raiz == NULL || (raiz->dir == NULL && raiz->esq == NULL)){
        return NULL;
    }
    else{
        int auxesq, auxdir;
        auxesq = 1 + altura(raiz->esq);
        auxdir = 1 + altura(raiz->dir);
           if(auxesq>auxdir){
                 return auxesq;
           }
           else{
                return auxdir;
           }
     }
}

/**
 * Funcao que navega em-ordem na BST e
 * imprime seus elementos.
 **/
void emOrdem(struct noBst* raiz) {
    //IMPLEMENTAR
    if(raiz != NULL){
        emOrdem(raiz->esq);
        printf(" %d |", raiz->val);
        emOrdem(raiz->dir);
    }
}

/**
 * Funcao que navega pre-ordem na BST e
 * imprime seus elementos.
 **/
void preOrdem(struct noBst* raiz) {
    //IMPLEMENTAR
    if(raiz != NULL){
        printf(" %d |", raiz->val);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

/**
 * Funcao que navega pos-ordem na BST e
 * imprime seus elementos.
 **/
void posOrdem(struct noBst* raiz) {
    //IMPLEMENTAR
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf(" %d |", raiz->val);
    }
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * remove o no que contem o valor passado como
 * argumento. Tamanho deve ser decrementado.
 * Tamanho é passado por referência.
 **/
struct noBst* remover(struct noBst* raiz, int val, int* tamanho) {
    //IMPLEMENTAR
    if(raiz != NULL){
            if(val > raiz->val){
                raiz->dir = remover(raiz->dir, val, tamanho);
            }
            else if(val < raiz->val){
                 raiz->esq = remover(raiz->esq, val, tamanho);
            }
            else{
                if(raiz->esq == NULL && raiz->dir == NULL){
                    //free(raiz);
                    return NULL;
                }
                else if(raiz->esq == NULL && raiz->dir != NULL){

                    noBst *aux = raiz->dir;
                    //free(raiz->dir);
                    return aux;
                }
                else if(raiz->esq != NULL && raiz->dir == NULL){

                    noBst *aux = raiz->esq;
                    //free(raiz->esq);
                    return aux;
                }
                else{

                   //noBst *aux = raiz;
                   int aux2 = min(raiz->dir);
                    //Item itemAux = aux -> item;
                   raiz = remover(raiz, aux2, tamanho);
                   raiz->val = aux2;
                }
            }
            (*tamanho)--;
            return raiz;
        }
        return NULL;
}


#endif // BST_H
