#pragma once

#include <QObject>

class RestApi
{
public:
    RestApi();
    QJsonArray fetchStudents();
    QJsonArray fetchTeachers();

private:
    QJsonArray fetch(QUrl url);
};
