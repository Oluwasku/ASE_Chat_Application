#include <QCoreApplication>

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio/io_context.hpp>
#include <tcp_server.cpp>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

    return a.exec();
}

