#pragma once
#include "StackImplementation.h"
#include <vector>

class VectorStack : public IStackImplementation
{
public:
    void push(const ValueType& value) override;
    // удаление с хвоста
    void pop() override;
    // посмотреть элемент в хвосте
    const ValueType& top() const override;
    // проверка на пустоту
    bool isEmpty() const override;
    // размер 
    size_t size() const override;
    // виртуальный деструктор
    
    private:
    std::vector<ValueType> data;
};