#include "chat_home.h"
#include "ui_chat_home.h"
#include <QAbstractListModel>
#include <QStringList>
#include <QStringListModel>

chat_home::chat_home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chat_home)
{
    ui->setupUi(this);


}

chat_home::~chat_home()
{
    delete ui;
}

void chat_home::on_pushButton_send_clicked()
{

}
