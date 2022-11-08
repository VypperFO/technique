template <typename T>
class ArrayStack
{
  T *array;
  unsigned long topIndex;
  unsigned long length;

public:
  // Constructeur
  ArrayStack(unsigned long length)
  {
    // Initialiser les donnees membres;
    array = new T[length];
    this->length = length;
    topIndex = 0;
  }

  // Destruction
  ~ArrayStack()
  {
    delete[] array;
  }

  void push(T data)
  {
  }
};
