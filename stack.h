#ifndef STACK_H
#define STACK_H

template <class T>

class Stack {

private:
  T *data;
  int numElements;
  int numCapacity;

public:
  Stack() 
  {
    numElements = 0;
    numCapacity = 0;
    data = nullptr;
  }

  Stack(int numCap) 
  {
    numElements = 0;
    numCapacity = numCap;
  }

  Stack(Stack &rhs) 
  {

  }

  void assign(Stack &rhs) {}

  int size() 
  {

  }

  int capacity()
  {

  }

bool empty()
{

}

void clear()
{

}


void push(T data)
{



}


void pop()
{

}


  ~Stack();
};

#endif /* STACK_H */
