////////////////////////////////////////
// Author: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
// Instructor: Jeremy Kings (jeremy.kings@digipen.edu)
// Assignment:PRG 8.1.1 CORE ASSIGNMENT: Vector Container Class Part 1, PRG 8.1.4 CORE ASSIGNMENT: Vector Container Class Part 2
// Course: WANIC VGP2
////////////////////////////////////////



#include <iostream>  // cout
#include <cstdlib>   // abort
#include "Vector.h"

namespace CS170
{
//Constructors and Destructor 
Vector::Vector(void) : array_(0), size_(0), capacity_(0), allocs_(0)
{
}

Vector::Vector(const int array[], unsigned size) : size_(size), capacity_(size), allocs_(0)
{
    *array_ = *array;
}

Vector::Vector(const Vector& rhs) : size_(rhs.size()), capacity_(rhs.capacity()), allocs_(rhs.allocations())
{
    array_ = new int(capacity_);
    for (unsigned i = 0; i < rhs.size_; i++)
    {
        array_[i] = rhs.array_[i];
    }
}
Vector::~Vector(void)
{
    clear();

}

void Vector::clear(void)
{
    delete[] array_;
    array_ = nullptr;
    size_ = 0;
    capacity_ = 0;
    
}

bool Vector::empty(void) const
{
  return size_ == 0;
}

unsigned Vector::size(void) const
{
  return size_;
}

//Getters
unsigned Vector::capacity(void) const
{
  return capacity_;
}

unsigned Vector::allocations(void) const
{
  return allocs_;
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

    //I diffed the output from this implementation against the master output and the files were identical even though I'm confused about the pseudocode of this. Isn't array_[size_-1] the left index to the first element that the array goes through in the array? How does this implementation shift the elements rightwards?
    unsigned rightIndex = size_ - 1;
    for (unsigned i = size_; i > 0; i--)
    {
        array_[i] = array_[rightIndex];
        rightIndex -= 1;
    }
    array_[0] = value;

    size_ += 1;
}

void Vector::pop_back(void)
{
    size_ -= 1;
    
}

void Vector::pop_front(void)
{
    unsigned rightIndex = size_ - 1;
    for (unsigned i = 0; i < size_; i++)
    {
        array_[i] = array_[rightIndex];
        rightIndex += 1;
    }
    size_ -= 1;

    return;
}

//Operators
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





Vector& Vector::operator+=(const Vector& rhs)
{
    for (unsigned i = 0; i < rhs.size_; i++)
    {
        push_back(rhs.array_[i]);
    }

    return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
    
    Vector newVector;
    newVector +=  *this;
    newVector += rhs;
    return newVector;
}

Vector& Vector::operator=(const Vector& rhs) 
{
    size_ = rhs.size();
    capacity_ = rhs.capacity();
    allocs_ = rhs.allocations();

    for (unsigned i = 0; i < size_; i++)
    {
        push_back(rhs[i]);
    }

    return *this;
    
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