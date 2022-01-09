#ifndef CHAT_CLIENT_TEST_H
#define CHAT_CLIENT_TEST_H
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio/io_context.hpp>


using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class chat_client_test; }
QT_END_NAMESPACE

class chat_client_test : public QMainWindow
{
    Q_OBJECT

public:
    chat_client_test(QWidget *parent = nullptr);
    ~chat_client_test();

private:
    Ui::chat_client_test *ui;
};
#endif // CHAT_CLIENT_TEST_H
