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

Vector::Vector(const int array[], unsigned size) :  size_(size), capacity_(size), allocs_(0)
{
    array_ = new int[capacity_];
    for (unsigned i = 0; i < size_; i++)
    {
        array_[i] = array[i];
    }
    allocs_ += 1;
    
}

Vector::Vector(const Vector& rhs) : size_(rhs.size()), capacity_(size_), allocs_(1)
{
    array_ = new int[capacity_];
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

void Vector::remove(int value)
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

    //Decrease size_ here?
    size_ -= 1;
    //Loop through the rest of the array (NOT THE ENTIRE ARRAY, THE REST OF IT FROM THE INDEX WHERE VALUE IS) and equate array_[index] to array_[index + 1]
    for (unsigned i = valueIndex; i < size_; i++)
    {
        array_[i] = array_[i + 1];
    }
}

void Vector::insert(int value, unsigned position)
{
    if (size_ == capacity_)
    {
        grow();
    }

    for (unsigned i = size_; i > position; i--)
    {
        array_[i] = array_[i - 1]; //Wrong
    }

    array_[position] = value;
    size_ += 1;
}

//Getters
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
    
    for (unsigned i = size_; i > 0; i--)
    {
        array_[i] = array_[i-1];
        
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
    
    for (unsigned i = 0; i < size_-1; i++)
    {
        array_[i] = array_[i+1];
        
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
    unsigned loopNum = rhs.size_;
    for (unsigned i = 0; i < loopNum; i++)
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
    if (this == &rhs) 
    {
        return *this;
    }
    size_ = 0;
    if (capacity_ < rhs.capacity_)
    {
        delete[] array_;
        capacity_ = rhs.size_;
        array_ = new int[capacity_];
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