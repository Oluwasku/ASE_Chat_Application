#include "chat_client_test.h"
#include "ui_chat_client_test.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio/io_context.hpp>


using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;

chat_client_test::chat_client_test(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::chat_client_test)
{
    ui->setupUi(this);


    try {


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
        if( !error ) {
            //cout << "Client sent hello message!" << endl;
            ui->label->setText("Client sent hello message");
        }
        else {
            //cout << "send failed: " << error.message() << endl;
            ui->label->setText("send failed");
        }
        // getting response from server
        boost::asio::streambuf receive_buffer;
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
        if( error && error != boost::asio::error::eof ) {
            //cout << "receive failed: " << error.message() << endl;
            ui->label_2->setText("receive failed");

        }
        else {
            const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
            cout << data << endl;
            QString test = data;
             ui->label_2->setText(test);

        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    //return 0;
}




chat_client_test::~chat_client_test()
{
    delete ui;
}

// Client
void connect()
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
    if( !error ) {
       cout << "Client sent hello message!" << endl;
    }
    else {
       cout << "send failed: " << error.message() << endl;
    }
// getting response from server
   boost::asio::streambuf receive_buffer;
   boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
   if( error && error != boost::asio::error::eof ) {
       cout << "receive failed: " << error.message() << endl;
   }
   else {
       const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
       cout << data << endl;
   }
   //return 0;
}

