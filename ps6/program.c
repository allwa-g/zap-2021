#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>
#include <curses.h>
#include <stddef.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>
#include "program.h"
 
 
// size_t je unsigned typ of integer, teda nemoze obsahovat zaporne cisla 
 
//********************************************
// zacatie hry by pressing backspace
//*******************************************************
 
int start(int key) {
  switch (key) {
 
    default:
    {
      return 0;
    }
    case KEY_BACKSPACE:
    {
      return 1;
    }
 
 
 
  }
}
//**************************************************
//vykresli hracie pole a hadika a odmenu k tomu
//******************************************
void hra() {
 
  attron( COLOR_PAIR( 3 ) );
  clear(); // nic nebude na poli
 
 
  //vykreslenie hracieho pola
  int x = 0;
  int sirka = pole.sirka;
  int vyska = pole.vyska;
  while ( x < sirka) {
 
    int y = 0;
    while ( y < vyska) {
 
 
      if ((x == 0 )|| (x == sirka-1) || (y == 0 )|| (y == vyska-1)) {    // 0 lebo zaciatok a stena lebo takto je definovany okraj hracieho pola
        move(y, x);
        attron( COLOR_PAIR( 2) );
 
        addch('X');
        attroff(COLOR_PAIR(2));
 
      }
 
 
      //printf("X");
 
      y = y+1;
    }
    x = x +1;
  }
 
 
 
 
  //*****************************************
  //nakreslenie hadika
  //***********************************
  int  i = 0;
  while ( i < had.size) {
    move(had.telo[i].y, had.telo[i].x);
    attron(COLOR_PAIR(1));
    addch('0');
    attroff(COLOR_PAIR(1));
    i = i +1;
  }
  //**************************************
  //nakreslenie potravy
  //************************************
  move(food.b, food.a);
  attron( COLOR_PAIR( 3) );
  addch('@');
  //addch('+');
  attroff(COLOR_PAIR(3));
 
 
 
  //******************************************
  // nakreslenie odmeny
  //****************************************
  attron(COLOR_PAIR(5));
  move(odmena.c, odmena.d);
  //move(had.telo[i].y, had.telo[i].x);
  addch('@');
  attroff(COLOR_PAIR(5));
 
 
 
  //***********************************************
  // nakreslenie bariery
  //*********************************************
  for (int i = 0; i<0; i++){
    for (int j = 0; j<0; j++){
      for (int k = 0; k<0; k++){
 
  attron(COLOR_PAIR(2));
  move(barrier.e + j  , barrier.f+k);
  addch('X');
  addch('\0');
  move(barrier.e +i, barrier.f + j);
  addch('X');
 
  attroff(COLOR_PAIR(2));
      }
    }
  }
 
 
  //*************************************
  // vypisanie skore
  //**********************************
 
  move(pole.vyska, 4);    // urcujeme kde bude vypisane skore 
  int score = (had.size*10)-10;   // hodnota skore je dlzka hadika *10
  int level = ((had.size*10-10)/20)+1;
  attron(COLOR_PAIR(1));  // farba
  printw("SCORE: %d     LEVEL: %d ", score,level);   // vypisanie
  attroff(COLOR_PAIR(1));   // farba
  move(pole.vyska + (1),4);  // pokus o vypisanie levelu
  attron( COLOR_PAIR( 2 ) );
  printf("Level : ");
  attrset(COLOR_PAIR(2));
  //printf("       \n");
 
 
  refresh(); // to je na to aby sa aplikovali vsetky zmeny do pola
 
}
 
void draw_barrier(){
  int n = 15;
  for (int i =0; i<n; i++){
  barrier.e = (rand() % pole.vyska-1);
  barrier.f = (rand() % pole.sirka-1);
  }
}
 
 
void draw_f() {   // vykresli jedlo 
  food.b = (rand() % pole.vyska-2)+1; 
  food.a = (rand() % pole.sirka-2)+1; 
}
 
 
 
/*
void draw_odmena(){
  odmena.d = (rand() % pole.vyska - 2)+1;
  odmena.c = (rand() % pole.sirka - 2)+1;
 
  //odmena.d = food.b;
  //odmena.c = food.a;
 
 
}*/
 
