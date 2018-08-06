#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Vista.h"
#include "Tools.h"
#include "Errores.h"

//*************CONSTRUCTORES***********************
eErrores* nuevo_error(void)
{
    eErrores* returnAux;
    returnAux = (eErrores*)malloc(sizeof(eErrores));
    return returnAux;
}


eErrores* new_error(char date[11],char time[6],char name[33],char msg[60],int gravedad,char email[65])
{
    eErrores* retorno = NULL;
    eErrores* pRecord = malloc(sizeof(eErrores));
    if(pRecord != NULL)
    {
        error_set_date(pRecord,date);
        error_set_time(pRecord,time);
        error_set_name(pRecord,name);
        error_set_msg(pRecord,msg);
        error_set_gravedad(pRecord,gravedad);
        error_set_email(pRecord,email);
        retorno = pRecord;
    }
    return retorno;
}
//**********GERRETS Y SETTERS***********************
int error_set_gravedad(eErrores* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->gravedad=num;
        retorno = 1;
    }
    return retorno;
}
int error_get_gravedad(eErrores* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->gravedad;
    }
    return num;
}
char* error_get_date(eErrores* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->date;
    }
    return texto;
}

int error_set_date(eErrores* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->date,texto);
        retorno =1;
    }
    return retorno;
}
char* error_get_time(eErrores* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->time;
    }
    return texto;
}

int error_set_time(eErrores* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->time,texto);
        retorno =1;
    }
    return retorno;
}
int error_set_name(eErrores* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->name,texto);
        retorno =1;
    }
    return retorno;
}
char* error_get_name(eErrores* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->name;
    }
    return texto;
}
char* error_get_msg(eErrores* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->msg;
    }
    return texto;
}

int error_set_msg(eErrores* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->msg,texto);
        retorno =1;
    }
    return retorno;
}
int error_set_email(eErrores* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->email,texto);
        retorno =1;
    }
    return retorno;
}
char* error_get_email(eErrores* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->email;
    }
    return texto;
}
