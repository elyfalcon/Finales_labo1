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


int main()
{
    int opcion;
    char seguir='S';

    ArrayList *ListaProductos;
    ArrayList *ListAuxiliar;
    ArrayList *ListaLocalidades;

    ListaProductos=al_newArrayList();//NO TE OLVIDES LOS PARENTESISSSSS
    ListAuxiliar=al_newArrayList();
    ListaLocalidades=al_newArrayList();

    if(ListaProductos !=NULL && ListAuxiliar!=NULL  && ListaLocalidades!=NULL)
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
                    system("pause");
                    break;
                case 3:
                   // ListAuxiliar=Gestion_Localidades(ListaProductos,prod_ComparaLocalidad);

                   ListAuxiliar=al_eliminaDuplicados(ListaProductos,prod_ComparaLocalidad);
                   printf("len: %d \n",ListAuxiliar->len(ListAuxiliar));
                   system("pause");


                    if(ListAuxiliar !=NULL)
                    {
                        ListaLocalidades=Gestion_Localidades(ListAuxiliar);
                        //vista_MostrarElementos(ListaLocalidades,"LISTADO DE LOCALIDADES",0,ListaLocalidades->len(ListaLocalidades) );

                        //al_MuestraElemento_desde_hasta(ListaLocalidades,"LISTADO POR LOCALIDADES",vista_MuestraUnElementoLocalidad ,0,ListaLocalidades->len(ListaLocalidades),100);
                        vista_MostrarElementosLocalidad(ListaLocalidades,"LISTADO POR LOCALIDADES",0,ListAuxiliar->len(ListAuxiliar));
                        system("pause");
                    }
                    break;
                case 4:
                    gestion_BuscarYGuardar(ListaProductos,ListaLocalidades);
                    break;
                case 0:
                    seguir='N';
                    break;

            }//fin switch

        }//fin while



    }

    return 0;
}
