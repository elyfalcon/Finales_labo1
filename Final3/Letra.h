#ifndef LETRA_H_INCLUDED
#define LETRA_H_INCLUDED


typedef struct
{
    char letra;
    char nombre[21];
    int vocal;
    int consonante;
}eLetra;

int est_EsVocal(char Letra);

#endif // LETRA_H_INCLUDED
