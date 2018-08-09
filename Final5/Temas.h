#ifndef TEMAS_H_INCLUDED
#define TEMAS_H_INCLUDED


typedef struct
{
    int id;
    char nombre_tema [25];
    char artista[25];
}eTemas;



#endif // TEMAS_H_INCLUDED
int tema_ComparaNombre(eTemas* eEmpleadoA,eTemas* eEmpleadoB);
