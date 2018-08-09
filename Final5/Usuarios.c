#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "Usuarios.h"
#include "Vista.h"
#include "Gestion.h"
#include "Temas.h"

//****************CONSTRUCTORES*******************
eUsuarios* nuevo_record(void)
{
    eUsuarios* returnAux;
    returnAux = (eUsuarios*)malloc(sizeof(eUsuarios));
    return returnAux;
}
int id;
    char nombre[25];
    char sexo;
    char pais[20];
    char password[8];
    char ip[15];


eUsuarios* new_persona(int id,char nombre[25],char sexo,char pais[20],char pass[8],char ip[15])
{
    eUsuarios* retorno = NULL;
    eUsuarios* pRecord = malloc(sizeof(eUsuarios));
    if(pRecord != NULL)
    {
        usuario_set_id(pRecord,id);
        usuario_set_nombre(pRecord,nombre);
        usuario_set_sexo(pRecord,sexo);
        usuario_set_pais(pRecord,pais);
        usuario_set_pass(pRecord,pass);
        usuario_set_ip(pRecord,ip);
        retorno = pRecord;
    }
    return retorno;
}
//**********GETTERS Y SETTERS ********************
int usuario_set_id(eUsuarios* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->id=num;
        retorno = 1;
    }
    return retorno;
}
int usuario_get_id(eUsuarios* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->id;
    }
    return num;
}
char* usuario_get_nombre(eUsuarios* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->nombre;
    }
    return texto;
}
int usuario_set_nombre(eUsuarios* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->nombre,texto);
        retorno =1;
    }
    return retorno;
}
char* usuario_get_email(eUsuarios* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->email;
    }
    return texto;
}
int usuario_set_email(eUsuarios* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->email,texto);
        retorno =1;
    }
    return retorno;
}
char* usuario_get_pais(eUsuarios* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->pais;
    }
    return texto;
}
int usuario_set_pais(eUsuarios* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->pais,texto);
        retorno =1;
    }
    return retorno;
}
char* usuario_get_pass(eUsuarios* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->password;
    }
    return texto;
}
int usuario_set_pass(eUsuarios* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->password,texto);
        retorno =1;
    }
    return retorno;
}
char* usuario_get_ip(eUsuarios* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->ip;
    }
    return texto;
}
int usuario_set_ip(eUsuarios* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->ip,texto);
        retorno =1;
    }
    return retorno;
}
char* usuario_get_sexo(eUsuarios* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->sexo;
    }
    return texto;
}
int usuario_set_sexo(eUsuarios* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->sexo,texto);
        retorno =1;
    }
    return retorno;
}
/*int eLetra_setLetra(eLetra* this, char *dato)
{
    this->letra=dato[0];
    return 0;
}*/
//****************FUNCIONES DE LA ESTRUCTURA+++++++++++
/*
int usuaraio_compara_elementos(void* pElementA,void* pElementB)
{
    int retorno=-1;
    eUsuarios *tmp_1;
    eUsuarios *tmp_2;
    tmp_1=(eUsuarios* ) pElementA;
    tmp_2=(eUsuarios* ) pElementB;

   if(tmp_1->nombre > tmp_2->void)
    {
        retorno=1;
    }
    else
    {
        if(tmp_1->letra < tmp_2->letra)
        {
            retorno=0;
        }
    }
    return retorno;
}*/
int usuario_ComparaNombre(eUsuarios* eEmpleadoA,eUsuarios* eEmpleadoB)
{
    int retorno=0;
    if (strcmp(((eUsuarios*)eEmpleadoA)->nombre,((eUsuarios*)eEmpleadoB)->nombre)==1)
    {
      retorno=1;
    }
        if (strcmp(((eUsuarios*)eEmpleadoA)->nombre,((eUsuarios*)eEmpleadoB)->nombre)==-1)
    {
      retorno=-1;
    }
    return retorno;
}
