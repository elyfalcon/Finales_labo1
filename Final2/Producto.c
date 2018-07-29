#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Producto.h"
#include "Localidades.h"


eProducto* nuevo(void)
{
    eProducto* returnAux;
    returnAux = (eProducto*)malloc(sizeof(eProducto));
    return returnAux;
}

//*************Defino los setters y getters

int prod_get_id(eProducto* this)
{
    return this->id;
}
char* prod_get_nombre(eProducto* this)
{
    return this->nombre;
}
char* prod_get_dire(eProducto* this)
{
    char* direccion = NULL;
    if(this!=NULL)
    {
        direccion = this->direccion;
    }
    return direccion;
}


/*char* get_dire(eProducto* this)
{
    return this->direccion;
}*/
char* prod_get_localidad(eProducto* this)
{
    return this->localidad;
}
char* get_recibe(eProducto* this)
{
    return this->recibe;
}

int prod_set_Id(eProducto* this, int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->id = dato;
    }
    return 0;
}
int prod_set_nombre(eProducto* this, char* dato)
{
    strcpy(this->nombre,dato);
    return 0;
}
int prod_set_direccion(eProducto* this, char* dato)
{
    strcpy(this->direccion,dato);
    return 0;
}
int prod_set_localidad(eProducto* this, char* dato)
{
    strcpy(this->localidad,dato);
    return 0;
}
int prod_set_recibe(eProducto* this, char* dato)
{
    strcpy(this->recibe,dato);
    return 0;
}

int charToint(char* charInt)
{
    int nro;
    nro = atoi(charInt);
    return nro;
}

//*******************************************
int prod_ComparaLocalidad(void* eProductoA,void* eProductoB)
{
    int retorno=0;
    eProducto *prd_1;
    eProducto *prd_2;

    prd_1=(eProducto * ) eProductoA;
    prd_2=(eProducto * ) eProductoB;

    if (strcmp(((eProducto*)prd_1)->localidad,((eProducto*)prd_2)->localidad)==1)
    {
      retorno=1;
    }
     else if (strcmp(((eProducto*)prd_1)->localidad,((eProducto*)prd_2)->localidad)==-1)
    {
      retorno=-1;
    }
  /*  else
    {
        retorno=0;
    }*/
    return retorno;
}

