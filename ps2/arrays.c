#include<stdio.h>
#include<math.h>

float lift_a_car(const int stick_length, const int human_weight, const int car_weight); // 1
float unit_price(const float pack_price, const int rolls_count, const int pieces_count); // 2
int collatz(const int number); // 3
int opposite_number(const int n, const int number); // 4
void counter(const int input_array[], const int array_size, int result_array[2]);//5
unsigned long sum_squared(const int line);
int array_min(const int input_array[], const int array_size); //7.1
int array_max(const int input_array[], const int array_size); //7.2
unsigned long special_counter(const int input_array[], const int array_size); //8
int special_numbers(const int input_array[], const int array_size, int result_array[]);//9
//nezabudni na gcc -std=c11 -Wall -Werror arrays.c -lm -o ps2

int  main(){
  return 0;
}


//task 1
float lift_a_car(const int stick_length, const int human_weight, const int car_weight){

  float stick_l = stick_length;
  float human_w = human_weight;
  float car_w = car_weight;

    
  float f1=car_w*10;
  float f2=human_w*10;

  return roundf ((stick_l/(f1/f2+1))*100)/100;
}


//task 2
float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
    float pack_p = pack_price;
    float rolls_c = rolls_count;
    float pieces_c = pieces_count;

    return roundf ((pack_p/rolls_c/pieces_c*100)*100)/100;

}


//task 3
int collatz(const int number){

  int num = (int) number;
  int count = 0;
  int collatz = 0;


  while(num > 1){
    if(num % 2 == 0){
      num = num/2;
      count = count +1;
    }else {
      num = (num * 3) + 1;
      count = count + 1;
    }
    //collatz = collatz + 1;
  }
  /*if (num == 1){
    collatz = collatz + 1;
  }*/
  collatz = count +1;
  return collatz;
}


//task 4
int opposite_number(const int n, const int number){
    int pocet = (int) n;
    int cislo = (int) number;
    int result = 0;
    //int opposite = opposite_number;
    if ((pocet % 2 == 0) && (cislo < pocet)){
        if (pocet/2 > cislo){
            result = pocet/2 + cislo;
        } else {
            result = cislo - pocet/2;
        }
    }    
    return result;
}


// task 5
void counter(const int input_array[], const int array_size, int result_array[2]){

	int even = 0;
  int odd = 0;
	
  int idx = 0;
  
  while (idx < array_size){
    if (idx % 2 == 0){
      even =even + input_array[idx];	
		  idx = idx + 1;
    }
		idx=idx +1;
	}
	result_array[0] = even;


  idx = 1;
  
	while (idx < array_size){
    if(idx % 2 != 0){
      odd = odd + input_array[idx];
		  idx = idx + 1;
    }
		idx = idx +1;
	}
	result_array[1] = odd;
}


//task 6
unsigned long sum_squared(const int line){
  //int n = 3;
  //int n = 0;                
	long riadok[line];             //line = riadok lebo ked dam line robi to problemy
	unsigned long sqr = 1;

    //if (n == 0){                // line namiesto n
        //line[n] = 1;

    //} else {
    if (line >= 0){
        riadok[0] = 1;

        int idx = 1;
	    while (idx < line){ 
            riadok[idx]= (line - idx + 1) * (riadok[idx-1]) / idx;
            idx = idx+1;
        }
    
        int j = 0;
	    while (j < line){                             // j presunie priamo na hodnotu i
		    sqr = (riadok[j] * riadok[j]) + sqr;
            j = j+1;
	    }
    }
      return sqr;
      
}


// task 7.1
int array_min(const int input_array[], const int array_size){

	
	int minimum;
  int size = array_size;

	if (input_array > 0){
	  
    minimum = input_array[0];

    int idx = 1;
		while( idx < size){
	        
	    if(input_array[idx] < minimum){
	      minimum = input_array[idx];
	    }
      idx = idx + 1;
	  }

	}
	else if (input_array == NULL){    // ak input 0 return musi byt -1 -- pozri zadanie
    minimum = -1;
	}
  return minimum;
}


// task 7.2
int array_max(const int input_array[], const int array_size){

	
	int maximum;
  int size = array_size;


	if (input_array > 0){
	  
    maximum = input_array[0];

    int idx = 1;
		while( idx < size){
	        
	    if(input_array[idx] > maximum){
	      maximum = input_array[idx];
	    }
      idx = idx + 1;
	  }

	}
	else if (input_array == NULL){
    maximum = -1;
	}
  return maximum;
}


// task 8
unsigned long special_counter(const int input_array[], const int array_size){
  int odd = 0;
  int even = 0;
  //int sqr = 0; // neparne cisla umocnene na druhu
  int result;

  int idx = 0;
  while (idx < array_size) {
    if (idx % 2 == 0){
      even = even + input_array[idx];
    } else {
      odd = (input_array[idx]*input_array[idx]) + odd;
    }
    idx = idx + 1;
  }
  result = odd + even;
  return result;
}


//task 9
int special_numbers(const int input_array[], const int array_size, int result_array[]){

  int sum = 0;
  int special_num = 0;


  int j = 0;
  while ( j < array_size){
    int i = 1 + j;
	  while ( i < array_size){
		  sum = sum + input_array[i];
      i = i +1;
	  }	
	  if (input_array[j] > sum){
		  result_array[special_num] = input_array[j];
		  special_num = special_num + 1;
	  }
	  sum = 0;
    j = j +1;      
	}
	
  
  return special_num;
}
