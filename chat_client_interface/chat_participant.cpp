#ifndef CHAT_PARTICIPANT_H
#define CHAT_PARTICIPANT_H
#endif // CHAT_PARTICIPANT_H
#include <iostream>
#include <QDateTime>
#include <QAbstractListModel>
#include <QStringList>
#include <QStringListModel>

using namespace std;


class chat_participant
{
private:
    int chat_participant_ID;
    string firstname;
    string lastname;
    string email;
    string password;
    string picture;
    QDateTime transactio_date;

public:

    int getchat_participant_ID()
    {
        return chat_participant_ID;
    }

    void setfirstname(int  chat_participant_ID)
    {
        this->chat_participant_ID = chat_participant_ID;
    }

    string getfirstname()
    {
        return firstname;
    }

    void setfirstname(string  firstname)
    {
        this->firstname = firstname;
    }

    string getlastname()
    {
        return lastname;
    }

    void setlastname(string  lastname)
    {
        this->lastname = lastname;
    }

    string getpicture()
    {
        return picture;
    }

    void setpicture(string  picture)
    {
        this->picture = picture;
    }

    string getemail()
    {
        return email;
    }

    void setemail(string  email)
    {
        this->email = email;
    }

    string getpassword()
    {
        return password;
    }

    void setpassword(string  password)
    {
        this->password = password;
    }

    void setdatetime(QDateTime transactio_date)
    {
        this->transactio_date = transactio_date;
    }

    chat_participant()
    {

    }
    void submit_profile();
    void update_profile();
    void upload_Picture();
    void load_all_Contacts();
    QStringList view_active_contacts();

};

chat_participant new_chat_perticipant;

void submit_profile(string fname, string lname, string mail, string pswd, string picfilepath)
{

    new_chat_perticipant.setfirstname(fname);
    new_chat_perticipant.setlastname(lname);
    new_chat_perticipant.setemail(mail);
    new_chat_perticipant.setpassword(pswd);
    new_chat_perticipant.setpicture(picfilepath);
}

void update_profile(int chat_participant_ID, string fname, string lname, string mail, string pswd, string picfilepath)
{
    //new_chat_perticipant.(chat_participant_ID);

    new_chat_perticipant.setfirstname(fname);
    new_chat_perticipant.setlastname(lname);
    new_chat_perticipant.setemail(mail);
    new_chat_perticipant.setpassword(pswd);
    new_chat_perticipant.setpicture(picfilepath);
}

QStringList view_all_Contacts(int chat_participant_ID)
{
    QStringList list;
    QString text = "data in list view";
    return list << text;

}

QStringList view_active_contacts()
{
    QStringList list;
    QString text = "data in list view";
    return list << text;
}

bool uploadpicture(string filepath)
{
    return 1;
}

