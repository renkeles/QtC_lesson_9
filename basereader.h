#ifndef BASEREADER_H
#define BASEREADER_H

#include <QObject>
#include <QFile>

class BaseReader : public QObject
{
    Q_OBJECT
public:
    BaseReader(QObject *parent = nullptr);
    ~BaseReader();
    void Write(const QStringList &list);
    QList<QStringList> Read();
private:
    QFile* file;
};

#endif // BASEREADER_H
