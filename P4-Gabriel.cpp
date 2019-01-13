#include <stdio.h> //printf & scanf
#include <conio.h> //getch
#include <string.h> //strncmp & strcpy
#include <ctype.h> //toupper
#include <windows.h> //system
#include "Cuenca.h"

int opcion;
TipoDato Datos;

/*** Diseño del menu ***/

void bienvenida() {
  system("COLOR F4");
  printf("\n\n          Bienvenido al programa de gestion de Cuencas y presas.\n");
  Sleep(2000);
  printf("          Desarrollado por Gabriel Noguerales");
  Sleep(1000);
}

void imprimirMenu() {

  fflush(stdin);
  system("@cls||clear");
  system("COLOR F9");
  printf("\n\n");
  printf("          ........................................... \n");
  printf("          :      Gestion de Reservas de Agua        :\n");
  printf("          :.........................................:\n");
  printf("          : Alta cuenca/presa (Pulsar A)            :\n");
  printf("          : Nueva medicion (Pulsar N)               :\n");
  printf("          : Registros (Pulsar R)                    :\n");
  printf("          : Variaciones mensuales (Pulsar V)        :\n");
  printf("          : Salir (Pulsar S)                        :\n");
  printf("          : %cTeclear una opcion valida (A|N|R|V|S)? :\n",168);
  printf("          :.........................................:\n");
  printf("\n\n");

}
/** Seleccion de opcion **/
char respuestaUsuario() {
  char respuesta;
  do {
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),125);
    printf("\n>>> ");
    fflush(stdin);
    scanf("%s",&respuesta);
    respuesta = toupper(respuesta);
    if (respuesta != 'A' && respuesta != 'S' && respuesta != 'N' && respuesta != 'V' && respuesta != 'R') {
      printf("Error: La opcion elegida no valida");
    }
  } while (respuesta != 'A' && respuesta != 'S' && respuesta != 'N' && respuesta != 'V' && respuesta != 'R');
  system("COLOR F9");
  return respuesta;
}



/** Tratamiento de la salida del usuario del programa **/
char salida() {
  char respuesta;
  system("@cls||clear");
  printf("\n\n\t\t%cEsta seguro que desea salir del programa (S/N)?",168);
  do {
    printf("\n\t\t>>> ");
    fflush(stdin);
    scanf("%s",&respuesta);
    respuesta = toupper(respuesta); //Normalizamos el input a mayusculas
    if (respuesta != 'S' && respuesta != 'N') {
      printf("\t\tError: La opcion elegida no valida");
    }
  } while (respuesta != 'S' && respuesta != 'N');
  return respuesta;
}

/** Ejecucion de la opcion elegida **/
char analizarRespuesta(TipoDato &dato,char r) {
  char charSalida = 'A';
  switch (r) {
  case 'A': system("@cls||clear"); fflush(stdin);
    dato.introducirCuenca();
    Sleep(1000);
    break;
  case 'V': dato.verRegistros();
    Sleep(1000);
    break;
  case 'S': charSalida = salida();
    break;
  case 'N': system("@cls||clear"); fflush(stdin); dato.introducirMedicion(); Sleep(1000);
    break;
  }
  return charSalida;
}


void menu() {
  char r = ' ';
  while (r!='S') {
    imprimirMenu();
    r = analizarRespuesta(Datos,respuestaUsuario());
  }
}



int main() {
  bienvenida();
  menu();
  //Getch maneja la salida del programa
  getch();
}
