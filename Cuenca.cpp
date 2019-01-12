#include <stdio.h>
#include "Cuenca.h"
#include <ctype.h>
#include <windows.h>
void TipoDato::verRegistros(){
    printf("La presa %s - %s tiene una capacidad de %d ",cuenca[0].nombreCuenca,cuenca[0].presa[0].nombrePresa,cuenca[0].presa[0].volumenMax);
  }
void TipoDato::introducirCuenca(){
  TipoNombre nCuenca, nombrePresa;
  bool existente = false;
  bool escrito = false;
  int volumenMaxPresa;
  /*if(cuenca[0].contieneDatos == true && cuenca[1].contieneDatos == true && cuenca[2].contieneDatos == true){
    printf("\t\t Ya se ha almacenado el numero maximo de cuencas permitido");
  }
  else{*/
    printf("\n\n");
    printf("\t\t..........................................................\n");
    printf("\t\t:               Alta de cuenca/Presa                     :\n");
    printf("\t\t:     Por favor introduzca el nombre de la cuenca        :\n");
    printf("\t\t.......................................................... \n");
    printf("\t\t\n>>> ");
    scanf("%s",&nCuenca);
    //nCuenca = toupper(nCuenca);
    system("@cls||clear");
    printf("\n\n\t\t.......................................................... \n");
    printf("\t\t               Alta de cuenca/Presa               \n");
    printf("\t\t             Nombre de la cuenca: %s                      \n",nCuenca);
    printf("\t\t     Por favor introduzca el nombre de la Presa  \n");
    printf("\t\t.......................................................... \n");
    printf("\t\t\n>>> ");
    scanf("%s",&nombrePresa);
    //nombrePresa = toupper(nombrePresa);
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
    //Sleep(10000);
    if(cuenca[0].contieneDatos == false){
      strcpy(cuenca[0].nombreCuenca,nCuenca);
      if(cuenca[0].presa[0].contieneDatos == false){
        strcpy(cuenca[0].presa[0].nombrePresa,nombrePresa);
        cuenca[0].presa[0].volumenMax = volumenMaxPresa;
        cuenca[0].presa[0].contieneDatos = true;
        cuenca[0].contieneDatos = true;
        printf("Información guardada");
        Sleep(1000);
      }
    }
    else if(strcmp(cuenca[0].nombreCuenca,nCuenca) == 0){
      for(int i=0;i<5;i++){
        if(strcmp(cuenca[0].presa[i].nombrePresa,nombrePresa)==0){
          printf("\n\n La presa que intenta registrar ya ha sido registrada previamente");
          Sleep(3000);
          existente = true;
        }
      }
      if(existente == false){
        for(int i=0; i<5; i++){
          if(cuenca[0].presa[i].contieneDatos == false && escrito == false){
            cuenca[0].presa[i].volumenMax = volumenMaxPresa;
            strcpy(cuenca[0].presa[i].nombrePresa,nombrePresa);
            }
          }
        }
    }
  }
