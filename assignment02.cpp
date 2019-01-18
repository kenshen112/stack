#ifndef STACK_H
#define STACK_H

#include <cassert>

template <class T>

class Stack
{
  private:
   int  numElements;
   int cap;
   T *array;
   
  public:

   Stack()
   { 
      numElements = 0;
      cap = 0;
      array = new T[cap];      
   }
   
   Stack(int c)
   {
      numElements = 0;
      cap = c;
      array = new T[cap];      
   }

   Stack(const Stack <T> & rhs) throw (const char *);
   
   int size() const
   {
      return numElements;
   }

   T& top()
   {
      if (numElements == 0 || numElements == cap || cap == 0)
      {
         throw "ERROR: Unable to reference the element from an empty Stack";
      }

      else
      {
         return array[cap];
      }
   }
   
   int capacity() const
   {
      return cap;
   }
   
   Stack& operator= (const Stack& rhs) throw(const char*)
   {
      if (this != &rhs)
      {
         if (cap != rhs.cap)
         {
            delete [] array;

            // copy over the capacity and size
            //assert(rhs.cap >= 0 && rhs.cap <= rhs.numElements);
            cap = rhs.cap;
            numElements = rhs.numElements;
            
            assert(rhs.numElements >= 0);

            
      // do nothing if there is nothing to do
      if (rhs.numElements == 0)
      {
         numElements = 0;
         cap = 0;
         array = NULL;
      }

      // attempt to allocate
      try
      {
         array = new T[rhs.numElements];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate buffer";
      }
         }

      // copy the items over one at a time using the assignment operator
      for (int i = 0; i < cap; i++)
         array[i] = rhs.array[i];

      // the rest needs to be filled with the default value for T
      for (int i = cap; i < numElements; i++)
         array[i] = T();
      }
      
      return *this;
   }

   void push(const T& item)
   {  

// do nothing if there is nothing to do
      if (numElements == 0)
      {
         delete [] array;
         numElements++;
         array = new T[numElements];
         cap++;
         array[cap] = item;
      }
     else if (cap < numElements - 1)
      {
         cap++;
         array = new T[cap];
         array[cap] = item;
      }
      if(numElements == cap || cap > numElements)
      {
         numElements ++;
         array = new T[numElements];
         array[numElements] = item;
      }   
      else
      {
         cap++;
         array = new T[cap];
         array[cap] = item;
      }

   }

   void pop()
   {
      if (numElements == 0 || numElements == cap)
      {
         throw "ERROR: Unable to pop from an empty Stack";
      }
         
      array[cap] = T();
      cap--;
   }
   
   int empty()
   {
      if (numElements == 0)
      {
         return true;
      }

      else
      {
         return false;
      }
   }

   ~Stack()
   {
      delete [] array;
   }
};


template <class T>
Stack <T> :: Stack(const Stack <T> & rhs) throw (const char *)
{
   assert(rhs.numElements >= 0);

   // do nothing if there is nothing to do
   if (rhs.numElements == 0)
   {
      numElements = 0;
      cap = 0;
      array = NULL;
      return;
   }

   // attempt to allocate
      try
      {
         array = new T[rhs.numElements];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate buffer";
      }

      // copy over the capacity and size
      assert(rhs.cap >= 0 && rhs.cap <= rhs.numElements);
      numElements = rhs.numElements;
      cap = rhs.cap;

      // copy the items over one at a time using the assignment operator
      for (int i = 0; i < cap; i++)
         array[i] = rhs.array[i];

      // the rest needs to be filled with the default value for T
      for (int i = cap; i < numElements; i++)
         array[i] = T();
}   

#endif /* STACK_H */
