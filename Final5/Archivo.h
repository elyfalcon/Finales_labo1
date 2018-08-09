#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "Archivo.h"
#include "ArrayList.h"

int cargarDesdeArchivo(ArrayList* this,const char* nombre,int (*pFunc)(void*,void*));
int parserEstructura(FILE* pFile, ArrayList* this);
int parserEstructuraTema(FILE* pFile, ArrayList* this);


#endif // ARCHIVO_H_INCLUDED




