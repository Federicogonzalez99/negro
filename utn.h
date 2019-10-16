#include "lavadero.h"
/** \brief Pide un entero y verifica que no contenga caracteres
 *
 * \param msg char*
 * \param msgError char*
 * \param minSize int
 * \param maxSize int
 * \param min int
 * \param max int
 * \param reintentos int
 * \param input int*
 * \return int
 *
 */
int utn_PedirEntero(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input);
/** \brief Pide un mensaje y verifica que no contenga numeros
 *
 * \param msg char*
 * \param msgError char*
 * \param min int
 * \param max int
 * \param reintentos int*
 * \param resultado char*
 * \return int
 *
 */
int utn_PedirString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
/** \brief Recibe una cadena de caracteres y verifica que sean numeros
 *
 * \param stringRecibido char*
 * \return int
 *
 */
int utn_esNumerico(char* stringRecibido);
/** \brief Valida si el numero recbido esta entre el min y el max
 *
 * \param stringRecibido char*
 * \param min int
 * \param max int
 * \return int
 *
 */
int utn_validarRango(char* stringRecibido, int min, int max);
/** \brief Pide un nombre y verifica que no contenga numeros
 *
 * \param msg char*
 * \param msgError char*
 * \param min int
 * \param max int
 * \param reintentos int
 * \param resultado char*
 * \return int
 *
 */
int utn_pedirNombre(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
/** \brief Recibe una cadena de caracteres y verifica que no contenga numeros
 *
 * \param stringRecibido char*
 * \return int
 *
 */
int utn_validarNombre(char* stringRecibido);
/** \brief Pide un char y verifica que este no sea un numero
 *
 * \param msg char*
 * \param msgError char*
 * \param min int
 * \param max int
 * \param reintentos int
 * \param resultado char*
 * \return int
 *
 */
int utn_PedirChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
/** \brief Verifica que el char sea una letra
 *
 * \param charRecibido char
 * \return int
 *
 */
int utn_esChar(char charRecibido);
/** \brief Busca un lugar libre y devuelve la posicion
 *
 * \param array[] eAuto
 * \param tam int
 * \param posicion int*
 * \return int
 *
 */
int buscarLugarLibre(eAuto array[], int tam, int* posicion);
/** \brief Lista las marcas del array
 *
 * \param array[] eMarca
 * \param tam int
 * \return int
 *
 */
int listar_Marcas(eMarca array[],int tam);
/** \brief Verifica si el id ingresado es correcto
 *
 * \param array[] eMarca
 * \param tam int
 * \param valor int
 * \return int
 *
 */
int buscarIdMarcas(eMarca array[], int tam, int valor);
/** \brief Informa el array de colores
 *
 * \param array[] eColor
 * \param tam int
 * \return int
 *
 */
int listar_Colores(eColor array[],int tam);
/** \brief Verifica si el id de colores ingresado es correcto
 *
 * \param array[] eColor
 * \param tam int
 * \param valor int
 * \return int
 *
 */
int buscarIdColor(eColor array[],int tam,int valor);
/** \brief Verifica si la patente ingresada pertenece a un auto cargado
 *
 * \param array[] eAuto
 * \param tam int
 * \param valor int
 * \return int
 *
 */
int buscarPatenteA(eAuto array[],int tam,int valor);
/** \brief Recibe el id y busca la descripcion de la marca
 *
 * \param array[] eMarca
 * \param tam int
 * \param id int
 * \param descripcion char*
 * \return int
 *
 */
int buscar_descripcionMarca(eMarca array[], int tam,int id, char* descripcion);
/** \brief Lista el array de servicios
 *
 * \param array[] eServicio
 * \param tam int
 * \return int
 *
 */
int listar_servicios(eServicio array[], int tam);
/** \brief Busca una patente y devuelve su posicion
 *
 * \param array[] eAuto
 * \param tam int
 * \param patente int
 * \param posicion int*
 * \return int
 *
 */
int buscarPatente(eAuto array[], int tam, int patente,int* posicion);

