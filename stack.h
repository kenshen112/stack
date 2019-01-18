#ifndef STACK_H
#define STACK_H

class Stack
{

};

/*******************************************
* Stack :: Assignment
*******************************************/
template <class T>
Stack <T> & Stack <T> :: operator = (const Stack <T> & rhs) throw (const char *)
{

}

/*******************************************
* Stack :: Assignment
*******************************************/
template <class T>
Stack <T> & Stack <T> :: operator = (const Stack <T> & rhs)
throw (const char *)
{

   numElements = 0;
   if (rhs.size() > rhs.capacity())
   {
      resize(rhs.size());
   }
   numElements = rhs.size();

   for (int i = 0; i < numElements - 1; i++)
   {
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
bool vector <T> ::empty()
{
   if (size() == 0)
   {
      isEmpty = true;
   }
   else
   {
      isEmpty = false;
   }
   return isEmpty;
}

/********************************************
* Stack : RESIZE
* resizes the vector buffer
*******************************************/
template <class T>
int Stack <T> ::resize(int capacityNew)
{
   try
   {
      T * dataNew = new T[capacityNew];

      for (int i = 0; i < numElements; i++)
      {
         dataNew[i] = data[i];
      }

      data = dataNew;
      numCapacity = capacityNew;
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer for vector";
   }
}

}; // namespace custom

#endif /* STACK_H */
