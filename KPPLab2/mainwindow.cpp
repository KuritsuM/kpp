#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "customlabel.h"

#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(changeWindowName()));
    connect(ui->plainTextEdit, SIGNAL(textChanged()), this, SLOT(copyAndChangeA()));
    connect(ui->plainTextEdit, SIGNAL(textChanged()), this, SLOT(showStarsInLabel()));
    connect(this, SIGNAL(starsChanged()), ui->label, SLOT(incValue()));
    connect(ui->label, SIGNAL(moreThenTen()), this, SLOT(setDisabled()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeWindowName() {
    this->setWindowTitle(ui->lineEdit->text());
}

void MainWindow::copyAndChangeA() {
    QString word = ui->plainTextEdit->toPlainText().replace("a", "*");
    if (word.count("*") > ui->plainTextEdit_2->toPlainText().count("*")) {
        emit starsChanged();
    }
    ui->plainTextEdit_2->setPlainText(word);
}

void MainWindow::showStarsInLabel() {
    QString counted = QString::number(ui->plainTextEdit_2->toPlainText().count("*"));
}

void MainWindow::setDisabled() {
    ui->plainTextEdit->setDisabled(true);
}
