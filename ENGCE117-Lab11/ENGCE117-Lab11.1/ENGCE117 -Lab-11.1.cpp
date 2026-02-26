#include <stdio.h>

int BinSearch( int d[], int n, int f ) ;

int main() {
    int data[ 6 ] = { 1, 2, 3, 4, 5, 7 } ;
    int n = 6 ; 
    int find = 5 ;
    
    int pos = BinSearch( data, n, find ) ;
    
    if ( pos != -1 ) {
        printf( "Found %d at %d\n", find, pos ) ;
    } else {
        printf( "Not Found\n" ) ;
    }
    
    return 0 ;
}

int BinSearch( int d[], int n, int f ) {
    int low = 0 ;
    int high = n - 1 ;
    
    while ( low <= high ) {
        int mid = low + ( high - low ) / 2 ;
        
        if ( d[ mid ] == f ) {
            return mid ;
        } else if ( d[ mid ] < f ) {
            low = mid + 1 ;
        } else {
            high = mid - 1 ;
        }
    }
    return -1 ;
}