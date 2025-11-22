#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define WHITE "\033[0;37m"

typedef struct ficha {
  char color[11];
  int tipo; // 0 peon, 1 coronada
} ficha_t;

typedef struct casilla {
  char color[11];
  bool ocupada;
  ficha_t ficha;
} casilla_t;
    
void imprimir_tablero(casilla_t tablero[8][8]);
void inicializar_tablero(casilla_t tablero[8][8]);
int main(){
  
}

void inicializar_tablero(casilla_t tablero[8][8]) {
  ficha_t ficha_jugador1 = {RED};
  ficha_t ficha_jugador2 = {BLUE};
  casilla_t casilla_aux;
  /*La impresion se realizara considerando que se esta viendo el tablero desde
   *arriba, comenzando con la esquina superior izquierda, la cual se
   *considerara como la posicion 0,0.
   */
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      // Si es fila par o 0 comienza con casilla clara (pares o 0 son claras)
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          casilla_aux.ocupada = false;
          strcpy(casilla_aux.color, WHITE);
        } else {
          // Fichas del primer jugador
          if (i == 0 || i == 2) {
            casilla_aux.ocupada = true;
            casilla_aux.ficha = ficha_jugador1;
          } else if (i == 6) { // Fichas del segundo jugador
            casilla_aux.ocupada = true;
            casilla_aux.ficha = ficha_jugador2;
          } else {
            casilla_aux.ocupada = false;
          }
          strcpy(casilla_aux.color, YELLOW);
        }
      } else {
        // Si es fila impar comienza con casilla oscura (pares o 0 son oscuras)
        if (j % 2 == 0) {
          if (i == 1) {
            casilla_aux.ocupada = true;
            casilla_aux.ficha = ficha_jugador1;
          } else if (i == 5 || i == 7) {
            casilla_aux.ocupada = true;
            casilla_aux.ficha = ficha_jugador2;
          } else {
            casilla_aux.ocupada = false;
          }
          strcpy(casilla_aux.color, YELLOW);
        } else {
          casilla_aux.ocupada = false;
          strcpy(casilla_aux.color, WHITE);
        }
      }
      tablero[i][j] = casilla_aux;
    }
  }
  imprimir_tablero(tablero);
}

void imprimir_tablero(casilla_t tablero[8][8]) {
  // Cambiar al color correspondiente
  for (int j = 0; j < 8; j++) {
    printf("    %d  ", j);
  }
  for (int i = 0; i < 8; i++) {
    printf("\n");
    for (int j = 0; j < 8; j++) {
      printf("%s", tablero[i][j].color);
      printf("   --- ");
    }
    printf("\n");
    printf("%s", WHITE);
    printf("%d", i);
    for (int j = 0; j < 8; j++) {
      printf("%s", tablero[i][j].color);
      if (tablero[i][j].ocupada)
        printf(" | %s%c %s| ", tablero[i][j].ficha.color, 'P',
               tablero[i][j].color);
      else
        printf(" |   | ");
    }
    printf("\n");
    for (int j = 0; j < 8; j++) {
      printf("%s", tablero[i][j].color);
      printf("   --- ");
    }
    printf("\n");
  }
}