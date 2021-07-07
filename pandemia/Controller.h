/** \brief Busca en la LinkedList el id con el numero mayor, le suma uno y devuelve el resultado
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, el proximo id para otorgar
 **/
int controller_setId(LinkedList* pArrayList);

/** \brief Busca el numero de id dado dentro de la LinkedList y devuelve el indice del elemento con ese ID.
 *
 * \param Puntero del tipo LinkedList a la lista
 * \param Un entero, el ID buscado
 * \return Un entero, el indice del elemento que tiene ese ID
 **/
int controller_getIndexById(LinkedList* pArrayLista,int idBuscado);

/** \brief Abre el archivo de tipo texto que se solicita y llama a la funcion parser_FromText
 *
 * \param Puntero al archivo, con su ruta correspondiente
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_loadFromText(char* path , LinkedList* pArrayLista);


/** \brief Abre el archivo de tipo binario que se solicita y llama a la funcion parser_FromBinary
 *
 * \param Puntero al archivo, con su ruta correspondiente
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_loadFromBinary(char* path , LinkedList* pArrayList);

/** \brief Agrega un elemento a la lista
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_addEstructura(LinkedList* pArrayLista);

/** \brief Modifica un elemento
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_edit(LinkedList* pArrayList);

/** \brief Borra un elemento de la lista
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_remove(LinkedList* pArrayLista);

/** \brief Imprime por pantalla la lista
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_List(LinkedList* pArrayLista);

/** \brief Llama a las funciones de ordenamiento pasandole los parametros
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_sort(LinkedList* pArrayList);

/** \brief Guarda la lista que esta en memoria dinamica en un archivo de texto csv
 *
 * \param Puntero al archivo, con su ruta correspondiente
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_saveAsText(char* path , LinkedList* pArrayList);

/** \brief Guarda la lista que esta en memoria dinamica en un archivo binario
 *
 * \param Puntero al archivo, con su ruta correspondiente
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_saveAsBinary(char* path , LinkedList* pArrayList);

/** \brief Llama a la funcion filter
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_filter(LinkedList* pArrayLista, int filtro);

/** \brief Dado un codigo numerico, devuelve la descripcion de dicho codigo
 *
 * \param Un entero, el codigo
 * \param Un puntero a char, donde quiero que escriba la descripcion
 **/
void getDescripcionCodigo(int codigo, char* descripcionCodigo);

/** \brief Llama a la funcion map
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_map(LinkedList* pArrayLista);

/** \brief Imprime por pantalla un informe sobre los paises con numero mayor de muertos
 *
 * \param Puntero a la lista de paises
 * \return Un entero, 1 si tuvo exito y 0 si hubo error
 *
 */
int controller_informe(LinkedList* pArrayLista);