void centre() {
  int sirka = pole.sirka;
  int vyska = pole.vyska;
  had.telo[0].x = sirka / 2; // zaciatok hada bude v strede
  had.telo[0].y = vyska / 2; 
  had.size = 1; // velkost hada na zaciatku je 
}
 
 
 
 
 
void had2() {
 
  int i = had.size-1;
  while ( i >= 0) {
    had.telo[i].x += had.telo[i].v.x; 
    had.telo[i].y += had.telo[i].v.y;
    if (i != 0) {
      had.telo[i].v.x = had.telo[i-1].v.x;
      had.telo[i].v.y = had.telo[i-1].v.y;
    }
    i = i-1;
  }
 
}
 
void add_clanok() {
 
  had.telo[had.size].x = had.telo[had.size-1].x; // aktualna pozicia hada
  had.telo[had.size].y = had.telo[had.size-1].y; // aktualna pozicia hada
  had.size  = had.size + 1; // dlzka hada s novym clankom
}
 
 
void skontroluj() {
 
  // ak had narazil do steny
  if (  had.telo[0].x ==0 || had.telo[0].y == 0 || had.telo[0].x == pole.sirka-1 || had.telo[0].y == pole.vyska-1 ) {
    if (had.telo[0].x ==odmena.c || had.telo[0].x == odmena.c ||
    had.telo[0].y == odmena.d || had.telo[0].y == odmena.d){
      mode = koniec;
    }
    mode = koniec; 
  }
  //**********************************
  // ak had narazil do prekazky
  //*********************************
  /*
  if (had.telo[0].x == barrier.e || had.telo[0].y == barrier.f){
    mode = koniec;
 
  }*/
 
  //*********************************
  // ak narazil do seba
  //****************************
  size_t i = 1;
  while ( i < had.size) {
    if (had.telo[0].x == had.telo[i].x && had.telo[0].y == had.telo[i].y) {
      mode = koniec; // Game Over
    }
 
    i = i+1;
 
  }
  //********************************
  // ak zjedol potravu
  //***********************************
  if ((had.telo[0].x == food.a && had.telo[0].y == food.b )|| (had.telo[0].x == odmena.c && had.telo[0].y == odmena.d)) {
    add_clanok(); // prida clanok omg
    draw_f(); // vykresli na novu poziciu
    int level = 3;
    if (((had.size*10-10)/20)+1 >level){
      add_clanok();
      //draw_odmena();
      draw_f();
      int level = 5;
      if (((had.size*10-10)/20)+1 >level){
        add_clanok();
        draw_f;
        int level = 7;
        if (((had.size*10-10)/20)+1 > level)
        draw_f;
        add_clanok();
      }
    }
 
    //draw_odmena();
  }
  /*
  if (had.telo[0].x == odmena.c && had.telo[0].y == odmena.d){
    mode=koniec;
 
  }*/
  /*
  if (had.telo[0].x == barrier.e && had.telo[0].y == barrier.f){
    mode = koniec;
    exit;
  }*/
 
  if (had.telo[0].x == odmena.c && had.telo[0].y == odmena.d){
    add_clanok();
    //draw_odmena();
 
  }
}
 
 
 
//****************************************
// ovladanie hry klavesami   -- funkcia hotova
//*****************************************
 
void ovladanie(int key) {
 
 
  // React to arrow keys
  switch (key) {
    case KEY_UP: 
    case 'w':
    case 'W':
    {
      had.telo[0].v.x = 0; // zmena smeru pohybu
      had.telo[0].v.y = -1; 
      break;
    }
    case KEY_DOWN: 
    case 's':
    case 'S':
    {
      had.telo[0].v.x = 0;
      had.telo[0].v.y = 1;
      break;
    }
    case KEY_RIGHT:
    case 'd':
    case 'D':
    {
      had.telo[0].v.x = 1;
      had.telo[0].v.y = 0;
      break;
    }
    case KEY_LEFT:
    case 'a':
    case 'A': 
    {
      had.telo[0].v.x = -1;
      had.telo[0].v.y = 0;
      break;
    }
    case 'q':
    case 'Q':
    {
      mode = koniec;
      exit;
    }
  }
 
}
 
