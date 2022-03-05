#ifndef __MAIN_HEADER
#define __MAIN_HEADER
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>

typedef struct {
  int x,y;
} Rych;

typedef struct {
  Rych v;
  int x,y;
} HadTail;

typedef struct {
  HadTail telo[200];
  size_t size;
} Had;

typedef struct {
  int  vyska,sirka;
} Pole;

typedef struct {
  int a,b;
} Food;

typedef struct {
  int c,d;
} Odmena;


typedef struct{
  size_t e,f;
} Barrier;


void zaciatok();
void koniec();
void play();
void hra();
void draw_f();
void draw_odmena();
void draw_barrier();
void centre();
void add_clanok();
void hra2();
void skontroluj();
void ovladanie (int key);
void play();
void koniec();
void zaciatok();
void update();
void end();



Had had;
Food food;
Pole pole;
Barrier barrier;
Odmena odmena;

void (*mode)(void) = zaciatok;



#endif