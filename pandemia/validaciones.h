#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/** \brief Muestra por pantalla un menu de opciones
 *
 * \return Devuelve la opcion elegida por el usuario
 **/
int menuOpciones(void);

/** \brief Vuelve a llamar al menu de opciones
 *
 * \return Un entero, devuelve la opcion elegida por el usuario en el menu
 **/
int reCall(void);

/** \brief Muestra un mensaje, pide al usuario ingresar un numero y lo devuelve
 *
 * \param Un puntero a char, el mensaje que se quiere mostrar
 * \return Un entero, el numero ingresado por el usuario
 **/
int obtenerNumero(char mensaje[]);

/** \brief Valida si un numero esta dentro de un rango
 *
 * \param Un entero, el numero a validar
 * \param Un entero, el valor maximo del rango
 * \param Un entero, el valor minimo del rango
 * \return Un entero, si el numero esta dentro del devuelve el numero
 **/
int validacionDeNumero(int numero,int minimo, int maximo);

/** \brief Valida si una cadena contiene solo letras
 *
 * \param Una cadena a validar
 * \return Un entero, devuelve 1 si son letras, devuelve -1 si son numeros
 **/
int sonLetras(char cadena[]);

/** \brief Valida si un caracter es f o m
 *
 * \param Un caracter a validar
 * \return Un entero, devuelve 1 si es f o m, devuelve 0 si es otro caracter
 **/
int validacionSexo(char sexo);


/** \brief Valida si un numero flotante esta dentro de un rango
 *
 * \param Un flotante, el numero a validar
 * \param Un entero, el valor maximo del rango
 * \param Un entero, el valor minimo del rango
 * \return Un flotante, si el numero esta dentro del devuelve el numero
 **/
float validacionDeNumeroFloat(float numero,int minimo, int maximo);

/** \brief Muestra un mensaje, pide al usuario ingresar un numero y lo devuelve
 *
 * \param Un puntero a char, el mensaje que se quiere mostrar
 * \return Un flotante, el numero ingresado por el usuario
 **/
float obtenerNumeroFlotante(char mensaje[]);

/** \brief Muestra un mensaje, pide al usuario ingresar un nombre de archivo, lo concatena
 *         con la extension csv y escribe el resultado en una cadena de texto
 *
 * \param Un puntero a char, el mensaje que se quiere mostrar
 **/
void pedirNombreArchivoTexto(char* nombre);

/** \brief Muestra un mensaje, pide al usuario ingresar un nombre de archivo, lo concatena
 *         con la extension bin y escribe el resultado en una cadena de texto
 *
 * \param Un puntero a char, el mensaje que se quiere mostrar
 **/
void pedirNombreArchivoBinario(char* nombre);

#endif // VALIDACIONES_H_INCLUDED
