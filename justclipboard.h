#ifndef JUSTCLIPBOARD_H
#define JUSTCLIPBOARD_H

#include <QObject>
#include <QClipboard>
#include <QMimeData>

class JustClipboard : public QObject {
    Q_OBJECT

public:
    explicit JustClipboard(QClipboard *clipboard, QObject *parent = nullptr);

private:
    QClipboard *clipboard;
    QMimeData *mimeData;

private slots:
    void dataChanged();
};

#endif // JUSTCLIPBOARD_H
