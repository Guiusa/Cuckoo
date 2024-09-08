#include "hashlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define mod %

nodo_t *t1, *t2 ;

/*
 * Inicializa as tabelas hash t1 e t2
 */
int init_ht() {
    t1 = malloc(M * sizeof(nodo_t)) ;
    if (!t1) {
        perror("Impossível alocar t1\n") ;
        return 0 ;
    }

    t2 = malloc(M * sizeof(nodo_t)) ;
    if (!t2) {
        perror("Impossível alocar t2\n") ;
        return 0 ;
    }

    for(int i = 0; i < M; i++)
        t1[i].ocp = t2[i].ocp = 0 ;
    return 1 ;
}
//##############################################################################



/*
 * Libera as tabelas hash em memória
 */
void free_ht(){
    free(t1) ;
    free(t2) ;
}
//##############################################################################



/*
 * Printa hash tables para depuração
 */
void print_ht(){
    for(int i = 0; i<M; i++){
        if(t1[i].ocp){
            printf("T1[%2d] = %d", i, t1[i].v) ;
        } else printf("T1[%2d] LIVRE", i) ;
        printf("\t\t") ;
        if(t2[i].ocp){
            printf("T2[%2d] = %d", i, t2[i].v) ;
        } else printf("T2[%2d] LIVRE", i) ;
        printf("\n") ;
    }
}
//##############################################################################



/*
 * Funções de hashing
 */
int h1(int key){
    int pos = key mod M ;
    return pos ;
}
int h2(int key){
    int pos = floor(M * (key * 0.9 - floor(key * 0.9))) ;
    return pos ;
}
//##############################################################################



/*
 * Inserção de elementos
 */
int include_ht(int key){
    int pos1 = h1(key) ;
    if(t1[pos1].ocp){
        int pos2 = h2(t1[pos1].v) ;
        t2[pos2].v = t1[pos1].v ;
        t2[pos2].ocp = 1 ;
    }
    t1[pos1].v = key ;
    t1[pos1].ocp = 1 ;
    return pos1 ;
}
//##############################################################################



/*
 * Busca de elementos
 */
int search_ht(int key){
    int pos1 = h1(key) ;
    if(!t1[pos1].ocp) return -1 ;
    if(t1[pos1].v == key) return pos1 ;
    int pos2 = h2(key) ;
    if(t2[pos2].v == key) return pos2 ;
    return -1 ;
}
//##############################################################################



/*
 * Exclui um elemento
 */
int remove_ht(int key){
    int pos2 = h2(key) ;
    if(t2[pos2].v == key && t2[pos2].ocp){
        t2[pos2].ocp = 0 ;
        return pos2 ;
    }
}
//##############################################################################
