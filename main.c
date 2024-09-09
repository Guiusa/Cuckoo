#include <stdio.h>
#include "hashlib.h"

int main(){
    if(!init_ht()) return 1 ;

    char c ;
    int k ;

    c = getchar() ;
    while(c != EOF){
        scanf(" %d\n", &k) ;
        if(c == 'i') include_ht(k) ;
        if(c == 'r') remove_ht(k) ;
        c = getchar() ;
    }
    print_ht() ;
    free_ht() ;
    return 0 ;
}
