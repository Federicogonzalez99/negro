#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LAVADERO_H_INCLUDED
#define LAVADERO_H_INCLUDED
typedef struct
{
    int dia;
    int mes;
    int anio;
    int estado;
}eFecha;

typedef struct
{
    int idMarca;
    char descripcion[20];
    int estado;
}eMarca;

typedef struct
{
    int idColor;
    char nombreColor[20];
    int estado;
}eColor;

typedef struct
{
    int idAuto;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int estado;
}eAuto;

typedef struct
{
    int idServicio;
    char descripcion[25];
    int precio;
    int estado;
}eServicio;
#endif // LAVADERO_H_INCLUDED
int lavadero_autoI(eAuto array[], int tam);
int lavadero_fechaI(eFecha array[], int tam);
int alta_auto(eAuto array[], int tam,eMarca arrayMarca[], int tamMar, eColor arrayColor[], int tamColor, int* contAuto,int* flag);
