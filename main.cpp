#include <QCoreApplication>
#include <QDebug>
#include <smart.h>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";
    Smart smart;
    return QCoreApplication::exec();
}
