#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n) {
   int row[9][9] = {0};
   int col[9][9] = {0};
   int box[9][9] = {0};
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         if (n->sudo[i][j] != 0) {
            int num = n->sudo[i][j] - 1;
               int k = (i / 3) * 3 + j / 3;// k es el indice de la caja
               if (row[i][num] || col[j][num] || box[k][num])//Se verifica si el número num ya está presente en la fila i, la columna j o el cuadro 3x3 al que pertenece la celda (i, j)
               return 0;
               row[i][num] = col[j][num] = box[k][num] = 1;
            }
        }
    }
   return 1;
}

//9x9
List* get_adj_nodes(Node* n) {
    List* list = createList();
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (n->sudo[i][j] == 0) { // Si hay un cero en la posición (i, j)
                for (int num = 1; num <= 9; num++) {
                    Node* new_node = copy(n);
                    new_node->sudo[i][j] = num;
                    if (is_valid(new_node)) {//prueba con todos los numeros de 1 a 9 y ve si es valido
                        pushBack(list, new_node);
                    } else {
                        free(new_node); 
                    }
                }
                return list; 
            }
        }
    }
    return list; 
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/