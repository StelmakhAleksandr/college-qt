#pragma once

#include <QObject>

class RestApi
{
public:
    RestApi();
    QJsonArray fetchStudents();
};
