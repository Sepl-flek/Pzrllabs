#include "VectorStack.h"

void VectorStack::push(const ValueType& value) 
{
    data.push_back(value);
}

void VectorStack::pop()
{
    if(data.size() > 0)
    data.pop_back();
}

const ValueType& VectorStack::top() const
{
    return data.back();
}

bool VectorStack::isEmpty() const
{
    return data.size() <= 0;
}

size_t VectorStack::size() const 
{
    return data.size();
}