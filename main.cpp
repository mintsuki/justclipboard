#include <QApplication>
#include <QDebug>

#include "justclipboard.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    qDebug() << "justclipboard: started";

    auto jc = new JustClipboard(a.clipboard());

    int ret = a.exec();

    delete jc;
    return ret;
}
