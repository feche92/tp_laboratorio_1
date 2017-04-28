#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[30];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona[], int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona[], int, int);

/** \brief recibe el array, lo ordena y lo muestra
 *
 * \param el array
 * \param la cantidad de subindices del array
 *
 */

 void imprimir(EPersona[], int);

 /** \brief recibe los valores del array y muestra un grafico de barras
  *
  * \param valor del primer subindice del array
  * \param valor del segundo subindice del array
  * \param valor del tercer subindice del array
  *
  */

  void grafico(int, int, int);


  /** \brief recibe la cadena como pasaje de referencia y guarda un nombre
   *
   * \param cadena de caracteres
   *
   */

 void validarNombre(char[]);

 /** \brief recibe dos limites y devuelve un entero dentro del mismo
  *
  * \param limite menor
  * \param limite mayor
  * \return la edad del usuario
  *
  */


  int validarEdad(int, int);

  /** \brief valida que usuario ingrese S/N
   *
   * \return si el usuario escribe S devuelve 1 sino 0
   *
   */

  int validaS_N(void);

  /** \brief muestra el array de estructura
   *
   * \param el array
   * \param la cantidad del subindice
   *
   */

    void mostrarLista(EPersona[],int);




#endif // FUNCIONES_H_INCLUDED
