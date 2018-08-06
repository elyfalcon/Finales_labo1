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


eUsuario* nuevo_usuario(void)
{
    eUsuario* returnAux;
    returnAux = (eUsuario*)malloc(sizeof(eUsuario));
    return returnAux;
}
//**********************************************
int usuario_set_id(eUsuario* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->id_usuario=num;
        retorno = 1;
    }
    return retorno;
}

int usuario_get_id(eUsuario* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->id_usuario;
    }
    return num;
}
int usuario_set_popu(eUsuario* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->popu_usuario=num;
        retorno = 1;
    }
    return retorno;
}
int usuario_get_popu(eUsuario* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->popu_usuario;
    }
    return num;
}
char* usuario_get_nick(eUsuario* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->nick;
    }
    return texto;
}
int usuario_set_nick(eUsuario* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->nick,texto);
        retorno =1;
    }
    return retorno;
}
//********************************************************
