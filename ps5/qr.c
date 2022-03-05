#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
void encode_char(char character, bool bits[8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
char decode_byte(const bool bits[8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);
int main(){

    return 0;
}


//malo by to fungovat, pls aspon dajaky bod
void encode_char(char character, bool bits[8]) {
    char znak = character;
    int binary = 7;

    while ( (binary > 0) || (binary == 0)){
        
        bits[binary] = znak & 1;
        binary = binary-1;
        znak = znak >> 1;
    }
    
        
}
//***************************************************************

char decode_byte(const bool bits[8]) {
    //int ASCII = 0;
    unsigned char znak = 0;


    int ASCII = 0;
    while ( ASCII < 8) {
        
        int x = znak <<1;
  /*
        if (bits[i]){  // nevedela som aku podmienku dat 
            ASCII = ASCII + x;
        }
        x = x/2;
        i++;
        */
        znak = x | bits[ASCII];
        ASCII = ASCII+1;
    }
    return znak;
}


// toto je uz oki , uz to netreba upravovat //////////////////////////////////////////////////////////////////////////


void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
    int binary = 0;
    //int j = 0;
    //int size = strlen(string);

    while (binary < strlen(string) || (binary == strlen(string))) {

        if (binary >= 0){
            encode_char(string[binary], bytes[binary]);
        }
        
        
        binary = binary+1;
    }
}


void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
    int ASCII = 0;
    int i = 0;
    while (i < rows) {
        int j = 0;
        int x = 128;
        while (j < 8){
            ASCII = ASCII + x;
            x = x/2;
            j++;
        }
        string[i] = decode_byte(bytes[i]);
        i = i+1;
    }
}


// po tadial////////////////////////////////////////////////////////////////////

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    int stlpec = cols;
    int off = offset;
    int bin = 8;
    int abc = 0;


        int po = 0;
        while ( po < off){

            int ps = 0;   // pozicia v stlpci
            while ( ps < stlpec){

                int pb = 0;
                while ( pb < bin){
                    blocks[pb+po*bin][ps] = false;
                    pb = pb +1;
                }
                ps = ps+1;
            }
            po = po+1;
        }



    int h = 0;
    while ( h < off){
        int ps = 0;
        while ( ps < stlpec){

            int pb = 0;
            while ( pb < bin){
                if (!(ps + abc >= rows)) {
                    int x = h*bin;
                    int y = h*stlpec;
                    blocks[pb+x][ps] = bytes[ps+y][pb];
                }
                pb = pb+1;
            }
            ps = ps+1;
        }      
        abc += stlpec;
        h = h+1;
    }
}



void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    int riadok = rows;
    int stlpec = cols;
    int off = offset;
    int bin = 8;

    int cr = 0;  // cr je cislo riadku  

    while ( cr < riadok){
        int pb = 0;  // pozicia b
        while ( pb < bin){
            bytes[cr][pb] = false;
            pb = pb+1;
        }
        cr = cr+1;
    }


    int po = 0;
    while ( po < off){
        int pr = 0;   // pr pozicia v riadku
        while ( pr < riadok){
            int pb = 0;
            while ( pb < bin){
                int x = po*stlpec;
                int y = po*bin;
                bytes[pr+x][pb] = blocks[pb+y][pr];
                pb= pb+1;
            }
            pr = pr+1;
        }
        po = po+1;
    }
}
