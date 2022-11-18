#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    validator = new Validator();
    connect(ui->lineEdit, SIGNAL(editingFinished()), this, SLOT(validateName()));
    connect(ui->lineEdit_2, SIGNAL(editingFinished()), this, SLOT(validateEmail()));
    connect(ui->lineEdit_3, SIGNAL(editingFinished()), this, SLOT(validateTheme()));
    connect(ui->lineEdit_4, SIGNAL(editingFinished()), this, SLOT(validateText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::validateName() {
    validationResult[0] = "";

    if (!validator->validateName(ui->lineEdit->text())) {
        validationResult[0] = "Имя должно иметь минимум 2 пробела между символами.\n";
    }

    ui->textEdit->setText(formFromValidationResult());
}

void MainWindow::validateEmail() {
    validationResult[1] = "";

    if (!validator->validateEmail(ui->lineEdit_2->text())) {
        validationResult[1] = "Email должен содержать @.\n";
    }

    ui->textEdit->setText(formFromValidationResult());
}

void MainWindow::validateTheme() {
    validationResult[2] = "";

    if (!validator->validateTheme(ui->lineEdit_3->text())) {
        validationResult[2] = "Тема должна быть с большой буквы.\n";
    }

    ui->textEdit->setText(formFromValidationResult());
}

void MainWindow::validateText() {
    validationResult[3] = "";

    if (!validator->validateTheme(ui->lineEdit_4->text())) {
        validationResult[3] = "Текст должен начинаться с большой буквы и заканчиваться на маленькую букву.\n";
    }

    ui->textEdit->setText(formFromValidationResult());
}

QString MainWindow::formFromValidationResult() {
    QString result = "";

    for (auto& valRes : validationResult) {
        if (QString::compare(valRes, "", Qt::CaseInsensitive)) result.append(valRes);
    }

    return result;
}
