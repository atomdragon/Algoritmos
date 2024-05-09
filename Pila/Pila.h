#include "Nodo.h"
using namespace std;

template<class T>
class Pila {
private:
	Nodo<T>* tope;
public:
	Pila() { tope = NULL; };
	void push(T v);
	T pop();
	bool estaVacia();
	void print();
};

template<class T>
void Pila<T>::push(T v) {
	if (estaVacia()) {
		tope = new Nodo<T>(v);
	}
	else {
		tope = new Nodo<T>(v, tope);

	}
}
template<class T>
T Pila<T>::pop() {
	if (estaVacia()) {
		//throw "Error, pila vacía";
		return NULL;
	}
	else {
		Nodo<T>* aux = tope;	//[REZC]aux: apuntará al Nodo, para luego liberar su 
		T elemento = (T)(tope->get_Elem());
		tope = (Nodo<T>*) tope->get_Sgte();
		delete aux;	//[REZC]Se libera memoria del Nodo removido por POP
		return elemento;
	}
}

template<class T>
bool Pila<T>::estaVacia() {
	return (tope == NULL);
}

template<class T>
inline void Pila<T>::print()
{
	Nodo<T>* aux = tope;
	while (aux!=nullptr)
	{
		cout << aux->get_Elem() << " ";
		aux = aux->get_Sgte();
	}
		
	cout << endl;

	delete aux;

}


