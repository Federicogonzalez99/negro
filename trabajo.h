#include "lavadero.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
typedef struct
{
    int id;
    int patente;
    int idServicio;
    int estado;
    eFecha fechas;
}eTrabajo;
#endif
/** \brief Verifica si el id ingresado pertenece a un servicio
 *
 * \param array[] eServicio
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarIdServicio(eServicio array[], int tam,int id);
/** \brief Busca un lugar libre en el array trabajo y devuelve su posicion
 *
 * \param array[] eTrabajo
 * \param tam int
 * \param posicion int*
 * \return int
 *
 */
int buscarLugarLibreTrabajo(eTrabajo array[], int tam, int* posicion);
/** \brief Inicializa el campo estado en 1
 *
 * \param array[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int trabajo_Inicializar(eTrabajo array[], int tam);
/** \brief Pide una patente la verifica y da de alta un servicio
 *
 * \param array[] eAuto
 * \param tam int
 * \param arraySer[] eServicio
 * \param tamSer int
 * \param arrayMar[] eMarca
 * \param tamMar int
 * \param arrayTrabajo[] eTrabajo
 * \param tamTrabajo int
 * \param contTrabajo int*
 * \return int
 *
 */
int alta_trabajo(eAuto array[], int tam, eServicio arraySer[], int tamSer,eMarca arrayMar[],int tamMar, eTrabajo arrayTrabajo[], int tamTrabajo, int* contTrabajo);
/** \brief Informa los trabajos realizados
 *
 * \param arrayTrabajo[] eTrabajo
 * \param tamT int
 * \param arrayAuto[] eAuto
 * \param tamA int
 * \param arrayServicio[] eServicio
 * \param tamS int
 * \return int
 *
 */
int listar_Trabajos(eTrabajo arrayTrabajo[], int tamT, eAuto arrayAuto[],int tamA, eServicio arrayServicio[], int tamS);
/** \brief Recibe el id y devuelve la descripcion y el precio del servicio
 *
 * \param array[] eServicio
 * \param tam int
 * \param id int
 * \param precio int*
 * \param descripcion char*
 * \return int
 *
 */
int buscar_descripcionServicios(eServicio array[], int tam,int id, int* precio,char* descripcion);
