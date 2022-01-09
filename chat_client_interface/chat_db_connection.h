#ifndef CHAT_DB_CONNECTION_H
#define CHAT_DB_CONNECTION_H

#include <iostream>
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
    int query_ID;
    string connection;

public:

     chat_db_connection();
     QString open_db_connection();
     QString close_db_connection();
     //QStringList getrecord(int query_ID);


    void setquery_ID(int  query_ID)
    {
        this->query_ID = query_ID;
    }


/*
    QSqlDatabase chat_sqldb;

    QString open_db_connection()
    {
        try
        {
            QString status;
            chat_sqldb = QSqlDatabase::addDatabase("QSQLITE");
            chat_sqldb.setDatabaseName("/home/ntu-admin/repositories/sqlitestudio/SQLiteStudio/ASE_Chat_DB");
            if (chat_sqldb.open() == true)
            {
                status = "Connection to DB opened successfully";
                return status;
            }
            else
            {
                 status = "Connection to DB failed";
                //return false;
                 return status;
            }
        }
        catch (QException &ex)
        {
            cout << &ex << endl;
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
            cout << &ex << endl;
            return false;
        }
    }
    */

};


#endif // CHAT_DB_CONNECTION_H
