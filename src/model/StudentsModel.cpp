#include "StudentsModel.h"

#include "../classes/RestApi.h"

namespace {
constexpr auto FirstName = "firstName";
constexpr auto LastName = "lastName";
constexpr auto PhoneNumber = "phoneNumber";
constexpr auto Email = "email";
constexpr auto GroupName = "groupName";
}

StudentsModel::StudentsModel()
{
    RestApi api;
    m_students = api.fetchStudents();
}

int StudentsModel::rowCount(const QModelIndex& parent) const
{
    return m_students.size();
}

QVariant StudentsModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= rowCount())
        return QVariant();
    QJsonObject student = m_students[index.row()].toObject();
    StudentsModelItemRole studentRole = (StudentsModelItemRole)role;
    switch (studentRole) {
    case StudentsModelItemRole::FirstNameRole:
        return student[FirstName].toString();
    case StudentsModelItemRole::LastNameRole:
        return student[LastName].toString();
    case StudentsModelItemRole::PhoneNumberRole:
        return student[PhoneNumber].toString();
    case StudentsModelItemRole::EmailRole:
        return student[Email].toString();
    case StudentsModelItemRole::GroupNameRole:
        return student[GroupName].toString();
    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> StudentsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[(int)StudentsModelItemRole::FirstNameRole] = FirstName;
    roles[(int)StudentsModelItemRole::LastNameRole] = LastName;
    roles[(int)StudentsModelItemRole::PhoneNumberRole] = PhoneNumber;
    roles[(int)StudentsModelItemRole::EmailRole] = Email;
    roles[(int)StudentsModelItemRole::GroupNameRole] = GroupName;
    return roles;
}

void StudentsModel::editModel(int row)
{
    // m_data[row].name = QString("edited");
    // m_data[row].color = QString("green");
    // updateRow(row);
}

void StudentsModel::updateRow(int row)
{
    auto index = this->index(row, 0);
    emit dataChanged(index, index);
}
