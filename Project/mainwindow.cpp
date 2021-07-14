#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget->setInteraction(QCP::iRangeZoom, true);//Добавление зума на графике
    ui->widget->setInteraction(QCP::iRangeDrag, true);//добавление перемещения по графику
}

MainWindow::~MainWindow()
{
    delete ui;
}

QMap<QString,QVector<int>> Data;//инициализация главной переменной: ключ - время пакета, данные - вектор данных

void MainWindow::on_OpenFileButton_clicked()
{
    ui->comboBox->clear(); //очищаем список со временем(нужно если требуется открыть новый файл)
    ui->widget->clearGraphs();//очищаем график(нужно если требуется открыть новый файл)
    Data.clear();//очищаем главную переменную(нужно если требуется открыть новый файл)

    QString FileName = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::currentPath(), "*.txt");//вызов диалогового окна для открытия файла
    ui->FilePath->setText(FileName);//считывание имени файла
    QFile file(FileName);//открытие файла

    ui->comboBox->clear();//очистка листа выбора
    QVector<int>TemporaryDataMass;//временное хранилище данных в числовом формате
    int kofic;//коэфициент умножения
    QString TemporaryData,TemporaryData1,LineTest,LineTest1,CorrectSignal;//инициализация:
                                                                          //доп. переменной времени(которая будет записываться в список),
                                                                          //доп. переменной времени1(в которую будет считываться время каждой строки),
                                                                          //переменной в которую будет записываться строка из файла,
                                                                          //той же переменной, но без информации о корректности/некорректности строки
                                                                          //переменой корректности/некорректности строки
    QStringList list;//временное хранилище данных в строковом формате
    int NumPac;//номер строки пакета
    if ((file.exists())&&(file.open(QIODevice::ReadOnly))){//открываем файл
        while(!file.atEnd()){//и пока он не закончился
            LineTest = file.readLine();//считываетм 1 строку
            LineTest1 = LineTest.left(LineTest.lastIndexOf(" "));//убераем из нее информацию о корректности/некорректности строки
            CorrectSignal = LineTest.right(6).left(4);//записываем информацию о корректности/некорректности строки
            TemporaryData1 = LineTest1.left(LineTest1.indexOf("#"));//записываем время из строки
            list  = LineTest1.split(" ");//разбиваем строку на массив по пробелу
            list.takeFirst();//убераем уже считанную информацию
            list.takeFirst();//убераем не требуемую информацию
            NumPac = list.takeFirst().toInt(nullptr,16);//записываем номер строки пакета
            kofic = list.takeFirst().toInt(nullptr,16);//записываем коэфициент умножения
            if(CorrectSignal=="True"){//если строка пришла корректно
                for(auto &i :list){//перебираем все значения из строкового хранилища
                    TemporaryDataMass.push_back(kofic*i.toInt(nullptr,16));//и переносим их во временное хранилище
                                                                           //данных в числовом формате, умножая на коэфициент
                }

                if(NumPac==0){//если номер строки пакета 0(те пришела строка из нового пакета)
                    TemporaryData = TemporaryData1;//переносим информацию из переменной времени1 в переменную времени
                }

                for(auto i : TemporaryDataMass){//перебирая элементы данных в числовом формате
                    Data[TemporaryData].push_back(i);//переносим их в вектор данных под нужным ключем(если такого
                                                     //ключа не было - создастся, если был - дополнится новыми элементами)
                }
                TemporaryDataMass.clear();//очитска временного хранилища данных
            }
        }
        file.close();//закрываем файл

    }
   for(const auto &i : Data.keys()){//перебирая все ключи(вмемя прибытия пакетов)
        ui->comboBox->addItem(i);//переноим их в список
    }
}

void MainWindow::on_comboBox_currentTextChanged(const QString &SelectedTime)
{
    QVector<double> SelectedData,SelectedDataTime;//инициализация временных хранилищ для данных и времени(y и x на графике)
    double counter = 0, MaxElement = 0, MinElement = 0;//инициализация счетчика(для заполнения хранилища времени) и
                                       //максимального/минимального элемента(для маштабирования графика)
    for (auto i : Data.keys()){//перебираем все ключи хранилища
        if(SelectedTime ==i){//когда находим совпадение
            for(auto q : Data[i]){//перебираем хранилище данных из найденного ключа
                SelectedData.push_back(q);//переносим хранилище данных во временное хранилище
                SelectedDataTime.push_back(counter);//заполняем хранилище времени равным колличеством элементов
                counter++;
                if(q>MaxElement){//во время перебора ищем максимальный элемент
                    MaxElement=q;//и когда находим - записываем его
                }
                if(q<MinElement){//во время перебора ищем максимальный элемент
                    MinElement=q;//и когда находим - записываем его
                }
            }
        }
    }
    ui->widget->clearGraphs();//очищаем график
    ui->widget->xAxis->setRange(0,SelectedDataTime.size()+5);//настраиваем масштаб оси Х
    ui->widget->yAxis->setRange(MinElement-5,MaxElement+5);//настраиваем масштаб оси Y
    ui->widget->addGraph();//добавляем график
    ui->widget->graph(0)->addData(SelectedDataTime,SelectedData);//передаем графику данные
    ui->widget->replot();//рисуем график
}

