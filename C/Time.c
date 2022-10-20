#include<stdio.h>
#include<stdlib.h>
int main()
{

    int h = 0, m = 0, s = 0 ;

    /* h is using for hour and m for minute and s is for second */
    double i ;
    printf( "\nEnter any time in HH//MM//SS: " ) ;
    scanf( "%d %d %d", &h, &m, &s ) ;
start:
    ;
    for( h ; h < 24 ; h++) { // 24 hour = 1 day

        for( m ; m < 60 ; m++ ) { // 1 hour = 60 minute
            for( s ; s < 60 ; s++ ) { // 1 minute = 60 second

                system( "cls" ) ; // system() is a library function of stdlib.h header file. This function is used to run system/ command prompt commands, here cls is command to clear the output screen
                printf( "\t\n\t\t\t\t\tThe time is:%d:%d:%d", h, m, s ) ;

                if( h < 12 )
                    printf( "AM" ) ;
                else
                    printf( "PM" ) ;
                printf( "\t\n\t\t\t\t\t10 October 2022, Wednesday" );

                /*if( h = '0' )
                printf("(12 AM)" ) ;*/
                for( i = 0 ; i < 89999902 ; i++ ) {

                    i++ ;
                    i-- ;

                }

                //s = 0 ;
            }

            s = 0 ;
            //m = 0 ;

        }

        m = 0 ;

        goto start ;
    }
}
