#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ArrayList.h"
#include "Archivo.h"
#include "Estructura.h"
#include "Gestion.h"
#include "Tools.h"



#define MASCARA_IMPRIMIR "%c\t%s\t%d\t%d\t\n"

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
int vista_MuestraUnElemento(void * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        retorno=0;
        printf(MASCARA_IMPRIMIR,eLetra_getLetra(record),letra_get_nombre(record),letra_get_vocal(record),letra_get_conson(record)); //definir una mascara

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
        printf("\nLETRA\tNOMBRE\tVOCAL\tCONSONANTE\n\n");
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

