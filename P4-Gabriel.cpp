#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "Cuenca.h"

int opcion;
TipoDato Datos;

/*** Diseño del menu ***/

char respuestaUsuario(){
  char respuesta;
  do{
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),125);
    printf("\n>>> ");
    fflush(stdin);
    scanf("%s",&respuesta);
    respuesta = toupper(respuesta);
    if(respuesta != 'A' && respuesta != 'S' && respuesta != 'N' && respuesta != 'V' && respuesta != 'R'){
      printf("Error: La opcion elegida no valida");
    }
  }while(respuesta != 'A' && respuesta != 'S' && respuesta != 'N' && respuesta != 'V' && respuesta != 'R');
  system("COLOR F9");
  return respuesta;
  }

void imprimirMenu(){

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
void bienvenida(){
  system("COLOR F4");
  printf("\n\n          Bienvenido al programa de gestion de Cuencas y presas.\n");
  Sleep(2000);
  printf("          Desarrollado por Gabriel Noguerales");
  Sleep(1000);
  }
char salida(){
  char respuesta;
  system("@cls||clear");
  printf("%cEsta seguro que desea salir del programa (S/N)?",168);
  do{
  printf("\n>>> ");
  fflush(stdin);
  scanf("%s",&respuesta);
  respuesta = toupper(respuesta); //Normalizamos el input a mayusculas
  }while(respuesta != 'S' && respuesta != 'N');
  return respuesta;
}
void analizarRespuesta(TipoDato &dato,char r){
    TipoNombre s;
    switch(r){
    case 'A': system("@cls||clear"); fflush(stdin);
              dato.introducirCuenca();
              printf("%s",dato.cuenca[0].nombreCuenca);
              Sleep(1000);
              break;
    case 'V': dato.verRegistros();
              Sleep(3000);
              break;

  }}
void menu() {
  char r;
  while(r!='S'){
    imprimirMenu();
    analizarRespuesta(Datos,respuestaUsuario());
    r = salida();
}}
int main() {
  bienvenida();
  menu();
  getch();
}
