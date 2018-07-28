#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED



void vista_ShowMenu(char *opcion);
void vista_ShowTitulo(char titulo[]);
int vista_Muestra1UnElemento(eProducto * emp);
void vista_MostrarElementos(ArrayList *this,char *Titulo,int desde, int hasta);
int vista_MuestraUnElementoLocalidad(eProducto * prod);





#endif // VISTA_H_INCLUDED
