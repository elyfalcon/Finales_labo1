#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Logs.h"
#include "Service.h"
#include "Tools.h"
#include "Vista.h"



//***********CONSTRUCTORES*******************
eLogEntry* nuevo_log(void)
{
    eLogEntry* returnAux;
    returnAux = (eLogEntry*)malloc(sizeof(eLogEntry));
    return returnAux;
}
//*********S*****************
eLogEntry* new_log(char date[11],char time[6],int serviceId,int gravedad,char msg[60])
{
    eLogEntry* retorno = NULL;
    eLogEntry* pRecord = malloc(sizeof(eLogEntry));
    if(pRecord != NULL)
    {

        log_set_date(pRecord,date);
        log_set_time(pRecord,time);
        log_set_IdService(pRecord,serviceId);
        log_set_gravedad(pRecord,gravedad);
        log_set_msg(pRecord,msg);
        retorno = pRecord;
    }
    return retorno;
}

//*********GETTERS Y SETTERS ****************************************

int log_set_IdService(eLogEntry* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->serviceId=num;
        retorno = 1;
    }
    return retorno;
}

int log_get_IdService(eLogEntry* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->serviceId;
    }
    return num;
}
char* log_get_date(eLogEntry* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->date;
    }
    return texto;
}

int log_set_date(eLogEntry* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->date,texto);
        retorno =1;
    }
    return retorno;
}
char* log_get_time(eLogEntry* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->time;
    }
    return texto;
}

int log_set_time(eLogEntry* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->time,texto);
        retorno =1;
    }
    return retorno;
}
int log_set_gravedad(eLogEntry* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->gravedad=num;
        retorno = 1;
    }
    return retorno;
}

int log_get_gravedad(eLogEntry* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->gravedad;
    }
    return num;
}
char* log_get_msg(eLogEntry* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->msg;
    }
    return texto;
}

int log_set_msg(eLogEntry* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->msg,texto);
        retorno =1;
    }
    return retorno;
}
//***********FIN SETTERS Y GETTERS********************
