#include "hashlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define mod %
#define TRUE 1
#define FALSE 0
#define LIVRE 0
#define OCUPADO 1
#define EXCLUIDO 2

nodo_t *t1, *t2 ;
pnode_t *l ;

/*
 * Aloca as tabelas hash t1 e t2
 * Inicializa todos os nodos como livres
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

    for(int i = 0; i < M; i++){
        t1[i].ocp = t2[i].ocp = LIVRE ;
        t1[i].v = t2[i].v = 0 ;
    }
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
 * Printa hash table
 */
int comp(const void *frst, const void *scnd){ // Comparação para o qsort
    pnode_t p1 = * (pnode_t *) frst ;
    pnode_t p2 = * (pnode_t *) scnd ;
    if(p1.v > p2.v){
        return TRUE ;
    } else if (p1.v < p2.v) {
        return FALSE ;
    } else {
        if(p1.table > p2.table){
            return TRUE ;
        } else if (p1.table < p2.table) {
            return FALSE ;
        } else 
            return (p1.p > p2.p) ;
    }
}
void print_ht(){
    l = malloc(2 * M * sizeof(pnode_t)) ; // Aloca um vetor e pnodes para ordenar
    int c = 0 ;
    for(int i = 0; i<M; i++){ // Enche o vetor e conta em c quantos elementos
        if(t1[i].ocp == OCUPADO){
            l[c].v = t1[i].v ;
            l[c].table = 1 ;
            l[c].p = i ;
            c++ ;
        }
        if(t2[i].ocp == OCUPADO){
            l[c].v = t2[i].v ;
            l[c].table = 2 ;
            l[c].p = i ;
            c++ ;
        }
    }
    // Ordena e printa todos os elementos
    qsort((void *) l, c, sizeof(pnode_t), comp) ;
    for(int i = 0; i<c; i++)
        printf("%d,T%d,%d\n", l[i].v, l[i].table, l[i].p) ;
    
    free(l) ;
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
    if(t1[pos1].ocp == OCUPADO){
        if(t1[pos1].v == key) return -1 ; // Elemento duplicado
        int pos2 = h2(t1[pos1].v) ;
        if(t2[pos2].v == key) return -1 ; // Elemento duplicado
        // Joga elemento j em t1 para t2
        t2[pos2].v = t1[pos1].v ;
        t2[pos2].ocp = OCUPADO ;
    }
    t1[pos1].v = key ;
    t1[pos1].ocp = OCUPADO ;
    return pos1 ;
}
//##############################################################################



/*
 * Busca de elementos
 */
int search_ht(int key){
    int pos1 = h1(key) ;
    if(t1[pos1].ocp == LIVRE) return -1 ; // Se posição está livre em h1, não existe
    if(t1[pos1].v == key) return pos1 ; // Se está em h1 retorna posição
    int pos2 = h2(key) ;
    if(t2[pos2].v == key) return pos2 ; // Se está em h2 retorna posição
    return -1 ; // Não existe
}
//##############################################################################



/*
 * Exclui um elemento
 */
int remove_ht(int key){
    int pos2 = h2(key) ;
    if(t2[pos2].ocp != LIVRE && t2[pos2].v == key){
        t2[pos2].ocp = EXCLUIDO ; // Marca como removido
        return pos2 ;
    }
    int pos1 = h1(key) ;
    if(t1[pos1].v == key && t1[pos1].ocp != LIVRE){
        t1[pos1].ocp = EXCLUIDO ; // Marca como removido
        return pos1 ;
    }
    return -1 ;
}
//##############################################################################



/*
 * Depuração
 * Usado durante desenvolvimento
 */
void debug_ht(){
    for(int i = 0; i<M; i++){
        printf("t1[%2d]", i) ;
        switch (t1[i].ocp){
        case LIVRE:
            printf(" LIVRE") ;
            break ;
        case OCUPADO:
            printf(" = %3d", t1[i].v) ;
            break ;
        case EXCLUIDO:
            printf(" EXCLUIDO") ;
            break ;
        }
        printf("\t\t") ;
        printf("t2[%2d]", i) ;
        switch (t2[i].ocp){
        case LIVRE:
            printf(" LIVRE") ;
            break ;
        case OCUPADO:
            printf(" = %3d", t2[i].v) ;
            break ;
        case EXCLUIDO:
            printf(" EXCLUIDO") ;
            break ;
        }
        printf("\n") ;
    }
    printf("\n\n") ;
}
//##############################################################################
