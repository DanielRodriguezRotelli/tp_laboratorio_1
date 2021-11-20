/*
 * ArrayEmployees.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Aye
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define APELLIDO_LEN  51
#define NOMBE_LEN  51

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty; // 0:ocupado    1:vacio/libre
}Employee;


/**
 * \brief Coloca todas las banderas en LIBRE, para poder ingresar datos.
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \return Devuelve por retorno 1 si las banderas quedaron en LIBRE, 0 si no se pudieron incializar las banderas.
 */
int initEmployees(Employee* list, int len);


/**
 * \brief Muestra el menu principal del programa.
 * \return Devuelve por referencia el valor de la opcion deseada.
 */
void menuPrincipal(int* opcionDeMenu);


/**
 * \brief Pide al ususario los datos del empleado para dar el alta.
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \param idAux coorespondiente al pasaje por parametro del valor de la variable.
 * \param nameAux[] coorespondiente al pasaje por parametro de la cadena de string.
 * \param lastNameAux[] coorespondiente al pasaje por parametro de la cadena de string.
 * \param salaryAux coorespondiente al pasaje por parametro del valor de la variable.
 * \param sectorAux coorespondiente al pasaje por parametro del valor de la variable.
 * \return Devuelve por retorno 0 si pedir los datos, -1 si no se pudo.
 */
int pedirDatosEmpleado(Employee* list, int len, int* idAux, char nameAux[], char lastNameAux[], float* salaryAux, int* sectorAux);


/**
 * \brief Ingresa al array los valores de los parametros.
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \param id coorespondiente al pasaje por parametro del valor de la variable id.
 * \param name coorespondiente al pasaje por parametro de la cadena de string nombre.
 * \param lastNameAux coorespondiente al pasaje por parametro de la cadena de stringlasName.
 * \param salary coorespondiente al pasaje por parametro del valor de la variable salary.
 * \param sector coorespondiente al pasaje por parametro del valor de la variable sector.
 * \return Devuelve por retorno 0 si los valores se cargaron, -1 si no se pudieron pudieron cargarse.
 */
int addEmployees(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);


/**
 * \brief Crea el Id nuevo.
 * \param Dentro usa otra funcion static.
 * \return Devuelve por puntero el Id creado
 */
void crearIdNuevo(int* idCreado);


/**
 * \brief Busca el id de un empleado.
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \param id coorespondiente al pasaje por parametro del valor de la variable que desea buscar. En este caso el Id.
 * \return Devuelve por retorno 0 si encontro el Id, -1 si no lo encontro.
 */
int findEmployeeById(Employee* list, int len, int id);


/**
 * \brief Modifica el array ubicado en la posicion del Id buscado.
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \param posicionId coorespondiente al pasaje por parametro del valor de la variable coorespondiente a la posicion de Id buscado.
 * \param la funcion solo modifica el nombre, apellido, salario, y sector, No puede modificar el ID.
 * \return Devuelve por retorno 0 si pudo hacer modificaciones, -1 si no se pudo..
 */
int modificarArray(Employee* list, int len, int posicionId);


/**
 * \brief Hace una baja logica del array correspondiente al Id
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \param id coorespondiente al pasaje por parametro del valor de la variable id
 * \param La funcion recibe un id y luego cambia la bandera de si esta lleno a vacio, de esta manera sobreescribir los datos.
 * \return Devuelve por retorno 0 si pudo dar de baja, -1 si no se pudo.
 */
int removeEmployee(Employee* list, int len, int id);


/**
 * \brief Busca una posicion libre en el array.
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param pPosicionLibre correspondiente a la posicion libre que encuentra.
 * \param la funcion busca en el array una posicion con bandera libre.
 * \return Devuelve por retorno 0 si encuentra banderas LIBRE, -1 si no encuentra banderas Libre.
 */
int buscarPosicionLibre(Employee* list, int len, int* pPosicionLibre);


/**
 * \brief Busca una posicion ocupada en el array.
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param pPoscionOcupada correspondiente a la posicion ocupada que encuentra.
 * \param la funcion busca en el array una posicion con bandera ocupada.
 * \return Devuelve por retorno 0 si encuentra banderas ocupadas, -1 si no se pudo encontrar banderas ocupadas.
 */
int buscarPosicionOcupado(Employee* list, int len, int* pPosicionOcupado);


/**
 * \brief Imprime solo un array de empleados
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param La funcion solo imprime una posicion es que tiene banderas ocupada.
 */
void printEmp(Employee* list);


/**
 * \brief Recorre todo el array e imvoca a la funcion que imprime
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \return Devuelve por retorno 0 si pudo recorrer e invocar a la funcion de imprimir, -1 si no pudo.
 */
int printEmployees(Employee* list, int len);


/**
 * \brief Muestra el menu de la opcion Informes
 * \param opcionesdeMenuInforme corresponde a la opcion elegida en el menu
 * \return Devuelve por puntero el valor de la opcion elegida.
 */
void menuInforme(int* opcionDeMenuInforme);



/**
 * \brief Ordena el array
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \param order correspondiente al valor pasado por parametro de la opcion elegida en listar el array
 * \param la funcion ordena el array de forma creciente o decreciente segun lo que el usuario desee.
 * \return Devuelve por retorno 0 si pudo ordenar, -1 si no pudo.
 */
int sortEmployees(Employee* list, int len, int order);


/**
 * \brief Suma todos los salarios del array
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \param La funcion recorre el array y va acumulando todos los salarios encontrados
 * \return Devuelve por retorno el valor de la suma.
 */
float SumaSalarios(Employee* list, int len);


/**
 * \brief Cuenta la cantidad de salarios.
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \param La funcion recorre el array y va contando todos los salarios encontrados
 * \return Devuelve por retorno la cantidad de salarios encontrados.
 */
int contarCantidadSalarios(Employee* list, int len);


/**
 * \brief Realiza el promedio de los salarios
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \return Devuelve por retorno el promedio de todos los salarios encontrados
 */
float promedioSalario(float sumaSalarios, int cantSalarios);


/**
 * \brief Busca los salarios superiores al promedio de salarios
 * \param Employee* list correspondiente a al puntero del array de la Estructura Employee.
 * \param len correspondiente al tamaño del array.
 * \param promedio correspondiente al pasaje por parametro del valor de la variable promedio
 * \param La funcion recorre el array, busca y cuenta los salario superiores al promedio
 * \return Devuelve por retorno la cantidad de salarios superiores al promedio encontrados.
 */
int buscarSalarioMayorAlPromedio(Employee* list, int len, float promedio);



void altaForzada(Employee* list,int idEmpleado,char* nombre, char* apellido,  float salario, int sector, int indice);



#endif /* ARRAYEMPLOYEES_H_ */
