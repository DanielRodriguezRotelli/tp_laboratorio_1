#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxNode=NULL;
	int index;

	if(this!=NULL && nodeIndex>=0 && ll_len(this)>nodeIndex)
	{
		auxNode = this->pFirstNode;
		for(index=0; index<nodeIndex;index++)
		{
			auxNode = auxNode->pNextNode;
		}
	}
    return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* auxNodo;
    Node* newNodo=(Node*)malloc(sizeof(Node));

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
    	if(newNodo!=NULL)
    	{
    		//diferenciar los 3 casos
			if(nodeIndex==0)//primera posicion
			{
				auxNodo = this->pFirstNode;
				this->pFirstNode = newNodo;
				newNodo->pNextNode = auxNodo;
			}
			else
			{
				auxNodo = getNode(this,nodeIndex-1);
				newNodo->pNextNode = auxNodo->pNextNode;
				auxNodo->pNextNode = newNodo;
			}
			this->size++;
			newNodo->pElement = pElement;
			returnAux=0;
    	}
    	//construyo un nuevo nodo
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux=-1;
	if(this!=NULL)
	{
		returnAux=addNode(this,this->size,pElement);
	}

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)// getNode
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0)
    {
    	Node* pNodo=getNode(this,index);
		if(pNodo!=NULL)
		{
			returnAux=pNodo->pElement;//Bien
		}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0)
    {
    	Node* pNodo=getNode(this,index);
    	if(pNodo!=NULL)
    	{
    		pNodo->pElement=pElement;
    		returnAux =0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodo;
    Node* pNodoAnterior;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	if(index==0) //borro 1er nodo
		{
			// borro el primero
			//1)obtengo el nodo a borrar (posicion 0)
			pNodo=this->pFirstNode;
			//2) escribo como first el siguiente del nodo que borro
			this->pFirstNode=pNodo->pNextNode;
			//3)borro el Nodo
			free(pNodo);
			//4)size--
			this->size--;
		}
		else // borro uno del medio o el ultimo
		{
			pNodo = getNode(this,index);
			pNodoAnterior = getNode(this,index-1);
			pNodoAnterior->pNextNode=pNodo->pNextNode;
			free(pNodo);
			this->size--;
		}
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len=(ll_len(this)-1);

    if(this!=NULL && this->size==0)
    {
    	returnAux=0;
    }
    else
    {
    	for(i=len; i>=0; i--)
    	{
    		returnAux=ll_remove(this,i);
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	returnAux=ll_clear(this);
    	if(returnAux==0)
    	{
    		free(this);
    	}
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* auxNode;


    if(this!=NULL)
    {
		for(i=0; i<ll_len(this); i++)
		{
			auxNode=getNode(this,i);
			if(auxNode!=NULL)
			{
				if(auxNode->pElement==pElement)
				{
					returnAux=i;
					break;
				}
			}
		}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(this->pFirstNode==NULL)
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement) // add
{
    int returnAux = -1;
    //printiar el size si es que no funciona
    if(this!=NULL && index<=this->size)
    {
    	returnAux=addNode(this,index,pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index) // get y remove
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	returnAux = ll_get(this,index);
    	ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	returnAux=0;
    	if(ll_indexOf(this,pElement)>=0)
    	{
    		returnAux=1;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	int i;
	void* aux;

	if(this!=NULL && this2!=NULL)
	{
		returnAux=0;
		for(i=0; i<ll_len(this2); i++)
		{
			aux=ll_get(this2, i);
			if(ll_contains(this,aux)==1)
			{
				returnAux=1;
			}
			else
			{
				returnAux=0;
				break;
			}
		}
	}
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* aux=NULL;

    if(this!=NULL && from<=this->size && from>=0 && to<=this->size && to>=from)
    {
    	cloneArray=ll_newLinkedList();
    	if(cloneArray!=NULL)
    	{
    		for(i=from; i<=to; i++)
    		{
    			aux=ll_get(this, i);
    			ll_add(cloneArray,aux);
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
    	cloneArray=ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int flagSwap=0;
    int i;
    void* auxA;
    void* auxB;
    int orderValue;

    if(this!=NULL && ll_len(this)>0 && pFunc!=NULL && (order==0 || order==1))
    {
    	returnAux=1;
    	do
    	{
    		flagSwap=0;
    		for(i=0; i<(ll_len(this)-1); i++)
    		{
    			auxA=ll_get(this,i);
    			auxB=ll_get(this,i+1);
    			if(auxA!=NULL && auxB!=NULL)
    			{
    				orderValue=pFunc(auxA,auxB);
    				if((orderValue==-1 && order==0) || (orderValue==1 && order==1))
    				{
    					flagSwap=1;
    					ll_set(this, i, auxB);
    					ll_set(this, i+1, auxA);
    				}
    			}
    		}
    	}while(flagSwap==1);
    	returnAux=0;
    }
    return returnAux;

}


/** \brief Encuentra todos los elementos de la lista y aplica la funcion recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion
 * \return int Retorna  (-1) Error: si el puntero a la listas y el puntero a la funcion es NULL
                        ( 0) Si ok
 */
int ll_map(LinkedList* this, void (*pFunc)(void* ))
{
    int returnAux =-1;
    int i;
    void* auxA;

    if(this!=NULL && pFunc!=NULL)
    {
		for(i=0; i<ll_len(this); i++)
		{
			auxA=ll_get(this,i);

			if(auxA!=NULL)
			{
				pFunc(auxA);
			}
		}
    	returnAux=0;
    }
    return returnAux;
}



/** \brief Crea una nueva lista con los elementos filtrados segun la funcion de criterio.
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion
 * \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al a la nueva lista filtrada.
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* ))
{
    int criterio;
    int i;
    void* auxA;
    LinkedList* newList;

    if(this!=NULL && pFunc!=NULL)
    {
    	newList=ll_newLinkedList();
    	if(newList!=NULL)
    	{
    		for(i=0; i<ll_len(this); i++)
			{
				auxA=ll_get(this,i);
				if(auxA!=NULL)
				{
					criterio=pFunc(auxA);
					if(criterio==0)
					{
						ll_add(newList,auxA);
					}
				}
			}
    	}

    }
    return newList;
}

/*
int ll_printListGame(LinkedList* this, void (*pFunc)(void* ))
{
    int returnAux =-1;
    int i;
    void* auxA;
    Arcade* buffer

    if(this!=NULL && pFunc!=NULL)
    {
		for(i=0; i<ll_len(this); i++)
		{
			auxA=ll_get(this,i);

			if(auxA!=NULL)
			{
				pFunc(auxA);
			}
		}
    	returnAux=0;
    }
    return returnAux;
}
*/



