#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedWidth(minWidth);
    this->setFixedHeight(minHeight);
    this->setMinimumWidth(minWidth);
    this->setMinimumHeight(minHeight);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->setWindowTitle("DeadLiner");

    qWidget = new QQuickWidget(this);
    qWidget->setSource(QUrl("qrc:/qmls/MainQML.qml"));
    qWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    sModel = new QStandardItemModel;
    sModel->setColumnCount(3);
    sModel->setHeaderData(0, Qt::Orientation::Horizontal, "Дедлайн");
    sModel->setHeaderData(1, Qt::Orientation::Horizontal, "Задание");
    sModel->setHeaderData(2, Qt::Orientation::Horizontal, "Прогресс(0/10)");

    tView = new QTableView(this);
    tView->setModel(sModel);
    tView->setColumnWidth(0, minWidth/7);
    tView->setColumnWidth(1, minWidth - minWidth/7 - minWidth/7 - 60);
    tView->setColumnWidth(2, minWidth/7);

    ui->verticalLayout->addWidget(qWidget, 1, 0);
    ui->verticalLayout->addWidget(tView, 2, 0);

    QQuickItem *root = qWidget->rootObject();
    if(root)
    {
        QObject *addbutton = root->findChild<QObject*>("addButton");
        if(addbutton)
        {
            connect(addbutton, SIGNAL(sendInfo(QString,QString,QString)), this, SLOT(takeInfo(QString,QString,QString)));
        }
    }

    QList<QStringList> backup = reader.Read();
    if(!backup.isEmpty())
    {
        for(auto i : backup)
        {
            sModel->appendRow(QList<QStandardItem*>{new QStandardItem{i.at(0)}, new QStandardItem{i.at(1)}, new QStandardItem{i.at(2)}});
        }
    }

}

MainWindow::~MainWindow()
{
    for(auto i : infoList)
    {
       reader.Write(QStringList{i.deadline, i.textTask, i.progress});
    }
    delete ui;
}

void MainWindow::takeInfo(QString deadline, QString text, QString progress)
{
    infoList.append(infoTask{deadline, text, progress});
    sModel->appendRow(QList<QStandardItem*>{new QStandardItem{deadline}, new QStandardItem{text}, new QStandardItem{progress}});
}

