#include <stdio.h>
#include <stdlib.h>

#include "Archivo.h"
#include "Producto.h"
#include "ArrayList.h"
#include "vista.h"


ArrayList* Lista_Localidad(ArrayList* this)
{
    int i;
    char local[25];
    ArrayList *ListAux;
    ArrayList *ListOrdenada;
    ListAux=NULL;
    ListOrdenada=NULL;
    if(this!=NULL)
    {
        ListAux=al_newArrayList();
        ListOrdenada=al_clone(this);
        eProducto* prod;
        if(ListAux !=NULL)
        {
            ListOrdenada->sort(ListOrdenada,prod_ComparaLocalidad,1);
        }
    for(i=0;i<ListOrdenada->len(ListOrdenada);i++)
    {
     prod=this->get(this,i);
//     local=prod[i]->localidad;

   //  if(prod->localidad==local))
     {
         al_add(ListAux,prod);
     }

    }//fin for
    }//fin if(this!=NULL)
    return ListAux;
}
ArrayList* Gestion_Localidades(ArrayList* this, int (*pFunc)(void* ,void*))
{
   int returnAux = -1;
    ArrayList* aux;
    ArrayList* ListAux;

    int i=0;
    int cant;
    eProducto *emp;

    if(this!= NULL && pFunc!=NULL )
    {
        ListAux=al_newArrayList();
        if(aux!=NULL)
        {
            aux=(al_get(this,i));
            cant=this->len(this);
            for(i=1;i < cant -1;i++)
            {
                    if(pFunc(aux,al_get(this,i))==0)
                    {
                     //  emp=aux;
                       al_add(ListAux,al_get(this,i));
                       returnAux=0;
                    }//fin if(pfunc)

            }//fin 1er for
        }//fin 1er for
    }
    return ListAux;
}

