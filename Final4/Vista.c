#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ArrayList.h"
#include "Archivo.h"
#include "Estructura.h"
#include "Gestion.h"
#include "Tools.h"
#include "Feed.h"
#include "Usuario.h"
#include "Mensaje.h"

#define MASCARA_IMPRIMIR "%d\t%d\t%d\t%.50s\t\n"
#define MASCARA_IMPRIMIR2 "%d\t%s\t\t%d\n"
#define MASCARA_IMPRIMIR3 "%d\t%.25s\t\t%d\t%d\t%s\t\t%d\n"

void vista_ShowMenu(char *opcion)
{
    int op;
    system("cls");
    printf("\n\n");
    printf("**********MENU PRINCIPAL**********\n\n");
    printf("Ingrese una opcion: \n");
    printf("%s \n",opcion);
    printf("\n0.  Salir \n");


}
void vista_ShowTitulo(char titulo[])
{
    printf("%s----\n\n",titulo);
}
//****************************FUNCIONES DE IMPRESION ******************************
//**********************************************************************************
int vista_MuestraUnElemento(eMensajes * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        retorno=0;
        printf(MASCARA_IMPRIMIR,mensaje_get_id(record),mensaje_get_idUsuario(record),mensaje_get_popu(record),mensaje_get_texto(record));//definir una mascara
    }
    return retorno;
}

int vista_MuestraUnElementoUsuario(void * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        retorno=0;
        printf(MASCARA_IMPRIMIR2,usuario_get_id(record),usuario_get_nick(record),usuario_get_popu(record));//definir una mascara
    }
    return retorno;
}
int vista_MuestraUnFEED(eFeed * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        retorno=0;
      //  printf(MASCARA_IMPRIMIR3,feed_record->id_mensaje,record->mensaje,record->popu,record->id_usuario,record->nick,record->popu_feed);//definir una mascara

        printf(MASCARA_IMPRIMIR3,feed_get_idmens(record),feed_get_texto(record),feed_get_popuMens(record),feed_get_idUsu(record),feed_get_nick(record),feed_get_popu_Usu(record));//definir una mascara
    }
    return retorno;
}

int vista_MuestraElementos(ArrayList *this,char *Titulo,char * SubTitulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado)
{
    int retorno=-1;
    int i;
    int cont=0;
    if(this!=NULL && Titulo!=NULL)
    {
        if(this->isEmpty(this)==0)
        {
        retorno=0;
        system("cls");
        printf("\n\n-------- %s --------\n",Titulo);
        printf("\n%s\n",SubTitulo);
        printf("===============================================================================\n");
        if(this->isEmpty(this)==0)//No esta vacio
        {
            for(i=desde;i<hasta;i++)
            {
                if(cont!=0 && cont %paginado==0)
                {
                    system("pause");
                    system("cls");
                    printf("\n\n-------- %s --------\n",Titulo);
                }
                pFunc(al_get(this,i)); //llama a la funcion que muestra 1 elemento
                cont++;
            }
            if(cont!=0)
            {//pausa la ultima tanda de elementos mostrados
                system("pause");
            }
        }//if(this->isEmpty(this)==0)
        else
        {//o con error o sin datos a mostrar
            printf("\n Sin Datos a Motrar...\n");
            system("pause");
        }
       }
       else if(this->isEmpty !=0)
       {
           printf("Lista vacia\n");
           system("pause");
       }
    }//if(this!=NULL && Titulo!=NULL)
    return retorno;
}
//*****************************************************************
void vista_ingresarTexto (char texto[], int cantTexto, char pregunta[])
{
    char titulo [50];
    char auxtitulo [cantTexto-1];
    int i;

    printf("%s\t", pregunta);
    fflush(stdin);
    gets (titulo);
    for (i=0; i<cantTexto; i++)
    {
        auxtitulo[i]=titulo[i];
    }
    strcpy(texto, auxtitulo);
}
