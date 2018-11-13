/*
 * NodoDoble.h
 *
 *  Created on: 11 nov. 2018
 *      Author: gabit
 */

#ifndef NODODOBLE_H_
#define NODODOBLE_H_

#ifndef NULL
#define NULL 0
#endif

/* Un NodoDoble es la minima parte que compone una estructura dinamica de elementos.
 * Contiene un elemento de la estructura y se puede conectar a dos NodoSimple, uno
 * anterior al mismo y otro posterior.
 */
template<class T> class NodoDoble {

private:

	NodoDoble<T>* anterior;
	T elemento;
	NodoDoble* siguiente;

public:
	/* Pre: -.
	 * Post: El contenido es 'elemento' y no esta conectado a otro NodoSimple.
	 */
	NodoDoble(T elemento);

	/* Pre: -.
	 * Post: Contiene el dato 'elemento';
	 */
	void setContenido(T elemento);

	/* Pre: -.
	 * Post: Se conecta a 'anterior';
	 */
	void setAnterior(NodoDoble<T>* anterior);

	/* Pre: -.
	 * Post: Se conecta a 'siguiente';
	 */
	void setSiguiente(NodoDoble<T>* siguiente);

	/* Pre: -.
	 * Post: Devuelve el elemento contenido.
	 */
	T getContenido();

	/* Pre: -.
	 * Post: Devuelve el NodoDoble anterior al cual esta conectado.
	 */
	NodoDoble<T>* getAnterior();

	/* Pre: -.
	 * Post: Devuelve el NodoDoble siguiente al cual esta conectado.
	 */
	NodoDoble<T>* getSiguiente();
};


template<class T> NodoDoble<T>::NodoDoble(T elemento){
	this->anterior = NULL;
	this->elemento = elemento;
	this->siguiente = NULL;
}

template<class T> void NodoDoble<T>::setContenido(T elemento){
	this->elemento = elemento;
}

template<class T> void NodoDoble<T>::setAnterior(NodoDoble<T>* anterior){
	this->anterior = anterior;
}

template<class T> void NodoDoble<T>::setSiguiente(NodoDoble<T>* siguiente){
	this->siguiente = siguiente;
}

template<class T> T NodoDoble<T>::getContenido(){
	return this->elemento;
}

template<class T> NodoDoble<T>* NodoDoble<T>::getAnterior(){
	return this->anterior;
}

template<class T> NodoDoble<T>* NodoDoble<T>::getSiguiente(){
	return this->siguiente;
}

#endif /* NODODOBLE_H_ */
