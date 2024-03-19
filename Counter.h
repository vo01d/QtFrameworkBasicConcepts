#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

enum class Operation {
    Increment,
    Decrement
    // other operations
};

class Counter : public QObject {
    Q_OBJECT
public:
    Counter(int = 0);

    int getValue() const;
    void increment();
    void decrement();

signals:
    void valueChanged(const Operation&);

public slots:
    void handleOperation(const Operation&);

private:
    int m_value;
};

#endif // COUNTER_H
