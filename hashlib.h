#define M 11
/*
 * Struct armazenada nas hash tables
 * v    Valor do nodo
 * ocp  Estado do nodo {LIVRE,OCUPADO,EXCLUIDO}
 */
typedef struct nodo_t {
    int v ;
    short ocp ;
} nodo_t ;

/*
 *  Struct para ordenação e impressão da saída
 *  v       Valor do nodo
 *  table   Tabela que está inserido {1,2}
 *  p       Posição na tabela
 */
typedef struct print_node {
    int v ;
    short table ;
    int p ;
} pnode_t ;

int init_ht() ;
void free_ht() ;
void print_ht() ;
int include_ht(int key) ;
int search_ht(int key) ;
int remove_ht(int key) ;
void debug_ht() ;
