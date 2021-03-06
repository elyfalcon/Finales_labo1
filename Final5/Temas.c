#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "Usuarios.h"
#include "Temas.h"
#include "Vista.h"
#include "Gestion.h"
#include "Archivo.h"


eTemas* nuevo_tema(void)
{
    eTemas* returnAux;
    returnAux = (eTemas*)malloc(sizeof(eTemas));
    return returnAux;
}

eTemas* new_tema(int id,char nombre_tema[25],char artista[25])
{
    eTemas* retorno = NULL;
    eTemas* pRecord = malloc(sizeof(eTemas));
    if(pRecord != NULL)
    {
        tema_set_id(pRecord,id);
        tema_set_nombre(pRecord,nombre_tema);
        tema_set_artista(pRecord,artista);

        retorno = pRecord;
    }
    return retorno;
}
//**********************GETTERS Y SETTERS *********************

int tema_set_id(eTemas* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->id=num;
        retorno = 1;
    }
    return retorno;
}
int tema_get_id(eTemas* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->id;
    }
    return num;
}
char* tema_get_nombre(eTemas* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->nombre_tema;
    }
    return texto;
}
int tema_set_nombre(eTemas* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->nombre_tema,texto);
        retorno =1;
    }
    return retorno;
}
char* tema_get_artista(eTemas* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->artista;
    }
    return texto;
}
int tema_set_artista(eTemas* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->artista,texto);
        retorno =1;
    }
    return retorno;
}
//******************************************************
int tema_ComparaNombre(eTemas* eEmpleadoA,eTemas* eEmpleadoB)
{
    int retorno=0;
    if (strcmp(((eTemas*)eEmpleadoA)->nombre_tema,((eTemas*)eEmpleadoB)->nombre_tema)==1)
    {
      retorno=1;
    }
        if (strcmp(((eTemas*)eEmpleadoA)->nombre_tema,((eTemas*)eEmpleadoB)->nombre_tema)==-1)
    {
      retorno=-1;
    }
    return retorno;
}
