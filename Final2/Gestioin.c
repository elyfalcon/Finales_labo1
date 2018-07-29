#include <stdio.h>
#include <stdlib.h>

#include "Archivo.h"
#include "Producto.h"
#include "ArrayList.h"
#include "vista.h"
#include "Localidades.h"

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
    ArrayList* aux1;
    ArrayList* ListAux;
    ArrayList* ListLocal;
    eLocalidad *local;

    int i,j;
    int cant;
    eProducto *emp;


    if(this!= NULL && pFunc!=NULL )
    {
        ListAux=al_clone(this);
        ListLocal=al_newArrayList();
        local=nueva;

        if(aux!=NULL)
        {
            cant=this->len(this);
            for(i=0;i < cant ;i++)
            {
                aux=(al_get(this,i));
                for(j=i+1;j<cant-1;j++)
                {
                    aux1=(al_get(this,j));

                    if(pFunc(aux,al_get(this,j))==0)
                    {
                      al_add(ListLocal,aux);
                      aux1=this->pop(this,aux1);
                      local=localidad_set_localidad(prod_get_localidad(aux1));
                      // al_add(ListAux,al_get(this,i));

                       returnAux=0;
                    }//fin if(pfunc)
                    else if(pFunc(aux,al_get(this,j))!=0)
                    {
                      //  local=aux;
                      //  al_add(ListAux,local);
                    }

            }//fin 1er for
            }//fin 2 for
        }//fin 1er for
    }
    return ListAux;
}
/*int gestion_quita_duplicados(void* eProductoA,void* eProductoB)
{
    int retorno=-1;
    int i,j;


    for(i=0;i<this->len(this);i++)
    {
        for(j=i+1;j<this->len(this)-1;j++)
        {
            if(prod_ComparaLocalidad())
        }


    }//fin for(i=


}*/
