#ifndef CHAT_DB_CONNECTION_H
#define CHAT_DB_CONNECTION_H
#endif // CHAT_PARTICIPANT_H
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


class chat_db_connection
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

     chat_db_connection();
     //bool open_db_connection();
     //bool close_db_connection();



//QSqlDatabase chat_sqldb;
bool open_db_connection()
{
    try
    {
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

