#include "chat_home.h"
#include "ui_chat_home.h"
#include "chat_participant.cpp"
#include "chat_data_manager.cpp"
#include "chat_connection.cpp"
#include "chat_message.cpp"
#include <QAbstractListModel>
#include <QStringList>
#include <QStringListModel>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSettings>


#include <iostream>
#include <QDateTime>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio/io_context.hpp>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;

chat_home::chat_home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chat_home)
{
    ui->setupUi(this);

    /// Make the chat widgets invisible on application load
    ui->listView_message_out->hide();
    ui->lineEdit_message_in->hide();
    ui->pushButton_send->hide();
    ui->listView_contacts->hide();
}

chat_home::~chat_home()
{
    delete ui;
}

/**
 * @brief chat_home::on_pushButton_send_clicked responsible for
 * submitting the chat message.
 */
void chat_home::on_pushButton_send_clicked()
{
    chat_participant new_participant;
    chat_message new_chat_message;
    QStringListModel model;
    int listrow = ui->listView_message_out->currentIndex().row();
    QStringList list_string;
    QString chat_message = ui->lineEdit_message_in->text();
    list_string << chat_message;
    model.insertRows(listrow, 1);
    model.setStringList(list_string);
    ui->listView_message_out->setModel(new QStringListModel(list_string));

    ///Save chat message by calling the message save member method.
    if(new_chat_message.save_chat_message(ui->lineEdit_message_in->text(),
                                          new_participant.getchat_participant_ID(), 3, "NULL") == 1)
    {

    }
     else
    {

    }
    /// Clear up entry on the text box
    ui->lineEdit_message_in->setText("");
}

/**
 * @brief chat_home::on_pushButton_userlogin_clicked
 * Manages user login scenarion
 */
void chat_home::on_pushButton_userlogin_clicked()
{
    QMessageBox msgBox;  /// Message box to feedback status to user
    ///call chat_participant object method to retrive user profile
    chat_participant new_participant;
    int user_ID = new_participant.chat_participant_login(ui->lineEdit_username->text(), ui->lineEdit_password->text());
    if(user_ID != 0)
    {
        msgBox.setText("Login successful");
        msgBox.exec();

        /// Make the chat widgets visisble after successful login
        ui->listView_message_out->show();
        ui->lineEdit_message_in->show();
        ui->pushButton_send->show();
        ui->listView_contacts->show();

        /// Load all user contacts to the current logged in context.
        new_participant.load_all_Contacts(user_ID);
       }

    else if(user_ID == 0)
    {
        msgBox.setText("username and password incorrect.");
        msgBox.exec();
    }
    /// Clears textboxes
    ui->lineEdit_username->setText(" ");
    ui->lineEdit_password->setText("");
}

/**
 * @brief chat_home::on_pushButton_register_clicked
 * call chat_participant object method to submit profile method
    from the UI widgets
 */
void chat_home::on_pushButton_register_clicked()
{
    QMessageBox msgBox;
    chat_participant new_participant;
    if (new_participant.submit_profile(ui->lineEdit_username_2->text(),
     ui->lineEdit_fullname->text(), ui->lineEdit_email->text(),
     ui->lineEdit_password_2->text()) == true)
    {
        msgBox.setText("Registration successful");
        msgBox.exec();
    }
     else
    {
        msgBox.setText("Registration failed");
        msgBox.exec();
    }
    /// Explicitly clear the lineEdit widgets of input texts
    ui->lineEdit_username_2->setText(" ");
    ui->lineEdit_fullname->setText(" ");
    ui->lineEdit_email->setText(" ");
    ui->lineEdit_password_2->setText(" ");
}

/**
 * @brief chat_home::on_pushButton_update_clicked
 * call chat_participant object method to update profile method
    from the UI widgets
 */
void chat_home::on_pushButton_update_clicked()
{
    // call chat_participant object method to submit registration
    QMessageBox msgBox;
    chat_participant new_participant;
    //QString str = QString::number(6);
    if (new_participant.update_profile( 6, ui->lineEdit_username_2->text(),
     ui->lineEdit_fullname->text(), ui->lineEdit_email->text(),
     ui->lineEdit_password_2->text()) == true)
    {
        msgBox.setText("Update successful");
        msgBox.exec();
    }
     else
    {
        msgBox.setText("update failed");
        msgBox.exec();
    }
    // Clear up entry on the text box
    ui->lineEdit_username_2->setText(" ");
    ui->lineEdit_fullname->setText(" ");
    ui->lineEdit_email->setText(" ");
    ui->lineEdit_password_2->setText(" ");
}
