#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int vacuna1dosis;
    int vacuna2dosis;
    int sinVacunar;
}ePais;

/** \brief Constructor de una nuevo pais, Crea un espacio en memoria dinámica y escribe los parametros dados
 *
 * \param Puntero a char, el id
 * \param Puntero a char, el nombre
 * \param Puntero a char, 1 dosis de vacuna
 * \param Puntero a char, 2 dosis de vacuna
 * \param Puntero a char, los sin vacunar
 * \return Puntero a la estructura creada
 *
 */
ePais* pais_newParametros(char* idStr, char* nombreStr, char* vacuna1DosisStr, char* vacuna2DosisStr,char* sinVacunarStr);

/** \brief Constructor por defecto de un pais
 *
 * \return Puntero a la estructura creada
 *
 */
ePais* pais_new(void);

/** \brief Escribe la variable pasada como parámetro en el campo ID de la estructura
 *
 * \param Puntero al pais
 * \param Un entero, el id
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 *
 */
int pais_setId(ePais* pPais, int id);

/** \brief Escribe la variable pasada como parámetro en el campo nombre de la estructura
 *
 * \param Puntero al pais
 * \param Puntero a char, el nombre
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 *
 */
int pais_setNombre(ePais* pPais,char* nombre);

/** \brief Escribe la variable pasada como parámetro en el campo recuperados de la estructura
 *
 * \param Puntero al pais
 * \param Un entero, primera dosis de vacuna
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 *
 */
int pais_setVacuna1Dosis(ePais* pPais, int recuperados);

/** \brief Escribe la variable pasada como parámetro en el campo infectados de la estructura
 *
 * \param Puntero al pais
 * \param Un entero, segunda dosis de vacuna
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 *
 */
int pais_setVacuna2Dosis(ePais* pPais, int infectados);

/** \brief Escribe la variable pasada como parámetro en el campo muertos de la estructura
 *
 * \param Puntero al pais
 * \param Un entero, los sin vacunar
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 *
 */
int pais_setSinVacunar(ePais* pPais, int muertos);

/** \brief Lee el valor del campo id de la estructura pais y lo copia en la variable pasada como parametro
 *
 * \param Puntero al pais
 * \param Puntero a un entero, el id
 * \return Un entero, 1 si lo pudo leer y 0 si hubo error
 *
 */
int pais_getId(ePais* pPais,int* id);

/** \brief Lee el valor del campo nombre de la estructura pais y lo copia en la variable pasada como parametro
 *
 * \param Puntero al pais
 * \param Puntero a char, el nombre
 * \return Un entero, 1 si lo pudo leer y 0 si hubo error
 *
 */
int pais_getNombre(ePais* pPais, char* nombre);

/** \brief Lee el valor del campo vacuna 1 dosis de la estructura pais y lo copia en la variable pasada como parametro
 *
 * \param Puntero al pais
 * \param Puntero a entero, vacuna 1 dosis
 * \return Un entero, 1 si lo pudo leer y 0 si hubo error
 *
 */
int pais_getVacuna1Dosis(ePais* pPais,int* infectados);

/** \brief Lee el valor del campo vacuna 2 dosis de la estructura pais y lo copia en la variable pasada como parametro
 *
 * \param Puntero al pais
 * \param Puntero a entero, vacuna 2 dosis
 * \return Un entero, 1 si lo pudo leer y 0 si hubo error
 *
 */
int pais_getVacuna2Dosis(ePais* pPais,int* recuperados);

/** \brief Lee el valor del campo sin vacunar de la estructura pais y lo copia en la variable pasada como parametro
 *
 * \param Puntero al pais
 * \param Puntero a entero, los sin vacunar
 * \return Un entero, 1 si lo pudo leer y 0 si hubo error
 *
 */
int pais_getSinVacunar(ePais* pPais,int* muertos);

/** \brief Recibe dos punteros y compara el campo vacuna 1 dosis de ambas estructuras
 *
 * \param Puntero a un elemento
 * \param Puntero al otro elemento
 * \return Devuelve 1 si el valor del primero es mayor que el segundo, -1 si es menor y 0 si son iguales
 *
 */
int pais_nivelVacunacion(void* p1, void* p2);

/** \brief Asigna valores random dentro de los limites dados a los campos vacuna 1 y 2 de la estructura
 *         y asigna al campo sin vacunar el valor necesario para completar el 100 % entre los 3
 *
 * \param Puntero a un elemento
 * \return Devuelve 1 si lo logra y 0 si hubo error
 *
 */
int funcionDeMapeo(void* pElement);


/** \brief Determina si el valor del campo vacuna 2 dosis es mayor o menor de 30
 *
 * \param Puntero a un elemento
 * \return Devuelve 1 si es menor y 0 si es mayor
 *
 */
int filterExitosos(void* pElement);

/** \brief Determina si el valor del campo sin vacunar es mayor al de los campos vacuna 1 y 2 sumados
 *
 * \param Puntero a un elemento
 * \return Devuelve 1 si es mayor y 0 si es menor
 *
 */
int filterHorno(void* pElement);
#endif // PAIS_H_INCLUDED
