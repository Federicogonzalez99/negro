#include "lavadero.h"
int utn_PedirEntero(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input);
int utn_PedirString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
int utn_esNumerico(char* stringRecibido);
int utn_validarRango(char* stringRecibido, int min, int max);
int utn_pedirNombre(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int utn_validarNombre(char* stringRecibido);
int utn_PedirChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int utn_esChar(char charRecibido);
int buscarLugarLibre(eAuto array[], int tam, int* posicion);
int listar_Marcas(eMarca array[],int tam);
int buscarIdMarcas(eMarca array[], int tam, int valor);
int listar_Colores(eColor array[],int tam);
int buscarIdColor(eColor array[],int tam,int valor);
