#ifndef DECIDER_H
#define DECIDER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class Decider : public QObject
{
    Q_OBJECT
public:
    explicit Decider(QObject *parent = 0);
    void decideAndSend();

signals:

public slots:
    void newConnection();
    void readyRead();

private:
    QTcpServer *server;
    std::vector<QTcpSocket*> clients;
    int players;
    QMap<QString, int> hands;

};

#endif // DECIDER_H
