#include "minzulink.h"
#include <QApplication>
#include  <QDesktopServices>
#include <QUrl>

MinzuLink::MinzuLink(QObject *parent)
    : QAbstractItemModel(parent)
{
    QDesktopServices::openUrl(QUrl("https://www.baidu.com", QUrl::TolerantMode));
}


