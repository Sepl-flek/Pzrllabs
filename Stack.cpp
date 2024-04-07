#include "Stack.h"
#include "ListStack.h"
#include "VectorStack.h"

Stack::Stack(StackContainer container): _containerType(container)
{
    if(container == StackContainer::Vector)
    {
        _pimpl = new VectorStack();
    }
    else if(container == StackContainer::List)
    {
        _pimpl = new ListStack();
    }
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container):_containerType(container)
{
    if(container == StackContainer::Vector)
    {
        _pimpl = new VectorStack();
    }
    else if(container == StackContainer::List)
    {
        _pimpl = new ListStack();
    }
    for(int i = 0; i < arraySize; ++i)
    {
        _pimpl->push(valueArray[i]);
    }
}
Stack::Stack(const Stack& copyStack):_containerType(copyStack._containerType)
{
    *this = copyStack;
}

Stack& Stack::operator=(const Stack& copyStack)
{
    if (this != &copyStack) {
        delete _pimpl;
        _containerType = copyStack._containerType;
        if(_containerType == StackContainer::Vector) 
            _pimpl = new VectorStack(*dynamic_cast<VectorStack*>(copyStack._pimpl));
        else if (_containerType == StackContainer::List)
            _pimpl = new ListStack(*dynamic_cast<ListStack*>(copyStack._pimpl));
    }
    return *this;
}

Stack::Stack(Stack&& moveStack) noexcept : _pimpl(moveStack._pimpl), _containerType(moveStack._containerType){
    *this = std::move(moveStack);
}

Stack& Stack::operator=(Stack&& moveStack) noexcept {
    if (this != &moveStack) {
        delete _pimpl;
        _pimpl = moveStack._pimpl;
        _containerType = moveStack._containerType;
        moveStack._pimpl = nullptr;
    }
    return *this;
}

Stack::~Stack()
{
    delete _pimpl;
}

void Stack::push(const ValueType& value) 
{ 
    _pimpl->push(value); 
}
void Stack::pop() 
{ 
_pimpl->pop(); 
}
const ValueType& Stack::top() const {
return _pimpl->top();
}
bool Stack::isEmpty() const {
return _pimpl->isEmpty();
}
size_t Stack::size() const {
return _pimpl->size(); 
}