#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ArrayList.h"
#include "Estructura.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"


#define MASCARA_ARCHIVO "%[^,],%[^,],%[^,],%[^\n]\n" //defino aca la mascara para el parser
#define TIENE_ENCABEZADO 1

int cargarDesdeArchivo(ArrayList *this,const char* nombre)
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
            if(parserEstructura(pArchivo,this)==0)
            {
                flag= 1;
                fclose(pArchivo);
            }
        }
    }
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
    int guardoDato;
    void* record;
//    int cantidadDatosLeidos;
    char cabecera[50];
    char letra[5];
    char nom[21];
    char vocal[5];
    char conso[5];

    if(pFile != NULL && this!=NULL)
    {
        retorno = -2;
        if(TIENE_ENCABEZADO == 1)
        {
            fgets(cabecera, 80, pFile);//descarto la lectura del encabezado
        }
        while(!feof(pFile))
        {
            retorno = 0;
            record = nuevo_record();
            if(record != NULL)
            {
                fscanf(pFile,MASCARA_ARCHIVO,letra,nom,vocal,conso);
             //   fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",letra,nom,vocal,conso);
                    eLetra_setLetra(record,letra);
                    eLetra_setNombre(record,nom);
                    eLetra_setVocal(record,atoi(vocal));
                    eLetra_setConsonante(record,atoi(conso));
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
int GuardarArchivoT(ArrayList* this, const char* nombre)
{
        int retorno=-1;
        int i;
        int tamanio=0;
        if(this!=NULL)
        {
            void* record;
            FILE *f;
            f=fopen(nombre, "w");
            if(f==NULL)
            {
                retorno=0;
            }
            else
            {
                if(record !=NULL)
                {
                    tamanio=al_len(this);
                    for (i=0; i<tamanio; i++)
                    {
                    record = (void*)al_get(this, i);
                    fprintf(f,MASCARA_ARCHIVO,eLetra_getLetra(record),letra_get_nombre(record),letra_get_vocal(record),letra_get_conson(record));
                    retorno=1;
                    }//fin for
                    }//fin if(aux!=NULL)
                fclose(f);
            }//fin else
        }// fin if(!=null)
        if(retorno==1)
        {
            printf("Se creo el archivo %s correctamente\n",nombre);
            system("pause");
        }
        else
        {
            printf("No se pudo crear el archivo %s\n",nombre);
            system("pause");
        }
        return retorno;
}
//FALTA CARGAR Y GUARDAR ARCHIVO BINARIO
