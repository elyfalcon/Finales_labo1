#ifndef LOGS_H_INCLUDED
#define LOGS_H_INCLUDED


typedef struct
{
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[60];
}eLogEntry;

#endif // LOGS_H_INCLUDED
int comparaLog(void* eEmpleadoA,void* eEmpleadoB);
int comparaLog_conValor(void* eEmpleadoA,int num);
