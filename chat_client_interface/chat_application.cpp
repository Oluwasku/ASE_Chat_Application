#include "chat_application.h"
#include "ui_chat_application.h"
#include "chat_tcp_client.cpp"
#include <QAbstractListModel>
#include <QStringList>
#include <QStringListModel>

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
}

chat_application::~chat_application()
{
    delete ui;
}


void chat_application::on_pushButton_Login_clicked()
{
    ui->label_15->setText("I am running");

    QStringListModel model;
    int listrow = ui->listView->currentIndex().row();
    QStringList list_string;
    QString chat_message = ui->lineEdit_8->text();
    list_string << chat_message;
    model.insertRows(listrow, 1);
    model.setStringList(list_string);
    ui->listView->setModel(new QStringListModel(list_string));
    ui->lineEdit_8->setText(" ");
}
