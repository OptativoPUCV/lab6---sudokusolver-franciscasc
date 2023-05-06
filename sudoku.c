#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

bool verificar(Node* n, int numero){
  int arreglo[10] = {};
  int z = 0;
  for(int h = 0; h < 9; h++){
    if(n->sudo[h][z] == numero){
      arreglo[h] += 1;
      return false;
    }
    z++;
  }
  z = 0;
  for(int j = 0; j < 9; j++){
    if(n->sudo[j][z] == numero){
      arreglo[j] += 1;
      return false;
    }
    z++;
  }

  //recorrer matriz 3x3
  int j = 4, p;
  for(p = 0; p < 9; p++){
    int h = 3 *(j/3) + (p/3);
    int z = 3 *(j%3) + (p%3);
    if(n->sudo[h][z] == numero){
      arreglo[p] += 1;
      return false;
    }
    /*printf("%d", n->sudo[h][z]);
    if(p%3 == 2) printf("\n");*/
  }
  
  return true;
}

int is_valid(Node* n){
  int k, b;
  for(k = 0; k < 9; k++){
    for(b = 0; b < 9; b++){
      if(n->sudo[k][b] != 0){
        if(!verificar(n, k))
          return 0;
      }
    }
  }
  return 1;
}

bool busqueda(Node * nodoNuevo, int aumento, bool mov){
  int m, z;
  for(m = 0; m < 9; m++){
    for(z = 0; z < 9; z++){
      if(nodoNuevo->sudo[m][z] == 0){
        nodoNuevo->sudo[m][z] = aumento;
        mov = true;
        return mov;
      }
    }
  }
  return false ;
}

List* get_adj_nodes(Node* n){
    List* list = createList();
    int h;
    bool nuevoMov = false;
    if(n == NULL) return NULL;
    for(h = 1; h <= 9; h++){
      Node* nodoNuevo = createNode();
      nodoNuevo = copy(n);
      //if(is_valid(nodoNuevo))
      nuevoMov = busqueda(nodoNuevo, h, nuevoMov);  
      if(nuevoMov != true){
        break;
      }
    //esto no fucionó
      /*for(m = 0; m < 9; m++){
        for(z= 0; z < 9; z++){
          if(n->sudo[m][z] == '0'){
            n->sudo[m][z] = h;
            break;
          }
        }
      }*/
      pushBack(list, nodoNuevo);
    }
  return list;
}


int is_final(Node* n){
    int z = 0;
    for(int h = 0; h < 9; h++){
      if(n->sudo[z][h] == 0)
        return 0;
      z++;
    }
    return 1;
}

Node* DFS(Node* initial, int* cont){
  Stack * S = createStack(); 
  push(S, initial);
  while(S != NULL){
    if(top(S) != NULL) {
      pop(S);
      break;
    }
  }
  
  return NULL;
}




/*int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/