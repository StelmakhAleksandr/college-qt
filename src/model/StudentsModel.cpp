#include "StudentsModel.h"

#include "../classes/RestApi.h"

StudentsModel::StudentsModel()
{
    RestApi api;
    m_students = api.fetchStudents();
    qDebug() << m_students.size();
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
        return student["firstName"].toString();
    case StudentsModelItemRole::LastNameRole:
        return student["lastName"].toString();
    case StudentsModelItemRole::PhoneNumberRole:
        return student["phoneNumber"].toString();
    case StudentsModelItemRole::EmailRole:
        return student["email"].toString();
    case StudentsModelItemRole::GroupNameRole:
        return student["groupName"].toString();
    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> StudentsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[(int)StudentsModelItemRole::FirstNameRole] = "firstName";
    roles[(int)StudentsModelItemRole::LastNameRole] = "lastName";
    roles[(int)StudentsModelItemRole::PhoneNumberRole] = "phoneNumber";
    roles[(int)StudentsModelItemRole::EmailRole] = "email";
    roles[(int)StudentsModelItemRole::GroupNameRole] = "groupName";
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
