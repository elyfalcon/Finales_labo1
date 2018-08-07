#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Letra.h"

eLetra* nueva_letra(void)
{
    eLetra* returnAux;
    returnAux = (eLetra*)malloc(sizeof(eLetra));
    return returnAux;
}
//+++++++++++++++++++++getters

char* letra_get_letra(eLetra* this)
{
    return this->letra;
}
char* letra_get_nombre(eLetra* this)
{
    return this->nombre;
}
int letra_get_vocal(eLetra* this)
{
    return this->vocal;
}
int letra_get_conson(eLetra* this)
{
    return this->consonante;
}

//  ------ SET -------
int eLetra_setLetra(eLetra* this, char *dato)
{
    this->letra=dato[0];
    return 0;
}

int eLetra_setNombre(eLetra* this, const char* dato)
{
    strcpy(this->nombre, dato);
    return 0;
}

int eLetra_setVocal(eLetra* this, int dato)
{
    this->vocal = dato;
    return 0;
}

int eLetra_setConsonante(eLetra* this, int dato)
{
    this->consonante = dato;
    return 0;
}

// --------- GETERS -------------------
char eLetra_getLetra(void * record)
{
    eLetra *tmp_1;
    tmp_1=(eLetra * ) record;

    return tmp_1->letra;
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
 int gestion_ComparaLetra(void* eLetraA,void* eLetraB)
{//-2 ERROR  y espues el standaroutput de strcmp
    int retorno=-2;
    eLetra *prd_1;
    eLetra *prd_2;

    if(eLetraA!=NULL && eLetraB!=NULL)
    {
        prd_1=(eLetra * ) eLetraA;
        prd_2=(eLetra * ) eLetraB;
        if(prd_1->letra == prd_2->letra)
       // retorno=strcmp( prd_1->letra,prd_2->letra );
       retorno=0;
    }
    return retorno;
}

int gestion_ComparaLetraConLeter(char letra,void* eLetraB)
{
    int retorno=-1;
    eLetra *prd_1;

    if(eLetraB!=NULL)
    {
        retorno=1;
        prd_1=(eLetra * ) eLetraB;
        if(letra == prd_1->letra)
        {
            retorno=0;
        }
    }
    return retorno;
}


int letra_recorrePalabra(char *texto)
{
    int retorno;


}
/*

//++++++++++++++++++++++++
int letra_set_vocal(eLetra* this, int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->vocal = dato;
    }
    return 0;
}
int letra_set_nombre(eLetra* this, char* dato)
{
    strcpy(this->nombre,dato);
    return 0;
}
int letra_set_letra(eLetra* this, char* dato)
{
    strcpy(this->letra,dato);
    return 0;
}
int letra_set_conso(eLetra* this, int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->consonante = dato;
    }
    return 0;
}
*/
