#include "customlabel.h"

CustomLabel::CustomLabel(QWidget *parent)
    : QLabel(parent)
{

}

void CustomLabel::incValue() {
    if (++value > signalValue) {
        emit moreThenTen();
    }

    this->setText(QString::number(value));
}

void CustomLabel::decValue() {
    if (value > 0) {
        --value;
    }

    this->setText(QString::number(value));
}
