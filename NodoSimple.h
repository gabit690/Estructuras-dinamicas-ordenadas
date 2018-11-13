/*
 * NodoSimple.h
 *
 *  Created on: 11 nov. 2018
 *      Author: gabit
 */

#ifndef NODOSIMPLE_H_
#define NODOSIMPLE_H_

#ifndef NULL
#define NULL 0
#endif

/* Un NodoSimple es la minima parte que compone una estructura dinamica de elementos.
 * Contiene un elemento de la estructura y se puede conectar a otro NodoSimple
 * mediante un puntero.
 */
template<class T> class NodoSimple {

private:

	T elemento;
	NodoSimple<T>* siguiente;

public:
	/* Pre: -.
	 * Post: El contenido es 'elemento' y no esta conectado a otro NodoSimple.
	 */
	NodoSimple(T elemento);

	/* Pre: -.
	 * Post: Contiene el dato 'elemento';
	 */
	void setContenido(T elemento);

	/* Pre: -.
	 * Post: Se conecta a 'siguiente';
	 */
	void setSiguiente(NodoSimple* siguiente);

	/* Pre: -.
	 * Post: Devuelve el elemento contenido.
	 */
	T getContenido();

	/* Pre: -.
	 * Post: Devuelve el NodoSimple al cual esta conectado.
	 */
	NodoSimple* getSiguiente();
};

template<class T> NodoSimple<T>::NodoSimple(T elemento) {
	this->elemento = elemento;
	this->siguiente = NULL;
}

template<class T> void NodoSimple<T>::setContenido(T elemento){
	this->elemento = elemento;
}

template<class T> void NodoSimple<T>::setSiguiente(NodoSimple<T>* siguiente){
	this->siguiente = siguiente;
}

template<class T> T NodoSimple<T>::getContenido(){
	return this->elemento;
}

template<class T> NodoSimple<T>* NodoSimple<T>::getSiguiente(){
	return this->siguiente;
}


#endif /* NODOSIMPLE_H_ */
