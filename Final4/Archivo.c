#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Estructura.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"
#include "fenv.h"
#include "Mensaje.h"
#include "Usuario.h"

#define MASCARA_ARCHIVO "%[^,],%[^,],%[^,],%[^\n]\n" //defino aca la mascara para el parser de mensajes
#define MASCARA_ARCHIVO2 "%[^,],%[^,],%[^\n]\n" //defino la mascara para los usuarios
#define MASCARA_ARCHIVO_FEED "%d,%s,%d,%d,%s,%d\n"
#define TIENE_ENCABEZADO 1

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
            if(pFunc(pArchivo,this)==0)
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
    eMensajes* record;
//    int cantidadDatosLeidos;
    char cabecera[50];
    char id[50];
    char mensaje[1600];
    char popu[50];
    char idusu[50];
    char menaje_limite[200];

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
            record = nuevo_mensaje();
            if(record != NULL)
            {
                fscanf(pFile,MASCARA_ARCHIVO,id,idusu,popu,mensaje);
               // fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,idusu,popu,mensaje);
                    mensaje_set_id(record,atoi(id));
                    mensaje_set_idUsuario(record,atoi(idusu));
                    mensaje_set_popu(record,atoi(popu));
                    strncpy(menaje_limite,mensaje,200);// corto la longitud del mensaje
                    mensaje_set_texto(record,menaje_limite);

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


int parserEstructuraUsuario(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
    int guardoDato;
    void* record;
//    int cantidadDatosLeidos;
    char cabecera[50];
    char id[50];
    char nik[25];
    char popu[50];
   // char idusu[50];
    //char menaje_limite[200];

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
            record = nuevo_usuario();
            if(record != NULL)
            {
                fscanf(pFile,MASCARA_ARCHIVO2,id,nik,popu);
                    usuario_set_id(record,atoi(id));
                    usuario_set_nick(record,nik);
                    usuario_set_popu(record,atoi(popu));

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
                     fprintf(f,"ID_MENSAJE,MENSAJE,POPULARIDAD_MENSAJE,ID_USUARI,NICK,POPULARIDAD_USUARIO \n");
                    for (i=0; i<tamanio; i++)
                    {
                    record = (void*)al_get(this, i);
                    fprintf(f,MASCARA_ARCHIVO_FEED,feed_get_idmens(record),feed_get_texto(record),feed_get_popuMens(record),feed_get_idUsu(record),feed_get_nick(record),feed_get_popu_Usu(record));
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
//********************************************************
/*int Estr_borrar_elemento(ArrayList* this,ArrayList* that)
{
    int retorno=-1;
    int element,indice;
    char resp;
    void* record;

    if(this !=NULL && that !=NULL)
    {
        retorno=0;
        element=Valida_PedirEntero("Ingrese el Codigo del producto a dar de baja:\n");
        if(element >0)
        {
            indice=prod_buscarId(this,element);
            record=al_get(this,indice);
            if(record ==NULL)
            {
             indice=prod_buscarId(that,element);
             record=al_get(that,indice);
             retorno=1;
            }
            if(record ==NULL)
            {
                printf("No se encontro el producto\n");
                vista_pausar();
            }
            else if(record !=NULL)
            {
            vista_Muestra1UnElemento(record);
            resp=Valida_confirmacion("Confirma dar de baja este producto?");
            if(resp=='N')
                {
                    printf("Operacion cancelada\n");
                }
                else if(resp=='S')
                {
                 //prod=this->pop(this,this->indexOf(this, prod));
                 if(retorno==1)
                 {
                  record = that->pop(that, record);
                  free(record);
                  that->sort(that,prod_comparaProducto,1);
                  data_actualizarArchivo(that,NOM_ARCH2);
                 }
                 else
                 {
                    record = this->pop(that, record);
                    free(record);
                    this->sort(this,prod_comparaProducto,1);
                    data_actualizarArchivo(this,NOM_ARCH);
                 }
                 retorno=1;
                }
            }//fin else record !=NULL
         }//fin if(element)
    }//fin if(this)
    if(retorno==1)
    {
        printf("se dio de baja exitosamente:\n");
    }
    return retorno;
}
*/
