#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menuOpciones()
{
    int opcion;
    char ingreso[2];

    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("1. Cargar los datos desde un archivo .csv (modo texto).\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar estadisticas\n");
    printf("4  Filtrar por paises exitosos\n");
    printf("5  Filtrar por paises en el horno\n");
    printf("6  Ordenar por nivel de vacunacion\n");
    printf("7  Mostrar pais mas castigado  \n");
    printf("8. Salir \n");
    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\nIngrese Una Opcion: ");
    fflush(stdin);
    gets(ingreso);
    opcion = atoi(ingreso);
    opcion = validacionDeNumero(opcion,1,8);
    return opcion;
}

int reCall(void)
{
    int i;
    printf("\n");
    system("pause");
    printf("PRESIONE ENTER PARA CONTINUAR");
    system("cls");
    i = menuOpciones();
    return i;
}

int obtenerNumero(char mensaje[])
{
    int numero;

    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%d", &numero);
    return numero;
}

int validacionDeNumero(int numero,int minimo, int maximo)
{
    int i;

    i=numero;

    while(minimo>numero||numero>maximo)
    {
        printf("Error, numero fuera de rango, reingresar: ");
        scanf("%d",&i);
        numero = i;
    }

    return i;
}

int sonLetras(char cadena[])
{
    int todoOk= -1;
    int i;
    int longitud = strlen(cadena);

      for(i= 0; i < longitud; i++)
      {
          if((cadena[i] > 65 && cadena[i] < 90) || (cadena[i] > 97 && cadena[i] < 122))
          {
              //son letras
              todoOk= 1;
          }
      }

   // devuelve 1 si son letras, devuelve -1 si son numeros

    return todoOk;
}

int validacionSexo(char sexo)
{
    int todoOk = 0;

    if(sexo == 'm' || sexo == 'f' )
    {
        todoOk = 1;
    }
    return todoOk;
}


float validacionDeNumeroFloat(float numero,int minimo, int maximo)
{
    float i;

    i=numero;

    while(minimo>numero||numero>maximo)
    {
        printf("Error, numero fuera de rango, reingresar: ");
        scanf("%f",&i);
        numero = i;
    }

    return i;
}

float obtenerNumeroFlotante(char mensaje[])
{
    float numero;

    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%f", &numero);
    return numero;
}

void pedirNombreArchivoTexto(char* nombre)
{
    char extension[5] = ".csv";
    char archivo[10];

    printf("Ingrese nombre del archivo: (sugerido vacunas)");
    fflush(stdin);
    gets(archivo);
    strcat(archivo,extension);
    strcpy(nombre, archivo);
}

void pedirNombreArchivoBinario(char* nombre)
{
    char extension[5] = ".bin";
    char archivo[10];

    printf("Ingrese nombre del archivo: (sugerido dataBIN)");
    fflush(stdin);
    gets(archivo);
    strcat(archivo,extension);
    strcpy(nombre, archivo);
}
