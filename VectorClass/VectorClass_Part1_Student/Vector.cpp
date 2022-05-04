////////////////////////////////////////
// Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Instructor: Jeremy Kings (jeremy.kings@digipen.edu)
// Assignment:PRG 8.1.1 CORE ASSIGNMENT: Vector Container Class Part 1
// Course: WANIC VGP2
////////////////////////////////////////



#include <iostream>  // cout
#include <cstdlib>   // abort
#include "Vector.h"

namespace CS170
{
//A default constructor that sets the array_, size_, capacity_, and allocs_ members to 0
Vector::Vector(void) : array_(0), size_(0), capacity_(0), allocs_(0)
{
}
//A destructor that deletes array_ and sets the size_ and capacity_ to 0
Vector::~Vector(void)
{
    clear();

}

//This function checks if size_ is equal to 0 or not
bool Vector::empty(void) const
{
  return size_ == 0;
}
//This function is a getter for size_
unsigned Vector::size(void) const
{
  return size_;
}
//This function is a getter for capacity_
unsigned Vector::capacity(void) const
{
  return capacity_;
}
//This function is a getter for allocs_
unsigned Vector::allocations(void) const
{
  return allocs_;
}
//See destructor
void Vector::clear(void)
{
    delete[] array_;
    array_ = nullptr;
    size_ = 0;
    capacity_ = 0;
    
}
//This accesses a Vector's array_ values
// Params: index: The index of array_ the user wants to access
// Returns: The value at array_[index]
int Vector::operator[](unsigned index) const
{
    check_bounds(index);
    return array_[index];
}
//This accesses a Vector's array_ values
// Params: index: The index of array_ the user wants to access
// Returns: The value at array_[index]
//The big difference between this one and the last one are that the last one is specialized for const Vectors. There isn't really a difference as far as the implementation goes
int& Vector::operator[](unsigned index)
{
    check_bounds(index);
    return array_[index];
}

//Inserts a new array_ value at the end of the array.
// Params: value: The value that the user wants stored in the array_'s end
void Vector::push_back(int value)
{
    
    if (size_ == capacity_)
    {
        grow();
        
    }

    array_[size_] = value;
    size_ += 1;
}
//Inserts a new array_ value at the beginning of the array
// Params: value: The value that the user wants stored in the array_'s beginning
void Vector::push_front(int value)
{
    if (size_ == capacity_)
    {
        grow();
    }

    //Thanks for the comments about this one! It really simplified it.
    
    for (unsigned i = size_; i > 0; i--)
    {
        array_[i] = array_[i - 1];
    }
    array_[0] = value;

    size_ += 1;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// private 
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//This function checks if a user specified index is actually in a Vector array_ or not
//Params
//  index: The index that the user wants to test.
void Vector::check_bounds(unsigned index) const
{
    // Don't have to check for < 0 because index is unsigned
  if (index >= size_)
  {
    std::cout << "Attempting to access index " << index << ".";
    std::cout << " The size of the array is " << size_ << ". Aborting...\n";
    std::abort();
  }
}
//This function increases the maximum storage capacity of the Vector array_ member. It also needs to update the number of allocs_ during each call.
void Vector::grow(void)
{
    // Double the capacity
  capacity_ = (capacity_) ? capacity_ * 2 : 1;
    
    
    

  
  int* array_Copy = new int[capacity_];
  
  for (unsigned i = 0; i < size_; i++)
  {
      array_Copy[i] = array_[i];
  }
  
  delete[] array_;
 
  array_ = array_Copy;
  
  allocs_ += 1;
}

} // namespace CS170