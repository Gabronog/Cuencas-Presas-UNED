#include <stdio.h>
#include "Cuenca.h"
#include <ctype.h>
#include <windows.h>
#include <conio.h>

void TipoDato::verRegistros() {
  for (int i=0; i<3; i++) {
    for (int j=0;j<3;j++) {
      if (cuenca[i].contieneDatos && cuenca[i].presa[j].contieneDatos) {
        printf("La presa %s - %s tiene una capacidad de %d \n",cuenca[i].nombreCuenca,cuenca[i].presa[j].nombrePresa,cuenca[i].presa[j].volumenMax);
      }
    }
  }
}

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

/**
Introducir datos de las mediciones a una presa
Como pueden haber 2 presas con el mismo nombre en cuencas distintas
solicitaremos tambien la cuenca para introducir una medición **/
void TipoDato::introducirMedicion() {
  int volumenMedido, anio, dia, mes,contador;
  TipoNombre nombrePresa, nombreCuenca;
  TipoFecha fecha;
  bool cuencaEncontrada = false;
  bool presaEncontrada = false;
  bool escrito = false;

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
  dia = 0;
  contador = 0;
  while (dia>31 || dia<1) {
    contador++;
    if (contador == 50) {
      system("@cls || clear");
      printf("\n\nError fatal, violacion de tipo.");
      system("pause");
      return;
    }
    printf("\t\t\n>>> ");
    scanf("%d",&dia);
    if (dia>31 || dia<1) {
      printf("%d no es valido",dia);
    }
  }
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t             Volumen medido en la Presa: %d                     \n",volumenMedido);
  printf("\t\t             Dia de la medicion: %d                     \n",dia);
  printf("\t\t     Por favor introduzca el mes que se produjo la medicion  \n");
  printf("\t\t.......................................................... \n");
  mes = 0;
  contador = 0;
  while (mes>12 || mes<1 || (dia>29 && mes == 2)||((mes == 6 || mes==4||mes==11||mes==9) && dia==31)) {
    contador++;
    if (contador == 50) {
      system("@cls || clear");
      printf("\n\nError fatal, violacion de tipo.");
      system("pause");
      return;
    }
    printf("\t\t\n>>> ");
    scanf("%d",&mes);
    if (mes<1 || mes>12) {
      printf("%d no es valido",mes);
    }
  }
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
  contador = 0;
  anio = 0;
  while (anio<=0) {
    contador++;
    printf("\t\t\n>>> ");
    scanf("%d",&anio);
    if (contador == 50 || anio > 50000) {
      system("@cls || clear");
      printf("\n\nError fatal, violacion de tipo.");
      system("pause");
      return;
    }

  }
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t             Volumen medido en la Presa: %d                     \n",volumenMedido);
  printf("\t\t             Dia de la medicion: %d                     \n",dia);
  printf("\t\t             Mes de la medicion: %d                     \n",mes);
  printf("\t\t             A%co de la medicion: %d                     \n",164,anio);
  printf("\t\t.......................................................... \n");
  fecha.anio = anio;
  fecha.mes = mes;
  fecha.dia = dia;
  for (int i=0;i<3;i++) {
    if (cuenca[i].contieneDatos==true && escrito == false) {
      //Hay alguna cuenca almacenada con el mismo nombre?
      if (strcmp(cuenca[i].nombreCuenca,nombreCuenca)==0) {
        cuencaEncontrada = true;
        for (int j=0;j<5;j++) {
          //Hay alguna presa almacenada con el mismo nombre?
          if (strcmp(cuenca[i].presa[j].nombrePresa,nombrePresa)==0) {
            presaEncontrada = true;
            if (cuenca[i].presa[j].volumenMax>=volumenMedido) {
              for (int k=0;k<100;k++) {
                if (cuenca[i].presa[j].registro[k].contieneDatos == false && escrito == false) {
                  /*
                    Comprobamos


                  */
                  if (k == 0 ||
                      (cuenca[i].presa[j].registro[k-1].fecha.anio < fecha.anio) ||
                      ((cuenca[i].presa[j].registro[k-1].fecha.anio == fecha.anio) && (cuenca[i].presa[j].registro[k-1].fecha.mes < fecha.mes)) ||
                      ((cuenca[i].presa[j].registro[k-1].fecha.anio == fecha.anio) && (cuenca[i].presa[j].registro[k-1].fecha.mes == fecha.mes) && (cuenca[i].presa[j].registro[k-1].fecha.dia < fecha.dia))) {
                    if (fecha.comprobarFecha()) {
                      if (fecha.dia < 29 || fecha.mes != 2 || fecha.comprobarBisiesto()) {
                        cuenca[i].presa[j].registro[k].volumenMedido = volumenMedido;
                        cuenca[i].presa[j].registro[k].fecha.anio = fecha.anio;
                        cuenca[i].presa[j].registro[k].fecha.mes = fecha.mes;
                        cuenca[i].presa[j].registro[k].fecha.dia = fecha.dia;
                        cuenca[i].presa[j].registro[k].contieneDatos = true;
                        cuenca[i].presa[j].registro[k].ultimoRegistro = true;

                        if (k!=0) {
                          cuenca[i].presa[j].registro[k-1].ultimoRegistro = false;
                        }
                        escrito = true;
                        printf("Guardado el registro!\n");
                      } else {
                        printf("\nLa fecha \" %d de Febrero no es valida en un a%co no bisiesto \n",fecha.dia,164);escrito=true;
                      }
                    }
                  } else {
                    escrito = true;
                    printf("La fecha del registro debe ser posterior a la fecha del ultimo registro");
                  }
                }
              }
            } else {
              printf("\nEl volumen medido no puede exceder la capacidad de la presa\n");
            }
          }
        }
      }
    }
  }
  if (cuencaEncontrada == false) {
    printf("\nNo se ha encontrado la cuenca %s\n",nombreCuenca);
  }

  system("pause");
}

