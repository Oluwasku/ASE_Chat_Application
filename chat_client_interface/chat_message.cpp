#ifndef CHAT_MESSAGE_H
#define CHAT_MESSAGE_H

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

using namespace std;


class chat_message
{
private:
    int chat_message_ID;
    int chat_recipient_ID;
    int chat_sender_ID;
    QString chat_text;
    QDateTime creation_date;

public:

    int getchat_message_ID(int chat_message_ID)
    {
        return chat_message_ID;
    }

    void setchat_message_ID(int  chat_message_ID)
    {
        this->chat_message_ID = chat_message_ID;
    }

    int getchat_recipient_ID(int chat_recipient_ID)
    {
        return chat_recipient_ID;
    }

    void setchat_recipient_ID(int  chat_recipient_ID)
    {
        this->chat_recipient_ID = chat_recipient_ID;
    }
    int getchat_sender_ID()
    {
        return chat_sender_ID;
    }

    void setchat_sender_ID(int chat_sender_ID)
    {
        this->chat_sender_ID = chat_sender_ID;
    }
    QString getchat_message()
    {
        return chat_text;
    }

    void setchat_message(QString  chat_text)
    {
        this->chat_text = chat_text;
    }
    void setdatetime(QDateTime creation_date)
    {
        this->creation_date = creation_date;
    }

    chat_message()
    {

    }
    //int save_chat_message();
    QStringListModel get_chat_message_by_session_ID(int session_ID);
    QStringListModel get_chat_message_by_user_ID(int chat_sender_ID);
    QStringListModel loadContacts();
    void send_emoji();


int save_chat_message(QString chat_text, int chat_sender_ID, int chat_recipient_ID, QString emoji)
{
    chat_message new_chat_message;
    chat_data_manager data_manager;
    bool status = false;
    int rowcount = 0;
    QString str_recipient_id = QString::number(chat_recipient_ID);
    QString str_sender_id = QString::number(chat_sender_ID);
    try
    {
          if (data_manager.open_db_connection() == true)
            {
                QSqlQuery query;
                query.prepare("INSERT INTO tb_chat_message (chat_sender_ID, chat_recipient_ID, chat_message, chat_emoji, creation_date, "") "
                              "VALUES ('"+str_sender_id+"', '"+str_recipient_id+"', '"+chat_text+"', ""datetime('now'))," "''");

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

QStringList get_chat_message_history_by_user_ID(int chat_sender_ID)
{
    QStringList list;
    QString text = "data in list view";
    return list << text;
}

QStringList get_message_history_by_session_ID(int chat_recipient_ID)
{
    QStringList list;
    QString text = "data in list view";
    return list << text;
}

};


#endif // CHAT_MESSAGE_H
