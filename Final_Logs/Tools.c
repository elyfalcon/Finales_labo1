#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
//#include "Estructura.h"
//#include "Gestion.h"
#include "Vista.h"
#include "Logs.h"
#include "Service.h"

#define NOM_FEED "feed.csv"


char Responder(char mensaje[])
{
    char resp;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",&resp);
    resp=toupper(resp);
    while(resp!='S'&& resp!='N')
    {
      printf("\nDebe ingresar S(si) N(no)\n");
      scanf("%s",&resp);
      resp=toupper(resp);
    }
    return resp;
}
void tools_ValidaMenu(int opcion,int limite_inferior,int limite_superior)
{
     if(opcion <limite_inferior || opcion >limite_superior)
        printf("Debe elegir una opcion entre %d y %d: \n",limite_inferior,limite_superior);
}
int funcionFiltro(eLogEntry* aux)
{
    int retorno=-3;
    void *record;
    record=(eLogEntry * ) aux;

   if(log_get_gravedad(record) < 3)
    {
        retorno=1;
    }
    else if(log_get_gravedad(record) ==3 && log_get_IdService(record) !=45)
    {
        retorno=0;
    }
    else if(log_get_gravedad(record) >=4 && log_get_gravedad(record) <= 7)
    {
        retorno=-1;
    }
    return retorno ;
}
int tools_ingresarInt (char pregunta[], int minimo,int maximo)
{
    int numero;
    printf("%s\t", pregunta);
    fflush(stdin);
    scanf("%d", &numero);

    while(numero>maximo|| numero<minimo|| isalpha(numero))
    {
        fflush(stdin);
        printf("\nReingrese %s\t", pregunta);
        scanf("%d", &numero);
    }
    return numero;
}

int tools_ValidarCantCaracteres(char* cadena,int cantidad)
{
    int longi,flag;
    longi=strlen(cadena);
    flag=0;
    if(longi<=cantidad)
    {
        flag=1;
    }
    return flag;
}
void tools_RemoveSpaces(char* source)
{
  char* i = source;
  char* j = source;

  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
    {
    i++;
    }
  }
  *i = 0;
}
int tools_PedirEntero(char mensaje[])
{
    int auxiliar;
    do
    {
    printf("%s",mensaje);
    fflush(stdin);
    }while(scanf("%d",&auxiliar)==0);
    return auxiliar;
}

/*int tools_ComparaFrases(char* frase1,char* frase2)
 {
    char aux[20]={};
    char aux2[20]={};
    printf("Ingrese una frase\n");
    gets(frase1);
    printf("Ingrese una frase\n");
    gets(frase2);
    RemoveSpaces(frase1);
    RemoveSpaces(frase2);
    strlwr(frase1);
    strlwr(frase2);
    printf("frase1:%s",frase1);
    printf("frase1:%s",frase2);
    if(strcmp(frase1,frase2)==0)
    {
        printf("ya ingreso esa frase:");
    }
    else
        printf("Son distintas");
}
*/

/*ArrayList* Compara_2ArrayList(ArrayList* this,ArrayList* that,int (*pFunc)(void*,void*))///VEEERRR
{
    int retorno=-1;
    int i,j;
    ArrayList *ListAux;
    eMensajes* messg=NULL;
    eUsuario* usu=NULL;
    eFeed* feed=NULL;
    if(this !=NULL && that !=NULL)
    {
        retorno=0;
        ListAux=al_newArrayList();
        for(i=0;i<this->len(this);i++) //recorro el 1er ArrayList
        {
         messg=(eMensajes*)al_get(this,i);
         for(j=0;j <that->len(that);j++) //recorro el 2 ArrayList
         {
             usu=(eUsuario*)al_get(that,j);
             if(pFunc(messg,usu)==0)
             {
                 //int id_mensaje, char mensaje[200],int popu,int id_usuario,char nick[20], int pop_usuario
                feed=feed_new(est_get_idmensFeed(messg),est_get_textoFeed(messg),est_get_popuMens(messg),usu->id_usuario,usu->nick,usu->popu_usuario);

                 if(feed !=NULL)
                 {
                    ListAux->add(ListAux,feed);
                    retorno=1;
                 }//fin if(feed !=NULL)

             }//fin if(pFunc(al_get(this,i),al_get(that,j))==0)
         }//for(j=0;j <that->len(that);j++)
        }// fin for(i=0;i<this->len(this);i++)
    }//fin if(this!=NULL && that !=NULL)
    if(retorno==1)
    {
        GuardarArchivoT(ListAux,NOM_FEED);
        printf("Se creo correctamente \n");
        system("pause");
    }
    return ListAux;
}
*/
/*
int gestion_buscarId(ArrayList* this, int cod)
{
    int retorno=0;
    int i;
    eEstructura* record;
    if(this!=NULL && cod >0)
    {
        if(this->isEmpty(this)==0)
       {
        retorno=1;
    //    if(record !=NULL)
    //    {
            for(i=0;i<this->len(this);i++)
            {
            record=this->get(this,i);
            if(estruc_get_id(record)==cod)
            {
                retorno=i;
                break;
            }//fin if
            else if(estruc_get_id(record)!=cod)
            {
                retorno=-1;
            }
            }//fin for
//        }//fin if(record)
        }
    }//fin if(this!)
    return retorno;
}*/
/*eEstructura* BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor)
{
   int returnAux = -1;
    ArrayList* aux;
    int i=0;
    eEstructura *record;

    if(this!= NULL && pFunc!=NULL && (valor==0 || valor==1))//si es 1 busca maximo
    {
        if(aux!=NULL)
        {
            aux=(al_get(this,i));
            for(i=1;i < al_len(this)-1;i++)
            {
                if(valor==1)
                {
                    if(pFunc(aux,al_get(this,i))==1)
                    {
                       record=aux;
                       returnAux=0;
                    }//fin if(pfunc)
                    else
                    {
                        aux=al_get(this,i);
                        record=aux;
                    }
                    }//fin if(valor)
                if(valor==0)
                {
                    if(pFunc(aux,al_get(this,i))==-1)
                    {
                        record=aux;
                      //  aux=al_get(this,i);
                    }
                else
                {
                 aux=al_get(this,i);
                 record=aux;
                }
                returnAux=0;
                }//fin if
            }//fin 1er for
          //  } //fin 2do for
        }//fin 1er for
    }
    return record;
}*/
