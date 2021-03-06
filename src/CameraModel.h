#ifndef CAMERAMODEL_H
#define CAMERAMODEL_H

#include <QObject>
#include <QStandardItemModel>
#include "qqmlhelpers.h"
#include <QQmlApplicationEngine>
#include "CalaosConnection.h"
#include "Common.h"
#include <QQuickImageProvider>

class CameraModel: public QStandardItemModel, public QQuickImageProvider
{
    Q_OBJECT

    QML_WRITABLE_PROPERTY(bool, cameraVisible)

public:
    CameraModel(QQmlApplicationEngine *engine, CalaosConnection *con, QObject *parent = 0);

    enum
    {
        RoleName = Qt::UserRole + 1,
        RoleId,
        RoleUrl,
    };

    void load(const QVariantMap &homeData);

    Q_INVOKABLE QObject *getItemModel(int idx);

    virtual QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
    virtual QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

private:

    QQmlApplicationEngine *engine;
    CalaosConnection *connection;
};

class CameraItem: public QObject, public QStandardItem
{
    Q_OBJECT

    QML_READONLY_PROPERTY_MODEL(QString, name, CameraModel::RoleName)
    QML_READONLY_PROPERTY_MODEL(QString, url_single, CameraModel::RoleUrl)
    QML_READONLY_PROPERTY_MODEL(QString, cameraId, CameraModel::RoleId)
    QML_WRITABLE_PROPERTY(bool, cameraVisible)

public:
    CameraItem(CalaosConnection *con);

    void load(QVariantMap &d);

    void getPictureImage(QImage &image);

    void startCamera();

signals:
    void newFrameReceived();

private slots:
    void cameraPictureDownloaded(const QString &camid, const QByteArray &data);
    void cameraPictureFailed(const QString &camid);

private:
    QVariantMap cameraData;
    CalaosConnection *connection;
    QImage currentImage;
};

#endif // CAMERAMODEL_H
