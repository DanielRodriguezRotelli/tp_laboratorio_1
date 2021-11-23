

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this); //CUENTA EL LARGO DE LA LISTA
Node* test_getNode(LinkedList* this, int nodeIndex); // DEVUELVE EL DATO QUE ESTA EN EL INDICE
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement); //AGREGA EL ELEMENTO AL FINAL DE LA LISTA
void* ll_get(LinkedList* this, int index); //DEVUELVE EL PUNTERO AL ELEMENTO (EL LUGAR DONDE SE ENCUENTRA EL ELMENTO EN LA MEMORIA)
int ll_set(LinkedList* this, int index,void* pElement); // REEMPLAZA A UN ELEMENTO DENTRO DE LA LISTA
int ll_remove(LinkedList* this,int index); //
int ll_clear(LinkedList* this); //VACIA LA LISTA
int ll_deleteLinkedList(LinkedList* this); //ELIMINA LA LISTA
int ll_indexOf(LinkedList* this, void* pElement); //ME DEVUELVE LA POSICION DE UN ELEMENTO
int ll_isEmpty(LinkedList* this); // ME DICE SI HAY ELEMENTEOS DENTRO DE LA LISTA
int ll_push(LinkedList* this, int index, void* pElement); // PONE UN ELEMENTO EN LA LISTA ENTRE OTROS ELEMENTOS O AL FINAL DE LA LISTA
void* ll_pop(LinkedList* this,int index); // SACA ELEMENTO DE LA LISTA Y LO DEVUELVE PARA MOSTRARLO O AGREGARLO EN OTRA LISTA
int ll_contains(LinkedList* this, void* pElement); //SI EL ELEMENTO QUE PASO ESTA DENTRO DE LA LISTA
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this); //DEVUELVE UNA COPÌA DE LA LISTA
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); //
int ll_map(LinkedList* this, void (*pFunc)(void* ));
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* ));
