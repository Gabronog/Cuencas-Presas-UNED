#pragma once
typedef enum TipoMes {Enero,Febrero,Marzo,Abril,Mayo,Junio,Julio,Agosto,Septiembre,Octubre,Noviembre,Diciembre};
typedef enum TipoDia {Lunes,Martes,Miercoles,Jueves,Viernes,Sabado,Domingo};

typedef struct TipoFecha{
  TipoMes mes;
  TipoDia dia;
  int anio;

  void comprobarFecha();
  };

typedef struct TipoRegistro{
  int volumenMedido;
  TipoFecha fecha;
  };
typedef char TipoNombre[100];

typedef struct TipoPresa{
  TipoNombre nombrePresa;
  int volumenMax;
  TipoRegistro registro[100];
  bool contieneDatos;
  };
typedef TipoPresa TipoDatoPresa[5];
typedef struct TipoCuenca{
  void borrarCuenca();
  TipoDatoPresa presa;
  TipoNombre nombreCuenca;
  bool contieneDatos;
  };

typedef TipoCuenca TipoDatoCuenca [3];

typedef struct TipoDato{
    TipoDatoCuenca cuenca;
    void introducirCuenca();
    void verRegistros();
    void introducirMedicion(int anio, int mes, int dia,int volumen);
  };
