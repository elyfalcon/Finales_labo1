#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Estructura.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"
#include "fenv.h"
#include "Mensaje.h"
#include "Usuario.h"
#define NOM_ARCH "messages.csv"
#define NOM_ARCH2 "usuarios2.csv"
#define NOM_FEED "feed.csv"


int main()
{
   int opcion;
    char seguir='S';

    ArrayList *ListaMensajes;
    ListaMensajes=al_newArrayList();
    ArrayList *ListaUsuarios;
    ListaUsuarios=al_newArrayList();
    ArrayList* ListaFeed;
    ListaFeed=al_newArrayList();

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
                vista_MuestraElementos(ListaMensajes,"LISTADO DE MENSAJES Y POPULARIDAD","ID_M\tMENSAJE\t\tLIKES\tID_USUARIO",vista_MuestraUnElemento,0,ListaMensajes->len(ListaMensajes),15);
                system("cls");
                cargarDesdeArchivo(ListaUsuarios,NOM_ARCH2,parserEstructuraUsuario);
                vista_MuestraElementos(ListaUsuarios,"LISTADO DE USUARIOS CON POPULARIDAD","ID_USU\tNICK\t\tFOLLOWERS",vista_MuestraUnElementoUsuario,0,ListaUsuarios->len(ListaUsuarios),25);
                break;
            case 2:
                ListaFeed=Compara_2ArrayList(ListaMensajes,ListaUsuarios,est_ComparaElementos);
                if(ListaFeed !=NULL)
                {
                 vista_MuestraElementos(ListaFeed,"LISTADO DE POPULARIDAD","ID_M\tMENSAJE\t\t\t\t\tLIKES\tID_USU\tNICK\t\tFOLLOWERS",vista_MuestraUnFEED,0,ListaFeed->len(ListaFeed),15);
                }
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



















