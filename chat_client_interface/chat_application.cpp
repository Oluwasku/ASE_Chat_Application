#include "chat_application.h"
#include "ui_chat_application.h"
//#include "chat_tcp_client.cpp"
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

chat_application::chat_application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::chat_application)
{
    ui->setupUi(this);


    // Connect to server
    try
    {
        boost::asio::io_service io_service;
        //socket creation
        tcp::socket socket(io_service);
        //connection
        socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 1234 ));
        // request/message from client
        const QString msg = "Hello from Client!\n";
        //QString str_chat_participant_ID = QString::QString();
        boost::system::error_code error;
        boost::asio::write( socket, boost::asio::buffer(msg.toStdString()), error );
        if( !error )
        {
            cout << "Client sent hello message!" << endl;
            ui->label_10->setText("Client sent hello message");
        }
        else {
            cout << "send failed: " << error.message() << endl;
            ui->label_11->setText("send failed");
        }
        // getting response from server
        boost::asio::streambuf receive_buffer;
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
        if( error && error != boost::asio::error::eof ) {
            cout << "receive failed: " << error.message() << endl;
            ui->label_12->setText("receive failed");
        }
        else
        {
            const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
            cout << data << endl;
            QString test = data;
             ui->label_13->setText(test);
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    //return 0;



}

chat_application::~chat_application()
{
    delete ui;
}


//void chat_application::on_pushButton_Login_clicked()
void chat_application::on_pushButton_Login_clicked()
{
       //ui->label_11->setText(" Button_Login_clicked");
       //call chat_participant object method to retrive user profile
       chat_participant new_participant;
       int login_status = new_participant.chat_participant_login(ui->lineEdit_Username->text(), ui->lineEdit_password->text());
       if(login_status == 1)
       {
            ui->label_15->setText("Login successful");
       }
       else if(login_status < 1)
       {
           ui->label_15->setText("incorrect username and password");
       }
       ui->lineEdit_Username->setText(" ");
       ui->lineEdit_password->setText(" ");

}



void chat_application::on_pushButton_3_clicked()
{
        chat_message new_chat_message;
        QStringListModel model;
        int listrow = ui->listView->currentIndex().row();
        QStringList list_string;
        QString chat_message = ui->lineEdit_message->text();
        list_string << chat_message;
        model.insertRows(listrow, 1);
        model.setStringList(list_string);
        ui->listView->setModel(new QStringListModel(list_string));
        //Save chat message by calling the message save member method.
        if(new_chat_message.save_chat_message(ui->lineEdit_message->text(), 2, 3, "NULL") == 1)
        {
            ui->label_15->setText("message save successful");
        }
         else
        {
            ui->label_15->setText("message save failed");
        }
        // Clear up entry on the text box
        ui->lineEdit_message->setText("");
}

void chat_application::on_pushButton_register_clicked()
{
    // call chat_participant object method to submit registration
    chat_participant new_participant;
    if (new_participant.submit_profile(ui->lineEdit_firstname->text(),
     ui->lineEdit_lastname->text(), ui->lineEdit_email->text(),
     /*ui->lineEdit_username1->text(), ui->lineEdit_picture->text(),*/
     ui->lineEdit_password_2->text()) == true)
    {
        ui->label_15->setText("Registration successful");
    }
     else
    {
        ui->label_15->setText("Registration failed");
    }
    // Clear up entry on the text box
    ui->lineEdit_firstname->setText(" ");
    ui->lineEdit_lastname->setText(" ");
    ui->lineEdit_username1->setText(" ");
    ui->lineEdit_password_2->setText(" ");
    ui->lineEdit_email->setText(" ");
    ui->lineEdit_email->setText(" ");

}

void chat_application::on_pushButton_userlogin_clicked()
{
    ui->label_11->setText("Button_Login_clicked");
    //call chat_participant object method to retrive user profile
    chat_participant new_participant;
    int login_status = new_participant.chat_participant_login(ui->lineEdit_Username->text(),
                                                              ui->lineEdit_password->text());
    if(login_status == 1)
    {
         ui->label_15->setText("Login successful");
         // load all contacts.
        //new_participant.load_all_Contacts(1);


         // Initiate a chat connectionn to the server
         // Connect to server
         try
         {
             boost::asio::io_service io_service;
             //socket creation
             tcp::socket socket(io_service);
             //connection
             socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 1234 ));
             con_handler newconnection(io_service);
             newconnection.start();
             // request/message from client
             const QString msg = "Hello from Client!\n";
             //QString str_chat_participant_ID = QString::QString();
             boost::system::error_code error;
             boost::asio::write( socket, boost::asio::buffer(msg.toStdString()), error );
             if( !error )
             {
                 cout << "Client sent hello message!" << endl;
                 ui->label_10->setText("Client sent hello message");
             }
             else {
                 cout << "send failed: " << error.message() << endl;
                 ui->label_11->setText("send failed");
             }
             // getting response from server
             boost::asio::streambuf receive_buffer;
             boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
             if( error && error != boost::asio::error::eof ) {
                 cout << "receive failed: " << error.message() << endl;
                 ui->label_12->setText("receive failed");
             }
             else
             {
                 const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
                 cout << data << endl;
                 QString test = data;
                  ui->label_13->setText(test);
             }
         }
         catch (std::exception& e)
         {
             std::cerr << e.what() << endl;
         }
         //return 0;



    }
    else if(login_status < 1)
    {
        ui->label_15->setText("incorrect username and password");
          new_participant.load_all_Contacts(1);
    }
    ui->lineEdit_Username->setText(" ");
    ui->lineEdit_password->setText(" ");
}

void chat_application::on_pushButton_update_clicked()
{
    // call chat_participant object method to submit registration
    chat_participant new_participant;
    //QString str = QString::number(6);
    if (new_participant.update_profile( 6, ui->lineEdit_lastname->text(), ui->lineEdit_username1->text(),
     ui->lineEdit_email->text(), ui->lineEdit_password_2->text()) == true)
    {
        ui->label_15->setText("Update successful");
    }
     else
    {
        ui->label_15->setText("Update failed");
    }
    // Clear up entry on the text box
    ui->lineEdit_firstname->setText(" ");
    ui->lineEdit_lastname->setText(" ");
    ui->lineEdit_username1->setText(" ");
    ui->lineEdit_password_2->setText(" ");
    ui->lineEdit_email->setText(" ");
}
