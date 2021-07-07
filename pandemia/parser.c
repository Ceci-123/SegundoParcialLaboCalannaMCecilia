#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"

int parser_FromText(FILE* pFile, LinkedList* pArrayLista)
{
    ePais* pPais = NULL;
    char auxNombre[128];
    char auxId[21];
    char auxRecuperados[21];
    char auxInfectados[21];
    char auxMuertos[21];
    int retorno = 0;

    if(pFile != NULL && pArrayLista != NULL)
    {
        //lectura fantasma del encabezado
        fscanf(pFile,"%s\n",auxNombre);

        while(!feof(pFile))
        {
           if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n] \n",auxId,auxNombre,auxRecuperados,auxInfectados,auxMuertos) == 5)
           {
               pPais = pais_newParametros(auxId, auxNombre,auxRecuperados, auxInfectados,auxMuertos);
               ll_add(pArrayLista,pPais);

           }
            else
            {
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}

