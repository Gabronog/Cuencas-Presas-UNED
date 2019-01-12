#include <stdio.h>
#include "Cuenca.h"
#include <ctype.h>
#include <windows.h>
void TipoDato::verRegistros() {
  printf("La presa %s - %s tiene una capacidad de %d ",cuenca[0].nombreCuenca,cuenca[0].presa[0].nombrePresa,cuenca[0].presa[0].volumenMax);
}
void TipoDato::introducirCuenca() {
  TipoNombre nCuenca, nombrePresa;
  bool existente = false;
  bool escrito = false;
  bool cuencaExistente = false;
  bool limitemax = false;
  int volumenMaxPresa;
  printf("\n\n");
  printf("\t\t..........................................................\n");
  printf("\t\t:               Alta de cuenca/Presa                     :\n");
  printf("\t\t:     Por favor introduzca el nombre de la cuenca        :\n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%s",&nCuenca);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nCuenca);
  printf("\t\t     Por favor introduzca el nombre de la Presa  \n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%s",&nombrePresa);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t     Por favor introduzca la capacidad de la presa  \n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%d",&volumenMaxPresa);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t             Capacidad de la Presa: %d                     \n",volumenMaxPresa);
  printf("\t\t.......................................................... \n");
  for (int i=0;i<3;i++) {
    if (cuenca[i].contieneDatos==true) {
      printf("A");
      if (strcmp(cuenca[i].nombreCuenca,nCuenca)==0) {
        printf("S");
        cuencaExistente=true;
        for (int j=0;j<5;j++) {
          if (strcmp(cuenca[i].presa[j].nombrePresa,nombrePresa)==0) {
            printf("\n\n La presa que intenta registrar ya ha sido registrada previamente");
            Sleep(3000);
            existente = true;
          }
        }
        if (existente == false) {
          printf("W");
          for (int j=0; j<5; j++) {
            if (cuenca[i].presa[j].contieneDatos == false && escrito == false) {
              printf("Z");
              cuenca[i].presa[j].volumenMax = volumenMaxPresa;
              strcpy(cuenca[i].presa[j].nombrePresa,nombrePresa);
              cuenca[i].presa[j].contieneDatos = true;
              escrito=true;
            }
          }
        }
      }
    } else if (cuencaExistente==false) {
      printf("H");
      if (cuenca[i].contieneDatos== false) {
        cuencaExistente = true;
        cuenca[i].contieneDatos = true;
        strcpy(cuenca[i].nombreCuenca,nCuenca);
        cuenca[i].presa[0].volumenMax = volumenMaxPresa;
        strcpy(cuenca[i].presa[0].nombrePresa,nombrePresa);
        cuenca[i].presa[0].contieneDatos = true;
      }
    }
    if (cuenca[0].contieneDatos == true && cuenca[1].contieneDatos==true && cuenca[2].contieneDatos==true && limitemax == true) {
      printf("Ya se ha alcanzado el limite de cuencas que se pueden guardar.");
      limitemax = true;
      Sleep(2000);
    }
  }
}
