#pragma once

#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "model/StudentsModel.h"

class App : public QObject
{
    Q_OBJECT
public:
    App(int argc, char* argv[]);
    int run();
signals:
    void test(int);

private:
    void initSignals();

private:
    QGuiApplication m_app;
    QQmlApplicationEngine m_engine;
    StudentsModel m_studentsModel;
};
