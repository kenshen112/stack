#ifndef STACK_H
#define STACK_H

template <class T>

class Stack {

private:
  T *data; // this needs to be an array like data[].
  int numElements;
  int numCapacity;
  bool isEmpty;

public:
  Stack();

  Stack(int numCap);

  Stack(Stack &rhs);

  // Assignment operator
  Stack<T> &Stack<T>::operator=(const Stack<T> &rhs) throw(const char *);

  int size();

  int capacity();

  bool empty();

  void clear();

  void push(T element);
  // I think push should look like this void push(const T & element). push is
  // looking for an int

  void pop();

  // Getter
  const T &stack<T>::top() const throw(const char *);

  // Setter
  T &stack<T>::top() throw(const char *);

  ~Stack();
};

template <class T> 
Stack <T> Stack() {
  numElements = 0;
  cap = 0;
  array = new T[cap];
}

template <class T> Stack<T> Stack(int c) {
  numElements = 0;
  cap = c;
  array = new T[cap];
}

template <class T> Stack<T> Stack(const Stack<T> &rhs) throw(const char *) {
  try {
    if (maxSize != rhs.maxSize) {
      data = new T[rhs.maxSize];
    }

    for (int i = 0; i < rhs.size(); i++) {
      data[i] = rhs.data[i];
    }
    maxSize = rhs.maxSize;
    position = rhs.position;
  } catch (std::bad_alloc &er) {
    throw(" ERROR: Unable to allocate a new buffer for vector");
    exit(1);
  }
}

int size() const { return numElements; }

/*******************************************
 * Stack :: Assignment
 *******************************************/
template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs) throw(const char *) {

  numElements = 0;
  if (rhs.size() > rhs.capacity()) {
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
template <class T> bool Stack<T>::empty() {
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
 * thereby increasing size by one.
 *******************************************/
void push(T data) {
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
void pop() {
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
const T &stack<T>::top() const throw(const char *);
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
}
}
; // namespace custom

#endif /* STACK_H */
