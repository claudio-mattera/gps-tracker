#ifndef APPLICATION_PATHCONTROLLER_H
#define APPLICATION_PATHCONTROLLER_H

#include <wobjectdefs.h>

#include <QGeoPositionInfoSource>
#include <QGeoPath>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

class PathController: public QObject {
    // Q_OBJECT
    W_OBJECT(PathController)

public:
    PathController(QObject *parent = 0);

    QGeoPath geoPath() const { return mGeoPath; }

    void setGeoPath(const QGeoPath &geoPath){
        if(geoPath == mGeoPath) {
            return;
        }
        mGeoPath = geoPath;
        emit geopathChanged();
    }

    void geopathChanged()
    W_SIGNAL(geopathChanged)

    QGeoCoordinate center() const { return mCenter; }

    void setCenter(const QGeoCoordinate &center){
        if(center == mCenter) {
            return;
        }
        mCenter = center;
        emit centerChanged();
    }

    void centerChanged()
    W_SIGNAL(centerChanged)

private:
    QGeoPath mGeoPath;
    QGeoCoordinate mCenter;

    W_PROPERTY(QGeoPath, geopath READ geoPath WRITE setGeoPath NOTIFY geopathChanged)
    W_PROPERTY(QGeoCoordinate, center READ center WRITE setCenter NOTIFY centerChanged)
};

#endif // APPLICATION_PATHCONTROLLER_H
