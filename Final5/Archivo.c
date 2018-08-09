#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Usuarios.h"
#include "Temas.h"
#define TIENE_ENCABEZADO 1
#define MASCARA_USUAIRO "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
#define MASCARA_TEMAS "%[^,],%[^,],%[^\n]\n"


int cargarDesdeArchivo(ArrayList *this,const char* nombre,int (*pFunc)(void*,void*))
{
	int flag = 0;
	FILE *pArchivo;

    if(this !=NULL && nombre !=NULL)
    {
        pArchivo=fopen(nombre,"r");
        if(pArchivo != NULL)
        {
            flag=0;
		//pArchivo= fopen("nombre", "wb");
        //    if(parserEstructura(pArchivo,this)==0)
        if(pFunc(pArchivo,this)==0)
            {
                flag= 1;
                fclose(pArchivo);
            }
        }//fin if(pArchivo != NULL)
    }// fin if(this !=NULL && nombre !=NULL)
        if(flag ==1)
        {
	    printf("Carga Correcta:\n");
    system("pause");
        }
        else
        {
            printf("No se pudo cargar\n");
            system("pause");
        }
	return flag;

}

int parserEstructura(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
//    int cantidadDatosLeidos;
    char cabecera[50];
    int guardoDato;
    eUsuarios* record;
    char variable1[5];
    char variable2[25];
    char variable3[25];
    char variable4[25];
    char variable5 [30];
    char variable6[45];
    char variable7[25];


    if(pFile != NULL && this!=NULL)
    {
        retorno = -2;
        if(TIENE_ENCABEZADO == 1)
        {
            //descarto la lectura del encabezado
            fgets(cabecera, 80, pFile);
        }

        while(!feof(pFile))
        {
            retorno = 0;
            record = nuevo_record();
            if(record != NULL)
            {

                fscanf(pFile,MASCARA_USUAIRO,variable1,variable2,variable3,variable4,variable5,variable6,variable7);
                    usuario_set_id(record,atoi(variable1));
                    usuario_set_nombre(record,variable2);
                    usuario_set_email(record,variable3);
                    usuario_set_sexo(record,variable4);
                    usuario_set_pais(record,variable5);
                    usuario_set_pass(record,variable6);
                    usuario_set_ip(record,variable7);

                al_add(this, record);
                cantidadFilasLeidas++;
            }
            else if(record==NULL)//Sin memoria
            {
                printf("No hay memoria suficiente:\n");
                system("pause");
                break;
            }
        }
    }
    return retorno;
}
int parserEstructuraTema(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
//    int cantidadDatosLeidos;
    char cabecera[50];
    int guardoDato;
    eUsuarios* record;
    char variable1[5];
    char variable2[25];
    char variable3[25];
    char variable4[25];
    char variable5 [30];
    char variable6[45];
    char variable7[25];


    if(pFile != NULL && this!=NULL)
    {
        retorno = -2;
        if(TIENE_ENCABEZADO == 1)
        {
            //descarto la lectura del encabezado
            fgets(cabecera, 80, pFile);
        }

        while(!feof(pFile))
        {
            retorno = 0;
            record = nuevo_record();
            if(record != NULL)
            {
                fscanf(pFile,MASCARA_TEMAS,variable1,variable2,variable3);
                    tema_set_id(record,atoi(variable1));
                    tema_set_nombre(record,variable2);
                    tema_set_artista(record,variable3);

                al_add(this, record);
                cantidadFilasLeidas++;
            }
            else if(record==NULL)//Sin memoria
            {
                printf("No hay memoria suficiente:\n");
                system("pause");
                break;
            }
        }
    }
    return retorno;
}
