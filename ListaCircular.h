/*
 * ListaCircular.h
 *
 *  Created on: 11 nov. 2018
 *      Author: gabit
 */

#ifndef LISTACIRCULAR_H_
#define LISTACIRCULAR_H_

#include "NodoSimple.h"

/*
 * Es una coleccion dinamica de elementos dispuestos en una
 * secuencia.
 *
 * El ultimo elemento esta conectado a primer elemento y si
 * solo tuviera uno ese estaria conectado consigo mismo.
 *
 * Tiene un cursor que le permite recorrer los elementos
 * secuencialmente.
 */
template<class T> class ListaCircular {

private:

	NodoSimple<T>* primero;
	unsigned int tamanio;
	NodoSimple<T>* cursor;

public:

	/* Pre: -.
	 * Post: Crea una listaCircular vacia.
	 */
	ListaCircular();

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
	 * no (en el caso de que la lista este vacia).
	 * Si la lista tiene elementos para recorrer entonces el cursor no tendra un limite de
	 * posiciones que recorrer ya que la lista es circular.
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
	~ListaCircular();

private:

	/* Pre: Lista no vacia y 'posicion' pertenece al intervalo [1, contarElementos()].
	 * Post: Devuelve el nodoSimple ubicado en la posicion indicada.
	 */
	NodoSimple<T>* obtenerNodo(unsigned int posicion);
};

template<class T> ListaCircular<T>::ListaCircular(){
	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
}

template<class T> bool ListaCircular<T>::estaVacia(){
	return (this->primero==NULL);
}

template<class T> unsigned int ListaCircular<T>::contarElementos(){
	return this->tamanio;
}

template<class T> void ListaCircular<T>::iniciarCursor(){
	this->cursor = NULL;
}

template<class T> bool ListaCircular<T>::avanzarCursor(){
	if(this->cursor!=NULL){
		this->cursor = this->cursor->getSiguiente();
	}
	else{
		this->cursor = this->primero;
	}
	return (this->cursor!=NULL);
}

template<class T> T ListaCircular<T>::obtenerCursor(){
	return this->cursor->getContenido();
}

template<class T> void ListaCircular<T>::insertar(T elemento, unsigned int posicion){
	NodoSimple<T>* nuevo = new NodoSimple(elemento);

	if(posicion != 1){
		NodoSimple<T>* anterior;
		anterior = this->obtenerNodo(posicion-1);
		nuevo->setSiguiente(anterior->getSiguiente());
		anterior->setSiguiente(nuevo);
	}
	else{
		nuevo->setSiguiente(this->primero);
		if(this->estaVacia()){
			nuevo->setSiguiente(nuevo);
		}
		this->primero = nuevo;
	}

	this->tamanio++;

	// Invalidamos cualquier recorrido actual.
	this->iniciarCursor();
}

template<class T> T ListaCircular<T>::remover(unsigned int posicion){
	T elemento;
	NodoSimple<T>* removido;
	if(posicion!=1){
		NodoSimple<T>* anterior = this->obtenerNodo(posicion - 1);
		removido = anterior->getSiguiente();
		anterior->setSiguiente(removido->getSiguiente());
	}
	else{
		removido = this->primero;

		if(removido->getSiguiente()!=NULL){
			NodoSimple<T>* ultimoElemento;
			ultimoElemento = this->obtenerNodo(this->contarElementos());
			ultimoElemento->setSiguiente(removido->getSiguiente());
		}
		this->primero = removido->getSiguiente();
	}

	this->tamanio--;

	elemento = removido->getContenido();
	delete removido;

	return elemento;
}

template<class T> ListaCircular<T>::~ListaCircular(){
	while(!this->estaVacia()){
		this->remover(1);
	}
}

template<class T> NodoSimple<T>* ListaCircular<T>::obtenerNodo(unsigned int posicion){
	NodoSimple<T>* nodoApuntado;
	nodoApuntado = this->primero;
	for(unsigned elemento = 1; elemento < posicion; elemento++){
		nodoApuntado = nodoApuntado->getSiguiente();
	}
	return nodoApuntado;
}

#endif /* LISTACIRCULAR_H_ */
