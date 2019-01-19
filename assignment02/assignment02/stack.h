#ifndef STACK_H
#define STACK_H

namespace custom
{

template <class T>

class stack {

private:
  T *data; 
  int numElements;
  int numCapacity;
  bool isEmpty;

public:
  stack()
  {
  numElements = 0;
  numCapacity = 0;
  data = new T[numCapacity];
 }

stack(int c) 
{
  numElements = 0;
  numCapacity = c;
  data = new T[numCapacity];
}

stack(const Stack<T> &rhs) throw(const char *) {
  try {
    if (numElements != rhs.numElements) {
      data = new T[rhs.numElements];
    }

    for (int i = 0; i < rhs.size(); i++) {
      data[i] = rhs.data[i];
    }

    numCapacity = rhs.numCapacity;
    numElements = rhs.numElements;
  } catch (std::bad_alloc &er) {
    throw(" ERROR: Unable to allocate a new buffer for vector");
    exit(1);
  }
}

  // Assignment operator
  stack<T> &stack<T>::operator=(const Stack<T> &rhs) throw(const char *);

  int size() const;

  int capacity();

  bool empty();

  void clear();

  void push(const T & element);
  // I think push should look like this void push(const T & element). push is
  // looking for an int

  void pop();

  // Getter
  stack<T>::top() const throw(const char *);

  // Setter
  T &stack<T>::top() throw(const char *);

  ~stack();
};

template <class T>

int stack <T> :: size() const { return numElements; }

/*******************************************
 * Stack :: Assignment
 *******************************************/
template <class T>
stack<T> &stack<T>::operator=(const stack<T> &rhs) throw(const char *) {

  numElements = 0;
  if (rhs.size() > rhs.numCapacity()) {
    resize(rhs.size());
  }
  numElements = rhs.size();

  for (int i = 0; i < numElements - 1; i++) {
    data[i] = rhs.data[i];
  }
  // Not sure on this one
  return *this;
}

/********************************************
 * Stack : EMPTY
 * checks if the vector is empty
 *******************************************/
template <class T> 
bool stack<T>::empty() {
  if (size() == 0) {
    isEmpty = true;
  } else {
    isEmpty = false;
  }
  return isEmpty;
}

/********************************************
 * Stack : PUSH
 * Adds an element to the top of the stack,
 * thereby increasing size by one Const T
 *******************************************/

template <class T>
void stack <T> :: push(const T & element) {
  if (size() = capacity()) {
    resize(capacity() * 2);
  }
  data[numElements++] = element;
}

/********************************************
 * Stack : POP
 * Remove the top-most element in the stack,
 * thereby reducing the size by one.
 *******************************************/
template <class T>
void stack <T> :: pop() {
  if (!empty()) {
    --numElements;
  } else {
    return;
  }
}

/********************************************
 * Stack : TOP : getter
 * Returns the top-most element in the stack.
 *******************************************/
template <class T> 
stack<T>::top() const throw(const char *);
{
  if (!empty()) {
    return data[size() - 1];
  } else {
    throw "ERROR: Unable to reference the element from an empty stack";
  }
}

/********************************************
 * Stack : RESIZE
 * resizes the vector buffer
 *******************************************/
template <class T> 
int Stack<T>::resize(int capacityNew) {
  try {
    T *dataNew = new T[capacityNew];

    for (int i = 0; i < numElements; i++) {
      dataNew[i] = data[i];
    }

    data = dataNew;
    numCapacity = capacityNew;
  } catch (std::bad_alloc) {
    throw "ERROR: Unable to allocate new buffer for vector";
  }
};
} // namespace custom


#endif /* STACK_H */
