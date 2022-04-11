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
}

int Vector::operator[](unsigned index) const
{
    return array_[index];
}

int& Vector::operator[](unsigned index)
{
    return array_[index];
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

}

} // namespace CS170