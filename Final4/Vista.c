#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ArrayList.h"
#include "Archivo.h"
#include "Estructura.h"
#include "Gestion.h"
#include "Tools.h"



#define MASCARA_IMPRIMIR "%d\t%d\t%d\t%.50s\t\n"
#define MASCARA_IMPRIMIR2 "%d\t%s\t%d\n"

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
        printf(MASCARA_IMPRIMIR,est_get_idmensaje(record),est_get_idUsuario(record),est_get_popu(record),est_get_texto(record));//definir una mascara
    }
    return retorno;
}

int vista_MuestraUnElementoUsuario(void * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        retorno=0;
        printf(MASCARA_IMPRIMIR2,est_get_idUsu(record),est_get_nick(record),est_get_popu_Usu(record));//definir una mascara
    }
    return retorno;
}


int vista_MuestraElementos(ArrayList *this,char *Titulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado)
{
    int retorno=-1;
    int i;
    int cont=0;
    if(this!=NULL && Titulo!=NULL)
    {
        retorno=0;
        system("cls");
        printf("\n\n-------- %s --------\n",Titulo);
        printf("\nId\tId_Mens\tLikes\tMENSAJE\n\n");
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
