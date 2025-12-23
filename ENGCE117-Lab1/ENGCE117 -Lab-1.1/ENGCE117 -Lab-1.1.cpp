#include <stdio.h>

int main() {
    int n ;
    int fee ;
    
    printf( "Enter N : " ) ;

    if ( scanf( "%d", &n ) !=  1) {
        printf( "An error occurred while entering data. Please enter an integer.\n" ) ;
        return 1 ;
    }

    if ( n < 0 ) {
        printf( "Please enter a non-negative integer.\n" ) ;
        return 1 ;
    }

    printf( "\n--- result ---\n"  ) ;
    for ( fee = 1; fee <= n; fee++ ) {
        printf( "[%d] Hello world\n" , fee ) ;
    }
    return 0 ;
}// end main