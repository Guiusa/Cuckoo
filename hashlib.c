#include "hashlib.h"
#include <stdlib.h>
#include <stdio.h>
#define mod %

int *t1, *t2 ;

/*
 * Inicializa as tabelas hash t1 e t2
 */
int init_ht() {
    t1 = (int *) malloc(M * sizeof(int)) ;
    if (!t1) {
        perror("Impossível alocar t1\n") ;
        return 0 ;
    }

    t2 = (int *) malloc(M * sizeof(int)) ;
    if (!t2) {
        perror("Impossível alocar t2\n") ;
        return 0 ;
    }
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
        printf("T1[%2d] = %d", i, t1[i]) ;
        printf("\t\t") ;
        printf("T2[%2d] = %d", i, t2[i]) ;
        printf("\n") ;
    }
}
//##############################################################################



/*
 * Inserção de elementos 
 */
int h1(int key){
    int pos = key mod M ;
    if(t1[pos] != 0)
        return 0 ;
    t1[pos] = key ; 
    return pos ;
}
int h2(int key){
    int pos = ((int) M * ((int) ((key * 0.9) - ((int) key * 0.9)))) ;
    t2[pos] = key ;
    return pos ;
}
int include_ht(int key){
    if(!h1(key))
        h2(key) ;
    return 0 ;
}
