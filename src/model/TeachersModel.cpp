#include "TeachersModel.h"

#include "../classes/RestApi.h"

namespace {
constexpr auto FirstName = "firstName";
constexpr auto LastName = "lastName";
constexpr auto PhoneNumber = "phoneNumber";
constexpr auto Email = "email";
constexpr auto DepartmentName = "departmentName";
}

TeachersModel::TeachersModel()
{
    RestApi api;
    m_teachers = api.fetchTeachers();
}

int TeachersModel::rowCount(const QModelIndex& parent) const
{
    return m_teachers.size();
}

QVariant TeachersModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= rowCount())
        return QVariant();
    QJsonObject teacher = m_teachers[index.row()].toObject();
    StudentsModelItemRole studentRole = (StudentsModelItemRole)role;
    switch (studentRole) {
    case StudentsModelItemRole::FirstNameRole:
        return teacher[FirstName].toString();
    case StudentsModelItemRole::LastNameRole:
        return teacher[LastName].toString();
    case StudentsModelItemRole::PhoneNumberRole:
        return teacher[PhoneNumber].toString();
    case StudentsModelItemRole::EmailRole:
        return teacher[Email].toString();
    case StudentsModelItemRole::DepartmentNameRole:
        return teacher[DepartmentName].toString();
    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> TeachersModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[(int)StudentsModelItemRole::FirstNameRole] = FirstName;
    roles[(int)StudentsModelItemRole::LastNameRole] = LastName;
    roles[(int)StudentsModelItemRole::PhoneNumberRole] = PhoneNumber;
    roles[(int)StudentsModelItemRole::EmailRole] = Email;
    roles[(int)StudentsModelItemRole::DepartmentNameRole] = DepartmentName;
    return roles;
}
