#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h>
#include <ctype.h>


int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}


int is_word_guessed(const char secret[] , const char letters_guessed[]){ // skontroluje ci je slovo uhadnute vrati hodnotu 1 a bolo uhadnute , inak 0
        int letter = 0; // l = letter 
        for (int idx = 0; idx < strlen(secret); idx++){
                for (int j = 0; j < strlen(letters_guessed); j++){
                        if(secret[idx]==letters_guessed[j]){
                              letter ++;  
                        }        
                }
        }
        if (letter == strlen(secret)){   // ak sa pocet uhadnutych pismen rovna dlzke slova
                return 1;    //slovo bolo uhadnute 
        }
        else {  // l != strlen(secret)
                return 0;  // slovo nebolo uhadnute
        }

}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){ // aktualizuje hadane slovo guessed word  tak ze na neuhadnutych poziciach je _ a na uhadnutych je pismeno

    for (int idx =0; idx < strlen(secret); idx++){  // runs all positions in word
        int letter = 0; 
        for (int j =0; j < strlen(letters_guessed); j++){
               
            if(secret[idx]==letters_guessed[j]){ // ak sa pismeno na pozicii i v hadanom slove rovna pismenu v uz hadanych pismenach 
                guessed_word[idx] = secret[idx];
                letter = 1;    
            }    
        }
        if (letter == 0){
                guessed_word[idx]='_';
        }
    }

    guessed_word[strlen(secret)] = '\0';    

}

void get_available_letters(const char letters_guessed[], char available_letters[]){ // aktualizuje retazec dostupnych pismen
//ctrl - kontrola
        char abc [] = "abcdefghijklmnopqrstuvwxyz\0"; //26
	int n=0; // n = nepouzite
        int idx=0;
	do {  
		int letter = 0;
		for (int ctrl =0; ctrl <strlen(letters_guessed); ctrl ++) {  // skontroluj s kazdym znakom z letters guessed
			if (abc[idx ] == letters_guessed[ctrl ]) {   // ak pismeno na pozicii i sa zhoduje s pismenom na pozicii j
				letter = 1;     //pismeno uz bolo pouzite
			}
		}
		if (letter == 0) {   // ak pismeno nebolo pouzite
			available_letters[n] = abc[idx ];    // pismeno na pozicii n z available letters sa zhodujes s pismenom v abc na pozicii i
			n++;
		}
                idx = idx +1;
	} while ( idx <strlen(abc));     //pre kazde pismeno z abc
        available_letters[n] = '\0';

}


void hangman(const char secret[])
{       printf("Welcome to the game, Hangman!\n");
        printf("I am thinking of a word that is %ld letters long.\n", strlen(secret));
        printf("-------------\n");
        
        char letters_guessed[26] = "";
        //int input = 0;
       
        int noa = 8;   // noa = number of attempts


        char available_letters[26];
        get_available_letters(letters_guessed, available_letters);

        while(is_word_guessed(secret, letters_guessed)==0 && noa > 0){
                

                printf("You have %d guesses left.\n", noa);  // vypise pocet pokusov
                //char available_letters[26];
                get_available_letters(letters_guessed, available_letters);
                printf("Available letters: %s\n", available_letters);
                printf("Please guess a letter: "); 
                char tip[20];
                scanf("%s", tip);    // nacitanie hodnoty - tipnutie pismena



                // zmena velkych pismen na male ak boli zadane velke pismena 
                // podla ascii tabulky zmeni velke pismena na male
                int ascii =0;   
                while(ascii<= strlen(tip)){
                        if (tip[ascii] >= 65 && tip[ascii] <= 90){
                                tip[ascii] = tip[ascii] +32;
                        }
                        ascii = ascii + 1;
                }

// ------------------------------------------------------------------------------------------

                if(strlen(tip)!= 1 ){   // ak bolo zadane slovo 
                        //input= 1;
                        if(strcmp(secret, tip)==1){      // ak sa nerovnaju vrati hodnotu 1
                                printf("Sorry, bad guess. The word was %s.\n", secret);
                        }
                        else if (strcmp(secret, tip)==0){   // porovna slova, ak sa rovnaju vrati hodnotu 0
                                


                                printf("Congratulations, you won!\n");
                        }
                        break;


                        
                }
                
                if (strlen(tip) == 1){ // ak bolo zadane pismeno


                        char pismeno = tip[0];
                       

                        if(strchr(letters_guessed,pismeno) == NULL) {  // ak sa
                                int velkost = strlen(letters_guessed);
                                letters_guessed[velkost]= pismeno;
                                letters_guessed[velkost+1]= '\0';
                                
                                
                                
                                if(strchr(secret,pismeno)!=NULL){
                                        printf("Good guess:");
                                        noa = noa;

                                }
                                else if (strchr(secret, pismeno) == NULL){
                                        printf("Oops! That letter is not in my word:");
                                        noa =  noa -1;
                                }
                    
                        }


                        else if(strchr(letters_guessed,pismeno) != NULL && (strchr(secret,pismeno)!=NULL)){ // ak sa uz pouzite pismeno zhoduje s tipnutym pismenom
                                printf("Oops! You've already guessed that letter:");
                        }

                        else if (strchr(letters_guessed,pismeno) != NULL ){
                                printf("Oops! %c is not a valid letter:", tip[0]);
                        }



                        char guessed_word[26];
                        
                        get_guessed_word(secret, letters_guessed, guessed_word);
                        int gw = 0;
                        do {
                                printf(" %c",guessed_word[gw]);
                                gw = gw +1;

                        } while (gw <strlen(secret));
                        printf("\n");
                        printf("-------------\n");
                }

        }

         
        if(noa==0){
                printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
        }
        else{
                printf("Congratulations, you won!\n");
        }
        
}
