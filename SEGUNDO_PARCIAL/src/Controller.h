#include "Arcade.h"


int controller_loadFromText(char* path , LinkedList* pArrayListArcade);
//int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addArcade(LinkedList* pArrayListArcade);
int controller_editArcade(LinkedList* pArrayListArcade);
int controller_removeArcade(LinkedList* pArrayListArcade);
int controller_ListArcade(LinkedList* pArrayListArcade);
int controller_sortPrintArcade(LinkedList* pArrayListArcade);
int controller_menuSortArcade(LinkedList* pArrayListArcade);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
//int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
void controller_menu(int* optionMenu);
int controller_menuEditArcade(LinkedList* pArrayListArcade, Arcade* auxArcade);
int controller_makeFileMultiplayer(char* path , LinkedList* pArrayListArcade);
void controller_exitProgram(int *option);
int controller_renewCoinsArcade(LinkedList* pArrayListArcade);
//int controller_ListArcadeMap(LinkedList* pArrayListArcade);
int controller_printListGames( LinkedList* pArrayListArcade);
int controller_makeFileGames(char* path, LinkedList* pArrayListArcade);

