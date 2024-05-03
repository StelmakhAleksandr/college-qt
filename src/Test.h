#pragma once

#include <QDebug>
#include <QObject>

class Test : public QObject
{
    Q_OBJECT
public:
    Test();
public slots:
    void test(int a)
    {
        qDebug() << "slot test" << a;
    }
};
