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

using namespace std;


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

    int getchat_participant_ID()
    {
        return chat_participant_ID;
    }

    void setfirstname(int  chat_participant_ID)
    {
        this->chat_participant_ID = chat_participant_ID;
    }

    QString getfirstname()
    {
        return firstname;
    }

    void setfirstname(QString  firstname)
    {
        this->firstname = firstname;
    }

    QString getlastname()
    {
        return lastname;
    }

    void setlastname(QString  lastname)
    {
        this->lastname = lastname;
    }

    QString getusername()
    {
        return username;
    }

    void setusername(QString  username)
    {
        this->username = username;
    }

    QString getpicture()
    {
        return picture;
    }

    void setpicture(QString  picture)
    {//ui->label_14->setText("connection opened");
        // QSqlQuery query("SELECT * FROM tb_chat_participant where username "
        //"= '" +ui->lineEdit_Username->text() +"' and password ='"+ ui->lineEdit_password->text() + "'");
        this->picture = picture;
    }

    QString getemail()
    {
        return email;
    }

    void setemail(QString  email)
    {
        this->email = email;
    }

    QString getpassword()
    {
        return password;
    }

    void setpassword(QString  password)
    {
        this->password = password;
    }

    QDateTime getcreation_date()
    {
        return creation_date;
    }

    void setcreation_date(QDateTime creation_date)
    {
        this->creation_date = creation_date;
    }


    //bool submit_profile(QString fname, QString lname, QString uname, QString mail, QString pswd, QString picfilepath);
    //bool update_profile();
    //bool submit_profile();
    void upload_Picture();
    //void load_all_Contacts();
    bool chat_participant_login();
    QStringList view_active_contacts();

    void password_encryption(QString password)
    {


    }


    int chat_participant_login(QString username, QString password)
    {
       int rowcount = 0;
        chat_data_manager data_manager;
        try
        {

            if (data_manager.open_db_connection())
            {
                QSqlQuery query;
                query.prepare("SELECT * FROM tb_chat_participant where username='"+username+"' and password='"+password+"'");

                if (query.exec() == true)
                {
                    rowcount = query.numRowsAffected();
                    while (query.next())
                    {
                        rowcount++;
                    }
                }                
            }
        }
        catch (QException &ex)
        {
            qDebug() << "DB connection not opened";

        }
        data_manager.close_db_connection();
        return rowcount;
        }


//Class method to submit new chat participant profile
bool submit_profile(QString firstname, QString lastname, QString email, QString username, QString picfilepath, QString password)
 {
    chat_participant new_chat_perticipant;
    chat_data_manager data_manager;
    bool status = false;
    try
    {
        if (data_manager.open_db_connection() == true)
        {
            QSqlQuery query;
            query.prepare("INSERT INTO tb_chat_participant (firstname, lastname, email, username, picture, password, creation_date) "
                          "VALUES ("
                          "'" + firstname +"', "
                          "'" + lastname +"', "
                          "'" + email +"', "
                          "'" + username +"', "
                          "'" + picfilepath +"', "
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

bool update_profile(int chat_participant_ID, QString firstname, QString lastname, QString username, QString email, QString password)
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
            query.prepare("UPDATE tb_chat_participant SET firstname='"+firstname+"', lastname='"+lastname+"', "
                          "username='"+username+"', email='"+email+"', password='"+password+"', "
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

int load_all_Contacts(int chat_participant_ID)
{
    chat_data_manager data_manager;
    bool status = false;
    QString str_chat_participant_ID = QString::number(1);
    int rowcount = 0;
    try
    {
        if (data_manager.open_db_connection())
        {
            QSqlQuery query;
            query.prepare("SELECT  DISTINCT tb_chat_message.chat_sender_ID, tb_chat_message.chat_recipient_ID, "
                          "(SELECT DISTINCT username FROM tb_chat_participant "
                            "WHERE tb_chat_participant.chat_participant_ID = tb_chat_message.chat_sender_ID )"
                       "FROM tb_chat_message"
                       "WHERE chat_recipient_ID = 1"
                       "ORDER BY creation_date");

            //query.prepare("SELECT DISTINCT username FROM tb_chat_participant RIGHT JOIN tb_chat_message ON tb_chat_message.chat_recipient_ID = tb_chat_participant.chat_participant_ID WHERE chat_sender_ID = '"+str_chat_participant_ID+"' ORDER BY tb_chat_message.creation_date DESC;");
            //query.prepare("SELECT * FROM tb_chat_participant");
            if (query.exec() == true)
            {
                rowcount = query.numRowsAffected();
                while (query.next())
                {
                    rowcount++;
                }
            }
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
        return rowcount;
}


};



