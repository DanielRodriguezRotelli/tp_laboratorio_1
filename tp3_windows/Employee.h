#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

#define NAME_LEN 256

typedef struct
{
    int id;
    char nombre[NAME_LEN];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new(void); // devuelve un puntero a employee
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr); //devuelve un puntero a employee pero con sus datos cargados
void employee_delete(Employee* this);

int employee_findById(LinkedList* pList, int id);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_compareName(void* a, void* b);
int employee_compareId(void* a, void* b);

int employee_getNextId(char* path);

#endif // employee_H_INCLUDED