void TipoDato::comprobarRegistros() {

  int anio, dia, mes, media,contador;
  int totalVolMax = 0;
  int totalVolMedido = 0;
  TipoNombre nombrePresa, nombreCuenca;
  TipoFecha fecha;
  bool cuencaRegistrada = false;
  bool presaRegistrada = false;

  /** Introduccion de datos **/
  system("@cls||clear");
  printf("\n\n");
  printf("\t\t..........................................................\n");
  printf("\t\t:                Consulta de mediciones                  :\n");
  printf("\t\t:       Por favor introduzca el nombre de la cuenca      :\n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%s",nombreCuenca);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t                  Consulta de mediciones                      \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t     Por favor introduzca el nombre de la Presa  \n");
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  scanf("%s",nombrePresa);
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t                  Consulta de mediciones                      \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t     Por favor introduzca el dia a partir del cual quiere consultar las mediciones  \n");
  printf("\t\t.......................................................... \n");
  dia = 0;
  contador = 0;
  while (dia>31 || dia<1) {
    contador++;
    if (contador == 50) {
      system("@cls || clear");
      printf("\n\nError fatal, violacion de tipo.");
      system("pause");
      return;
    }
    printf("\t\t\n>>> ");
    scanf("%d",&dia);
    if (dia>31 || dia<1) {
      printf("%d no es valido",dia);
    }
  }
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t                  Consulta de mediciones                      \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t             Dia inicial de consulta de las mediciones: %d                     \n",dia);
  printf("\t     Por favor introduzca el mes a partir del cual quiere consultar las mediciones  \n");
  printf("\t\t.......................................................... \n");
  mes = 0;
  contador = 0;
  while (mes>12 || mes<1 || (dia>29 && mes == 2)||((mes == 6 || mes==4||mes==11||mes==9) && dia==31)) {
    contador++;
    if (contador == 50) {
      system("@cls || clear");
      printf("\n\nError fatal, violacion de tipo.");
      system("pause");
      return;
    }
    printf("\t\t\n>>> ");
    scanf("%d",&mes);
    if (mes<1 || mes>12) {
      printf("%d no es valido",mes);
    }
  }
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t               Alta de cuenca/Presa               \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t             Dia inicial de consulta de las mediciones: %d                     \n",dia);
  printf("\t\t             Mes inicial de consulta de las mediciones: %d                     \n",mes);
  printf("\t     Por favor introduzca el a%co a partir del cual quiere consultar las mediciones  \n",164);
  printf("\t\t.......................................................... \n");
  printf("\t\t\n>>> ");
  contador = 0;
  anio = 0;
  while (anio<=0) {
    contador++;
    printf("\t\t\n>>> ");
    scanf("%d",&anio);
    if (contador == 50 || anio > 50000) {
      system("@cls || clear");
      printf("\n\nError fatal, violacion de tipo.");
      system("pause");
      return;
    }

  }
  system("@cls||clear");
  printf("\n\n\t\t.......................................................... \n");
  printf("\t\t                  Consulta de mediciones                      \n");
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t             Nombre de la Presa: %s                      \n",nombrePresa);
  printf("\t\t             Dia inicial de consulta de las mediciones: %d                     \n",dia);
  printf("\t\t             Mes inicial de consulta de las mediciones: %d                     \n",mes);
  printf("\t\t             A%co inicial de consulta de las mediciones: %d                     \n",164,anio);
  printf("\t\t.......................................................... \n");
  fecha.anio = anio;
  fecha.mes = mes;
  fecha.dia = dia;
  if (fecha.comprobarFecha() == true && (fecha.dia < 29 || fecha.mes != 2 || fecha.comprobarBisiesto())) {
    for (int i=0;i<3;i++) {
      if (strcmp(cuenca[i].nombreCuenca,nombreCuenca)==0) {
        /** Existen registros de la cuenca **/
        cuencaRegistrada = true;
        for (int j=0;j<5;j++) {
          if (strcmp(cuenca[i].presa[j].nombrePresa,nombrePresa)==0) {
            /** Existen registros de la presa y de la cuenca
                Mostraremos los registros de la presa
                y el Total de la cuenca y de la region
            **/
            presaRegistrada = true;
            printf("\n\n");
            printf("\t\t    Cuenca   |    Presa    |    Volumen    |  Fecha   \n");
            printf("\t\t ------------|-------------|---------------|----------\n");
            for (int k = 0 ;k < 100;k++) {
              if (cuenca[i].presa[j].registro[k].contieneDatos) {
                media = (100*cuenca[i].presa[j].registro[k].volumenMedido) / cuenca[i].presa[j].volumenMax;
                printf("\t\t  %s       |   %s   |   %d - %d%c  | %d/%d/%d \n",cuenca[i].nombreCuenca,cuenca[i].presa[j].nombrePresa,cuenca[i].presa[j].registro[k].volumenMedido,media,37,cuenca[i].presa[j].registro[k].fecha.dia,cuenca[i].presa[j].registro[k].fecha.mes,cuenca[i].presa[j].registro[k].fecha.anio);
              }
            }
          }
        }
        if (presaRegistrada == true) {
          for (int j=0;j<5;j++) {
            if (cuenca[i].presa[j].contieneDatos) {
              totalVolMax = totalVolMax + cuenca[i].presa[j].volumenMax;
              for (int k = 0 ;k < 100;k++) {
                if (cuenca[i].presa[j].registro[k].contieneDatos && cuenca[i].presa[j].registro[k].ultimoRegistro) {
                  totalVolMedido = totalVolMedido + cuenca[i].presa[j].registro[k].volumenMedido;
                }
              }
            }
          }
          media = (totalVolMedido*100)/totalVolMax;
          printf("\t\t  %s       |    TOTAL    |   %d - %d%c  |---------- \n",cuenca[i].nombreCuenca,totalVolMedido,media,37);
        }
      }
    }
    if (presaRegistrada == false) {
      /** No existen registros de la cuenca ni de la presa
          Mostraremos todos los registros de la region
      **/
      if (cuencaRegistrada == false) {
        printf("\n\n");
        printf("\t\t    Cuenca   |    Presa    |    Volumen    |  Fecha   \n");
        printf("\t\t ------------|-------------|---------------|----------\n");
      } else {
        /** Existen registros de la cuenca pero no de la presa
            Mostraremos todos los registros de la cuenca posterior a esa fecha
        **/
        printf("\n\n");
        printf("\t\t    Cuenca   |    Presa    |    Volumen    |  Fecha   \n");
        printf("\t\t ------------|-------------|---------------|----------\n");
        for (int i=0;i<3;i++) {
          if (strcmp(cuenca[i].nombreCuenca,nombreCuenca)==0) {
            for (int j=0;j<5;j++) {
              if (cuenca[i].presa[j].contieneDatos) {
                totalVolMax = totalVolMax + cuenca[i].presa[j].volumenMax;
                for (int k = 0 ;k < 100;k++) {
                  if (cuenca[i].presa[j].registro[k].contieneDatos && cuenca[i].presa[j].registro[k].ultimoRegistro) {
                    totalVolMedido = totalVolMedido + cuenca[i].presa[j].registro[k].volumenMedido;
                  }
                }
              }
            }
            /** Total de la cuenca **/
            media = (totalVolMedido*100)/totalVolMax;
            printf("\t\t  %s       |    TOTAL    |   %d - %d%c  |---------- \n",cuenca[i].nombreCuenca,totalVolMedido,media,37);
          }
        }
      }
    }
    /** Total de todas las cuencas **/
    for (int i=0;i<3;i++) {
      for (int j=0;j<5;j++) {
        if (cuenca[i].presa[j].contieneDatos) {
          totalVolMax = totalVolMax + cuenca[i].presa[j].volumenMax;
          for (int k = 0 ;k < 100;k++) {
            if (cuenca[i].presa[j].registro[k].contieneDatos && cuenca[i].presa[j].registro[k].ultimoRegistro) {
              totalVolMedido = totalVolMedido + cuenca[i].presa[j].registro[k].volumenMedido;
            }
          }
        }
      }
    }
    media = (totalVolMedido*100)/totalVolMax;
    printf("\t\t  TODAS      |    TOTAL    |   %d - %d%c  |---------- \n",totalVolMedido,media,37);
  }
  system("pause");
}

