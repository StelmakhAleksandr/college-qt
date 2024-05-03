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
    QNetworkAccessManager manager;
    QEventLoop loop;
    QUrl url("https://college.eboard.games/students");
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
