////////////////////////////////////////
// Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Instructor: Jeremy Kings (jeremy.kings@digipen.edu)
// Assignment: PRG 8.1.7 CORE ASSIGNMENT: Vector Container Class Part 3
// Course: WANIC VGP2
////////////////////////////////////////



#include <iostream>  // cout
#include <cstdlib>   // abort
#include "Vector.h"

namespace CS170
{
//This function constructs a vector with all the member variables initialized to 0 
 template <typename T>
Vector<T>::Vector(void) : array_(0), size_(0), capacity_(0), allocs_(0)
{
}

//This function constructs a vector. size_ and capacity_ get initialized to the size argument, allocs gets set to 1, and each of the passed in array values are stored in the array_ member.
template <typename T>
Vector<T>::Vector(const T array[], unsigned size) :  size_(size), capacity_(size), allocs_(0)
{
    array_ = new T[capacity_];
    for (unsigned i = 0; i < size_; i++)
    {
        array_[i] = array[i];
    }
    allocs_ += 1;
    
}
//This is for initializing a Vector with the data of another Vector. The only difference should be in the allocs and the capacity_ of the newly constructed Vector as everything else is supposed to be the same.
template <typename T>
Vector<T>::Vector(const Vector& rhs) : size_(rhs.size()), capacity_(size_), allocs_(1)
{
    array_ = new T[capacity_];
    for (unsigned i = 0; i < rhs.size_; i++)
    {
        array_[i] = rhs.array_[i];
    }
}
//A destructor that calls clar
template <typename T>
Vector<T>::~Vector(void)
{
    clear();

}
//Deletes and null points array_, and sets size_ and capacity_ to 0.
template <typename T>
void Vector<T>::clear(void)
{
    delete[] array_;
    array_ = nullptr;
    size_ = 0;
    capacity_ = 0;
    
    
}
//I don't remember if I did this one but this one checks if size_ == 0
template <typename T>
bool Vector<T>::empty(void) const
{
  return size_ == 0;
}

//Removes a value from the Vector array_
//Params: value, the value that the user wants removed from the array (NOT THE INDEX OF THE VALUE)
template <typename T>
void Vector<T>::remove(T value)
{
    //Might need to declare a variable to store the index where value is before the loop starts
    unsigned valueIndex = 0;
    //Loop through array_ until array_ item is found with int equal to value
    for (unsigned i = 0; i < size_; i++)
    {
        //Break loop once the equal is found
        if (array_[i] == value)
        {
            valueIndex = i;
            break;
        }
    }

    //Decrease size_ here
    size_ -= 1;
    //Loop through the rest of the array (NOT THE ENTIRE ARRAY, THE REST OF IT FROM THE INDEX WHERE VALUE IS) and equate array_[index] to array_[index + 1]
    for (unsigned i = valueIndex; i < size_; i++)
    {
        array_[i] = array_[i + 1];
    }
}

//Inserts a new item in the the Vector array_
//Params:
//  value: The value the user wants inserted
//  position: The index of array_ in which the user wants value inserted
template <typename T>
void Vector<T>::insert(T value, unsigned position)
{
    if (size_ == capacity_)
    {
        grow();
    }

    for (unsigned i = size_; i > position; i--)
    {
        array_[i] = array_[i - 1]; 
    }

    array_[position] = value;
    size_ += 1;
}

//Gets the user access to size_
template <typename T>
unsigned Vector<T>::size(void) const
{
  return size_;
}

//Gets the user access to capacity_
template <typename T>
unsigned Vector<T>::capacity(void) const
{
  return capacity_;
}
//Gets the user access to allocs_
template <typename T>
unsigned Vector<T>::allocations(void) const
{
  return allocs_;
}
//Inserts a new value at the end of the Vector array_
// Params: 
// value: the value the user wants to insert into the array
template <typename T>
void Vector<T>::push_back(T value)
{

    if (size_ == capacity_)
    {
        grow();

    }

    array_[size_] = value;
    size_ += 1;
}

//Inserts a new value into the front of the array
// Params:
// value: The value the user wants to insert into the array
template <typename T>
void Vector<T>::push_front(T value)
{
    if (size_ == capacity_)
    {
        grow();
    }

    //I diffed the output from this implementation against the master output and the files were identical even though I'm confused about the pseudocode of this. Isn't array_[size_-1] the left index to the first element that the array goes through in the array? How does this implementation shift the elements rightwards?
    
    for (unsigned i = size_; i > 0; i--)
    {
        array_[i] = array_[i-1];
        
    }
    array_[0] = value;

    size_ += 1;
}

//Removes the last value from the Vector array_
template <typename T>
void Vector<T>::pop_back(void)
{
    size_ -= 1;
    
}

//Removes the first value from the Vector array_
template <typename T>
void Vector<T>::pop_front(void)
{
    
    for (unsigned i = 0; i < size_-1; i++)
    {
        array_[i] = array_[i+1];
        
    }
    size_ -= 1;

    return;
}


template <typename T>
void Vector<T>::swapv(Vector& other)
{
    Vector otherCopy = Vector(other);
    other = *this;
    other.capacity_ = this->capacity_;
    other.allocs_ = this->allocs_;
    *this = otherCopy;
    this->capacity_ = otherCopy.capacity_;
    this->allocs_ = otherCopy.allocs_;
}
//Operators

//This one returns the value at array_[index] if the index is valid. A version made for const Vectors
template <typename T>
T Vector<T>::operator[](unsigned index) const
{
    check_bounds(index);
    return array_[index];
}
//This is identical to the previous operator but for non const value access
template <typename T>
T& Vector<T>::operator[](unsigned index)
{
    check_bounds(index);
    return array_[index];
}




//Basically appends rhs onto the end of this Vector
template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& rhs)
{
    unsigned loopNum = rhs.size_;
    for (unsigned i = 0; i < loopNum; i++)
    {
        push_back(rhs.array_[i]);
    }

    return *this;
}
//Returns the connection of this Vector and rhs Vector. I think this one's primarily intended to be used when initializing other Vectors as the sums of two different Vectors
template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& rhs) const
{
    
    Vector newVector;
    newVector +=  *this;
    newVector += rhs;
    return newVector;
}
//This assigns rhs array_ data (ADDRESS CONTENT, I DON'T MEAN THE POINTERS THEMSELVES)to this Vector.
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) 
{
    if (this == &rhs) 
    {
        return *this;
    }
    size_ = 0;
    if (capacity_ < rhs.capacity_)
    {
        delete[] array_;
        capacity_ = rhs.size_;
        array_ = new T[capacity_];
        allocs_ += 1;
    }
    
    
    
    
    for (unsigned i = 0; i < rhs.size_; i++)
    {
        push_back(rhs[i]);
    }

    return *this;
    
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// private (I DID NOT WORK ON ANY OF THESE FUNCTIONS)
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <typename T>
void Vector<T>::check_bounds(unsigned index) const
{
    // Don't have to check for < 0 because index is unsigned
  if (index >= size_)
  {
    std::cout << "Attempting to access index " << index << ".";
    std::cout << " The size of the array is " << size_ << ". Aborting...\n";
    std::abort();
  }
}
template <typename T>
void Vector<T>::grow(void)
{
    // Double the capacity
  capacity_ = (capacity_) ? capacity_ * 2 : 1;
    
    
    

  
  T* array_Copy = new T[capacity_];
  
  for (unsigned i = 0; i < size_; i++)
  {
      array_Copy[i] = array_[i];
  }
  
  delete[] array_;
 
  array_ = array_Copy;
  
  allocs_ += 1;
}

} // namespace CS170