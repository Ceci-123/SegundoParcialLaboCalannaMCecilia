#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"
#include "pais.h"



int controller_loadFromText(char* path, LinkedList* pArrayLista)
{
    FILE* pFile;
    ll_clear(pArrayLista);
    pFile = fopen(path,"r");
    int auxiliarRetorno = 1;

    if(pArrayLista != NULL)
    {
        if(pFile == NULL)
        {
            printf("No se encontro el archivo\n");
            system("pause");
            auxiliarRetorno = 0;
        }
        parser_FromText(pFile,pArrayLista);
    }
    else
    {
        printf("Error en la lista\n");
        system("pause");
        auxiliarRetorno = 0;
    }
    fclose(pFile);
    return auxiliarRetorno;
}


int controller_List(LinkedList* pArrayLista)
{
    ePais* auxiliarPais;
    int tamanio;
    int id;
    char nombre[128];
    int vacuna1Dosis;
    int vacuna2Dosis;
    int sinVacunar;
    int todoOk = 0;

    printf("    ID    PAIS          DOSIS VACUNA 1 DOSIS VACUNA 2 SIN VACUNAR \n");
    tamanio = ll_len(pArrayLista);
    for(int i=0;i< tamanio;i++)
    {
        auxiliarPais = ll_get(pArrayLista,i);
        pais_getId(auxiliarPais,&id);
        pais_getNombre(auxiliarPais,nombre);
        pais_getVacuna1Dosis(auxiliarPais,&vacuna1Dosis);
        pais_getVacuna2Dosis(auxiliarPais,&vacuna2Dosis);
        pais_getSinVacunar(auxiliarPais,&sinVacunar);

        printf("%2d %20s      %2d             %2d             %2d\n",id,nombre,vacuna1Dosis,vacuna2Dosis,sinVacunar);
        todoOk = 1;
    }
    return todoOk;
}
//
//
int controller_sort(LinkedList* pArrayLista)
{

    int todoOk= 0;
    ll_sort(pArrayLista,pais_nivelVacunacion,1);
    todoOk = 1;



    return todoOk;
}
//
//
int controller_saveAsText(char* path, LinkedList* pArrayLista)
{
    FILE* pFile;
    ePais* auxiliarPais;
    int tamanio;
    char nombre[20];
    int id;
    int vacuna1Dosis;
    int vacuna2Dosis;
    int sinVacunar;
    int auxiliarRetorno;

    if(pArrayLista == NULL)
    {
       printf("Direccion de memoria de la lista incorrecta");
       auxiliarRetorno = 0;
    }

    if(pArrayLista != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile == NULL)
        {
           printf("No se pudo abrir el archivo\n");
           auxiliarRetorno = 0;
        }
        else
        {
            tamanio = ll_len(pArrayLista);
            fprintf(pFile,"id,nombre,vacuna1dosis,vacuna2dosis,sinvacunar\n");
            for(int i=0;i<tamanio;i++)
            {
                auxiliarPais = (ePais*)ll_get(pArrayLista,i);
                pais_getId(auxiliarPais, &id);
                pais_getNombre(auxiliarPais,nombre);
                pais_getVacuna1Dosis(auxiliarPais,&vacuna1Dosis);
                pais_getVacuna2Dosis(auxiliarPais, &vacuna2Dosis);
                pais_getSinVacunar(auxiliarPais, &sinVacunar);
                fprintf(pFile,"%d,%s,%d,%d,%d\n",id,nombre,vacuna1Dosis,vacuna2Dosis,sinVacunar);
            }
        }
    fclose(pFile);
    auxiliarRetorno = 1;
    }

    return auxiliarRetorno;
}

int controller_filter(LinkedList* pArrayLista, int filtro)
{
    int todoOk = 0;

    if(pArrayLista != NULL)
    {
        switch(filtro)
        {
        case 1:
              if(controller_List(ll_filter(pArrayLista, filterExitosos)))
              {
                 todoOk = 1;
                 controller_saveAsText("archivoExitosos.csv",ll_filter(pArrayLista, filterExitosos));
              }
              break;
        case 2:
             if(controller_List(ll_filter(pArrayLista, filterHorno)))
              {
                 todoOk = 1;
                 controller_saveAsText("archivoAlHorno.csv",ll_filter(pArrayLista, filterHorno));
              }
            break;
        }

    }

    return todoOk;
}

int controller_map(LinkedList* pArrayLista)
{
    int todoOk = 0;

    if(pArrayLista != NULL)
    {
        if(controller_List(ll_map(pArrayLista, funcionDeMapeo)))
        {
            todoOk = 1;
            //controller_saveAsText("archivoMapeado.csv",ll_map(pArrayLista, funcionDeMapeo));
        }

    }

    return todoOk;

}

int controller_informe(LinkedList* pArrayLista)
{
    int todoOk = 0;
    int tamanio;
    int mayor = 0;
    ePais* pPais = NULL;
    int sinVacunarObtenidos;

    if(pArrayLista != NULL)
    {
       tamanio = ll_len(pArrayLista);
       for(int i=0;i< tamanio;i++)
       {
           pPais = ll_get(pArrayLista,i);
           pais_getSinVacunar(pPais,&sinVacunarObtenidos);
           if(i == 0 || sinVacunarObtenidos > mayor )
           {
               mayor = sinVacunarObtenidos;
           }
       }
       printf("El mayor porcentaje de no vacunados es %d y corresponde a: \n", mayor);

       // recorro de nuevo
       for(int i=0;i< tamanio;i++)
       {
           pPais = ll_get(pArrayLista,i);
           pais_getSinVacunar(pPais,&sinVacunarObtenidos);
           if(sinVacunarObtenidos == mayor )
           {
              printf("%s", pPais->nombre);
           }
       }
     todoOk = 1;
    }
    printf("\n\n");
    system("pause");
    return todoOk;
}


