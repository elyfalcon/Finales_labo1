#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Letra.h"
#include "Vista.h"
#include "Gestion.h"
#define NOM_ARCH "dato.csv"

int main()
{
    int opcion;
    char seguir='S';
    char nom[21];
    ArrayList *ListaLetras;
    ListaLetras=al_newArrayList();
    ArrayList *ListaPalabras;
    ArrayList *ListaConPalabras;
    ListaConPalabras=al_newArrayList();
    ArrayList *ListaSinLetras;
    if(ListaLetras !=NULL)
    {
     while(seguir=='S')
     {
         vista_ShowMenu("1:Altas\n2:Completar\n3:Listar\n");
         scanf("%d",&opcion);
        ValidaMenu(opcion,0,4);
          switch(opcion)
            {
            case 1:
                cargarDesdeArchivo(ListaLetras,NOM_ARCH);
                vista_MuestraElementos(ListaLetras,"LISTADO DE LETRAS","LETRA\tNOMBRE\tVOCAL\tCONSONANTE\n",vista_Muestra1UnElemento,0,ListaLetras->len(ListaLetras),20);
                break;
            case 2:
                gestion_Completar(ListaLetras,completa_VocalConsonante);
                vista_MuestraElementos(ListaLetras,"LISTADO DE LETRAS","LETRA\tNOMBRE\tVOCAL\tCONSONANTE\n",vista_Muestra1UnElemento,0,ListaLetras->len(ListaLetras),20);
                break;
            case 3:
                 ListaSinLetras=al_clone(ListaLetras);
                vista_ingresarTexto(nom,21,"Ingrese una palabra");
                if(ListaSinLetras !=NULL)
                {
                    ListaConPalabras=gestion_Existen_Letras(ListaSinLetras,nom);
                    vista_MuestraElementos(ListaSinLetras,"LISTADO DE LAS LETRAS QUE NO FORMAN LA PALABRA INGRESADA","LETRA\tNOMBRE\tVOCAL\tCONSONANTE\n",vista_Muestra1UnElemento,0,ListaSinLetras->len(ListaSinLetras),20);
                }
                if(ListaConPalabras !=NULL)
                {
                   vista_MuestraElementos(ListaConPalabras,"LISTADO DE LETRAS DE LA PALABRA INGRESADA","LETRA\tNOMBRE\tVOCAL\tCONSONANTE\n",vista_Muestra1UnElemento,0,ListaConPalabras->len(ListaConPalabras),20);

                }

                break;
            case 0:
                seguir='N';
                break;
                }//fin switch
     }//fin while
    }//fin if

    return 0;
}
