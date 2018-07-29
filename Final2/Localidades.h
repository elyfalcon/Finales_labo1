#ifndef LOCALIDADES_H_INCLUDED
#define LOCALIDADES_H_INCLUDED


typedef struct
{
    int id;
    char localidad[25];

}eLocalidad;


eLocalidad* nueva(void);


#endif // LOCALIDADES_H_INCLUDED
