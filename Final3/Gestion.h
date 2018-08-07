#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED

ArrayList* Lista_Localidad(ArrayList* this);

ArrayList* al_eliminaDuplicados(ArrayList* this, int (*pFunc)(void* ,void*));
ArrayList* Gestion_Localidades(ArrayList* this);

#endif // GESTION_H_INCLUDED
int completa_VocalConsonante(eLetra * record);
