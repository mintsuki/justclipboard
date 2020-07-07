#include "justclipboard.h"

#include <QDebug>
#include <QUrl>

JustClipboard::JustClipboard(QClipboard *clipboard, QObject *parent) : QObject(parent) {
    this->clipboard = clipboard;
    this->mimeData  = nullptr;
    connect(clipboard, SIGNAL(dataChanged()), this, SLOT(dataChanged()));
}

void JustClipboard::dataChanged() {
    const QMimeData *newMimeData = clipboard->mimeData();
    qDebug() << "justclipboard: data changed:" << newMimeData->formats();

    if (newMimeData->formats().empty()) {
        if (mimeData != nullptr && !mimeData->formats().empty()) {
            qDebug() << "justclipboard: restoring clipboard:" << mimeData->formats();
            disconnect(clipboard, SIGNAL(dataChanged()), this, SLOT(dataChanged()));
            clipboard->setMimeData(mimeData);
            connect(clipboard, SIGNAL(dataChanged()), this, SLOT(dataChanged()));
            mimeData = nullptr;
        }
        return;
    }

    if (mimeData == nullptr)
        mimeData = new QMimeData;
    mimeData->clear();

    if (newMimeData->hasText()) {
        mimeData->setText(newMimeData->text());
        return;
    } else if (newMimeData->hasImage()) {
        mimeData->setImageData(newMimeData->imageData());
        return;
    } else if (newMimeData->hasColor()) {
        mimeData->setColorData(newMimeData->colorData());
        return;
    } else if (newMimeData->hasHtml()) {
        mimeData->setHtml(newMimeData->html());
        return;
    } else if (newMimeData->hasUrls()) {
        mimeData->setUrls(newMimeData->urls());
        return;
    }
}
