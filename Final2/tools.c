#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"
#include "Archivo.h"

int ValidarCantCaracteres(char* cadena,int cantidad)
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
void RemoveSpaces(char* source)
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
int ComparaFrases(char* frase1,char* frase2)
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
int PedirEntero(char mensaje[])
{
    int auxiliar;

    do
    {
    printf("%s",mensaje);
    fflush(stdin);
    }while(scanf("%d",&auxiliar)==0);
    return auxiliar;
}
char Responder(char mensaje[])
{
    char resp;
    //int flag=-1;

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

void ValidaMenu(int opcion,int limite_inferior,int limite_superior)
{
     if(opcion <limite_inferior || opcion >limite_superior)
        printf("Debe elegir una opcion entre %d y %d: \n",limite_inferior,limite_superior);
}

void ShowMenu(char *opcion)
{
    system("cls");
    printf("MENU PRINCIPAL\n\n");
    printf("Ingrese una opcion: \n");
    printf("%s \n",opcion);
    printf("\n0.  Salir \n");
}
int funcionFiltro(void* aux)
{
    int retorno=0;
    eProducto *emp;
    emp=(eProducto * ) aux;

    if(prod_get_id(emp) > 20000)
    {
        retorno=1;
    }
    return retorno ;
}
/*eEmpleado* BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor)
{
   int returnAux = -1;
    ArrayList* aux;
    int i=0;
    eEmpleado *emp;

    if(this!= NULL && pFunc!=NULL && (valor==0 || valor==1))
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
                       emp=aux;
                       returnAux=0;
                    }//fin if(pfunc)
                    else
                    {
                        aux=al_get(this,i);
                        emp=aux;
                    }
                    }//fin if(valor)
                if(valor==0)
                {
                    if(pFunc(aux,al_get(this,i))==-1)
                    {
                        emp=aux;
                      //  aux=al_get(this,i);
                    }
                else
                {
                 aux=al_get(this,i);
                 emp=aux;
                }
                returnAux=0;

                }//fin if

            }//fin 1er for

          //  } //fin 2do for

        }//fin 1er for
    }
    return emp;

}*/
