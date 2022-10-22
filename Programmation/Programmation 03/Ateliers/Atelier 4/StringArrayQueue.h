#include <stdlib.h>

struct StringArrayQueue {
  char **array;       ///< Tableau de chaine de caracteres.
  size_t length;      ///< Taille du tableau de cahine de caracteres.
  size_t count;       ///< Nombre de donnes dans le tableau.
  size_t frontIndex;  ///< Indice, dans le tableau, du devant.
};

///@brief Initialisation de la file de cahines de caracteresé
///@param arrayQueue file de chaines de caracteres a initialiser
///@param length Taille de la file de chaines de caracteres
void StringArrayQueueInit(struct StringArrayQueue *arrayQueue, size_t length){
  arrayQueue->length = length;
  arrayQueue->count = arrayQueue->frontIndex = 0;
  arrayQueue->array = malloc(sizeof(size_t) * length);
}

/// @brief Liberation du tableau de cahine de caractere
/// @param arrayQueue file de chaine de caracteres a liberer
void StringArrayQueueFree(struct StringArrayQueue *arrayQueue){
  free(arrayQueue->array);
}

/// @brief Enfilement d'une chaine de caracteres a la fin de la file.
/// @param arrayQueue file dans laquelle enfiler
/// @param string chaine de caracters a enfiler
void StringArrayQueuePush(struct StringArrayQueue *arrayQueue, char* string){
  if (arrayQueue->count < arrayQueue->length){
    arrayQueue->array[(arrayQueue->frontIndex + arrayQueue->count++) % arrayQueue->length] = string;
  }
}

/// @brief Defilement d'une chaine de caracteres a la fin de la file.
/// @param arrayQueue file dans laquelle defiler
void StringArrayQueuePop(struct StringArrayQueue *arrayQueue){
  if (arrayQueue->count){
    arrayQueue->frontIndex = (arrayQueue->frontIndex + 1) % arrayQueue->length;
    arrayQueue->count--;
  }
}

/// @brief Obtention de la chaine de caracteres au devant de la file
/// @param arrayQueue file a fronter
/// @return chaine de caracteres au devant de la file
char* StringArrayQueueFront(struct StringArrayQueue *arrayQueue){
  if (arrayQueue->count){
    return arrayQueue->array[arrayQueue->frontIndex];
  } 
    return "";
}

/// @brief Obtention de la chaine de caracteres au devant de la file
/// @param arrayQueue file a fronter
/// @return chaine de caracteres au derriere de la file
char* StringArrayQueueBack(struct StringArrayQueue *arrayQueue){
  if (arrayQueue->count){
    return arrayQueue->array[(arrayQueue->frontIndex + arrayQueue->count - 1) % arrayQueue->length];
  } 
    return "";
}


size_t StringArrayQueueSize(struct StringArrayQueue *arrayQueue){
  return arrayQueue->count;
}

