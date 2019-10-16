#include "trabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "lavadero.h"
int trabajo_Inicializar(eTrabajo array[], int tam)
{
    int i;
    int retorno = -1;
    if(array!=NULL && tam>0)
    {
        for(i=0;i<tam;i++)
        {
            array[i].estado = 1;
        }
        retorno = 0;
    }
    return retorno;
}
int buscarLugarLibreTrabajo(eTrabajo array[], int tam, int* posicion)
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
int buscarIdServicio(eServicio array[], int tam,int id)
{
    int i;
    int retorno =-1;
    if(array!=NULL && tam>0)
    {
        for(i=0;i<tam;i++)
        {
            if(array[i].idServicio == id)
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
int alta_trabajo(eAuto array[], int tam, eServicio arraySer[], int tamSer,eMarca arrayMar[],int tamMar, eTrabajo arrayTrabajo[], int tamTrabajo, int* contTrabajo)
{
    int auxPatente;
    int idServicio;
    int posicion;
    int retorno = -1;
    if(arrayTrabajo!=NULL && tamTrabajo > 0)
    {
        if(buscarLugarLibreTrabajo(arrayTrabajo,tamTrabajo,&posicion)==0)
        {
            (*contTrabajo)++;
            arrayTrabajo[posicion].id = *contTrabajo;
            listar_autos(array,tam,arrayMar,tamMar);
            utn_PedirEntero("\nIngrese la patente del auto: ", "Error",1,sizeof(int),1,1000,2,&auxPatente);
            if(buscarPatenteA(array,tam,auxPatente)==0)
            {
                arrayTrabajo[posicion].patente=auxPatente;
            }
            else
            {
                printf("Patente incorrecta");
            }
            listar_servicios(arraySer,tamSer);
            utn_PedirEntero("\nIngrese ID del servicio: ","Error",1,20010,20000,20004,2,&idServicio);
            if(buscarIdServicio(arraySer,tamSer,idServicio)==0)
            {
                arrayTrabajo[posicion].idServicio=idServicio;
            }
            else
            {
                printf("ID del servicio incorrecto");
            }
            arrayTrabajo[posicion].estado = 0;
            retorno = 0;
            utn_PedirEntero("\nIngrese Dia: ", "Error",1,sizeof(int),1,31,2,&arrayTrabajo[posicion].fechas.dia);
            utn_PedirEntero("\nIngrese Mes: ","Error",1,sizeof(int),1,12,2,&arrayTrabajo[posicion].fechas.mes);
            utn_PedirEntero("\nIngrese Anio: ", "Error",1,2020,1,2020,2,&arrayTrabajo[posicion].fechas.anio);
        }
        else
        {
            printf("No hay lugar libre");
        }

    }
    return retorno;
}
int listar_Trabajos(eTrabajo arrayTrabajo[], int tamT, eAuto arrayAuto[],int tamA, eServicio arrayServicio[], int tamS)
{
    int i;
    int retorno = -1;
    char descripcion[25];
    int precio;
    if(arrayTrabajo!=NULL && tamT > 0)
    {
         for(i=0;i<tamT;i++)
        {
        if(arrayTrabajo[i].estado==0)
        {
            buscar_descripcionServicios(arrayServicio,tamS,arrayTrabajo[i].idServicio,&precio,descripcion);
            printf("Patente: %d - IDServicio: %d - Descripcion: %s - Precio: %d - \nDia: %d\nMes: %d\nAnio: %d",arrayTrabajo[i].patente,arrayTrabajo[i].idServicio,descripcion,precio,arrayTrabajo[i].fechas.dia,arrayTrabajo[i].fechas.mes,arrayTrabajo[i].fechas.anio);
        }
        retorno = 0;
        }

    }
   return retorno;
}
int buscar_descripcionServicios(eServicio array[], int tam,int id, int* precio,char* descripcion)
{
    int i;
    int retorno = -1;

    if(array!=NULL && tam > 0)
    {
        for(i=0;i<tam;i++)
        {
            if(id==array[i].idServicio)
            {
               strcpy(descripcion,array[i].descripcion);
               *precio = array[i].precio;
               retorno = 0;
               break;
            }
        }
    }
    return retorno;
}
