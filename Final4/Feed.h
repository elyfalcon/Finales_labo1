#ifndef FEED_H_INCLUDED
#define FEED_H_INCLUDED


typedef struct
{
    int id_mensaje;
    char mensaje[200];
    int popu;
    int id_usuario;
    char nick[20];
    int popu_feed;
}eFeed;
#endif // FEED_H_INCLUDED
