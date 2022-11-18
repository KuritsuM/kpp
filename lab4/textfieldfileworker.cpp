#include "textfieldfileworker.h"

TextFieldFileWorker::TextFieldFileWorker(QObject *parent) : QObject(parent)
{   
}

TextFieldFileWorker::~TextFieldFileWorker()
{
}

void TextFieldFileWorker::saveToFile(QString filename, QString value)
{
    QFile file(filename);
    file.open(QFile::ReadWrite | QIODevice::Truncate);

    QTextStream outStream(&file);
    outStream << value;

    file.close();
}

QString TextFieldFileWorker::openFromFile(QString filename)
{
    QFile file(filename);

    QString value = "";

    if (file.open(QFile::ReadOnly)) {
        QTextStream inStream(&file);

        value = inStream.readAll();
    }

    file.close();

    return value;
}
