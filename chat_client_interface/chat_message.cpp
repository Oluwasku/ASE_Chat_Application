#ifndef CHAT_PARTICIPANT_H
#define CHAT_PARTICIPANT_H
#endif // CHAT_PARTICIPANT_H
#include <iostream>
#include <QDateTime>
#include <QAbstractListModel>
#include <QStringList>
#include <QStringListModel>

using namespace std;


class chat_message
{
private:
    int chat_message_ID;
    int chat_user_ID;
    int session_ID;
    string message;
    QDateTime transactio_date;

public:

    int getchat_message_ID(int chat_message_ID)
    {
        return chat_message_ID;
    }

    void setchat_message_ID(int  chat_message_ID)
    {
        this->chat_message_ID = chat_message_ID;
    }

    int getchat_user_ID(int chat_user_ID)
    {
        return chat_user_ID;
    }

    void setchat_user_ID(int  chat_user_ID)
    {
        this->chat_user_ID = chat_user_ID;
    }
    int getsession_ID()
    {
        return session_ID;
    }

    void setsession_ID(int session_ID)
    {
        this->session_ID = session_ID;
    }
    string getmessage()
    {
        return message;
    }

    void setmessage(string  message)
    {
        this->message = message;
    }
    void setdatetime(QDateTime transactio_date)
    {
        this->transactio_date = transactio_date;
    }

    chat_message()
    {

    }
    void save_chat_message();
    QStringListModel get_chat_message_by_session_ID(int session_ID);
    QStringListModel get_chat_message_by_user_ID(int chat_user_ID);
    QStringListModel loadContacts();
    void send_emoji();

};

chat_message new_chat_message;

void save_chat_message(int msg_ID, int chat_user_ID, int session_ID, string chat_msg, QDateTime tran_time)
{

    new_chat_message.setchat_message_ID(msg_ID);
    new_chat_message.setchat_user_ID(chat_user_ID);
    new_chat_message.setsession_ID(session_ID);
    new_chat_message.setmessage(chat_msg);
    new_chat_message.setdatetime(tran_time);
}

QStringList get_chat_message_history_by_user_ID(int chat_user_ID)
{
    QStringList list;
    QString text = "data in list view";
    return list << text;
}

QStringList get_message_history_by_session_ID(int session_ID)
{
    QStringList list;
    QString text = "data in list view";
    return list << text;
}