/** Comprobacion de que la fecha es anterior a la fecha actual **/
bool TipoFecha::comprobarFecha() {
  int AnnoActual;
  int MesActual;
  int DiaActual;

  SYSTEMTIME str_t;
  GetSystemTime(&str_t);
  AnnoActual=str_t.wYear;
  MesActual=str_t.wMonth;
  DiaActual=str_t.wDay;

  if (anio>AnnoActual) { //Comparamos la fecha introducida con la actual
    return false;
  } else if ((mes>MesActual) && (anio==AnnoActual)) {
    return false;
  } else if ((dia>DiaActual) && (mes==MesActual) && (anio==AnnoActual)) {
    return false;
  } else {
    return true; //solo devuelve true si la fecha introducida es igual o inferior a la actual.
  }
}

/** Comprueba si el año introducido es bisiesto **/
bool TipoFecha::comprobarBisiesto() { //Función que comprueba si el año es bisiesto o no.
  if (((anio%4==0)&& (anio%100)!=0)||(anio%400)==0) {
    return true;
  } else {
    return false;
  }
}

int TipoFecha::calcularDiaSemana() {
  int a=0;
  int y=0;
  int m=0;
  int d=0;

  a = (14 - mes) / 12;
  y = anio - a;
  m = mes + 12 * a - 2;

  d = ((1 + y + y/4 - y/100 + y/400 + (31*m)/12) % 7);

  if (d==0) { //con Zeller el Domingo toma valor 0, nos interesa que valga 7.
    d=7;
  }
  return d;
}

