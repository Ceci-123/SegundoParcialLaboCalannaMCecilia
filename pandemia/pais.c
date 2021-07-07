#include "pais.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ePais* pais_newParametros(char* idStr, char* nombreStr, char* vacuna1DosisStr, char* vacuna2DosisStr,char* sinVacunarStr)
{
    int flag = 0;
    ePais* pPais = pais_new();

    if(pPais != NULL)
    {
        if(pais_setId(pPais, atoi(idStr)) == 1 &&
           pais_setNombre(pPais, nombreStr)==1 &&
           pais_setVacuna1Dosis(pPais, atoi(vacuna1DosisStr))==1 &&
           pais_setVacuna2Dosis(pPais, atoi(vacuna2DosisStr))==1 &&
           pais_setSinVacunar(pPais,atoi(sinVacunarStr) )==1)
           {
               flag = 1;
           }
        if(flag == 0)
        {
            printf("Ocurrio un error al inicializar");
            system("pause");
        }
    }
    return pPais;
}

ePais* pais_new(void)
{
    ePais* pPais = NULL;
    pPais = malloc(sizeof(ePais));
    if(pPais == NULL)
    {
        printf("No hay espacio suficiente en memoria\n");

    }
    return pPais;
}

int pais_setId(ePais* pPais, int id)
{
    int todoOk = 0;

    if(pPais !=NULL && id > 0)
    {
       pPais->id = id;
       todoOk = 1;
    }
    return todoOk;

}

int pais_setNombre(ePais* pPais,char* nombre)
{
    int todoOk= 0;
    if(pPais !=NULL && nombre != NULL)
    {
       strcpy(pPais->nombre, nombre);
       todoOk = 1;
    }
    return todoOk;
}

int pais_setVacuna1Dosis(ePais* pPais, int vacuna1Dosis)
{
    int todoOk = 0;

    if(pPais !=NULL && vacuna1Dosis >= 0)
    {
       pPais->vacuna1dosis = vacuna1Dosis;
       todoOk = 1;
    }
    return todoOk;

}

int pais_setVacuna2Dosis(ePais* pPais, int vacuna2Dosis)
{
    int todoOk = 0;

    if(pPais !=NULL && vacuna2Dosis >= 0)
    {
       pPais->vacuna2dosis = vacuna2Dosis;
       todoOk = 1;
    }
    return todoOk;

}

int pais_setSinVacunar(ePais* pPais, int sinVacunar)
{
    int todoOk = 0;

    if(pPais !=NULL && sinVacunar >= 0)
    {
       pPais->sinVacunar = sinVacunar;
       todoOk = 1;
    }
    return todoOk;

}


int pais_getId(ePais* pPais,int* id)
{
    int todoOk = 0;
    if(pPais !=NULL && id != NULL)
    {
        *id = pPais->id;
        todoOk = 1;
    }
    return todoOk;

}

int pais_getNombre(ePais* pPais, char* nombre)
{
    int todoOk = 0;
    if(pPais !=NULL && nombre != NULL)
    {
       strcpy(nombre,pPais->nombre);
       todoOk = 1;
    }
    return todoOk;

}

int pais_getVacuna1Dosis(ePais* pPais,int* vacuna1Dosis)
{
    int todoOk = 0;

    if(pPais != NULL && vacuna1Dosis != NULL)
    {
       *vacuna1Dosis = pPais->vacuna1dosis;
        todoOk = 1;
    }
    return todoOk;
}

int pais_getVacuna2Dosis(ePais* pPais,int* vacuna2Dosis)
{
    int todoOk = 0;

    if(pPais != NULL && vacuna2Dosis != NULL)
    {
       *vacuna2Dosis = pPais->vacuna2dosis;
        todoOk = 1;
    }
    return todoOk;
}

int pais_getSinVacunar(ePais* pPais,int* sinVacunar)
{
    int todoOk = 0;

    if(pPais != NULL && sinVacunar != NULL)
    {
       *sinVacunar = pPais->sinVacunar;
        todoOk = 1;
    }
    return todoOk;
}


int pais_nivelVacunacion(void* p1, void* p2)
{
    int resultado;
    ePais* auxiliar1 = NULL;
    ePais* auxiliar2 = NULL;

    if(p1 != NULL && p2 != NULL)
    {
        auxiliar1 = (ePais*) p1;
        auxiliar2 = (ePais*) p2;
       if(auxiliar1->vacuna1dosis > auxiliar2->vacuna1dosis)
    {
        resultado = 1;
    }
    else
    {
        if(auxiliar1->vacuna1dosis < auxiliar2->vacuna1dosis)
        {
            resultado = -1;
        }
        else
        {
            resultado = 0;
        }
    }

    }
   return resultado;
}

int funcionDeMapeo(void* pElement)
{
    int retorno = 0;
    ePais* auxiliar = NULL;
    auxiliar = (ePais*) pElement;
    int vacuna1Dosis;
    int vacuna2Dosis;
    int sinVacunar;
    int minimo = 1;
    int max1 = 60;
    int max2 = 40;

    vacuna1Dosis = rand() % (max1 -minimo + 1) + minimo ;
    vacuna2Dosis = rand() % (max2 -minimo + 1) + minimo  ;
    sinVacunar = 100 - (vacuna1Dosis + vacuna2Dosis);

    auxiliar->vacuna1dosis = vacuna1Dosis;
    auxiliar->vacuna2dosis = vacuna2Dosis;
    auxiliar->sinVacunar = sinVacunar;

    retorno = 1;

    return retorno;
}


int filterExitosos(void* pElement)
{
    int retorno = 0;
    ePais* auxiliar = NULL;
    auxiliar = (ePais*) pElement;
    if(auxiliar->vacuna2dosis > 30)
    {
        retorno = 1;
    }
    return retorno;
}


int filterHorno(void* pElement)
{
    int retorno = 0;
    ePais* auxiliar = NULL;
    auxiliar = (ePais*) pElement;
    int vacuna1 = auxiliar->vacuna1dosis;
    int vacuna2 = auxiliar->vacuna2dosis;
    int sumaVacunas = vacuna1 + vacuna2;

    if(auxiliar->sinVacunar > sumaVacunas)
    {
        retorno = 1;
    }
    return retorno;
}
