#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ArrayList.h"
#include "Archivo.h"
#include "Estructura.h"
#include "Tools.h"
#include "Vista.h"

int gestion_Recorre_ArrayList(ArrayList *this,int (*pFunc)(void*))
{
    int retorno=-1;
    int i;
    if(this!=NULL )
    {
        retorno=-2;
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=0; i<this->len(this) ; i++)
            {
                retorno=pFunc(al_get(this,i)); //llamada a una funcion que se pasa por parametro
            }
        }//if(this->isEmpty(this)==0)
    }//if(this!=NULL && Titulo!=NULL)
    return retorno;
}


