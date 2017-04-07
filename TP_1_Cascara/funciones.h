#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief recibe los operandos y los suma
 *
 * \param primer operando
 * \param segundo operando
 * \return la suma final de los operandos
 *
 */

float suma(float, float);

/** \brief recibe los operando y los resta
 *
 * \param primer operando
 * \param segundo operando
 * \return la resta final de los operandos
 *
 */

 float resta(float, float);

 /** \brief recibe los operando y los multiplica
 *
 * \param primer operando
 * \param segundo operando
 * \return la multiplicacion final de los operandos
 *
 */

 float multiplicacion(float, float);

 /** \brief recibe los operando y los divide
 *
 * \param primer operando
 * \param segundo operando
 * \return la division final de los operandos
 *
 */

 float division(float, float);

 /** \brief recibe un operando y calcula su factorial
 *
 * \param primer operando
 * \return muestra el factorial de dicho operando
 *
 */

float factorial(float);

/** \brief recibe el operando, valida el dato y llama a la funcion factorial
 *
 * \param primer operando
 * \return devuelve 0 si no esta validado el dato o el factorial de dicho operando
 *
 */

float validarFactorial(float);

/** \brief Llama a todas las funciones y muestra sus resultados
 *
 * \param primer operando
 * \param segundo operando
 *
 */

 void operaciones(float, float);






#endif // FUNCIONES_H_INCLUDED
