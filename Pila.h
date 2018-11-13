/*
 * Pila.h
 *
 *  Created on: 11 nov. 2018
 *      Author: gabit
 */

#ifndef PILA_H_
#define PILA_H_

#include "NodoSimple.h"

/*
 * Es una coleccion dinamica de elementos dispuestos en una
 * secuencia.
 *
 * Sigue la estructura L.I.F.O. (Last In First Out) donde
 * el ultimo elemento insertado (llamado tope de la pila) es el
 * primero que se quita.
 *
 */
template<class T> class Pila {

private:

	NodoSimple<T>* tope;
	unsigned int tamanio;

public:

	/* Pre: -.
	 * Post: Crea una Pila vacia.
	 */
	Pila();

	/* Pre: -.
	 * Post: Indica si esta vacia.
	 */
	bool estaVacia();

	/* Pre: -.
	 * Post: Devuelve la cantidad de elementos que tiene la Pila.
	 */
	unsigned int contarElementos();

	/* Pre: -.
	 * Post: agrega un elemento en la parte superior de la pila que sera el
	 * nuevo tope y aumenta el tamanio en 1.
	 */
	void apilar(T elemento);

	/* Pre: Pila no vacia.
	 * Post: Devuelve el elemento ubicado en el tope, lo remueve y reduce
	 * el tamanio de la pila en 1.
	 */
	T desapilar();

	/* Pre: -.
	 * Post: Libera la memoria pedida.
	 */
	~Pila();
};

template<class T> Pila<T>::Pila(){
	this->tope = NULL;
	this->tamanio = 0;
}

template<class T> bool Pila<T>::estaVacia(){
	return (this->tope==NULL);
}

template<class T> unsigned int Pila<T>::contarElementos(){
	return this->tamanio;
}

template<class T> void Pila<T>::apilar(T elemento){
	NodoSimple<T>* nuevo = new NodoSimple(elemento);
	nuevo->setSiguiente(this->tope);
	this->tope = nuevo;
	this->tamanio++;

}

template<class T> T Pila<T>::desapilar(){
	T elemento;
	NodoSimple<T>* removido;
	removido = this->tope;
	this->tope = removido->getSiguiente();
	elemento = removido->getContenido();
	delete removido;
	this->tamanio--;
	return elemento;
}

template<class T> Pila<T>::~Pila(){
	while(!this->estaVacia()){
		this->desapilar();
	}
}

#endif /* PILA_H_ */
