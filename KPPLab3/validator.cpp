#include "validator.h"
#include <QRegularExpression>

Validator::Validator()
{

}

bool Validator::validateName(QString name) {
    QRegularExpression re("([a-zA-Z]+\\s){2}[a-zA-Z]+");
    return re.match(name).hasMatch();
}

bool Validator::validateEmail(QString email) {
    QRegularExpression re("[.\\S]+[@][.\\S]+");
    return re.match(email).hasMatch();
}

bool Validator::validateTheme(QString theme) {
    QRegularExpression re("[A-Z][A-Za-z0-9\\s]+");
    return re.match(theme).hasMatch();
}

bool Validator::validateText(QString text) {
    QRegularExpression re("[A-Z][A-Za-z0-9\\s]+[.]");
    return re.match(text).hasMatch();
}
