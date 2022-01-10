#ifndef CHAT_HOME_H
#define CHAT_HOME_H

#include <QMainWindow>

namespace Ui {
class chat_home;
}

class chat_home : public QMainWindow
{
    Q_OBJECT

public:
    explicit chat_home(QWidget *parent = nullptr);
    ~chat_home();

private slots:
    void on_pushButton_send_clicked();

    void on_pushButton_userlogin_clicked();

    void on_pushButton_register_clicked();

    void on_pushButton_update_clicked();

private:
    Ui::chat_home *ui;
};

#endif // CHAT_HOME_H
