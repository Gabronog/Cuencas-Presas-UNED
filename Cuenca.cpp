#include <stdio.h>
#include "Cuenca.h"
#include <ctype.h>
#include <windows.h>
void TipoDato::verRegistros() {
  printf("La presa %s - %s tiene una capacidad de %d ",cuenca[0].nombreCuenca,cuenca[0].presa[0].nombrePresa,cuenca[0].presa[0].volumenMax);
}
void TipoDato::introducirCuenca() {
  TipoNombre nombreCuenca, nombrePresa;
  bool existente = false;  //Pondremos en true cuando hayamos una presa con ese nombre para prevenir tener 2 presas con el mismo nombre
  bool escrito = false;  // Pondremos en true cuando hayamos escrito la presa en una cuenca para evitar que se escriba 2 veces
  bool cuencaExistente = false; // Pondremos en true cuando hayamos encontrado una cuenca con el mismo nombre para prevenir la repeticion
  bool limitemax = false; //Pondremos en true cuando las 3 cuencas esten llenas para evitar que el codigo de comprobacion se repita 3 veces
  int volumenMaxPresa;  //Capacidad de la presa

  // Me duele tener que hacer scanf dentro de una funcion y no poder usar punteros aqui

  //Pedimos los datos al usuario
  printf("\n\n");
  printf("\t\t..........................................................\n");
  printf("\t\t:               Alta de cuenca/Presa                     :\n");
  printf("\t\t:     Por favor introduzca el nombre de la cuenca        :\n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%s",&nombreCuenca);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t     Por favor introduzca el nombre de la Presa  \n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%s",&nombrePresa);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t     Por favor introduzca la capacidad de la presa  \n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%d",&volumenMaxPresa);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t             Capacidad de la Presa: %d                     \n",volumenMaxPresa);
  printf("\t\t.......................................................... \n");
  for (int i=0;i<3;i++) {
    if (cuenca[i].contieneDatos==true) {
      //Hay alguna cuenca almacenada con el mismo nombre?
      if (strcmp(cuenca[i].nombreCuenca,nombreCuenca)==0) {
        cuencaExistente=true;
        for (int j=0;j<5;j++) {
          //Hay alguna presa almacenada con el mismo nombre?
          if (strcmp(cuenca[i].presa[j].nombrePresa,nombrePresa)==0) {
            printf("\n\n La presa que intenta registrar ya ha sido registrada previamente");
            Sleep(3000);
            existente = true;
          }
        }
        //Si no hay ninguna coincidencia creamos una presa en el siguiente espacio vacio
        if (existente == false) {
          for (int j=0; j<5; j++) {
            if (cuenca[i].presa[j].contieneDatos == false && escrito == false) {
              cuenca[i].presa[j].volumenMax = volumenMaxPresa;
              strcpy(cuenca[i].presa[j].nombrePresa,nombrePresa);
              cuenca[i].presa[j].contieneDatos = true;
              escrito=true;
            }
          }
        }
      }
    } else if (cuencaExistente==false) {
      //Si no hay ninguna cuenca almacenado con el mismo nombre
      if (cuenca[i].contieneDatos== false) {
        //Si hay alguna cuenca sin datos almacenamos la cuenca y presa
        cuencaExistente = true;
        cuenca[i].contieneDatos = true;
        strcpy(cuenca[i].nombreCuenca,nombreCuenca);
        cuenca[i].presa[0].volumenMax = volumenMaxPresa;
        strcpy(cuenca[i].presa[0].nombrePresa,nombrePresa);
        cuenca[i].presa[0].contieneDatos = true;
      }
    }
    //Si no hay espacio para la cuenca que desea insertar
    if (cuenca[0].contieneDatos == true && cuenca[1].contieneDatos==true && cuenca[2].contieneDatos==true && limitemax == true) {
      printf("Ya se ha alcanzado el limite de cuencas que se pueden guardar.");
      limitemax = true;
      Sleep(2000);
    }
  }
}
