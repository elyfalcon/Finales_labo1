#include <stdio.h>
#include <stdlib.h>

#include "Archivo.h"
#include "Producto.h"
#include "ArrayList.h"
#include "vista.h"
#include "Localidades.h"
#include "tools.h"

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



ArrayList* al_eliminaDuplicados(ArrayList* this, int (*pFunc)(void* ,void*))
{
    ArrayList* ListAux;
    if(this!= NULL && pFunc!=NULL )
    {
        ListAux=al_clone(this);
        if(ListAux!=NULL)
        {
            for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
            {
                for(int j=i+1;j < ListAux->len(ListAux) ; )
                {
                    if(pFunc(al_get(ListAux,i),al_get(ListAux,j))==0)
                    {
                      ListAux->pop(ListAux,j);
                    }
                    else
                    {
                        j++;
                    }
                }//FIN for(int j=i+1;j < ListAux->len(ListAux) ;j++)
            }//FIN for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
        }
    }
    return ListAux;
}

/*
ArrayList* al_eliminaDuplicados(ArrayList* this, int (*pFunc)(void* ,void*))
{
    ArrayList* ListAux;
    int i,j;

    if(this!= NULL && pFunc!=NULL )
    {
        ListAux=al_clone(this);
        if(ListAux!=NULL)
        {
            for(i=0;i < ListAux->len(ListAux) -1 ;i++)
            {
                for(j=i+1 ;j<ListAux->len(ListAux); )
                {

                    if(pFunc( al_get(ListAux,i), al_get (ListAux,j ) ) ==0)
                    if(pFunc( al_get(ListAux,i), al_get (ListAux,j )  ==0 ) )
                    {
                      ListAux->pop(ListAux,j);
                    }
                    else
                    {
                        if(pFunc( al_get(ListAux,i),al_get(ListAux,j )== -2 ))
                        {
                              printf("\n ERROR \n");
                              system("pause");
                        }
                        else
                        {
                            j++;
                        }

                    }//fin if(pfunc)
                }//fin 1er for
            }//fin 2 for
        }//fin 1er for
    }
   return ListAux;
}
*/

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
ArrayList* Gestion_Localidades(ArrayList* this)
{
    eProducto *auxprod;

    ArrayList* ListLocal;
    eLocalidad *auxlocal;
    char *localidad;

    int i;
    int cant;
    if(this!= NULL)
    {
        ListLocal=al_newArrayList();
        if(ListLocal!=NULL)
        {
            cant=this->len(this);
            for(i=0;i < cant ;i++)
            {
                auxprod=(al_get(this,i));//Obtengo producto
                localidad=prod_get_localidad(auxprod); //localidad del producto

                auxlocal=nueva();
                localidad_set_localidad(auxlocal,localidad);//cargo localidad en Recorset de localidades
                localidad_set_id(auxlocal,i+1);
                al_add(ListLocal,auxlocal); //Agrego el recorseet de localidades al ArrayList de localidades
            }//fin 1er for
        }//fin if(ListLocal!=NULL)
    }//fin if(this!= NULL)
    return ListLocal;
}

int gestion_buscarNombre(ArrayList* this, char nom[])
{
    int retorno=0;
    int i;
    eProducto* emp;
    if(this!=NULL && nom !=NULL)
    {
        if(this->isEmpty(this)==0)
       {
        retorno=1;
    //    if(emp !=NULL)
    //    {
            for(i=0;i<this->len(this);i++)
            {
            emp=this->get(this,i);
            if(prod_get_localidad(emp)==nom)
            {
                retorno=i;
                break;
            }//fin if
            else if(prod_get_localidad(emp)!=nom)
            {
                retorno=-1;
            }
            }//fin for
//        }//fin if(emp)
        }
    }//fin if(this!)
    return retorno;
}

int gestion_BuscarYGuardar(ArrayList* this,ArrayList* that)
{
    int retorno=-1;
    char nombre[25];
    int i,cod_prod,id,num_deposito,num;
    char resp;
    eProducto* prod;
    eLocalidad* local;
    ArrayList* Listreparto;

    if(this !=NULL && that!=NULL)
    {
        vista_MostrarElementosLocalidad(that,"LISTADO DE LOCALIDADES",0,that->len(that));
        num=ingresarInt("\Ingrese Nro que Desea Imprimir", 1, that->len(that));
        local=al_get(that,num-1);
        strcpy(nombre,local->localidad );
        //strcpy(nombre,(al_get(that,(num))) );
        Listreparto=al_filter3(this,prod_compareconLocalidad,nombre);
        if(Listreparto !=NULL)
        {
         strcat(nombre,".csv");
          al_MuestraElementos(Listreparto,"REPARTO DE LOCALIDADES",vista_Muestra1UnElemento,0,Listreparto->len(Listreparto),25);
          GuardarArchivoT(Listreparto,nombre);
        }
        else if(Listreparto==NULL)
        {
            printf("Lista vacia\n");
            system("pause");
        }

    }





  }
