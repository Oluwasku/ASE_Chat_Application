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
//Class created to handle server database related operations */
/**
 * @brief The chat_data_manager class
 * Class created to handle server database related operations
 */
class chat_data_manager
{
private:
    QString query; /// SQL Query
    bool status;    /// Status
    QString message; /// Error or status message
    QSqlDatabase chat_sqldb;  /// instance of the database object

public:
    /**
      * @brief setquery
      * @param query
      */
     void setquery(QString  query)
     {
         this->query = query;
     }
     /**
      * @brief getquery
      * @return
      */
     QString getquery()
     {
         return query;
     }
     /**
      * @brief setstatus
      * @param status
      */
     void setstatus(bool  status)
     {
         this->status = status;
     }
     /**
      * @brief getstatus
      * @return
      */
     bool getstatus()
     {QSqlDatabase chat_sqldb;
         return status;
     }
public:
    chat_data_manager()
    {
    }

  /**
 * @brief open_db_connection: Class method to open connection to database
 * @return
 */
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

/**
* @brief close_db_connection: Class method to close connection to database
* @return
*/
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
