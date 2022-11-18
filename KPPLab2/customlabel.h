#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QLabel>

class CustomLabel : public QLabel
{
    Q_OBJECT
private:
    int value = 0;
    const int signalValue = 10;
public:
    CustomLabel(QWidget *parent = nullptr);
public slots:
    void incValue();
    void decValue();
signals:
    void moreThenTen();
};

#endif // CUSTOMLABEL_H
