#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"
#include "Estructura.h"
#include "fenv.h"
#include "Mensaje.h"
#include "Usuario.h"

//********CONSTRUCTORES*********************




//***************FEED**************

//**********GETTERS PARA LETRAS*****************

/*char eLetra_getLetra(void * record)
{
    eLetra *tmp_1;
    tmp_1=(eLetra * ) record;

    return tmp_1->letra;
}*/
//*****************setters y getters genericos *****************************

//************USUARIO***********

//**************FEED****************

//*************************************************

/*int est_set_flotante(eMensajes* this, float flotante)
{
    int retorno =0;
    if(this!=NULL)
    {
        this->flotante=flotante;
        retorno =1;
    }
    return retorno;
}

float est_get_flotante(eMensajes* this)
{
    float flotante;
    if(this!=NULL)
    {
        flotante=this->flotante;
    }
    return flotante;
}*/
/*
int est_set_largo(eMensajes* this,long int largo)
{
    int retorno =0;
    if(this!=NULL)
    {
        this->largo=largo;
        retorno =1;
    }
    return retorno;
}

long int est_get_largo(eMensajes* this)
{
    long int largo;
    if(this!=NULL)
    {
        largo=this->largo;
    }
    return largo;
}*/

//FIN SETER AND GETER
//***************************************************************************
/*int Estr_borrar_elemento(ArrayList* this,ArrayList* that)
{
    int retorno=-1;
    int cod_record,indice;
    char resp;
    eEstructura* record;

    if(this !=NULL && that !=NULL)
    {
        retorno=0;
        cod_record=Valida_PedirEntero("Ingrese el Codigo del producto a dar de baja:\n");
        if(cod_record >0)
        {
            indice=prod_buscarId(this,cod_record);
            record=al_get(this,indice);
            if(record ==NULL)
            {
             indice=prod_buscarId(that,cod_record);
             record=al_get(that,indice);
             retorno=1;
            }
            if(record ==NULL)
            {
                printf("No se encontro el producto\n");
                vista_pausar();
            }
            else if(record !=NULL)
            {
            vista_Muestra1UnElemento(record);
            resp=Valida_confirmacion("Confirma dar de baja este producto?");
            if(resp=='N')
                {
                    printf("Operacion cancelada\n");
                }
                else if(resp=='S')
                {
                 //record=this->pop(this,this->indexOf(this, record));
                 if(retorno==1)
                 {
                  record = that->pop(that, record);
                  free(record);
                  that->sort(that,prod_comparaProducto,1);
                  data_actualizarArchivo(that,NOM_ARCH2);
                 }
                 else
                 {
                    record = this->pop(that, record);
                    free(record);
                    this->sort(this,prod_comparaProducto,1);
                    data_actualizarArchivo(this,NOM_ARCH);
                 }
                 retorno=1;
                }
            }//fin else prod !=NULL
         }//fin if(cod_prod)
    }//fin if(this)
    if(retorno==1)
    {
        printf("se dio de baja exitosamente:\n");
    }
    return retorno;
}
*/


//****************************************************
int est_compara_elementos_Estructura(void* pElementA,void* pElementB)
{
    int retorno=-1;
    eUsuario *tmp_1;
    eMensajes *tmp_2;
    tmp_1=(eUsuario* ) pElementA;
    tmp_2=(eMensajes * ) pElementB;

    if(tmp_1->id_usuario > tmp_2->id_usuario)
    {
        retorno=1;
    }
    else
    {
        if(tmp_1->id_usuario < tmp_2->id_usuario)
        {
            retorno=0;
        }
    }
    return retorno;
}
int est_ComparaElementos(void* eElemenA,void* eElemenB)
{//-2 ERROR  y espues el standaroutput de strcmp
    int retorno=-2;
    eMensajes *prd_1;
    eUsuario *prd_2;

    if(eElemenA!=NULL && eElemenB!=NULL)
    {
        prd_1=(eUsuario * ) eElemenA;
        prd_2=(eMensajes * ) eElemenB;
        if(prd_1->id_usuario == prd_2->id_usuario)
       // retorno=strcmp( prd_1->letra,prd_2->letra );
       retorno=0;
    }
    return retorno;
}
int est_EsVocal(char Letra)
{
    int retorno=-1;
    if(isalpha(Letra))
    {
        retorno=0;
        Letra=toupper( Letra );
        if(Letra=='A'||Letra=='E'||Letra=='I'||Letra=='O'||Letra=='U')
        {
            retorno=1;
        }
    }
    return retorno;
}
/*int est_ComparaLetraConLeter(char letra,void* eLetraB)
{
    int retorno=-1;
    void *prd_1;

    if(eLetraB!=NULL)
    {
        retorno=1;
        prd_1=(void * ) eLetraB;
        if(letra == prd_1->letra) //si el caracter es igual a un caracter del tipo estructura
        {
            retorno=0;
        }
    }
    return retorno;
}*/

/*int est_Existe_elementos(ArrayList* this ,char * cadLetras)
{//devuelve 1 si estan todas las letras.. 0 si no estan.

    int retorno=-1;
    int cont=0;
    ArrayList* ListAux;
    if(this!=NULL  && cadLetras!=NULL )
    {
        retorno=0;
        ListAux=al_clone(this);
        for(int i=0;i<strlen(cadLetras);i++) //recorro la cadena
        {
            for(int j=0;j<this->len(this);j++) //recorro el ArrayList
            {
                if( gestion_ComparaLetraConLeter(cadLetras[i],ListAux->get(ListAux,j) )== 0 ) //si existe
                {
                    cont++;
                    ListAux->pop(ListAux,j); //quito la letra
                    break;
                }
            }//fin for recorre ArrayList
        }//fin for recorre caracteres string
        if(strlen(cadLetras)==cont)
        {
            retorno=1;
        }
        return retorno;
    }
}
*/
