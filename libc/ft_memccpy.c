#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

// void	*memcpy( void * destination, const void * source, size_t size );

void *memccpy(void *dest, const void *src, int c, size_t n);
	size_t	i;

	i = 0;
	while (size)
	{
		*((unsigned char *)destination + i) = *((unsigned char *)source + i);
		i++;
		size--;
	}
	return (destination);
}
/*

int main() {
  
    int array [] = { 54, 85, 20, 63, 21 };
    int * copy = NULL;
    int length = sizeof( int ) * 5;
       
    copy = (int *) malloc( length );
    ft_memcpy( copy, array, length );
	memcpy( copy, array, length );
        

    for( length=0; length<5; length++ ) {
        printf( "%d ", copy[ length ] );
    }
    printf( "\n" );
        
    free( copy );
    
    return EXIT_SUCCESS;
}*/