#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Estructura.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"

#define NOM_ARCH "messages.csv"
#define NOM_ARCH2 "usuarios.csv"


int main()
{
   int opcion;
    char seguir='S';

    ArrayList *ListaMensajes;
    ListaMensajes=al_newArrayList();


    if(ListaMensajes !=NULL)
    {
        while(seguir=='S')
        {
            vista_ShowMenu("\n1:Cargar Archivos\n2:Implementar el feed\n3:Listar feed\n");
            scanf("%d",&opcion);
            tools_ValidaMenu(opcion,0,3);
            switch(opcion)
            {
            case 1:
                cargarDesdeArchivo(ListaMensajes,NOM_ARCH,parserEstructura);
                vista_MuestraElementos(ListaMensajes,"LISTADO DE MENSAJES Y POPULARIDAD",vista_MuestraUnElemento,0,ListaMensajes->len(ListaMensajes),15);
                system("cls");
                cargarDesdeArchivo(ListaMensajes,NOM_ARCH2,parserEstructuraUsuario);
                vista_MuestraElementos(ListaMensajes,"LISTADO DE USUARIOS CON POPULARIDAD",vista_MuestraUnElementoUsuario,0,ListaMensajes->len(ListaMensajes),25);
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



















