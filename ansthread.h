#ifndef ANSTHREAD_H
#define ANSTHREAD_H

#include <QThread>
#include <QTimer>

#include <QThread>

class ansThread : public QThread
{
    Q_OBJECT

private:
    int i;
    int intvl;
    QTimer* timer;

public:
    explicit ansThread( int interval, QObject *parent = 0);
    ~ansThread();


signals:
    void ansSelected();

private slots:
    void checkAns();

protected:
    void run();

};

#endif // ANSTHREAD_H




