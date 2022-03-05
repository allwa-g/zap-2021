#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h>
#include <ctype.h>
#include <time.h>
//#include "src/hangman/hangman.h"

int main() {
	char secret[26];

    srand(time(NULL));

		
	get_word(secret);

	hangman( secret);
return 0;
}
