#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INLCUDED

typedef struct
{
    int id;
    char nombre[25];
    char email[30];
    char sexo[8];
    char pais[15];
    char password[40];
    char ip[15];
}eUsuarios;



#endif // USUARIOS_H_INCLUDED
int usuario_ComparaNombre(eUsuarios* eEmpleadoA,eUsuarios
                          * eEmpleadoB);
