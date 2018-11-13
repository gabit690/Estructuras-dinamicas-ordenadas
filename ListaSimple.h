/*
 * ListaSimple.h
 *
 *  Created on: 11 nov. 2018
 *      Author: gabit
 */

#ifndef LISTASIMPLE_H_
#define LISTASIMPLE_H_

#include "NodoSimple.h"

/*
 * Es una coleccion dinamica de elementos dispuestos en una
 * secuencia.
 *
 * Tiene un cursor que le permite recorrer los elementos
 * secuencialmente.
 */
template<class T> class ListaSimple {

private:

	NodoSimple<T>* primero;
	unsigned int tamanio;
	NodoSimple<T>* cursor;

public:

	/* Pre: -.
	 * Post: Crea una listaSimple vacia.
	 */
	ListaSimple();

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

	/* Pre: Se ha iniciado un recorrido (invocando el metodo iniciarCurso()) y desde
	 * entonces no se han agregado o removido elementos de la lista.
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
	~ListaSimple();

private:

	/* Pre: Lista no vacia y 'posicion' pertenece al intervalo [1, contarElementos()].
	 * Post: Devuelve el nodoSimple ubicado en la posicion indicada.
	 */
	NodoSimple<T>* obtenerNodo(unsigned int posicion);

};

template<class T> ListaSimple<T>::ListaSimple(){
	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
}

template<class T> bool ListaSimple<T>::estaVacia(){
	return (this->primero==NULL);
}

template<class T> unsigned int ListaSimple<T>::contarElementos(){
	return this->tamanio;
}

template<class T> void ListaSimple<T>::iniciarCursor(){
	this->cursor = NULL;
}

template<class T> bool ListaSimple<T>::avanzarCursor(){
	if(this->cursor!=NULL){
		this->cursor = this->cursor->getSiguiente();
	}
	else{
		this->cursor = this->primero;
	}
	return (this->cursor!=NULL);
}

template<class T> T ListaSimple<T>::obtenerCursor(){
	return this->cursor->getContenido();
}

template<class T> void ListaSimple<T>::insertar(T elemento, unsigned int posicion){
	NodoSimple<T>* nuevo = new NodoSimple(elemento);
	if(posicion!=1){
		NodoSimple<T>* anterior;
		anterior = this->obtenerNodo(posicion-1);
		nuevo->setSiguiente(anterior->getSiguiente());
		anterior->setSiguiente(nuevo);
	}
	else{
		nuevo->setSiguiente(this->primero);
		this->primero = nuevo;
	}
	this->tamanio++;

	// Invalidamos cualquier recorrido actual.
	this->iniciarCursor();
}

template<class T> T ListaSimple<T>::remover(unsigned int posicion){
	T elemento;
	NodoSimple<T>* removido;
	if(posicion!=1){
		NodoSimple<T>* anterior = this->obtenerNodo(posicion - 1);
		removido = anterior->getSiguiente();
		anterior->setSiguiente(removido->getSiguiente());
	}
	else{
		removido = this->primero;
		this->primero = removido->getSiguiente();
	}
	elemento = removido->getContenido();
	delete removido;
	this->tamanio--;
	return elemento;
}

template<class T> ListaSimple<T>::~ListaSimple(){
	while(!this->estaVacia()){
		this->remover(1);
	}
}

template<class T> NodoSimple<T>* ListaSimple<T>::obtenerNodo(unsigned int posicion){
	NodoSimple<T>* nodoApuntado;
	nodoApuntado = this->primero;
	for(unsigned elemento = 1; elemento < posicion; elemento++){
		nodoApuntado = nodoApuntado->getSiguiente();
	}
	return nodoApuntado;
}

#endif /* LISTASIMPLE_H_ */
