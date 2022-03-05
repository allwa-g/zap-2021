
#include <stdio.h>

/*
fopen() pre inicializáciu práce so súborom
fclose() pre ukončenie práce so súborom
fgetc() pre čítanie zo súboru
fputc() pre zápis do súboru
*/


#include <stdbool.h>
#include <stdlib.h>

#define false 0
#define true 1

int main(int argc, char const *argv[]){   // taa tak jak v count words to funguje

    FILE * f_read = fopen(argv[1], "r");    
    FILE * f_write = fopen(argv[2], "w");

    char koniec[]= "STOP";
    char zaciatok[] = "START";


    int pocet= 0;
    int count = 0;
    int cislo = 0;


    char string[1000];
    char character;
    char medzera = ' ';


    bool is_start = false;    
    bool is_koniec = false;



   	while((character = fgetc(f_read)) != EOF) {   // pokial nie je EOF = END OF FILE

		if (is_start){


			if (character == medzera){

				pocet = pocet +1;
			}


			if (pocet % 2 == 0){  // kazde druhe

				if (character != medzera ){

					string[cislo] = character;
          			cislo = cislo +1;
				}

			} else {

		        if( pocet!= 1  && pocet!= 3  && 
				character == medzera){
		        	fputc(medzera, f_write);
		        } 

                int idx = 0;
		        while ( idx < cislo ){
		            fputc(string[idx], f_write);
                    idx = idx+1;
		        } 

		        cislo = 0;
			}
		}	

		if (!is_koniec){

			if(count < sizeof(zaciatok)-1) {

				if(zaciatok[count] == character) {
					count = count + 1;

					if(count == sizeof(zaciatok) - 1) {
						is_start = true;
						is_koniec = true;
						count = 0;
					}
				}
			}
		}


		if (is_koniec){

			if(count < sizeof(koniec)	) {

				if(koniec[count] == character) {

					count = count + 1;

					if(count == sizeof(koniec)-1) {

						break;
					}
				}
			}	
		}
	}	

  	fclose(f_read);

  	fclose(f_write);

  	return 0;
}
