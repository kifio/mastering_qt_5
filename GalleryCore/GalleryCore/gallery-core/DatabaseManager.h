#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "AlbumDao.h"
#include "PictureDao.h"
#include <QString>

class QSqlDatabase;

const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager
{

public:
    static DatabaseManager& instance();

    ~DatabaseManager();

    const AlbumDao albumDao;
    const PictureDao pictureDao;

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    QSqlDatabase* mDatabase;

};

#endif // DATABASEMANAGER_H
