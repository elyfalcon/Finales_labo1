#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

typedef struct
{
    int id_mensaje;
    char mensaje[200];
    int popu;
    int id_usuario;
}eMensajes;

typedef struct
{
    int id_usuario;
    char nick[20];
    int popu_usuario;
}eUsuario;
#endif // ESTRUCTURA_H_INCLUDED


/** \brief crea un nuevo elemento
 *
 * \param
 * \param
 * \return
 *
 */
eMensajes* nuevo_record(void);

/** \brief Compara 2 elementos de una estructura
 *
 * \param  elemento del tipo de la estructura
 * \param  elementp del tipo de la estructura
 * \return 1 si el primer elemento es > que el 2do, 0 si el 1er elemento es < que el 2do, -1 si son iguales
 *
 */
int est_compara_elementos_Estructura(void* pElementA,void* pElementB);

/** \brief verifica si un caracter es vocal o consonante
 *
 * \param character
 * \return 1 si es vocal
 *
 */
int est_EsVocal(char Letra);


/** \brief compara un caracter dado contra otro del tipo estructura
 *
 * \param char para comparar
 * \param char de tipo estructura para evaluar
 * \return 0 si ok
 */
int est_ComparaLetraConLeter(char letra,void* eLetraB);


/** \brief recorre el ArrayList haciendo un burbujeo comparando un elemento con los siguientes, si existe lo quita, incrmenta el contador y sigue
 *  comparando
 * \param ArrayList
 * \param cadena de caracteres a verificar (caracter por caracter)
 * \return 1 si OK
 */
int est_Existe_elementos(ArrayList* this ,char * cadLetras);


/** \brief Busca el maximo o minimo en un ArrayList
 *
 * \param void* ArrayList
 * \param void* Funcion que compara
 * \param int 1 si busca maximo o 0 si es minimo
 * \return eEstructura* BuscaMaximo(ArrayList* this, int
 *
 */
eMensajes* BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor);









