#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "Controller.h"
#include <time.h>

int main()
{
    int opcion;
    int resultado;
    char nombreArchivo[15];

    LinkedList* miLista = ll_newLinkedList();
    srand(time(NULL));
    //numero = rand() % (max -min + 1) + min  ;  //conseguir un random

    opcion = menuOpciones();


    for(;;)
    {

        if(opcion==8)
        {
            opcion = obtenerNumero("Desea salir ? 1.SI // 2. NO");
            if(opcion==1) break;
        }
    switch(opcion)
    {
    case 1:
        pedirNombreArchivoTexto(nombreArchivo);
        resultado = controller_loadFromText(nombreArchivo, miLista);
        if(resultado == 1)
        {
            printf("Archivo cargado con exito\n");
        }
        else
        {
            printf("Error en la carga del archivo\n");
        }
        break;
    case 2:
        resultado = controller_List(miLista);
        if(resultado != 1)
        {
          printf("No se puede mostrar la lista\n");
        }
        break;
    case 3:
        resultado = controller_map(miLista);
        if(resultado == 1)
        {
           printf("Archivo mapeado con exito\n");
        }
        else
        {
            printf("Error en el mapeado del archivo\n");
        }
        break;
    case 4:
        resultado = controller_filter(miLista,1);
        if(resultado == 1)
        {
           printf("Archivo filtrado con exito\n");
        }
        else
        {
            printf("Error en el filtrado del archivo\n");
        }
        break;

    case 5:
        resultado = controller_filter(miLista,2);
        if(resultado == 1)
        {
           printf("Archivo filtrado con exito\n");
        }
        else
        {
            printf("Error en el filtrado del archivo\n");
        }
        break;
    case 6:
        resultado = controller_sort(miLista);
        controller_List(miLista);
        if(resultado != 1)
        {
           printf("Error al ordenar la lista\n");
        }
        break;
    case 7:
        resultado = controller_informe(miLista);
        if(resultado != 1)

        {
            printf("Error en el informe \n");
        }
        break;

    }
    opcion = reCall();
    }
    ll_deleteLinkedList(miLista);
    return 0;
}

