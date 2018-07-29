#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED


typedef struct
{
    int id;
    char nombre[20];
    char direccion[25];
    char localidad[25];
    char recibe[15];

}eProducto;

int prod_ComparaLocalidad(void* eEmpleadoA,void* eEmpleadoB);
int prod_ComparaLocalidad2(void* eProductoA,void* eProductoB);
int prod_compareconLocalidad(void*pLocalidad, char* local);



#endif // PRODUCTO_H_INCLUDED
