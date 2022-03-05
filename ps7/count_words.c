#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){    // argc number of arguments passed argc pointer array - points to each argumnet pased to program

   
  FILE* f = fopen(argv[1], "r");

  int count = 0;
  int pocet = 0;

  char string[] = "ananas";
  char c;


    while((c = fgetc(f)) != EOF) {

        if(count < sizeof(string)-1) {

            int ASCII = 32;
            if(string[count] == c  || 
                string[count] == c + ASCII || 
                string[count] == c - ASCII) {
        
                    c = c + ASCII; 
                    count = count +1;
                
 

                        if(count == sizeof(string)-1) {
                            pocet = pocet +1;
                            count = 0;
                        }

            } else {
                count = 0;
            }
        }
    }



        fclose(f);

        FILE* ff = fopen(argv[1], "w");

  fputc(pocet +'0', ff);

  fclose(ff);
//return 0;
    return 0;
}

