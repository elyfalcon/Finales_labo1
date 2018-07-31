#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Estructura.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"

#define NOM_ARCH "nombre.csv"


int main()
{
   int opcion;
    char seguir='S';

    ArrayList *ListaEstructura;
    ListaEstructura=al_newArrayList();


    if(ListaEstructura !=NULL)
    {
        while(seguir=='S')
        {
            ShowMenu("\n1:n");
            scanf("%d",&opcion);
            ValidaMenu(opcion,0,7);
            switch(opcion)
            {
            case 1:
                break;
            case 2:
                break;
            case 0:
                seguir='N';
                break;
            default:
                printf("Ingrese una opcion valida");
                break;

            }//fin switch
        }//fin while
    }
    return 0;
}
