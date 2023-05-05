#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
   char ultimoM;
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

int is_valid(Node* n){

    return 1;
}


List* get_adj_nodes(Node* n){
    List* list = createList();
    int h, z, m;
    //char nuevoMov;
    /*if(n->ultimoM == '0'){
      nuevoMov = '0';
    }*/
    for(h = 0; h < 9; h++){
      Node* nodoNuevo = createNode();
      nodoNuevo = copy(n);
      for(m = 0; m < 9; m++){
        for(z= 0; z < 9; z++){
        if(n->sudo[h][z] == '0'){
          n->sudo[h][z] = m++;
        }
      }
    }
      pushBack(list, nodoNuevo);
    }
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  /*Stack * S = createStack(); 

  while(S != NULL){
    
  }*/
  
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