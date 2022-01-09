#include "chat_client_test.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chat_client_test w;
    w.show();
    return a.exec();
}
