#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Vista.h"
#include "Tools.h"
#include "Errores.h"
#define NOM_ARCH "log.txt"
#define NOM_ARCH2 "services.txt"
#define NOM_ARCH_W "warnings.txt"


int main()
{
   int opcion;
    char seguir='S';

    ArrayList *ListaLogs;
    ListaLogs=al_newArrayList();
    ArrayList *ListaServicios;
    ListaServicios=al_newArrayList();
    ArrayList *ListFiltrada;
    ListFiltrada=al_newArrayList();
    ArrayList *ListWarnings;
    ListWarnings=al_newArrayList();
    ArrayList* ListaImprime;
    ListaImprime=al_newArrayList();

    if(ListaLogs !=NULL && ListaServicios !=NULL)
    {
        while(seguir=='S')
        {
            vista_ShowMenu("\n1:Leer Log\n2:Procesar Informacion\n3:Mostrar Estadisticas\n");
            scanf("%d",&opcion);
            tools_ValidaMenu(opcion,0,3);
            switch(opcion)
            {
            case 1:
                cargarDesdeArchivo(ListaLogs,NOM_ARCH,parserEstructura);
                vista_MuestraElementos(ListaLogs,"LISTADO DE LOGS","DIA\t\tHORA\tID_SERV\tGRAV\tMENSAJE DE ERROR",vista_MuestraUnElemento,0,ListaLogs->len(ListaLogs),15);
                cargarDesdeArchivo(ListaServicios,NOM_ARCH2,parserEstructuraService);
                vista_MuestraElementos(ListaServicios,"LISTADO DE SERVICIOS","ID\tNOMBRE\t\teMail",vista_MuestraUnElementoService,0,ListaServicios->len(ListaServicios),20);
                break;
            case 2:
               // ListFiltrada=(gestion_Recorre_ArrayList(ListaLogs,funcionFiltro));
              //  vista_MuestraElementos(ListFiltrada,"LOGS CON GRAVEDAD MAYOR A 3","DIA\t\tHORA\tID_SERV\tGRAV\tMENSAJE DE ERROR",vista_MuestraUnElemento,0,ListFiltrada->len(ListFiltrada),15);
              //  ListWarnings=al_filter(ListaLogs,funcionFiltro);
             //   vista_MuestraElementos(ListWarnings,"LOGS CON GRAVEDAD IGUAL A 3 SIN ID 45","DIA\t\tHORA\tID_SERV\tGRAV\tMENSAJE DE ERROR",vista_MuestraUnElemento,0,ListWarnings->len(ListWarnings),15);
             //   GuardarArchivoT(ListWarnings,NOM_ARCH_W);
                ListaImprime=gestion_recorre2yJunta(ListaLogs,ListaServicios,funcionFiltro);
                if(ListaImprime !=NULL)
                {
                    vista_MuestraElementos(ListaImprime,"LISTA DE LA GRAVEDAD DE ERRORES","ERRORES CON GRAVEDAD MAYOR A 7",vista_MuestraUnElementoError,0,ListaImprime->len(ListaImprime),20);
                }
                break;
            case 3:
                break;
            case 0:
                seguir='N';
                break;
            default:
                printf("Ingrese una opcion valida");
                break;
            }//fin switch

        }// fin while(seguir=='S')
    }//fin if(ListaMensajes !=NULL)


}
