#ifndef MORSECONVERTER_H
#define MORSECONVERTER_H

#include <QObject>
#include <QTimer>
#include <QQueue>
#include <QString>
#include <QLabel>

class MorseConverter : public QObject {
    Q_OBJECT

public:
    explicit MorseConverter(QObject *parent = nullptr);
    QString convertToMorse(const QString &text);
    void startVisualization(const QString &text, QLabel *lamp);

    static inline const int Dot = 0;
    static inline const int Dash = 1;
    static inline const int Space = 2;

private:
    QQueue<int> symbolQueue;
    QTimer timer;

    QQueue<int> getSymbolQueue(const QString &morseCode);
    void visualizeNextSymbol(QLabel *lamp);
    void setupTimer();
};

#endif 
