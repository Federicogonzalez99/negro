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
/** \brief Inicializa el estado en todas las posiciones en 1
 *
 * \param array[] eAuto
 * \param tamanio del vector
 * \return retorna 0 si pudo hacer la carga
 *
 */
int lavadero_autoI(eAuto array[], int tam);
/** \brief Inicializa el estado en todas las posiciones en 1
 *
 * \param array[] eFecha
 * \param tamanio del vector
 * \return retorna 0 si se pudo hacer la carga
 *
 */
int lavadero_fechaI(eFecha array[], int tam);
/** \brief Busca un lugar libre en el vector y realiza la carga del auto
 *
 * \param array[] eAuto
 * \param tam int
 * \param arrayMarca[] eMarca
 * \param tamMar int
 * \param arrayColor[] eColor
 * \param tamColor int
 * \param contAuto int*
 * \param flag int*
 * \return devuelve 0 si se cargo correctamente el auto o -1 si no se pudo hacer
 *
 */
int alta_auto(eAuto array[], int tam,eMarca arrayMarca[], int tamMar, eColor arrayColor[], int tamColor, int* contAuto,int* flag);
/** \brief Pide una patente del auto, verifica si existe y si es asi da opciones para modificar el auto
 *
 * \param array[] eAuto
 * \param tamAu int
 * \param arrayColor[] eColor
 * \param tamColor int
 * \return devuelve 0 si se modifico correctamente o -1 si no se pudo hacer
 *
 */
int modificar_auto(eAuto array[], int tamAu,eColor arrayColor[],int tamColor);
/** \brief Pide una patente del auto, verifica si existe y si es asi se le da de baja
 *
 * \param array[] eAuto
 * \param tam int
 * \return devuelve 0 si se realizo la baja o -1 si no se pudo hacer
 *
 */
int baja_auto(eAuto array[], int tam);
/** \brief Realiza un informe de los autos ordenados por marca alfabeticamente y por patente
 *
 * \param array[] eAuto
 * \param tamAuto int
 * \param arrayM[] eMarca
 * \param tamM int
 * \return -1 si no se pudo ordenar y 0 si la funcion funciono correctamente
 *
 */
int listar_autos(eAuto array[], int tamAuto, eMarca arrayM[], int tamM);
