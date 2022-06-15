#include "basereader.h"



BaseReader::BaseReader(QObject *parent) : QObject(parent)
{
    file = new QFile("list.bin", this);
}

BaseReader::~BaseReader()
{
    if(file)
    {
        file->close();
    }
}

void BaseReader::Write(const QStringList &list)
{

    if(list.isEmpty())
    {
        return;
    }

    if(!file)
    {
        return;
    }

    if(!file->open(QIODevice::Append))
    {
        return;
    }

    int len = list.length();
    file->write((char*)&len, sizeof (len));

    for(auto i : list)
    {
        len = i.toUtf8().length();
        file->write((char*)&len, sizeof(len));
        file->write(i.toUtf8(), len);
    }

    file->close();
}

QList<QStringList> BaseReader::Read()
{
    QList<QStringList>qList{};

    if(!file)
    {
        return qList;
    }

    if(!file->open(QIODevice::ReadOnly))
    {
        return qList;
    }

    while(!file->atEnd())
    {
        QStringList qStrList{};
        int len{0};
        file->read((char*)&len, sizeof (len));
        for(int i{0}; i < len; ++i)
        {
            int size{0};
            file->read((char*)&size, sizeof (size));
            QByteArray byteArr;
            byteArr.resize(size);
            file->read(byteArr.data(), size);

            qStrList.append(QString(byteArr));
        }

        qList.append(qStrList);
    }

    file->close();
    return qList;
}


