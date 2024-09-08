#include <stdio.h>
#include "hashlib.h"

int main(){
    if(!init_ht()) return 1 ;

    include_ht(4) ;
    include_ht(15) ;

    print_ht() ;

    free_ht() ;
    return 0 ;
}
