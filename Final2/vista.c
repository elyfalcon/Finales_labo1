#include <stdio.h>
#include <stdlib.h>
#include "Archivo.h"
#include "Producto.h"
#include "ArrayList.h"

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
int vista_Muestra1UnElemento(eProducto * prod)
{
    int retorno=-1;
    if(prod !=NULL)
    {
        retorno=0;
        printf("%02d\t%15s\t\t%-20s\t\t\%-25s\t%s\n",prod_get_id(prod),prod_get_nombre(prod),prod->direccion,prod->localidad,prod->recibe); //definir una mascara
       // printf("%d\t%s\t%d\n",prod_get_id(emp),/*emp->descrip*/prod_get_descripcion(emp),prod_get_cantidad(emp));

    }
    return retorno;
}
int vista_MuestraUnElementoLocalidad(eProducto * prod)
{
    int retorno=-1;
    if(prod !=NULL)
    {
        retorno=0;
        printf("%02d\t%15s\n",prod_get_id(prod),prod->localidad);//,prod_get_nombre(prod),prod->direccion,,prod->recibe); //definir una mascara
       // printf("%d\t%s\t%d\n",prod_get_id(emp),/*emp->descrip*/prod_get_descripcion(emp),prod_get_cantidad(emp));

    }
    return retorno;
}
void vista_MostrarElementos(ArrayList *this,char *Titulo,int desde, int hasta)
{
    int i;
    int cont_lineas=0;
   // if(this !=NULL && desde>=0 && hasta < this->len(this))
   if(this !=NULL)
    {
        system("cls");
        printf("\n\n--------%s--------\n\n",Titulo);
        //printf("\nId Producto\tDireccion\tLocalidad\tRecibe\n\n");
        vista_ShowTitulo("\nId\t Producto\t\t\tDireccion\\t\tLocalidad\tRecibe");
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=desde;i<hasta;i++)
            {
                vista_Muestra1UnElemento(al_get(this,i));
                cont_lineas++;
                if(cont_lineas==15)
                {
                    system("pause");
                   // cont_lineas=0;
                }
            }//fin for i
        }
      //  system("\npause");
        else
        {
            printf("Lista vacia\n");
            system("pause");
        }
    }
}
void vista_MostrarElementosLocalidad(ArrayList *this,char *Titulo,int desde, int hasta)
{
    int i;
    int cont_lineas=0;
   // if(this !=NULL && desde>=0 && hasta < this->len(this))
   if(this !=NULL)
    {
        system("cls");
        printf("\n\n--------%s--------\n\n",Titulo);
        //printf("\nId Producto\tDireccion\tLocalidad\tRecibe\n\n");
        vista_ShowTitulo("\nId\t Localidad");
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=desde;i<hasta;i++)
            {
                vista_MuestraUnElementoLocalidad(al_get(this,i));
                cont_lineas++;
                if(cont_lineas==15)
                {
                    system("pause");
                   // cont_lineas=0;
                }
            }//fin for i
        }
      //  system("\npause");
        else
        {
            printf("Lista vacia\n");
            system("pause");
        }
    }
}