#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Estructura.h"
#include "Gestion.h"
#include "Vista.h"



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
int funcionFiltro(void* aux)
{
    int retorno=0;
    void *record;
    record=(void * ) aux;

 //  if(prod_get_id(record) > 20000)
    {
        retorno=1;
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

ArrayList* Compara_2ArrayList(ArrayList* this,ArrayList* that,int (*pFunc)(void*,void*))
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
      //  feed=nuevo_feed();
        ListAux=al_newArrayList();
        for(i=0;i<this->len(this);i++) //recorro el 1er ArrayList
        {
         messg=al_get(this,i);
         for(j=0;j <that->len(that);j++) //recorro el 2 ArrayList
         {
             usu=al_get(that,j);
             if(pFunc(al_get(this,i),al_get(that,j))==0)
             {
               // feed=feed_new(est_get_idmensFeed(messg),est_get_textoFeed(messg),est_get_popuMens(messg),est_get_idUsuFeed(usu),est_get_popu_UsuFeed(usu));
                feed=nuevo_feed();
                est_get_idmensFeed(messg);
                est_get_textoFeed(messg);
                est_get_popuMens(messg);
                est_get_idUsuFeed(usu);
                est_get_popu_UsuFeed(usu);

                est_set_idmensFeed(feed,messg);
                est_set_textoFeed(feed, messg);
                est_set_popuMens(feed, messg);
                est_set_idUsuario(feed, usu);
                est_set_nickFeed(feed, usu);
                est_set_popu_UsuFeed(feed, usu);

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
        printf("Se creo correctamente \n");
        system("pause");
    }
    return ListAux;
}
