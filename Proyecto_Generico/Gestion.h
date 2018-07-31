#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED




#endif // GESTION_H_INCLUDED

/** \brief Recorre todo el ArrayList e invoca una funcion para realizar alguna operacion
 *
 * \param ArrayList
 * \param funcion
 * \return la evaluacion de la funcion invocada
 */

int gestion_Recorre_ArrayList(ArrayList *this,int (*pFunc)(void*));
