#include <stdio.h>
#include <stdlib.h>
#include "Archivo.h"

#include "ArrayList.h"
#define MASCARA_IMPRIMIR "%c\t%s\t%d\t%d\n"


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
//**********************VISTAS DE IMPRESION***************************************
int vista_Muestra1UnElemento(void * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        retorno=0;
        printf(MASCARA_IMPRIMIR,letra_get_letra(record),letra_get_nombre(record),letra_get_vocal(record),letra_get_conson(record));
    }
    return retorno;
}

int vista_MuestraElementos(ArrayList *this,char *Titulo,char *SubTitulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado)
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
        printf("\n%s\n");
        printf("\n %s\n",SubTitulo);
        if(this->isEmpty(this)==0)//No esta vacio
        {
            for(i=desde;i<hasta;i++)
            {
                if(cont!=0 && cont %paginado==0)
                {
                   system("pause");
                    system("cls");
                }
                pFunc(al_get(this,i)); //llama a la funcion que muestra 1 elemento
                cont++;
            }
            if(cont!=0)
            {//pausa la ultima tanda de elementos mostrados
                printf("\n********************************************");
                printf("*                                          *");
                printf("*                                          *");
                printf("\n\nSe procesaron: %d registros               *\n\n",cont);
                printf("\n********************************************\n");
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


//***********************************FIN VISTA IMPRESION****************************************************
int al_MuestraElementos(ArrayList *this,char *Titulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado)
{
    int retorno=-1;
    int cont=0;
    if(this!=NULL && Titulo!=NULL)
    {
        retorno=0;
        system("cls");
        printf("\n\n-------- %s --------\n",Titulo);
        printf("\nID\tPRODUCTO\t\tDIRECCION\t\tLOCALIDAD\tRECIBE\n\n");
        if(this->isEmpty(this)==0)
        {//No esta vacio

            for(int index=desde;index<hasta;index++)
            {
                if(cont!=0 && cont %paginado==0)
                {
                    system("pause");
                    system("cls");
                    printf("\n\n-------- %s --------\n",Titulo);
                }
                pFunc(al_get(this,index));
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
int vista_Pedir_Localidad(int choice)
{
    int retorno=0;
    system("cls");
    vista_ShowTitulo("\n\t\tGENERAR REPARTO EN LOCALIDADES\n");


    return retorno;
}
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
