#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"
#include "Logs.h"
#include "Service.h"
#include "Errores.h"


ArrayList* gestion_Recorre_ArrayList(ArrayList *this,int (*pFunc)(void*))
{
    int retorno=-1;
    int i;
    int cant=0;
    eLogEntry *aux;
    ArrayList *ListAux;
    if(this!=NULL )
    {
        retorno=-2;
        ListAux=al_newArrayList();
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=0; i<this->len(this);i++ )
            {
                aux=al_get(this,i);
                retorno=pFunc(aux); //llamada a una funcion que se pasa por parametro
               if(retorno==1)
                {
                    //ListFiltrada->pop(ListFiltrada,aux);
                  //  aux=al_get(this,i);
                  //  al_remove(ListFiltrada,i);

                    cant++;

                }//fin if(pFunc(al_get(this,i))==1)
                else
                {
                    ListAux->add(ListAux,aux);
                }

              //   if(pFunc(al_get(this,i))==0 && aux->serviceId !=45)
              //  {
             //   GuardarArchivoT(this,NOM_ARCH_W);
            //    }
            }//for for(i=0; i<this->len(this) ; i++)
        }//if(this->isEmpty(this)==0)
    }//if(this!=NULL && Titulo!=NULL)
    else
    {
        printf("Lista vacia\n");
        system("pause");
    }
    return ListAux;
}

ArrayList* gestion_recorre2yJunta(ArrayList* this,ArrayList* that,int (*pFunc)(void*),int valor)
{
    int i,j;
    int cont=0;
    int cant=0;
    eLogEntry* log;
    eService* servicio;
    eErrores* error;
    ArrayList* ListAux;

    if(this !=NULL && that !=NULL)
    {
        ListAux=al_newArrayList();

        for(i=0;i < this->len(this);i++)
        {
            log=al_get(this,i);
            if(pFunc(log)==valor)
            {
                cant++;
                for(j=0;j < that->len(that);j++)
                {
                    servicio=al_get(that,j);
                    if(log_get_IdService(log,i)==(serv_get_Id(servicio,j)))
                    {
                        error=new_error(log_get_date(log),log_get_time(log),serv_get_name(servicio),log_get_msg(log),log_get_gravedad(log),serv_get_email(servicio));
                      // ListAux=->add(ListAux,error);
                      al_add(ListAux,error);
                      cont++;
                    }//fin if(log_get_IdService(log,i)==(serv_get_Id(servicio,j)))
                }//fin for(j=0;j < that->len(that);j++)

            }//fin if(pFunc(al_get(this,i))==-1)
        }//fin for(i=0;i < this->len(this);i++)

    }//fin if(this !=NULL && that !=NULL)
    return ListAux;
}

int gestion_Recorrer_ArrayList(ArrayList *this,int (*pFunc)(void*, void*),int valor)
{
    int retorno=-1;
    int i;
    int cant=0;
    eLogEntry *aux;
    if(this!=NULL )
    {
        retorno=-2;
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=0; i<this->len(this);i++ )
            {
                aux=al_get(this,i);
                retorno=pFunc(aux,valor); //llamada a una funcion que se pasa por parametro
                printf("id %d  gravedad= %d",aux->serviceId,log_get_gravedad(aux));
                system("pause");
               if(retorno==0 && (log_get_gravedad(aux)==3))
                {
                    printf("id %d  gravedad= %d",aux->serviceId,log_get_gravedad(aux));

                    //ListFiltrada->pop(ListFiltrada,aux);
                  //  aux=al_get(this,i);
                  //  al_remove(ListFiltrada,i);

                    cant++;

                }//fin if(pFunc(al_get(this,i))==1)

              //   if(pFunc(al_get(this,i))==0 && aux->serviceId !=45)
              //  {
             //   GuardarArchivoT(this,NOM_ARCH_W);
            //    }
            }//for for(i=0; i<this->len(this) ; i++)
        }//if(this->isEmpty(this)==0)
    }//if(this!=NULL && Titulo!=NULL)
    else
    {
        printf("Lista vacia\n");
        system("pause");
    }
    return cant;
}

