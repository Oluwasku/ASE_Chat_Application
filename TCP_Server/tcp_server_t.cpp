#include "tcp_server_t.h"
#include "ui_tcp_server_t.h"

tcp_server_t::tcp_server_t(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tcp_server_t)
{
    ui->setupUi(this);
}

tcp_server_t::~tcp_server_t()
{
    delete ui;
}

void tcp_server_t::on_pushButton_start_clicked()
{

}
