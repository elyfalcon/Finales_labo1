#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"


//********CONSTRUCTORES*********************
eEstru* nuevo_record(void)
{
    eEstru* returnAux;
    returnAux = (eEstru*)malloc(sizeof(eEstru));
    return returnAux;
}

//**********GETTERS PARA LETRAS*****************

/*char eLetra_getLetra(void * record)
{
    eLetra *tmp_1;
    tmp_1=(eLetra * ) record;

    return tmp_1->letra;
}*/
int est_compara_elementos_Estructura(void* pElementA,void* pElementB)
{
    int retorno=-1;
    void *tmp_1;
    void *tmp_2;
    tmp_1=(void* ) pElementA;
    tmp_2=(void * ) pElementB;

  /*  if(tmp_1-> > tmp_2->void)
    {
        retorno=1;
    }
    else
    {
        if(tmp_1->letra < tmp_2->letra)
        {
            retorno=0;
        }
    }
    return retorno;*/
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
int est_ComparaLetraConLeter(char letra,void* eLetraB)
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
}

int est_Existe_elementos(ArrayList* this ,char * cadLetras)
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
