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

Vector::Vector(void) : array_(0), size_(0), capacity_(0), allocs_(0)
{
}
Vector::~Vector(void)
{
    clear();

}

bool Vector::empty(void) const
{
  return size_ == 0;
}

unsigned Vector::size(void) const
{
  return size_;
}

unsigned Vector::capacity(void) const
{
  return capacity_;
}

unsigned Vector::allocations(void) const
{
  return allocs_;
}

void Vector::clear(void)
{
    delete[] array_;
    array_ = nullptr;
    size_ = 0;
    capacity_ = 0;
    
}

int Vector::operator[](unsigned index) const
{
    check_bounds(index);
    return array_[index];
}

int& Vector::operator[](unsigned index)
{
    check_bounds(index);
    return array_[index];
}

void Vector::push_back(int value)
{
    
    if (size_ == capacity_)
    {
        grow();
        
    }

    array_[size_] = value;
    size_ += 1;
}

void Vector::push_front(int value)
{
    if (size_ == capacity_)
    {
        grow();
    }

    unsigned rightIndex = size_-1;
    for (unsigned i = size_; i > 0; i--)
    {
        array_[i] = array_[rightIndex];
        rightIndex -= 1;
    }
    array_[0] = value;

    size_ += 1;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// private 
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

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

void Vector::grow(void)
{
    // Double the capacity
  capacity_ = (capacity_) ? capacity_ * 2 : 1;
    
    // Rest of the code here...
    

  //Instructions say allocate another int array that's twice the size of the OG array  (new int* array_ = (sizeof(int)*capacity))?
  int* array_Copy = new int[capacity_];
  //Loop through the og array and copy each of the elements into the new array
  for (unsigned i = 0; i < size_; i++)
  {
      array_Copy[i] = array_[i];
  }
  //Free the memory of the og array
  delete[] array_;
  array_ = array_Copy;
  //increment allocs_
  allocs_ += 1;
}

} // namespace CS170