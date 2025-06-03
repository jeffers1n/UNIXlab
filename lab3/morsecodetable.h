#ifndef MORSECODETABLE_H
#define MORSECODETABLE_H

#include <QMap>
#include <QChar>
#include <QString>

class MorseCodeTable {
public:
    MorseCodeTable();
    bool contains(QChar c) const;      
    QString value(QChar c) const;      

private:
    QMap<QChar, QString> table;
};

#endif
