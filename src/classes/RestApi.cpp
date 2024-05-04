#include "RestApi.h"

#include <QCoreApplication>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

RestApi::RestApi()
{
}

QJsonArray RestApi::fetchStudents()
{
    return fetch(QUrl("https://college.eboard.games/students"));
}

QJsonArray RestApi::fetchTeachers()
{
    return fetch(QUrl("https://college.eboard.games/teachers"));
}

QJsonArray RestApi::fetch(QUrl url)
{
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkRequest request(url);

    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);

    QNetworkReply* reply = manager.get(request);
    loop.exec();

    if (reply->error()) {
        qDebug() << "Request failed, " << reply->errorString();
        reply->deleteLater();
        return QJsonArray();
    }

    QString answer = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
    QJsonArray jsonArray = jsonResponse.array();

    reply->deleteLater();
    return jsonArray;
}
