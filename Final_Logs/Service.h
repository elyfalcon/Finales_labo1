#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED


typedef struct
{
    int id;
    char name[33];
    char email[65];
}eService;

#endif // SERVICE_H_INCLUDED

eService* BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor);
int comparaServicio(void* eEmpleadoA,void* eEmpleadoB);