// Game modes
void play() {
  had2(); // obnov zmeny
  skontroluj(); // 
  hra(); // nakresli hracie pole
}
 
 
void koniec() {
  //move((pole.vyska / 2) - 2, (pole.sirka / 2) - (strlen(text) / 2));
  char text[15] = "  GAME OVER !  ";
  int pol_vyska = pole.vyska/2;
  int pol_sirka = pole.sirka/2;
  //move((pole.vyska / 2) - 2, (pole.sirka / 2) - (strlen(text) / 2));
  move((pol_vyska), (pol_sirka) - (strlen(text) / 2));
  move((pol_vyska), (pol_sirka) - (strlen(text) / 2));
  char text1[31] = "  Press ENTER to start over  \0";
 
  hra(); // nakresli hracie pole
  refresh();
  attron(COLOR_PAIR(7));
  move((pol_vyska), (pol_sirka) - (strlen(text) / 2));
  printw("%s ", text,text1); // vypise game over
  attroff(COLOR_PAIR(7));
  refresh(); // refreshne zmeny a nacita ich
  while (getch() != '\n') {} // toto sa pouziva na ovladanie klavesami
  centre(); // nastavi hada za zaciatocnu poziciu
  mode = zaciatok;  
 
}
 
 
void zaciatok() {
 
  char text2[31] = "  Press BACKSPACE to start  !\0";
  char text3[50] = "  and then arrows or w, s, a, d or W, S, A, D   \0";
  attron( COLOR_PAIR( 3 ) );
  hra(); 
 
  int pol_vyska = pole.vyska/2;
  int pol_sirka = pole.sirka/2;
  move((pol_vyska) , (pol_sirka - (strlen(text2) / 2)));    
  move((pol_vyska) , (pol_sirka - (strlen(text3) / 2)));
  attrset( COLOR_PAIR( 7 ) );
  printw("%s, %s", text2,text3); // vypise text
  //printw("%s", text3);
  refresh(); // refreshne zmeny
  while (1) { // ovladanie klavesami
    int key = -1;
    ovladanie(key = getch());
    if (start(key)) {
      break;
    }
  }
  attroff(COLOR_PAIR(3));
  mode = play; 
}
 
 
//navazuje sa na game speed
 
void update() {
  mode();
}
 
 
void end(){
 
}
 
//*********************************************
// main 
//**************************************
 
 
int main() {
 
 
  initscr(); // inicializuje ncurses
  start_color();   // farbyyy
   init_pair( 1, COLOR_RED,     COLOR_BLACK );
    init_pair( 2, COLOR_GREEN,   COLOR_GREEN );
    init_pair( 3, COLOR_YELLOW,  COLOR_BLACK );
    init_pair( 4, COLOR_BLUE,    COLOR_BLACK );
    init_pair( 5, COLOR_CYAN,    COLOR_BLACK );
    init_pair( 6, COLOR_MAGENTA, COLOR_MAGENTA );
    init_pair( 7, COLOR_BLACK,   COLOR_WHITE );
 
 
 
 
  cbreak(); // klaves bez potvrdenia enteru
  noecho(); // aby nevypisovalo pismena ked pouzivam asdw
  keypad(stdscr, 2); 
 
 
  curs_set(0); // nebude vidno kurzor bude to vyzerat lepsie i suppose
 
 
 
  getmaxyx(stdscr, pole.vyska, pole.sirka); // zoberie max hodnotu vysku a sirku terminalu
 
  int riadok = 5; // riadok pre napisanie skore
  pole.vyska = pole.vyska - riadok; // odcita od vysky riadok pre score 
 
  int score = (had.size*10)-10;
 
 
 
 
  centre(); // vycentruje hada na stred
  draw_f(); // nakresli jedlo
  for (int i = 0; i<15; i++){
    draw_barrier();
  }
 
  //draw_odmena(); // nakresli odmenu
 
  draw_barrier();  // nakresli barieru
 
 
  hra(); // nakresli hru v maine
  signal(SIGALRM, update); // update funkcia pre rychlost 
  if (had.size <=5){
      int rychlost = 90000;
       ualarm(rychlost, rychlost); // urcuje rychlost
  }
 
  if (had.size > 5){
    int rychlost = 50000;
    ualarm(rychlost, rychlost);
  }
 
 
 
 
 
  while (1) {
    ovladanie(getch()); 
  }
 
 
 
  endwin(); // ukonci n curses aby sa vratilo do povodneho stavu
 
  return 0;
}
 