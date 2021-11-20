#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn_biblioteca.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
#define TRUE 0
#define FALSE 1


int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    int loadTextData;
    int loadBinaryData;
    int saveTextData=FALSE;
    int saveBinaryData=FALSE;
    int optionExit;


    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	controller_menu(&option);
        switch(option)
        {
            case 1:
			if(controller_loadFromText("data.csv",listaEmpleados)==TRUE)
			{
				loadTextData=TRUE;
			}
			else
			{
				printf("\nError. No se puede cargar lista de archivo.");
			}
			break;

            case 2:
			if(controller_loadFromBinary("dataBin.csv",listaEmpleados)==TRUE)
			{
				loadBinaryData=TRUE;
			}
			else
			{
				printf("\nError. No existe archivo binario. Tiene que guardar archivo en ese formato para poder cargarlo.");
			}
			break;

            case 3:
            if(loadTextData == TRUE || loadBinaryData == TRUE)
            {
            	if(controller_addEmployee(listaEmpleados)!=TRUE)
				{
					printf("\nError. No se pueden ingresar datos.");
				}
            }
            else
            {
            	printf("\nNo puede ingresar datos si no ha cargado los datos del archivo.");
            }


           	break;

            case 4:
            if(loadTextData == TRUE || loadBinaryData == TRUE)
            {
            	if(controller_editEmployee(listaEmpleados)!=TRUE)
				{
					printf("\nError. No se pueden realizar modificaciones.");
				}
            }
            else
			{
				printf("\nNo puede editar datos si no ha cargado los datos del archivo.");
			}

           	break;

            case 5:
            if(loadTextData == TRUE || loadBinaryData == TRUE)
            {
            	if(controller_removeEmployee(listaEmpleados)!=TRUE)
				{
					printf("\nError. No se puede eliminar empleados.");
				}
            }
            else
			{
				printf("\nNo puede eliminar datos si no ha cargado los datos del archivo.");
			}

           	break;

            case 6:
            if(loadTextData == TRUE || loadBinaryData == TRUE)
            {
            	if(controller_ListEmployee(listaEmpleados)!=TRUE)
				{
					printf("\nError. No se puede imprimir lista.");
				}
            }
            else
			{
				printf("\nNo puede impimir datos si no ha cargado los datos del archivo.");
			}

           	break;

            case 7:
            if(loadTextData == TRUE || loadBinaryData == TRUE)
            {
            	if(controller_sortEmployee(listaEmpleados)!=TRUE)
				{
					printf("\nError. No se puede ordenar la lista.");
				}
            }
            else
			{
				printf("\nNo puede ordenar datos si no ha cargado los datos del archivo.");
			}


            break;

            case 8:
            if(loadTextData == TRUE || loadBinaryData == TRUE)
            {
            	if(controller_saveAsText("data.csv",listaEmpleados)==TRUE)
				{
					saveTextData=TRUE;
				}
            	else
            	{
            		printf("\nError. No se pudo guardar en archivo.");
            	}
            }
            else
			{
				printf("\nNo puede guardar datos si no ha cargado los datos del archivo.");
			}

			break;

            case 9:
            if(loadTextData == TRUE || loadBinaryData == TRUE)
            {
            	if(controller_saveAsBinary("dataBin.csv",listaEmpleados)==TRUE)
				{
					saveBinaryData=TRUE;
				}
            	else
            	{
            		printf("\nError. No se pudo guardar en archivo.");
            	}
            }
            else
			{
				printf("\nNo puede guardar datos si no ha cargado los datos del archivo.");
			}
			break;

            case 10:
            if(loadTextData == TRUE || loadBinaryData == TRUE)
            {
            	if(saveTextData == FALSE && saveBinaryData == FALSE)
				{
					 printf("\nUsted no ha guardado los datos en archivo.");
					 printf("\nPor favor guarde los datos o perderá los cambios.");
				}
            	else
            	{
            		controller_exitProgram(&optionExit);
            	}
            }
            else
            {
            	controller_exitProgram(&optionExit);
            }
           	break;
        }
    }while(optionExit != 0);

    return 0;
}

