#include "ansthread.h"

ansThread::ansThread(int interval,QObject *parent) :
    QThread(parent)
  , i(0)
  , intvl(interval)
  , timer(0)
{
}

ansThread::~ansThread(){
    if( timer != 0 ) {
        delete timer;
    }
}

void ansThread::run(void)
{
    if(timer == 0)
    {
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(checkAns()));
    }
    timer->start(intvl);
    exec();
    timer->stop();
}

void ansThread::checkAns()
{
    emit ansSelected();
}
