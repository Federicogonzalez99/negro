#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lavadero.h"
#include "utn.h"
#define QTY_TYPO 5
#define QTY_SER 4
int main()
{
    char opcion;
    int flag=0;
    int contAuto=0;
    eFecha vecFecha[QTY_TYPO];
    lavadero_fechaI(vecFecha, QTY_TYPO);
    eAuto vecAuto[QTY_TYPO];
    lavadero_autoI(vecAuto,QTY_TYPO);
    eMarca vecMarca[QTY_TYPO]={
    {1000,"Renault",0},
    {1001,"Fiat",0},
    {1002,"Ford",0},
    {1003,"Chevrolet",0},
    {1004,"Peugeot",0}
    };
    eColor vecColor[QTY_TYPO]={
    {5000,"Negro",0},
    {5001,"Blanco",0},
    {5002,"Gris",0},
    {5003,"Rojo",0},
    {5004,"Azul",0}
    };
    eServicio vecServicio[QTY_SER]={
    {20000,"Lavado",250,0},
    {20001,"Pulido",300,0},
    {20002,"Encerado",400,0},
    {20003,"Completo",600,0}
    };

    do
    {
        utn_PedirChar("\nA.Alta auto\nB.Modificar Auto\nC.Baja Auto\nD.Listar Autos\nE.Listar Marcas\nF.Listar Colores\nG.Listar Servicios\nH.Alta Trabajo\nI.Listar Trabajos\nS.Salir\n","Error",1,10,2,&opcion);
        switch(opcion)
        {
        case 'A':
                alta_auto(vecAuto,QTY_TYPO,vecMarca,QTY_TYPO,vecColor,QTY_TYPO,&contAuto,&flag);
            break;
        case 'B':
                if(flag==1)
                {
                    modificar_auto(vecAuto,QTY_TYPO,vecColor,QTY_TYPO);
                }
                else
                {
                    printf("Primero tiene que dar de alta un auto");
                }
            break;
        case 'C':
            if(flag==1)
            {
                baja_auto(vecAuto,QTY_TYPO);
                printf("La baja se realizo con exito\n");
            }
            else
            {
                printf("Primero tiene que dar de alta un auto");
            }
            break;
        case 'D':
            listar_autos(vecAuto,QTY_TYPO,vecMarca,QTY_TYPO);
            break;
        case 'E':
            listar_Marcas(vecMarca,QTY_TYPO);
            break;
        case 'F':
            listar_Colores(vecColor,QTY_TYPO);
            break;
        case 'G':
            listar_servicios(vecServicio,QTY_SER);
            break;
        case 'H':
            break;
        case 'L':
            break;
        case 'S':
            break;
        default:
            printf("Opcion no valida");
        }
    }while(opcion!='S');

    return 0;
}
