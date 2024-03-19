#include "Counter.h"

Counter::Counter(const int value) : m_value(value) {}

int Counter::getValue() const {
    return m_value;
}

void Counter::increment() {
    ++m_value;
    emit valueChanged(Operation::Increment);
}

void Counter::decrement() {
    --m_value;
    emit valueChanged(Operation::Decrement);
}

void Counter::handleOperation(const Operation& counterAction){
    if(counterAction == Operation::Increment) {
        ++m_value;
    }
    else if(counterAction == Operation::Decrement) {
        --m_value;
    }
    // ...
}
