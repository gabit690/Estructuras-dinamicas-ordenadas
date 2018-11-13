/*
 * Cola.h
 *
 *  Created on: 11 nov. 2018
 *      Author: gabit
 */

#ifndef COLA_H_
#define COLA_H_

#include "NodoSimple.h"

/*
 * Es una coleccion dinamica de elementos dispuestos en una
 * secuencia.
 *
 * Sigue la estructura F.I.F.O. (First In First Out) donde
 * el primer elemento insertado (llamado frente de la cola) es el
 * primero que se quita.
 *
 * Las inserciones se realizan al final de la cola.
 *
 */
template<class T> class Cola {

private:

	NodoSimple<T>* frente;
	unsigned int tamanio;
	NodoSimple<T>* fondo;

public:

	/* Pre: -.
	 * Post: Crea una cola sin elementos.
	 */
	Cola();

	/* Pre: -.
	 * Post: indica si hay elementos en la cola.
	 */
	bool estaVacia();

	/* Pre: -.
	 * Post: devuelve la cantidad de elementos que tiene.
	 */
	unsigned int contarElementos();

	/* Pre: -.
	 * Post: agrega un elemento al final de la cola aumentando su tamanio en 1.
	 */
	void acolar(T elemento);

	/* Pre: hay elementos para desacolar.
	 * Post: quita el primer elemento de la cola reduciendo su tamanio en 1.
	 */
	T desacolar();

	/* Pre: -.
	 * Post: libera los recursos pedidos.
	 */
	~Cola();
};

template<class T> Cola<T>::Cola(){
	this->frente = NULL;
	this->tamanio = 0;
	this->fondo = NULL;
}

template<class T> bool Cola<T>::estaVacia(){
	return this->frente==NULL;
}

template<class T> unsigned int Cola<T>::contarElementos(){
	return this->tamanio;
}

template<class T> void Cola<T>::acolar(T elemento){
	NodoSimple<T>* nuevo = new NodoSimple<T>(elemento);
	if(this->fondo!=NULL){
		this->fondo->setSiguiente(nuevo);
	}
	else{
		this->frente = nuevo;
	}
	this->fondo = nuevo;
	this->tamanio++;
}

template<class T> T Cola<T>::desacolar(){
	T elemento;
	NodoSimple<T>* removido;
	removido = this->frente;
	if(this->frente==this->fondo){
		this->fondo = NULL;
	}
	this->frente = removido->getSiguiente();
	elemento = removido->getContenido();
	delete removido;
	this->tamanio--;
	return elemento;
}

template<class T> Cola<T>::~Cola(){
	while(!this->estaVacia()){
		this->desacolar();
	}
}

#endif /* COLA_H_ */
