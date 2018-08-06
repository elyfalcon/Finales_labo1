#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Vista.h"
#include "Tools.h"
#include "Errores.h"
#include "Service.h"
#include "Logs.h"
#define NOM_ARCH "log.txt"
#define NOM_ARCH2 "services.txt"
#define NOM_ARCH_W "warnings.txt"
#define NOM_ARCH_ERR "errors.txt"


int main()
{
   int opcion;
    char seguir='S';
    char sigo='S';
    int cantidad;
    eLogEntry* log;
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
            vista_ShowMenu("\n1:Leer Log\n2:Procesar Informacion\n3:Mostrar Estadisticas\n","MENU PRINCIPAL" );
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
                ListFiltrada=(gestion_Recorre_ArrayList(ListaLogs,funcionFiltro));
                if(ListFiltrada)
                {
                    vista_MuestraElementos(ListFiltrada,"LOGS CON GRAVEDAD MAYOR A 3","DIA\t\tHORA\tID_SERV\tGRAV\tMENSAJE DE ERROR",vista_MuestraUnElemento,0,ListFiltrada->len(ListFiltrada),15);
                }
                ListWarnings=gestion_recorre2yJunta(ListaLogs,ListaServicios,funcionFiltro,0);
                if(ListWarnings !=NULL)
                {
                vista_MuestraElementos(ListWarnings,"LOGS CON GRAVEDAD IGUAL A 3 SIN ID 45","DIA\t\tHORA\tID_SERV\tGRAV\tMENSAJE DE ERROR",vista_MuestraUnElementoError,0,ListWarnings->len(ListWarnings),15);
                GuardarArchivoT(ListWarnings,NOM_ARCH_W);
                }
                ListaImprime=gestion_recorre2yJunta(ListaLogs,ListaServicios,funcionFiltro,-3);
                if(ListaImprime !=NULL)
                {
                    vista_MuestraElementos(ListaImprime,"LISTA DE LA GRAVEDAD DE ERRORES","ERRORES CON GRAVEDAD MAYOR A 7",vista_MuestraUnElementoError,0,ListaImprime->len(ListaImprime),20);
                    GuardarArchivoT(ListaImprime,NOM_ARCH_ERR);
                }
                else
                {
                    printf("Lista Vacia ...\n");
                    system("pause");
                }
                break;
            case 3:

                while(sigo=='S')
                {
                vista_ShowMenu("\n1: Servicio con mas fallo\n2: Con gravedad menor a 3\n3: Con gravedad igual a 3\n4: Con gravedad entre 4 y 7\n5: Con gravedad mayor a 7\n","MENU DE ESTADISTICAS DE FALLO");
                scanf("%d",&opcion);
                tools_ValidaMenu(opcion,0,5);

                    switch(opcion)
                    {
                    case 1:
                        log=BuscaMaximo(ListaLogs,comparaServicio,1);
                        vista_MuestraUnElemento(log);
                        system("pause");
                        break;
                    case 2:
                        printf("CANTIDAD DE FALLOS CON GRAVEDAD MENOR 3= %d\n\n",ListaLogs->len(ListaLogs)-ListFiltrada->len(ListFiltrada));
                        system("pause");
                        break;
                    case 3:
                        cantidad=gestion_Recorrer_ArrayList(ListaLogs,comparaLog_conValor,45);
                        printf("cantidad %d",cantidad);
                        printf("CANTIDAD DE FALLOS CON GRAVEDAD IGUAL A 3 ES %d\n\n",ListWarnings->len(ListWarnings)+ cantidad);
                        system("pause");
                        break;
                    case 4:
                        printf("****************************************************\n");
                        printf("*\t\tCANTIDAD DE FALLOS= %d \t\t   *\n",ListWarnings->len(ListWarnings));
                        printf("*                                                  *\n");
                        printf("*\t\tCON GRAVEDAD ENTRE 4 Y 7\t   *\n");
                        printf("****************************************************\n");
                        system("pause");
                        break;
                    case 5:
                        printf("CANTIDA DE FALLOS CON GRAVEDAD MAYORES A 7 ES  %d\n",ListaImprime->len(ListaImprime));
                        system("pause");
                        break;
                    case 0:
                         sigo='N';
                        break;
                }//fin switch
                }
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
