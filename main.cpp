#include <QCoreApplication>

#include "Counter.h"
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Counter counter1(0), counter2(1);

    QObject::connect(&counter1, &Counter::valueChanged, &counter2, &Counter::handleOperation);
    QObject::connect(&counter2, &Counter::valueChanged, &counter1, &Counter::handleOperation);

    qInfo() << "Start values:";
    qInfo() << "counter1 = " << counter1.getValue() << ", counter2 = " << counter2.getValue() << "\n";

    counter1.increment();

    qInfo() << "Values after counter1.increment():";
    qInfo() << "counter1 = " << counter1.getValue() << ", counter2 = " << counter2.getValue() << "\n";

    counter2.increment();

    qInfo() << "Values after counter2.increment():";
    qInfo() << "counter1 = " << counter1.getValue() << ", counter2 = " << counter2.getValue() << "\n";

    counter1.decrement();

    qInfo() << "Values after counter1.decrement():";
    qInfo() << "counter1 = " << counter1.getValue() << ", counter2 = " << counter2.getValue() << "\n";

    counter2.decrement();

    qInfo() << "Values after counter2.decrement():";
    qInfo() << "counter1 = " << counter1.getValue() << ", counter2 = " << counter2.getValue() << "\n";

    return a.exec();
}
