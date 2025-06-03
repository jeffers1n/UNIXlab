#include "morseconverter.h"
#include "morsecodetable.h"
#include <QTimer>

MorseConverter::MorseConverter(QObject *parent)
    : QObject(parent) {
    setupTimer();
}

QString MorseConverter::convertToMorse(const QString &text) {
    MorseCodeTable table;
    QString result;

    for (QChar c : text) {
        if (table.contains(c)) {
            result += table.value(c) + " ";
        } else {
            result += "? ";
        }
    }
    return result.trimmed();
}

QQueue<int> MorseConverter::getSymbolQueue(const QString &morseCode) {
    QQueue<int> queue;
    QStringList letters = morseCode.split(' ', Qt::SkipEmptyParts);

    for (const QString &letter : letters) {
        for (QChar c : letter) {
            if (c == '.') queue.enqueue(Dot);
            else if (c == '-') queue.enqueue(Dash);
        }
        queue.enqueue(Space);
    }
    return queue;
}

void MorseConverter::startVisualization(const QString &text, QLabel *lamp) {
    if (!symbolQueue.isEmpty()) symbolQueue.clear();
    QString morseCode = convertToMorse(text);
    symbolQueue = getSymbolQueue(morseCode);
    visualizeNextSymbol(lamp);
}

void MorseConverter::visualizeNextSymbol(QLabel *lamp) {
    if (symbolQueue.isEmpty()) {
        lamp->setStyleSheet("background-color: gray;");
        return;
    }

    int symbol = symbolQueue.dequeue();
    switch (symbol) {
        case Dot:
            lamp->setStyleSheet("background-color: red;");
            QTimer::singleShot(200, [this, lamp]() {
                lamp->setStyleSheet("background-color: gray;");
                QTimer::singleShot(100, [this, lamp]() {
                    if (!symbolQueue.isEmpty()) visualizeNextSymbol(lamp);
                });
            });
            break;
        case Dash:
            lamp->setStyleSheet("background-color: red;");
            QTimer::singleShot(600, [this, lamp]() {
                lamp->setStyleSheet("background-color: gray;");
                QTimer::singleShot(100, [this, lamp]() {
                    if (!symbolQueue.isEmpty()) visualizeNextSymbol(lamp);
                });
            });
            break;
        case Space:
            lamp->setStyleSheet("background-color: gray;");
            QTimer::singleShot(700, [this, lamp]() {
                if (!symbolQueue.isEmpty()) visualizeNextSymbol(lamp);
            });
            break;
    }
}

void MorseConverter::setupTimer() {
    connect(&timer, &QTimer::timeout, this, [this]() {
    });
}
