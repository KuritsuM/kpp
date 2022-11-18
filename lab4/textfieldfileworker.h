#ifndef TEXTFIELDFILEWORKER_H
#define TEXTFIELDFILEWORKER_H

#include <QtGui/QGuiApplication>
#include <QFile>
#include <QTextStream>

class TextFieldFileWorker : public QObject
{
    Q_OBJECT

public:
    TextFieldFileWorker(QObject *parent = 0);

    Q_INVOKABLE void saveToFile(QString filename, QString value);
    Q_INVOKABLE QString openFromFile(QString filename);

    ~TextFieldFileWorker();
};

#endif // TEXTFIELDFILEWORKER_H
