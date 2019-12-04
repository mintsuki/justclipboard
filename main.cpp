#include <QApplication>
#include <QDebug>

#include "justclipboard.h"

int main(int argc, char *argv[]) {
    qDebug() << "justclipboard started";

    QApplication a(argc, argv);

    auto jc = new JustClipboard(a.clipboard());

    int ret = a.exec();

    delete jc;
    return ret;
}
