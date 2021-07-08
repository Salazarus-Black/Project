#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenFileButton_clicked()
{
    QString FileName = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::currentPath(), "*.txt");
    ui->FilePath->setText(FileName);
    QFile file(FileName);

    ui->comboBox->clear();
    QVector<QString> strList;
    if ((file.exists())&&(file.open(QIODevice::ReadOnly))){

        while(!file.atEnd())
        {
            strList.push_back(file.readLine(8));
            file.readLine(8);

            file.readLine();
        }
        for(const auto &i : strList){

            ui->comboBox->addItem(i);
        }
        file.close();
    }
}

