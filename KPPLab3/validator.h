#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QObject>

class Validator
{
public:
    Validator();

    bool validateName(QString name);

    bool validateEmail(QString email);

    bool validateTheme(QString theme);

    bool validateText(QString text);
};

#endif // VALIDATOR_H
