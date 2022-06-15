#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtQuickWidgets>
#include <QStandardItemModel>
#include <QTableView>
#include <QFile>
#include "basereader.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void takeInfo(QString,QString,QString);

private:
    Ui::MainWindow *ui;
    QQuickWidget *qWidget;
    QStandardItemModel *sModel;
    QTableView *tView;

    struct infoTask
    {
        QString deadline;
        QString textTask;
        QString progress;
    };

    QList<infoTask> infoList;

    BaseReader reader;

    int minWidth = 640;
    int minHeight = 480;



};
#endif // MAINWINDOW_H
