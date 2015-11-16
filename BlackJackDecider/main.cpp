#include <QCoreApplication>
#include "decider.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Decider decider;
    return a.exec();
}
