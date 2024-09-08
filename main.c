#include <stdio.h>
#include "hashlib.h"

int main(){
    if(!init_ht()) return 1 ;

    include_ht(10) ;
    include_ht(22) ;
    include_ht(4) ;
    include_ht(15) ;
    include_ht(59) ;

    print_ht() ;

    remove_ht(4) ;
    printf("\n\n") ;
    print_ht() ;

    free_ht() ;
    return 0 ;
}
