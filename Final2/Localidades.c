#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"
#include "vista.h"
#include "Localidades.h"


eLocalidad* nueva(void)
{
    eLocalidad* returnAux;
    returnAux = (eLocalidad*)malloc(sizeof(eLocalidad));
    return returnAux;
}

eLocalidad* local_nuevaLocal(int id,char nombre[])
{
    eLocalidad* retorno = NULL;
    eLocalidad* pLocal = malloc(sizeof(eLocalidad));

    if(pLocal != NULL)
    {
  //      localidad_set_id(pLocal,id);
        localidad_set_localidad(pLocal,nombre);

        retorno = pLocal;
    }
    return retorno;
}

char* localidad_get_localidad(eLocalidad* this)
{
    char* localidad;
    if(this!=NULL)
    {
        strcpy(localidad,this->localidad);
    }
    return localidad;
}
int localidad_set_localidad(eLocalidad* this, char* localidad)
{
    int retorno =0;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno =1;
    }
    return retorno;
}


int localidad_set_id(eLocalidad* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->id=num;
        retorno = 1;
    }
    return retorno;
}
/*

int localidad_get_id(eLocalidad* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->id;
    }
    return num;
}
*/
/*char* localidad_get_producto(eLocalidad* this)
{
    char* producto = NULL;
    if(this!=NULL)
    {
        producto = this->producto;
    }
    return producto;
}

int localidad_set_producto(eLocalidad* this, char* producto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->producto,producto);
        retorno =1;
    }
    return retorno;
}
char* localidad_get_direccion(eLocalidad* this)
{
    char* direccion = NULL;
    if(this!=NULL)
    {
        direccion = this->direccion;
    }
    return direccion;
}

int localidad_set_direccion(eLocalidad* this, char* direccion)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->direccion,direccion);
        retorno =1;
    }
    return retorno;
}*/


/*char* localidad_get_recibe(eLocalidad* this)
{
    char* recibe = NULL;
    if(this!=NULL)
    {
        recibe = this->recibe;
    }
    return recibe;
}
int localidad_set_recibe(eLocalidad* this, char* recibe)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->recibe,recibe);
        retorno =1;
    }
    return retorno;
}*/


