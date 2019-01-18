#ifndef STACK_H
#define STACK_H

template <class T>

class Stack {

private:
  T *data;
  int numElements;
  int numCapacity;

public:
  Stack();

  Stack(int numCap);

  Stack(Stack &rhs);

  void assign(Stack &rhs) {}

  int size();

  int capacity();

  bool empty();

  void clear();

  void push(T data);

  void pop();

  ~Stack();
};

Stack<T> Stack() {
  numElements = 0;
  numCapacity = 0;
  data = nullptr;
}

Stack<T> Stack(int numElements) {}

Stack<T> Stack(Stack &rhs) {}

Stack<T> ~Stack() {}

#endif /* STACK_H */
