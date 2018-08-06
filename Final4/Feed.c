#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Estructura.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"
#include "Feed.h"


eFeed* nuevo_feed(void)
{
    eFeed* returnAux;
    returnAux = (eFeed*)malloc(sizeof(eFeed));
    return returnAux;
}

eFeed* feed_new(int id_mensaje, char mensaje[200],int popu,int id_usuario,char nick[20], int pop_usuario)
{
    eFeed* retorno = NULL;
    eFeed* pRecord = malloc(sizeof(eFeed));
    if(pRecord != NULL)
    {
        feed_set_idmens(pRecord, id_mensaje);
        feed_set_texto(pRecord, mensaje);
        feed_set_popuMens(pRecord, popu);
        feed_set_idUsu(pRecord, id_usuario);
        feed_set_nick(pRecord, nick);
        feed_set_popu_Usu(pRecord, pop_usuario);
        retorno = pRecord;
    }
    return retorno;
}
//****************FIN CONSTRUCTORES***************************

//***************GETTERS Y SETTERS****************************
int feed_set_idmens(eFeed* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->id_mensaje=num;
        retorno = 1;
    }
    return retorno;
}
int feed_get_idmens(eFeed* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->id_mensaje;
    }
    return num;
}
int feed_set_idUsu(eFeed* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->id_usuario=num;
        retorno = 1;
    }
    return retorno;
}
int feed_get_idUsu(eFeed* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->id_usuario;
    }
    return num;
}
char* feed_get_texto(eFeed* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
       texto = this->mensaje;
    }
    return texto;
}
int feed_set_texto(eFeed* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->mensaje,texto);
        retorno =1;
    }
    return retorno;
}
char* feed_get_nick(eFeed* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        return this->nick;
    }
    return texto;
}
int feed_set_nick(eFeed* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->nick,texto);
        retorno =1;
    }
    return retorno;
}
int feed_set_popuMens(eFeed* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->popu=num;
        retorno = 1;
    }
    return retorno;
}
int feed_get_popuMens(eFeed* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->popu;
    }
    return num;
}
int feed_set_popu_Usu(eFeed* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->popu_feed=num;
        retorno = 1;
    }
    return retorno;
}
int feed_get_popu_Usu(eFeed* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->popu_feed;
    }
    return num;
}
//********************************************************
