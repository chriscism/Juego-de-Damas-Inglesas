#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

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
int menu();
bool validarNombres(char *nombre);

int main(){
  int opcion = menu();
  char nombre1[20];
  char nombre2[20];
  bool esValido;
  switch(opcion){
    case 1:
    system("clear");
    while (getchar() != '\n');
      do{
        printf("Nombre del jugador 1: ");
        fgets(nombre1, 20, stdin);
        nombre1[strlen(nombre1) - 1] = '\0'; // elimino el salto de linea
        esValido = validarNombres(nombre1);
        if(!esValido){
          printf("El nombre solo debe tener letras y numeros.\n");
        }
      }while(!esValido);

      system("clear");
      do{
        printf("Nombre del jugador 2: ");
        fgets(nombre2, 20, stdin);
        nombre2[strlen(nombre2) - 1] = '\0'; // elimino el salto de linea
        esValido = validarNombres(nombre2);
        if(!esValido){
          printf("El nombre solo debe tener letras y numeros.\n");
        }

        if(strcmp(nombre1, nombre2) == 0){
          printf("Los nombres no pueden repetirse.\n");
        }
      }while(!esValido || strcmp(nombre1, nombre2) == 0);

      // ya que los nombres se validan correctamente se muestra el tablero
      system("clear");
      casilla_t tablero[8][8];
    inicializar_tablero(tablero);

      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
  }
}

void inicializar_tablero(casilla_t tablero[8][8]){
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

void imprimir_tablero(casilla_t tablero[8][8]){

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

int menu(){
  char opcion[10];
  while (1) {
  printf("====== DAMAS INGLESAS =====\n");
  printf("[1] Jugar\n[2] Creditos\n[3] Historial de victorias\n[4] Salir\n"); 
  scanf("%s", opcion);

  // Validar que sea un solo dígito entre '1' y '4'
  if ((opcion[0] >= '1' && opcion[0] <= '4') && opcion[1] == '\0') {
/*Convierto el caracter a entero y hago que la funcion regrese ese valor*/
  int numero = atoi(opcion);
      return numero;
  }else{
      printf("Entrada invalida. Ingrese un numero entre 1 y 4.\n");
    sleep(1);
    system("clear");
    }
  }
}

bool validarNombres(char *nombre){
  for (int i = 0; i < strlen(nombre); i++) {
        // analiza caracter por caracter y si no es letra ni espacio es invalido
        if (!((nombre[i] >= 'a' && nombre[i] <= 'z') || 
              (nombre[i] >= 'A' && nombre[i] <= 'Z') || 
              nombre[i] == ' ')) {
            return false;
        }
    }
    return true;
}
