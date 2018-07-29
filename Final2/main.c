#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Archivo.h"
#include "Producto.h"
#include "ArrayList.h"
#include "vista.h"
#include "Gestion.h"
#include "Localidades.h"

#define NOM_ARCH "DATA_FINAL_V1.csv"
#define TIENE_ENCABEZADO 1

int main()
{
    int opcion;
    char seguir='S';

    ArrayList *ListaProductos;
    ArrayList *ListAuxiliar;

    ListaProductos=al_newArrayList();//NO TE OLVIDES LOS PARENTESISSSSS
    ListAuxiliar=al_newArrayList();

    if(ListaProductos !=NULL)
    {
        while(seguir=='S')
        {
            vista_ShowMenu("1:Cargar Archivo\n2:Imprimir Entregas\n3:Imprimir Localidades\n4:Generar archivo de reparto para localidad\n");
            scanf("%d",&opcion);
            ValidaMenu(opcion,0,4);

            switch(opcion)
                {
                case 1:
                cargarDesdeArchivo(ListaProductos,NOM_ARCH);
                    break;
                case 2:
                    vista_MostrarElementos(ListaProductos,"LISTADO DE ENTREGAS",0,ListaProductos->len(ListaProductos));
                    break;
                case 3:
                    ListAuxiliar=Gestion_Localidades(ListaProductos,prod_ComparaLocalidad);
                    if(ListAuxiliar !=NULL)
                    {
                        vista_MostrarElementosLocalidad(ListAuxiliar,"LISTADO POR LOCALIDADES",0,ListAuxiliar->len(ListAuxiliar));
                    }
                    break;
                case 0:
                    seguir='N';
                    break;

            }//fin switch

        }//fin while



    }

    return 0;
}
