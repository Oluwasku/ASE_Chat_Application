#ifndef CHAT_APPLICATION_H
#define CHAT_APPLICATION_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QFileInfo>


QT_BEGIN_NAMESPACE
namespace Ui { class chat_application; }
QT_END_NAMESPACE

class chat_application : public QMainWindow
{
    Q_OBJECT

public:
    chat_application(QWidget *parent = nullptr);
    ~chat_application();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_register_clicked();

    void on_pushButton_userlogin_clicked();

    void on_pushButton_update_clicked();

private:
    Ui::chat_application *ui;
    QSqlDatabase chat_sqldb;
};
#endif // CHAT_APPLICATION_H
