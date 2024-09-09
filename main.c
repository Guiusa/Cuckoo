#include <stdio.h>
#include "hashlib.h"

int main(){
    if(!init_ht()) return 1 ;

    /*
    include_ht(10) ;
    remove_ht(4) ;
    print_ht() ;
    */
    char c ;
    int k ;
    c = getchar() ;
    while(c != EOF){
        scanf(" %d", &k) ;
        if(c == 'i') include_ht(k) ;
        if(c == 'r') remove_ht(k) ;
        c = getchar() ;
    }
    print_ht() ;
    free_ht() ;
    return 0 ;
}
