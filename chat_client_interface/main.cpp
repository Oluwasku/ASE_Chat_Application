#include "chat_application.h"
#include "chat_participant.cpp"
#include "chat_tcp_client.cpp"

#include <QApplication>

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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chat_application w;
    w.show();

    /*
    try
    {
        cout << "Server started successfully!"<< endl;
        boost::asio::io_service io_service;
        Server newServer(io_service);
        io_service.run();


     } catch (std::exception& e)
     {
            std::cerr << e.what() << endl;
     }


    boost::asio::io_service io_service;
    tcp::socket socket(io_service);

    socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 1234 ) );
    const QString msg = "Hello from Client!\n";
    boost::system::error_code error;
    boost::asio::write( socket, boost::asio::buffer(msg.toStdString()), error );
*/
    /*
    if( !error )
    {     } catch (std::exception& e)
    {
           std::cerr << e.what() << endl;
    }
      //cout << "Client sent hello message!" << endl;     } catch (std::exception& e)
    {
           std::cerr << e.what() << endl;
    }
        //ui->label_11->setText("Client sent hello message!");
    }
    else
    {
      //cout << "send failed: " << error.message() << endl;
        //ui->label_11->setText("send failed:");
    }

    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);

    if( error && error != boost::asio::error::eof )
    {
      //cout << "receive failed: " << error.message() << endl;
       // QString errmsg.toStdString(error.message());
        //const QString* errmsg = error.message();

       //ui->label_12->setText("receive failed:");
    }
    else
    {
      const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
      cout << data << endl;
      //ui->label_12->setText(data);
    }
*/
    return a.exec();
}
