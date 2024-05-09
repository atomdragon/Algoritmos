#pragma once
template <class T>
class Nodo
{
private:
	//propiedades o atributos
	T elem;
	Nodo* sgte;
public:
	//Constructores
	Nodo()
	{
		sgte = nullptr;
	}
	Nodo(T dato, Nodo<T>* sig = NULL) {
		elem = dato;
		sgte = sig;
	}


	//Métodos Setter / Getter
	void set_Elem(T _elem)
	{
		elem = _elem;
	}
	T get_Elem() 
	{
	
		return elem;
	}

	void set_Sgte(Nodo* _Sgte)
	{
		sgte = _Sgte;
	}
	Nodo* get_Sgte()
	{
		return sgte;
	}

	//Métodos de Servicio
	bool es_vacio()
	{
		return sgte == NULL;
	}
};
