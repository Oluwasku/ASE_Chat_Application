#ifndef CHAT_DATA_MANAGER_H
#define CHAT_DATA_MANAGER_H

#include <iostream>
#include <chat_db_connection.h>
#include <QDateTime>
#include <QAbstractListModel>
#include <QStringList>
#include <QStringListModel>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QException>

using namespace std;


class chat_data_manager
{
private:
    QString query;
    bool status;
    QString message;
    QSqlDatabase chat_sqldb;

public:
     void setquery(QString  query)
     {
         this->query = query;
     }

     QString getquery()
     {
         return query;
     }

     void setstatus(bool  status)
     {
         this->status = status;
     }

     bool getstatus()
     {QSqlDatabase chat_sqldb;
         return status;
     }
public:
    chat_data_manager()
    {
    }
     //bool open_db_connection();
     //bool close_db_connection();


bool open_db_connection()
{
    try
    {
        QSqlDatabase chat_sqldb;
        QString status;
        chat_sqldb = QSqlDatabase::addDatabase("QSQLITE");
        chat_sqldb.setDatabaseName("/home/ntu-admin/Downloads/myDB/testsqlie.db");
        if (chat_sqldb.open())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (QException &ex)
    {
        qDebug() << "DB connection not opened";
    }

}

bool close_db_connection()
{
    try
    {
        QSqlDatabase chat_sqldb;
        chat_sqldb.close();
        chat_sqldb.removeDatabase(QSqlDatabase::defaultConnection);
        return true;
    }
    catch (QException &ex)
    {
       qDebug() << "DB connection not opened";
        return false;
    }
}

};

#endif // CHAT_DATA_MANAGER_H
