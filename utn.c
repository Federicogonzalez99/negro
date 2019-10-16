#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "lavadero.h"
#define MAX 30

int utn_PedirEntero(char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(utn_PedirString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)==0) //==0 sin errores !0
            {
                if(utn_esNumerico(bufferStr)==1)
                {
                    if(utn_validarRango(bufferStr, min, max)== 0)
                    {

                    *input=atoi(bufferStr);     // unsigned long int strtoul(const char *str, char **end, int base)?
                    retorno=0;
                    break;
                    }

                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}





int utn_PedirString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[MAX];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            //fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s 1",msgError);
            (*reintentos)--;
        }while((*reintentos)>=0);
    }
    return retorno;


}
int utn_esNumerico(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido!='\0';i++)
    {
        if(stringRecibido[i] < '0' || stringRecibido[i] > '9')
            retorno = 0;
        break;
    }
    return retorno;
}
int utn_validarRango(char* stringRecibido, int min, int max)
{
    int retorno = -1;
    int auxBuffer;
    auxBuffer=atoi(stringRecibido);
    if(auxBuffer >= min && auxBuffer <= max)
    {
        retorno = 0;
    }
    return retorno;
}
int utn_pedirNombre(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[max];
    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!utn_PedirString(msg, msgError, min, max, &reintentos, bufferStr))
            {
                if(utn_validarNombre(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }

            }
        }
        while(reintentos>=0);
    }
    return retorno;
}


int utn_validarNombre(char* stringRecibido)
{
    int retorno = 1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')
        {
            retorno = 0;
            break;
        }
    }

   return retorno;
}
int utn_PedirChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno = -1;

    char bufferAux[256];
    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(utn_PedirString(msg, msgError, 1,3,&reintentos, bufferAux)==0)
            {
                if(utn_esChar(bufferAux[0])==1)
                {
                    *resultado=bufferAux[0];
                    retorno = 0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos --;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int utn_esChar(char charRecibido)
{
    int retorno=1;
    if(charRecibido<'A' || (charRecibido>'Z' && charRecibido<'a') || charRecibido>'z')
        retorno=0;
    return retorno;
}
int buscarLugarLibre(eAuto array[], int tam, int* posicion)
{
    int retorno = -1;
    int i;
    if(array!=NULL && tam>=0 && posicion!=NULL)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].estado == 1)
            {
                retorno = 0;
                *posicion = i;
                break;
            }
        }
    }
    return retorno;
}

int listar_Marcas(eMarca array[],int tam)
{
    int retorno = -1;
    int i;
    if(array!=0 && tam >0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].estado==1)
                continue;
            else
            {
                printf("\n IDMarca: %d - Nombre: %s", array[i].idMarca,array[i].descripcion);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int buscarIdMarcas(eMarca array[], int tam, int valor)
{
    int i;
    int retorno =-1;
    if(array!=NULL && tam>0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].idMarca==valor)
            {
                if(array[i].estado==0)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}
int listar_Colores(eColor array[],int tam)
{
    int retorno = -1;
    int i;
    if(array!=0 && tam >0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].estado==1)
                continue;
            else
            {
                printf("\n IDColor: %d - Nombre: %s", array[i].idColor,array[i].nombreColor);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int buscarIdColor(eColor array[],int tam,int valor)
{
    int i;
    int retorno =-1;
    if(array!=NULL && tam>0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].idColor==valor)
            {
                if(array[i].estado==0)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}
int buscarPatente(eAuto array[], int tam, int patente,int* posicion)
{
    int i;
    int retorno = -1;
    if(array!=NULL && tam>0 )
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].patente==patente)
            {
                *posicion = i;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int listar_servicios(eServicio array[], int tam)
{
    int retorno = -1;
    int i;
    if(array!=0 && tam >0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].estado==1)
                continue;
            else
            {
                printf("\n IDServicio: %d - Servicio: %s - Precio: %d", array[i].idServicio,array[i].descripcion,array[i].precio);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int buscar_descripcionMarca(eMarca array[], int tam,int id, char* descripcion)
{
    int i;
    int retorno = -1;
    if(array!=NULL && tam > 0)
    {
        for(i=0;i<tam;i++)
        {
            if(id==array[i].idMarca)
            {
               strcpy(descripcion,array[i].descripcion);
               retorno = 0;
               break;
            }
        }
    }
    return retorno;
}
int buscarPatenteA(eAuto array[],int tam,int valor)
{
    int i;
    int retorno =-1;
    if(array!=NULL && tam>0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].patente == valor)
            {
                if(array[i].estado==0)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}
