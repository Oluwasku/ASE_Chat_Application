#ifndef CHAT_PARTICIPANT_H
#define CHAT_PARTICIPANT_H
#endif // CHAT_PARTICIPANT_H
#include <iostream>
#include <QDateTime>
#include <QAbstractListModel>
#include <QStringList>
#include <QStringListModel>
#include "chat_data_manager.cpp"
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQuery>
#include <QtGlobal>
#include <QDateTime>
#include <QCryptographicHash>
#include <QDataStream>
#include <QList>

using namespace std;

/**
 * @brief The chat_participant class
 * Represents the chat participant or chat user object.
 *
 */

class chat_participant
{
private:
    int chat_participant_ID;
    QString firstname;
    QString lastname;
    QString username;
    QString email;
    QString password;
    QString picture;
    QDateTime creation_date = QDateTime::currentDateTime();

public:
    /**
     * @brief getchat_participant_ID
     * @return
     */
    int getchat_participant_ID()
    {
        return chat_participant_ID;
    }
    /**
     * @brief setfirstname
     * @param chat_participant_ID
     */

    void setfirstname(int  chat_participant_ID)
    {
        this->chat_participant_ID = chat_participant_ID;
    }
    /**
     * @brief getfirstname
     * @return
     */
    QString getfirstname()
    {
        return firstname;
    }
    /**
     * @brief setfirstname
     * @param firstname
     */
    void setfirstname(QString  firstname)
    {
        this->firstname = firstname;
    }
    /**
     * @brief getlastname
     * @return
     */
    QString getlastname()
    {
        return lastname;
    }
    /**
     * @brief setlastname
     * @param lastname
     */
    void setlastname(QString  lastname)
    {
        this->lastname = lastname;
    }
    /**
     * @brief getusername
     * @return
     */
    QString getusername()
    {
        return username;
    }
    /**
     * @brief setusername
     * @param username
     */
    void setusername(QString  username)
    {
        this->username = username;
    }
    /**
     * @brief getpicture
     * @return
     */
    QString getpicture()
    {
        return picture;
    }
    /**
     * @brief setpicture
     * @param picture
     */
    void setpicture(QString  picture)
    {
        this->picture = picture;
    }
    /**
     * @brief getemail
     * @return
     */
    QString getemail()
    {
        return email;
    }
    /**
     * @brief setemail
     * @param email
     */
    void setemail(QString  email)
    {
        this->email = email;
    }
    /**
     * @brief getpassword
     * @return
     */
    QString getpassword()
    {
        return password;
    }
    /**
     * @brief setpassword
     * @param password
     */
    void setpassword(QString  password)
    {
        this->password = password;
    }
    /**
     * @brief getcreation_date
     * @return
     */
    QDateTime getcreation_date()
    {
        return creation_date;
    }
    /**
     * @brief setcreation_date
     * @param creation_date
     */
    void setcreation_date(QDateTime creation_date)
    {
        this->creation_date = creation_date;
    }

    /**
     * @brief upload_Picture
     */
    void upload_Picture();
    /**
     * @brief load_all_Contacts
     */
    void load_all_Contacts();
    /**
     * @brief chat_participant_login
     * @return
     */
    bool chat_participant_login();
    /**
     * @brief view_active_contacts
     * @return
     */
    QStringList view_active_contacts();

    /**
     * @brief password_encryption
     * @param password
     */
    void password_encryption(QString password)
    {

    }

    /**
     * @brief chat_participant_login
     * @param username
     * @param password
     * @return
     */
    int chat_participant_login(QString username, QString password)
    {
       int rowcount = -1;
       int user_id = -1;
       //QString user_id;
        chat_data_manager data_manager;
        try
        {
            if (data_manager.open_db_connection())
            {
                QSqlQuery query;
                query.prepare("SELECT * FROM tb_chat_participant where "
                              "username='"+username+"' and password='"+password+"'");
                if (query.exec() == true)
                {
                    rowcount = query.size();
                    while (query.next())
                    {
                        user_id = query.value(0).toInt();
                     }
                }
                else
                {
                    user_id = 0;
                }
            }
        }
        catch (QException &ex)
        {
            qDebug() << "DB connection not opened";

        }
        data_manager.close_db_connection();
        return user_id;
        }


//
    /**
 * @brief submit_profile - Class method to submit new chat participant profile
 * @param username
 * @param fullname
 * @param email
 * @param password
 * @return
 */
bool submit_profile(QString username, QString fullname, QString email, QString password)
 {
    chat_participant new_chat_perticipant;
    chat_data_manager data_manager;
    bool status = false;
    try
    {
        if (data_manager.open_db_connection() == true)
        {
            QSqlQuery query;
            query.prepare("INSERT INTO tb_chat_participant (username, fullname, email, password, creation_date)"
                          "VALUES ("
                          "'" + username +"', "
                          "'" + fullname +"', "
                          "'" + email +"', "
                          "'" + password +"', "
                          "datetime('now'))");

            if (query.exec() == true)
            {
                status = true;
            }
            else
            {
                status = false;
            }
        }
        else
        {
            qDebug() << "profile could not be submitted";
        }
    }
    catch (QException &ex)
    {
        qDebug() << " +"; ex ;
    }
     data_manager.close_db_connection();
    return status;
}

/**
 * @brief update_profile
 * @param chat_participant_ID
 * @param username
 * @param fullname
 * @param email
 * @param password
 * @return
 */
bool update_profile(int chat_participant_ID, QString username, QString fullname, QString email, QString password)
{
    chat_participant new_chat_perticipant;
    chat_data_manager data_manager;
    QString str_chat_participant_ID = QString::number(chat_participant_ID);
    bool status = false;
    try
    {
        if (data_manager.open_db_connection())
        {
            QSqlQuery query;
            query.prepare("UPDATE tb_chat_participant SET username='"+username+"', fullname='"+fullname+"', "
                          "username='"+email+"', password='"+password+"', "
                          "creation_date=datetime('now') WHERE chat_participant_ID='"+str_chat_participant_ID+"'");

            if (query.exec())
            {
                status = true;
            }
            else
            {
                status = false;
            }
        }
        else
        {
            qDebug() << "profile could not be submitted";
        }
    }
    catch (QException &ex)
    {
        qDebug() << " +"; ex ;
    }
     data_manager.close_db_connection();
    return status;
}

/**
 * @brief load_all_Contacts
 * @param chat_sender_ID
 * @return
 */
QListData load_all_Contacts(int chat_sender_ID)
{
    chat_data_manager data_manager;
    QString str_chat_participant_ID = QString::number(chat_sender_ID);
    QListData list;
    try
    {
        if (data_manager.open_db_connection())
        {
            QSqlQuery query;
            query.prepare("select * FROM tb_chat_message WHERE chat_sender_ID = '"+str_chat_participant_ID+"'");
            query.exec();

         }
        else
        {
            qDebug() << "DB connection not opened";
        }
    }
    catch (QException &ex)
    {
        qDebug() << "DB connection not opened";
    }
    data_manager.close_db_connection();
        return list;
}


};



