#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ArrayList.h"
#include "Archivo.h"
#include "Logs.h"
#include "Service.h"
#include "Tools.h"
#include "Errores.h"




#define MASCARA_IMPRIMIRLOG "%s\t%s\t%d\t%d\t%s\n"
#define MASCARA_IMPRIMIRSERV "%d\t%s\t%s\n"
#define MASCARA_IMPRIMIRERR7 "%s\t%s\t%s\t%s\%s\n"
#define MASCARA_IMPRIMIR3 "%d\t%.25s\t\t%d\t%d\t%s\t%d\n"

void vista_ShowMenu(char *opcion,char *titulo)
{
    int op;
    system("cls");
    printf("\n\n");
    printf("**********%s**********\n\n",titulo);
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

int vista_MuestraUnElemento(eLogEntry * record)
{
    int retorno=-1;
    record=(eLogEntry*)record;
    if(record !=NULL)
    {
        retorno=0;
        printf(MASCARA_IMPRIMIRLOG,log_get_date(record),log_get_time(record),log_get_IdService(record),log_get_gravedad(record),log_get_msg(record));//definir una mascara
    }
    return retorno;
}
int vista_MuestraUnElementoService(eService * record)
{
    int retorno=-1;
    record=(eLogEntry*)record;
    if(record !=NULL)
    {
        retorno=0;
        printf(MASCARA_IMPRIMIRSERV,serv_get_Id(record),serv_get_name(record),serv_get_email(record));//definir una mascara
    }
    return retorno;
}
int vista_MuestraUnElementoError(eErrores * record)
{
    int retorno=-1;
    record=(eErrores*)record;
    if(record !=NULL)
    {
        retorno=0;
        printf(MASCARA_IMPRIMIRERR7,error_get_date(record),error_get_time(record),error_get_name(record),error_get_msg(record),error_get_email(record));//definir una mascara
    }
    return retorno;
}
/*
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
int vista_MuestraUnFEED(eFeed * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        retorno=0;
        printf(MASCARA_IMPRIMIR3,record->id_mensaje,record->mensaje,record->popu,record->id_usuario,record->nick,record->popu_feed);//definir una mascara
    }
    return retorno;
}
*/
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
                printf("\n\nSe procesaron: %d registros\n\n",cont);
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
/*
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
*/