int TipoFecha::diasTieneMes() {
  switch (mes) {
  case 1: printf("\t\tEnero%22d\n",anio); return 31; break;
  case 2: printf("\t\tFebrero%20d\n",anio);
    if (comprobarBisiesto()==true) {
      return 29;
    } //si bisiesto es true, devolvera 29 dias.
    else {
      return 28;
    }                //si bisiesto es false, devolvera 28 dias.
    break;
  case 3: printf("\t\tMarzo%22d\n",anio); return 31; break;
  case 4: printf("\t\tAbril%22d\n",anio); return 30; break;
  case 5: printf("\t\tMayo%23d\n",anio); return 31; break;
  case 6: printf("\t\tJunio%22d\n",anio); return 30; break;
  case 7: printf("\t\tJulio%22d\n",anio); return 31; break;
  case 8: printf("\t\tAgosto%21d\n",anio); return 31; break;
  case 9: printf("\t\tSeptiembre%17d\n",anio); return 30; break;
  case 10: printf("\t\tOctubre%20d\n",anio); return 31; break;
  case 11: printf("\t\tNoviembre%18d\n",anio); return 30; break;
  case 12: printf("\t\tDiciembre%18d\n",anio); return 31; break;
  }
}

void TipoDato::dibujarCalendario() {
  int posicion, mes,contador, anio, diaPorMes, diaDibujado, diaSemana,diasPorMes,numerodeCuenca,numerodePresa,variacion;
  TipoFecha fecha;
  TipoNombre nombreCuenca, nombrePresa;
  bool cuencaRegistrada = false;
  bool presaRegistrada = false;
  bool registroEncontrado = false;

  system("@cls || clear");
  printf("\n\n");
  printf("\t\t.......................................................... \n");
  printf("\t\t:               Variacion de mediciones                  :\n");
  printf("\t\t:    Por favor introduzca el mes que desea consultar     :\n");
  printf("\t\t:    NO SE PUEDEN INTRODUCIR VALORES TIPO CHAR           :\n");
  printf("\t\t.......................................................... \n");
  mes = 0;
  contador = 0;
  while (mes<1 || mes>12) {
    contador++;
    if (contador == 50) {
      system("@cls || clear");
      printf("\n\nError fatal, violacion de tipo.");
      system("pause");
      return;
    }
    printf("\t\t\n>>> ");
    scanf("%d",&mes);
    if (mes<1 || mes>12) {
      printf("%d no es valido",mes);
    }
  }

  system("@cls || clear");
  printf("\t\t.......................................................... \n");
  printf("\t\t                Variacion de mediciones                    \n");
  printf("\t\t     Mes de consulta de las mediciones: %d            \n",mes);
  printf("\t\t     Por favor introduzca el a%co que desea consultar      \n",164);
  printf("\t\t     NO SE PUEDEN INTRODUCIR VALORES TIPO CHAR             \n");
  printf("\t\t.......................................................... \n");
  printf("\n\t\t>>> ");
  contador = 0;
  anio = 0;
  while (anio<=0) {
    contador++;
    scanf("%d",&anio);
    if (contador == 50 || anio > 50000) {
      system("@cls || clear");
      printf("\n\nError fatal, violacion de tipo.");
      system("pause");
      return;
    }

  }
  system("@cls || clear");
  printf("\t\t.......................................................... \n");
  printf("\t\t                Variacion de mediciones                    \n");
  printf("\t\t     Mes de consulta de las mediciones: %d            \n",mes);
  printf("\t\t     A%co de consulta de las mediciones: %d            \n",164,anio);
  printf("\t\t:    Por favor introduzca el nombre de la cuenca      :\n");
  printf("\t\t.......................................................... \n");
  printf("\n\t\t>>> ");
  scanf("%s",nombreCuenca);
  system("@cls || clear");
  printf("\t\t.......................................................... \n");
  printf("\t\t                Variacion de mediciones                    \n");
  printf("\t\t     Mes de consulta de las mediciones: %d            \n",mes);
  printf("\t\t     A%co de consulta de las mediciones: %d            \n",164,anio);
  printf("\t\t             Nombre de la cuenca: %s                      \n",nombreCuenca);
  printf("\t\t:    Por favor introduzca el nombre de la presa      :\n");
  printf("\t\t.......................................................... \n");
  printf("\n\t\t>>> ");
  scanf("%s",nombrePresa);

  posicion=1;
  fecha.mes = mes;
  fecha.anio = anio;
  diaSemana = fecha.calcularDiaSemana();
  for (int i=0;i<3;i++) {
    if (strcmp(cuenca[i].nombreCuenca,nombreCuenca)==0) {
      cuencaRegistrada = true;
      numerodeCuenca = i;
      for (int j=0;j<5;j++) {
        if (strcmp(cuenca[i].presa[j].nombrePresa,nombrePresa)==0) {
          /** Existen registros de la presa y de la cuenca
              Mostraremos las variaciones de los registros de la presa
          **/
          presaRegistrada = true;
          numerodePresa = j;
        }
      }
    }
  }

  system("@cls || clear");
  printf("\n\n");
  printf("\t\t Variacion Agua Embalsada\n\n");
  if (presaRegistrada) {
    printf("\tCuenca: %s \t - \t Presa: %s\n",nombreCuenca,nombrePresa);
  } else if (cuencaRegistrada) {
    printf("\tCuenca: %s \t - \t Presa: TODAS\n",nombreCuenca,nombrePresa);
  } else {
    printf("\tCuenca: TODAS \t - \t Presa: TODAS\n",nombreCuenca,nombrePresa);
  }
  diasPorMes = fecha.diasTieneMes();
  printf ("\t\tLU  MA  MI  JU  VI | SA  DO\n");
  printf("\t\t");
  for (int i=1; i<diaSemana; i++) {
    printf (" . ");          //desde 1 hasta el primer dia de la semana escribe " . "
    if (posicion%7==5) {     //Si estamos en la quinta posicion (es decir viernes)
      printf ("|");          //tenemos que poner "|"
    }
    printf (" ");            //espacio entre posiciones
    posicion=posicion+1;     //Sumamos 1 a la posicion para representar los 7 dias de la semana.
  }
  for (int i=1; i<diasPorMes;i++) {
    if (cuencaRegistrada) {
      if (presaRegistrada) {
        /** Tanto la cuenca como la presa existen en nuestros registros **/
        for (int k=0;k<100;k++) {
          if (k!=0 &&
              cuenca[numerodeCuenca].presa[numerodePresa].registro[k].contieneDatos &&
              cuenca[numerodeCuenca].presa[numerodePresa].registro[k].fecha.mes == fecha.mes &&
              cuenca[numerodeCuenca].presa[numerodePresa].registro[k].fecha.anio == fecha.anio &&
              cuenca[numerodeCuenca].presa[numerodePresa].registro[k].fecha.dia == i) {
            registroEncontrado = true;
            if (cuenca[numerodeCuenca].presa[numerodePresa].registro[k].volumenMedido != cuenca[numerodeCuenca].presa[numerodePresa].registro[k-1].volumenMedido &&
                (((cuenca[numerodeCuenca].presa[numerodePresa].registro[k].volumenMedido - cuenca[numerodeCuenca].presa[numerodePresa].registro[k-1].volumenMedido)*100)/cuenca[numerodeCuenca].presa[numerodePresa].volumenMax) != 0) {
              variacion = (((cuenca[numerodeCuenca].presa[numerodePresa].registro[k].volumenMedido - cuenca[numerodeCuenca].presa[numerodePresa].registro[k-1].volumenMedido)*100)/cuenca[numerodeCuenca].presa[numerodePresa].volumenMax);
              if (variacion >= 9 || variacion<= -9) {
                printf("EE");
              } else {
                printf("%d",variacion);
              }
            } else {
              printf("00");
            }
          }
        }
        if (registroEncontrado == false) {
          printf("--");
        }
        if (posicion%7==0) {     //si la posicion es 7(domingo) tenemos que saltar de linea
          printf("\n\t\t");
        } else if (posicion%7==5) { //si la posicion es 5(Viernes) tenemos que poner " | "
          printf (" | ");
        } else {
          printf("  ");
        }
        posicion = posicion +1;
        registroEncontrado = false;
      } else {
        /** La cuenca existe en nuestros registros pero la presa no
            Mostraremos la variacion mensual de la cuenca
        **/
      }
    }
  }
  system("Pause");
}
