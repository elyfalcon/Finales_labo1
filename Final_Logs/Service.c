#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Archivo.h"
#include "Logs.h"
#include "Service.h"
#include "Tools.h"
#include "Vista.h"



//*******CONSTRUCTORES *************
eService* nuevo_servicio(void)
{
    eService* returnAux;
    returnAux = (eService*)malloc(sizeof(eService));
    return returnAux;
}
//*********S*****************
eService* new_servicio(int id,char name[33],char email[65])
{
    eService* retorno = NULL;
    eService* pRecord = malloc(sizeof(eService));
    if(pRecord != NULL)
    {
        serv_set_Id(pRecord,id);
        serv_set_name(pRecord,name);
        serv_set_email(pRecord,email);
        retorno = pRecord;
    }
    return retorno;
}
//*****************SETTERS Y GETTERS*******************

int serv_set_Id(eService* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->id=num;
        retorno = 1;
    }
    return retorno;
}

int serv_get_Id(eService* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->id;
    }
    return num;
}
int serv_set_name(eService* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->name,texto);
        retorno =1;
    }
    return retorno;
}
char* serv_get_name(eService* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->name;
    }
    return texto;
}
int serv_set_email(eService* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->email,texto);
        retorno =1;
    }
    return retorno;
}
char* serv_get_email(eService* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->email;
    }
    return texto;
}
//**************************UNCIONES*************
eService* BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor)
{
   int returnAux = -1;
    ArrayList* aux;
    int i=0;
    eService *record;

    if(this!= NULL && pFunc!=NULL && (valor==0 || valor==1))//si es 1 busca maximo
    {
        if(aux!=NULL)
        {
            aux=(al_get(this,i));
            for(i=1;i < al_len(this)-1;i++)
            {
                if(valor==1)
                {
                    if(pFunc(aux,al_get(this,i))==1)
                    {
                       record=aux;
                       returnAux=0;
                    }//fin if(pfunc)
                    else
                    {
                        aux=al_get(this,i);
                        record=aux;
                    }
                    }//fin if(valor)
                if(valor==0)
                {
                    if(pFunc(aux,al_get(this,i))==-1)
                    {
                        record=aux;
                      //  aux=al_get(this,i);
                    }
                else
                {
                 aux=al_get(this,i);
                 record=aux;
                }
                returnAux=0;
                }//fin if
            }//fin 1er for
          //  } //fin 2do for
        }//fin 1er for
    }
    return record;
}
int comparaServicio(void* eEmpleadoA,void* eEmpleadoB)
{
 //   eEmpleado *eEmpleadoA;
 //   eEmpleado *eEmpleadoB;
    if(((eLogEntry*)eEmpleadoA)->serviceId > ((eLogEntry*)eEmpleadoB)->serviceId)
    {
        return 1;
    }
    if(((eLogEntry*)eEmpleadoA)->serviceId < ((eLogEntry*)eEmpleadoB)->serviceId)
    {
        return -1;
    }
    return 0;


}
