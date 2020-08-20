#include <QTimer>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>

#include "handlers.h"
#include "lib/libgoshim.h"

GoString toGoStr(QString s)
{
    char *c = s.toLocal8Bit().data();
    return (GoString){c, (long int)strlen(c)};
}


Backend::Backend(QObject *parent) : QObject(parent)
{
}

QString Backend::getAppName()
{
    return QString(GetAppName());
}

QString Backend::getVersion()
{
    return QString(GetVersion());
}

void Backend::switchOn()
{
    SwitchOn();
}

void Backend::switchOff()
{
    SwitchOff();
}

void Backend::donateAccepted()
{
    DonateAccepted();
}

void Backend::login(QString username, QString password)
{
    Login(toGoStr(username), toGoStr(password));
}

void Backend::resetError(QString errlabel)
{
    ResetError(toGoStr(errlabel));
}

void Backend::quit()
{
    Quit();
    emit this->quitDone();
}

