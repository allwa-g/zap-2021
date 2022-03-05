#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include "ballsortpuzzle.h"
#include <time.h>



// ************| 1 |******************************


void generator(const int rows, const int columns, char field[rows][columns]){
	int riadky = rows;
	int count[8];
	int random =0;
	char znaky[]={'!','@','#','%','$','^', '&','*'};
	int pvs = 2; //pocet volnych stlpcov


	int pz=0; //pocet znakov
	while (pz<(columns-pvs)){  // kolko roznych druhov znakov tam bude - zavisi to od poctu riadkov
		count[pz]=riadky;

		pz = pz +1;
	}

	int r = rand() % columns;   
    int q = r;
    while(q == r){
        q = rand() % columns; // random cisla z poctu stlpcov, resp urci random cisla stlcov ktore nebudu volne 
    }

	int riadok=0;
    while ( riadok<rows){

		int stlpec =0;
        while ( stlpec<columns){


			if (stlpec==r || stlpec==q) {

				field[riadok][stlpec] = ' ';
			//}else (stlpec!=r || stlpec!=q){
			}else{
		    
	 			random = rand() % (columns-pvs);

		 		do {
		 			random=rand() %(columns -pvs);
				}while (count[random]==0);


	    		count[random] = count[random] -1;
	    		field[riadok][stlpec]=znaky[random];
			}
			stlpec = stlpec +1;
        }
		riadok = riadok+1;
    }

}

//*********************| 2 |*****************************
/*
void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y){


	--x;
    --y;
	int row=rows;
	int m =0;
	char znak;
	int znak2;
	int z = 0;
	
	if (x==y){  // ak sa cislo stlpca z ktoreho znak chceme repsunut rovna cislu stlpca kam znak presuvame je to neplatny tah
		return;

	}

	bool next =false;   // ci je miesto volne

	while (true){
		

		
		if (field[m][x]!= ' '){  // ak sa pole nerovna ' ' teda nie je volne
					
				znak = field[m][x]; 
				
				znak2=m;
				next=true;
				
				break;
		}

		if (m==rows){
			printf("EMPTY COLUMN \n");
			break;

	
		}	
		m=m+1;
	

	}

	if (next){
		m = rows-1;
		while (true){
			if (field[m][y]==' '){
				break;
			}
			m = m-1;
		}
		row=m;
	}



	if (row != rows -1) {
		
		if (field[row+1][y] != znak && field[row][y]== ' ' ){ // ak sa znak v stlpci do ktoreho prenasame inzz znak nerovna s tym znakom potom = false
			if( m != rows){
				printf("MUST BE SAME \n");
				next=false;
			}
			
		
		}
	}


	if (next){

		if (field[z][y]!= ' ' ) {
			printf("COLUMN IS FULL\n");
		}else {
			m = rows-1;
			while (true){
				 
				if (field[m][y] == ' ') {
					field[m][y]=znak;
					field[znak2][x]=' ';
					break;	
				}
				m=m-1;
			}
		}
	}
}
*/



void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y){
    if (x==y){
		return;

	}
	x= x-1;
    y= y-1;
	int i =0;
	char copy;
	int copyX;
	int last=rows;

	bool canMove =false;
		while (true){
		
			if (field[i][x]!= ' '){
					
				copy= field[i][x];
				
				copyX=i;
				canMove=true;
				
				break;
			}
				i++;
			if (i==rows){
				printf("EMPTY COLUMN! \n");
				break;
			}
		}
		if (canMove){
			i = rows-1;
			while (true){
				if (field[i][y]==' '){
					break;
				}
				i--;
			}
			last=i;
		}

		if (last != rows -1) {
		
			if (field[last+1][y] != copy){
				if (i!= rows){
					printf("MUST BE THE SAME!\n");
					canMove=false;
				}
				
		
			}
		}

if (canMove){
		if (field[0][y]!= ' ' ) {
			printf("COLUMN FULL!\n");
		}else {
			i= rows-1;
			while (true){
				 
					 if (field[i][y] == ' ') {
						field[i][y]=copy;
						field[copyX][x]=' ';
						break;	
					}
				i--;
			}
		}
	}
}




//**********************| 3 |*****************************

bool check(const int rows, const int columns, char field[rows][columns])
{
    char znak_tst;
 	int stlpec=0;
    while ( stlpec<columns)
    {
        znak_tst = field[0][stlpec];
		int row=0;
        while( row<rows)
        {
            if (znak_tst != field[row][stlpec])
            {
                return false;

            }
			else if (znak_tst == field[row][stlpec]){
				//return true;
			}
			row = row +1;
        }
		stlpec = stlpec +1;
    }
    return true;
}


//***********************| 4 |****************************

void game_field(const int rows, const int columns, char field[rows][columns]){

	int riadok =0;
	int viac = 1;
    while (riadok < rows){


	  	printf("%d | ",riadok + viac);   // vypise cislo riadku

		  	int stlpec =0;
            while (stlpec <columns){


                printf("%c | ",field[riadok][stlpec]);   // vypise znak 
				stlpec = stlpec +viac;

            }
	    printf("\n");


		riadok = riadok+viac;
    }  

    printf("   ");
    // spodny riadok
	int col=0;
	//printf("\n   ");
	while ( col <columns){  // vypise spodne ohranicenie 
	 
	    printf("--- ");

		col++;
		//printf("\n   ");
	}
	printf("\n   ");

	int colnum=0;
	while (colnum<columns){  // vypise cisla stlpcov
	 	printf(" %d  ",colnum+viac);
		colnum = colnum + viac;

	}
	printf("\n");
}

//************************| 5 |********************

void ball_sort_puzzle(){
	int x;
	int y;
	int nom =0;    // number of moves .. pocet tahov
    char field[4][6];

    generator(4,6,field);
    game_field(4,6,field);

    while (check(4,6,field)!=true){
		printf("Number of moves: %d\n", nom);
		printf("Enter what: ");
	    scanf("%d",&x);
		//printf("\n");
		printf("Enter where: ");
		scanf("%d",&y);
		//printf("\n");
		down_possible(4,6,field,x,y);
		game_field(4,6,field);
		nom++;
		printf("******************************\n");
	}
	printf("YOU WON !\n");
}
