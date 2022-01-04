#ifndef CHAT_APPLICATION_H
#define CHAT_APPLICATION_H

#include <QMainWindow>

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

private:
    Ui::chat_application *ui;
};
#endif // CHAT_APPLICATION_H
