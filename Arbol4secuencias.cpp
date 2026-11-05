#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
};
Nodo* crearNodo(int valor) {
    Nodo* nuevo=new Nodo();
    nuevo->dato=valor;
    nuevo->izq=NULL;
    nuevo->der=NULL;
    return nuevo;
}
void preOrden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->dato << " ";
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}
void inOrden(Nodo* raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izq);
        cout << raiz->dato << " ";
        inOrden(raiz->der);
    }
}
void postOrden(Nodo* raiz) {
    if (raiz != NULL) {
        postOrden(raiz->izq);
        postOrden(raiz->der);
        cout << raiz->dato << " ";
    }
}

int main() {
    Nodo* raiz=crearNodo(10);          //Entonces aquí haríamos el nivel uno que sería la raiz del arbol
    raiz->izq=crearNodo(5);            //Depués vamos con el nivel 2
    raiz->der=crearNodo(15);
    raiz->izq->izq=crearNodo(2);       //Luego el nivel 3
    raiz->izq->der=crearNodo(7);
    raiz->izq->izq->izq=crearNodo(1);  //Y por último la secuencia 4

    cout << "--- ARBOL BINARIO DE 4 NIVELES ---" << endl;
    cout << "        (10)        " << endl;
    cout << "       /    \\       " << endl;
    cout << "     (5)    (15)    " << endl;
    cout << "     / \\            " << endl;
    cout << "   (2) (7)          " << endl;
    cout << "   /                " << endl;
    cout << " (1)                " << endl;

    //Y por último los tres recorridos que eran preorden, inorden y postorden
    cout << "Recorrido PreOrden : ";
    preOrden(raiz);
    cout << endl;
    cout << "Recorrido InOrden  : ";
    inOrden(raiz);
    cout << endl;
    cout << "Recorrido PostOrden : ";
    postOrden(raiz);
    cout << endl;
    return 0;
}