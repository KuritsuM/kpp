#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "./validator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Validator *validator;
    QVector<QString> validationResult = { "", "", "", "" };
    QString formFromValidationResult();

private slots:
    void validateName();
    void validateEmail();
    void validateTheme();
    void validateText();
};
#endif // MAINWINDOW_H
