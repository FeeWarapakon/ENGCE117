#include <stdio.h>

void go( int ***p, int **z ) {
    *p = z ;  
}

int main() {
    int *b = new int ; *b = 10 ;
    int *c = new int ; *c = 20 ;
    int **a ;

    go( &a, &b ) ;
    printf( "Input=>%d %p %p %p\n", **a, *a, a, &a ) ;
    printf( "\n" ) ;
    go( &a, &c ) ;
    printf( "Input=>%d %p %p %p\n", **a, *a, a, &a ) ;

    return 0 ;
}//end function