#ifndef STACK_H
#define STACK_H

namespace custom {

template <class T> class stack {

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

  stack(const stack<T> &rhs)  
  {
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
   //stack <T> & stack <T> :: operator = (const stack <T> & rhs) throw(const char *);
  //stack <T> & stack <T> :: operator =(const stack <T> & rhs) throw(const char *);
  
  int size() const { return numElements; }
  int capacity();

  bool empty();

  void clear();

  void push(const T &element);

  void pop();

  // Getter
  T top() const;

  // Setter
  T top();

  
  /*******************************************
   * Stack :: Assignment
   *******************************************/
  stack <T> operator = (const stack <T> & rhs) 
  {

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
  int resize(int capacityNew);
  ~stack(){

   clear();
  }
};


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
void stack<T>::push(const T &element) {
  if (size() == capacity()) {
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
void stack<T>::pop() {
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
T stack<T>::top() const {
  if (!empty()) {
    return data[numElements - 1];
  } else {
    throw "ERROR: Unable to reference the element from an empty stack";
  }
}

template <class T> 
T stack<T>::top() {
  if (!empty()) {
    return data[numElements - 1];
  } else {
    throw "ERROR: Unable to reference the element from an empty stack";
  }
}

/********************************************
 * Stack : RESIZE
 * resizes the vector buffer
 *******************************************/
template <class T> 
int stack<T>::resize(int capacityNew) {
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

template <class T>
void stack <T> :: clear()
{
    data = nullptr;
    delete[] data;
    numElements = 0;
    numCapacity = 0;
}



} // namespace custom

#endif /* STACK_H */
