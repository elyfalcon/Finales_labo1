#ifndef LOCALIDADES_H_INCLUDED
#define LOCALIDADES_H_INCLUDED


typedef struct
{
    int id;
    char localidad[25];
    char direccion[25];
    char producto[25];//nombre del producto
    char recibe[15];
}eLocalidad;


eLocalidad* nueva(void);


#endif // LOCALIDADES_H_INCLUDED
