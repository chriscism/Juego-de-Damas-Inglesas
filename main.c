#include <stdio.h>
#include <stdbool.h>

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
    
int main(){
  
}
