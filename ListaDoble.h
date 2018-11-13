/*
 * ListaDoble.h
 *
 *  Created on: 11 nov. 2018
 *      Author: gabit
 */

#ifndef LISTADOBLE_H_
#define LISTADOBLE_H_

#include "NodoDoble.h"

/*
 * Es una coleccion dinamica de elementos dispuestos en una
 * secuencia que tiene acceso al elemento anterior o posterior
 * de una posicion de la lista.
 *
 * Tiene un cursor que le permite recorrer los elementos
 * secuencialmente.
 *
 */
template<class T> class ListaDoble{

private:

	NodoDoble<T>* cursor;
	NodoDoble<T>* primero;
	unsigned int tamanio;

public:

	/* Pre: -.
	 * Post: Crea una ListaDoble vacia.
	 */
	ListaDoble();

	/* Pre: -.
	 * Post: Indica si esta vacia.
	 */
	bool estaVacia();

	/* Pre: -.
	 * Post: Devuelve la cantidad de elementos que tiene la lista.
	 */
	unsigned int contarElementos();

	/* Pre: -.
	 * Post: Deja preparado al cursor para realizar un nuevo recorrido
	 * de los elementos.
	 */
	void iniciarCursor();

	/* Pre: Se ha iniciado un recorrido (invocando el metodo iniciarCursor())
	 * y desde entonces no se han agregado o removido elementos de la lista.
	 * Post: Posiciona el cursor en el siguiente elemento del recorrido.
	 * El valor de retorno indica si el cursor se posiciono en un elemento de la lista o
	 * no (en el caso de que la lista este vacia o no hayan mas elementos para recorrer)
	 */
	bool avanzarCursor();

	/* Pre: El cursor esta posicionado en un elemento de la lista.
	 * Post: Devuelve el elemento en la posicion del cursor.
	 */
	T obtenerCursor();

	/* Pre: 'posicion' pertenece al intervalo [1, contarElementos()+1].
	 * Post: insertar un elemento en la posicion indicada aumentando el
	 * tamanio de la lista en 1.
	 */
	void insertar(T elemento, unsigned int posicion);

	/* Pre: Lista no vacia y 'posicion' pertenece al intervalo [1, contarElementos()].
	 * Post: Devuelve el elemento ubicado en la posicion indicada, lo remueve
	 * de la lista reduciendo su tamanio en 1.
	 */
	T remover(unsigned int posicion);

	/* Pre: -.
	 * Post: Libera la memoria pedida.
	 */
	~ListaDoble();

private:

	/* Pre: Lista no vacia y 'posicion' pertenece al intervalo [1, contarElementos()].
	 * Post: Devuelve el nodoSimple ubicado en la posicion indicada.
	 */
	NodoDoble<T>* obtenerNodo(unsigned int posicion);

};

template<class T> ListaDoble<T>::ListaDoble(){
	this->cursor = NULL;
	this->primero = NULL;
	this->tamanio = 0;
}

template<class T> bool ListaDoble<T>::estaVacia(){
	return (this->primero==NULL);
}

template<class T> unsigned int ListaDoble<T>::contarElementos(){
	return this->tamanio;
}

template<class T> void ListaDoble<T>::iniciarCursor(){
	this->cursor = NULL;
}

template<class T> bool ListaDoble<T>::avanzarCursor(){
	if(this->cursor!=NULL){
		this->cursor = this->cursor->getSiguiente();
	}
	else{
		this->cursor = this->primero;
	}
	return (this->cursor!=NULL);
}

template<class T> T ListaDoble<T>::obtenerCursor(){
	return this->cursor->getContenido();
}


template<class T> void ListaDoble<T>::insertar(T elemento, unsigned int posicion){
	NodoDoble<T>* nuevo = new NodoDoble(elemento);
	if(posicion!=1){
		NodoDoble<T>* anterior;
		NodoDoble<T>* posterior;
		anterior = this->obtenerNodo(posicion-1);
		posterior = anterior->getSiguiente();
		nuevo->setSiguiente(posterior);
		nuevo->setAnterior(anterior);
		if(posterior!=NULL){
			posterior->setAnterior(nuevo);
		}
		anterior->setSiguiente(nuevo);
	}
	else{
		nuevo->setSiguiente(this->primero);
		if(!this->estaVacia()){
			this->primero->setAnterior(nuevo);
		}
		this->primero = nuevo;
	}

	this->tamanio++;

	// Invalidamos cualquier recorrido actual.
	this->iniciarCursor();
}

template<class T> T ListaDoble<T>::remover(unsigned int posicion){
	T elemento;
	NodoDoble<T>* removido;
	if(posicion!=1){
		NodoDoble<T>* anterior = this->obtenerNodo(posicion - 1);
		removido = anterior->getSiguiente();
		NodoDoble<T>* posterior;
		posterior = removido->getSiguiente();
		anterior->setSiguiente(posterior);
		if(posterior!=NULL){
			posterior->setAnterior(anterior);
		}
	}
	else{
		removido = this->primero;
		this->primero = removido->getSiguiente();
		if(this->primero!=NULL){
			this->primero->setAnterior(NULL);
		}
	}
	elemento = removido->getContenido();
	delete removido;
	this->tamanio--;
	return elemento;
}

template<class T> ListaDoble<T>::~ListaDoble(){
	while(!this->estaVacia()){
		this->remover(1);
	}
}

template<class T> NodoDoble<T>* ListaDoble<T>::obtenerNodo(unsigned int posicion){
	NodoDoble<T>* nodoApuntado;
	nodoApuntado = this->primero;
	for(unsigned elemento = 1; elemento < posicion; elemento++){
		nodoApuntado = nodoApuntado->getSiguiente();
	}
	return nodoApuntado;
}

#endif /* LISTADOBLE_H_ */
