#include "chat_home.h"
#include "chat_participant.cpp"
#include "chat_connection.cpp"
#include <QMessageBox>
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
    //chat_application w;
    chat_home w;
    w.show();

    return a.exec();
}
