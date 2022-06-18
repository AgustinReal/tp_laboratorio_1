#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

struct Node
{
    void* pElement;                 //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;         //puntero al prox nodo
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;                       //cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;

#endif // LINKEDLIST_H_INCLUDED

//Publicas
LinkedList* ll_newLinkedList(void);//Usada
int ll_len(LinkedList* this);//Usada                                       //devuelve el valor del campo int size
Node* test_getNode(LinkedList* this, int nodeIndex);//No la supe implementar y tambien supuse que ya estaba en uso porque se usan en las funciones del linkedList.
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);//No la supe implementar y tambien supuse que ya estaba en uso porque se usan en las funciones del linkedList.
int ll_add(LinkedList* this, void* pElement);//Usada
void* ll_get(LinkedList* this, int index);//Usada
int ll_set(LinkedList* this, int index,void* pElement);// No supe donde implementarla
int ll_remove(LinkedList* this,int index);//Usada
int ll_clear(LinkedList* this);//Usada
int ll_deleteLinkedList(LinkedList* this);//Usada
int ll_indexOf(LinkedList* this, void* pElement);//Usada
int ll_isEmpty(LinkedList* this);//Usada
int ll_push(LinkedList* this, int index, void* pElement);//Usada
void* ll_pop(LinkedList* this,int index);//Usada                           //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
int ll_contains(LinkedList* this, void* pElement);//Usada
int ll_containsAll(LinkedList* this,LinkedList* this2);//Usada
LinkedList* ll_subList(LinkedList* this,int from,int to);//Usada
LinkedList* ll_clone(LinkedList* this);//Usada
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//Usada
