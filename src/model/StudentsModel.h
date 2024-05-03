#pragma once

#include <QAbstractListModel>
#include <QByteArray>
#include <QHash>
#include <QJsonArray>
#include <QJsonObject>
#include <QObject>
#include <QVector>

class StudentsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum class StudentsModelItemRole
    {
        FirstNameRole = Qt::UserRole + 1,
        LastNameRole,
        PhoneNumberRole,
        EmailRole,
        GroupNameRole
    };

    StudentsModel();
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void editModel(int row);
    void updateRow(int row);

private:
    QJsonArray m_students;
};
