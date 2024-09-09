#define M 11
typedef struct nodo_t {
    int v ;
    short ocp ;
} nodo_t ;

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
