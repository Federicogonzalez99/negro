#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "lavadero.h"
#define MAX 30
#define QTY_TYPO 5
int lavadero_autoI(eAuto array[], int tam)
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

int lavadero_fechaI(eFecha array[], int tam)
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
int alta_auto(eAuto array[], int tam,eMarca arrayMarca[], int tamMar, eColor arrayColor[], int tamColor, int* contAuto,int* flag)
{
    int posicion;
    int retorno = -1;
    int auxIdMarca;
    int auxIdColor;
    if(array!=NULL&&tam>0&&arrayMarca!=NULL&&tamMar>0&&arrayColor!=NULL&&tamColor>0&& contAuto!=NULL&&flag!=NULL)
    {
        if(buscarLugarLibre(array, tam, &posicion) == 0)
        {
             (*contAuto)++;
            array[posicion].idAuto = *contAuto;
            utn_PedirEntero("Ingrese patente(000-999): ","Error",1,sizeof(int),000,999,3,&array[posicion].patente);
            listar_Marcas(arrayMarca,tamMar);
            utn_PedirEntero("\nIngrese ID marca: ","Error",1,1010,1000,1004,3,&auxIdMarca);
            if(buscarIdMarcas(arrayMarca,tamMar,auxIdMarca)==0)
            {
                array[posicion].idMarca=auxIdMarca;
            }
            else
            {
                printf("Error en el id");
            }
            listar_Colores(arrayColor,tamColor);
            utn_PedirEntero("\nIngrese ID color: ","Error",1,5010,5000,5004,3,&auxIdColor);
            if(buscarIdColor(arrayColor,tamColor,auxIdColor)==0)
            {
                array[posicion].idColor = auxIdColor;
            }
            else
            {
                printf("Error en el id");
            }
            utn_PedirEntero("Ingrese modelo (1970-2019): ","Error",1,2020,1970,2019,3,&array[posicion].modelo);
            retorno = 0;
            *flag = 1;
            array[posicion].estado=0;
        }
        else
        {
            printf("No hay lugares libres");
        }
    }
    return retorno;
}
int modificar_auto(eAuto array[], int tamAu,eColor arrayColor[],int tamColor)
{
    int auxPatente;
    int auxColor;
    int posicion;
    char opcion;
    if(array!=NULL && tamAu>0 && arrayColor!=NULL && tamColor>0)
    {
        utn_PedirEntero("Ingrese la patente del auto: ","Error",1,sizeof(int),000,999,3,&auxPatente);
        if(buscarPatente(array,tamAu,auxPatente,&posicion)==0)
        {
            array[posicion].patente=auxPatente;

        do
            {
                utn_PedirChar("\nA.Color\nB.Modelo\nS.Salir\n","Error",'A','Z',2,&opcion);
            switch(opcion)
            {


        case 'A':

            listar_Colores(arrayColor, tamColor);
            utn_PedirEntero("\nIngrese ID del color: ","Error",1,5010,5000,5004,3,&auxColor);
            if(buscarIdColor(arrayColor,tamColor,auxColor)==0)
            {
                array[posicion].idColor=auxColor;
            }
            else
            {
                printf("ID no valido");
            }

            break;
        case 'B':
            utn_PedirEntero("Ingrese modelo del auto: ","Error",1,2020,1970,2020,3,&array[posicion].modelo);
            break;
        case 'S':
            break;
        default:
            printf("Opcion no valida");
            }
            }while(opcion!='S');
        }
        else
        {
          printf("Patente no valida");
        }
    }
    return 0;
}
int baja_auto(eAuto array[], int tam)
{
    int auxPatente;
    int posicion;
    int retorno = -1;
    if(array!=NULL && tam>0)
    {
        utn_PedirEntero("Ingrese la patente del auto: ", "Error",1,sizeof(int),000,999,2,&auxPatente);
        if(buscarPatente(array,tam,auxPatente,&posicion)==0)
        {
            array[posicion].estado = 1;
            array[posicion].idColor = 0;
            array[posicion].idAuto = 0;
            array[posicion].modelo = 0;
            array[posicion].patente = 0;
            retorno = 0;
        }
        else
        {
            printf("No se encontro ese numero de patente");
        }
    }
    return retorno;
}

int listar_autos(eAuto array[], int tamAuto, eMarca arrayM[], int tamM)
{
    char auxSalida[25];
    int i, j;
    int retorno = -1;
    eAuto aux;
    eMarca auxM;
    char auxDesc1[25];
    char auxDesc2[25];
    if(array!=NULL && tamAuto>0)
    {
    for(i=0;i<tamAuto -1 ;i++)
    {

        for(j=0;j<tamAuto -i -1;j++)
        {
            buscar_descripcionMarca(arrayM,tamM,array[j].idMarca, auxDesc1);
            buscar_descripcionMarca(arrayM,tamM,array[j + 1].idMarca,auxDesc2);

            if(strcmp(auxDesc1,auxDesc2)> 0)
            {
               auxM = arrayM[j];
               arrayM[j]= arrayM[j + 1];
               arrayM[j + 1]= auxM;

               aux = array[j];
               array[j]=array[j + 1];
               array[j + 1]=aux;
            }

            if(strcmp(auxDesc1,auxDesc2) == 0)
            {
                if(array[j].patente > array[j + 1].patente)
                {
                    auxM = arrayM[j];
                    arrayM[j]= arrayM[j + 1 ];
                    arrayM[j + 1]= auxM;


                    aux = array[j];
                    array[j]=array[j + 1];
                    array[j + 1]=aux;
                }
            }
        }
    }

    for(i=0;i<tamAuto;i++)
    {
        if(array[i].estado==0)
        {
            buscar_descripcionMarca(arrayM,tamM,array[i].idMarca,auxSalida);
            printf("\nIDAuto: %d - Patente: %d - IDColor: %d - Modelo: %d - Marca: %s",array[i].idAuto,array[i].patente,array[i].idColor,array[i].modelo,auxSalida);
        }

    }
    retorno = 0;
    }
    return retorno;
}





