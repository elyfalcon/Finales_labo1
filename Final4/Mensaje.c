#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Estructura.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"
#include "fenv.h"
#include "Mensaje.h"
#include "Usuario.h"

//********CONSTRUCTORES*********************
eMensajes* nuevo_mensaje(void)
{
    eMensajes* returnAux;
    returnAux = (eMensajes*)malloc(sizeof(eMensajes));
    return returnAux;
}
//*********************SETTERS Y GETTERS******************

int mensaje_set_id(eMensajes* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->id_mensaje=num;
        retorno = 1;
    }
    return retorno;
}
int mensaje_get_id(eMensajes* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->id_mensaje;
    }
    return num;
}
char* mensaje_get_texto(eMensajes* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->mensaje;
    }
    return texto;
}
int mensaje_set_texto(eMensajes* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->mensaje,texto);
        retorno =1;
    }
    return retorno;
}
int mensaje_set_popu(eMensajes* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->popu=num;
        retorno = 1;
    }
    return retorno;
}
int mensaje_get_popu(eMensajes* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->popu;
    }
    return num;
}
int mensaje_set_idUsuario(eMensajes* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->id_usuario=num;
        retorno = 1;
    }
    return retorno;
}
int mensaje_get_idUsuario(eMensajes* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->id_usuario;
    }
    return num;
}
//***********************FIN GETTERES Y SETTERS****************

