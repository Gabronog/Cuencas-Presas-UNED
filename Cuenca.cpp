#include <stdio.h>
#include "Cuenca.h"
#include <ctype.h>
#include <windows.h>
void TipoDato::verRegistros() {
  for(int i=0; i<3; i++){
    for(int j=0;j<3;j++){
      if(cuenca[i].contieneDatos && cuenca[i].presa[j].contieneDatos){
      printf("La presa %s - %s tiene una capacidad de %d \n",cuenca[i].nombreCuenca,cuenca[i].presa[j].nombrePresa,cuenca[i].presa[j].volumenMax);
}}}}

/** Introducir datos dentro de nuestro TipoDato.cuenca[] **/
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
  scanf("%s",nombreCuenca);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t     Por favor introduzca el nombre de la Presa  \n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%s",nombrePresa);
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
  system("pause");
  for (int i=0;i<3;i++) {
    if (cuenca[i].contieneDatos==true) {
      //Hay alguna cuenca almacenada con el mismo nombre?
      if (strcmp(cuenca[i].nombreCuenca,nombreCuenca)==0) {
        cuencaExistente=true;
        for (int j=0;j<5;j++) {
          //Hay alguna presa almacenada con el mismo nombre?
          if (strcmp(cuenca[i].presa[j].nombrePresa,nombrePresa)==0) {
            printf("\n\n La presa que intenta registrar ya ha sido registrada previamente\n");
            system("pause");
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
              printf("\tGuardado!\n");
              system("pause");
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
        printf("\tGuardado!\n");
        system("pause");
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

/**  Como pueden haber 2 presas con el mismo nombre siempre y cuando este en cuencas distintas solicitaremos tambien la cuenca para introducir una medici�n **/
void TipoDato::introducirMedicion(){
  int volumenMedido, anio, dia, mes;
  TipoNombre nombrePresa, nombreCuenca;

  printf("\n\n");
  printf("\t\t..........................................................\n");
  printf("\t\t:                    Nueva medicion                      :\n");
  printf("\t\t:       Por favor introduzca el nombre de la cuenca      :\n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%s",nombreCuenca);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t                    Nueva medicion                      \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t     Por favor introduzca el nombre de la Presa  \n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%s",nombrePresa);

  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t                        Nueva medicion                    \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t     Por favor introduzca el volumen medido en la presa  \n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%d",&volumenMedido);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t             Volumen medido en la Presa: %d                     \n",volumenMedido);
  printf("\t\t     Por favor introduzca el dia que se produjo la medicion  \n");
  printf("\t\t.......................................................... \n");
  do{printf("\t\t\n>>> ");
  scanf("%d",&dia);}while(dia>31 || dia<1);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t             Volumen medido en la Presa: %d                     \n",volumenMedido);
  printf("\t\t             Dia de la medicion: %d                     \n",dia);
  printf("\t\t     Por favor introduzca el mes que se produjo la medicion  \n");
  printf("\t\t.......................................................... \n");
  do{printf("\t\t\n>>> ");
  scanf("%d",&mes);}while(mes>12 || mes<1 || (dia>29 && mes == 2)||((mes == 6 || mes==4||mes==11||mes==9) && dia==31));
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t             Volumen medido en la Presa: %d                     \n",volumenMedido);
  printf("\t\t             Dia de la medicion: %d                     \n",dia);
  printf("\t\t             Mes de la medicion: %d                     \n",mes);
  printf("\t\t     Por favor introduzca el a%co que se produjo la medicion  \n",164);
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%d",&anio);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t             Volumen medido en la Presa: %d                     \n",volumenMedido);
  printf("\t\t             Dia de la medicion: %d                     \n",dia);
  printf("\t\t             Mes de la medicion: %d                     \n",mes);
  printf("\t\t             A%co de la medicion: %d                     \n",164,mes);
  printf("\t\t.......................................................... \n");

  system("pause");
}
