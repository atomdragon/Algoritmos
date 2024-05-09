#include "Nodo.h"
#include <iostream>

using namespace std;

template<class T>
class Cola {
private:
	Nodo<T>* inicio; 	//HEAD
	Nodo<T>* fin;		//TAIL
public:
	Cola() {
		this->inicio = NULL;
		this->fin = NULL;
	}
	void enqueue(T v);
	T dequeue();
	bool esVacia();
	void print();
	//void alldequeue();

};

template<class T>
bool Cola<T>::esVacia() {
	return (inicio == NULL);
}

template<class T>
void Cola<T>::enqueue(T v) {	//el nuevo Nodo INGRESA despues de "fin" (fin->siguiente)
	Nodo<T>* nodo = new Nodo<T>(v);
	if (esVacia()) {
		inicio = nodo;
		fin = inicio;
	}
	else {
		fin->set_Sgte(nodo); // 1)
		fin = nodo;

	}
	nodo = NULL;
}

template<class T>
T Cola<T>::dequeue() {	//El dato SALE de "inicio". "inicio" corre un nodo (inicio->siguiente)
	T dato = inicio->get_Elem();

	if (inicio == fin) { //Si hay UN solo Nodo
		// [rezc] delete inicio
		inicio = NULL;
		fin = NULL;
	}
	else {
		Nodo<T>* aux = inicio;	//[REZC] aux: Apunta al Nodo que será desencolado
		inicio = inicio->get_Sgte();	// 1)
		delete aux;	//[REZC] Libera memoria del Nodo
	}

	return dato;
}

template<class T>
inline void Cola<T>::print()
{
	Nodo<T>* aux = inicio;

	for (int i = 0; aux != nullptr; i++)
	{
		cout << aux->get_Elem() << " ";
		aux = aux->get_Sgte();
	}

	cout << endl;

	aux = NULL;
	delete aux;
}

//template<class T>
//inline void Cola<T>::alldequeue()
//{
//	Nodo<T>* aux = inicio;
//	for (int i = 0; aux !=nullptr ; i++)
//	{
//		inicio = inicio->get_Sgte();
//		aux = nullptr;
//		aux = inicio;
//	}
//
//	aux = NULL;
//	delete aux;
//	cout << "All elements are dequeued" << endl;
//}
