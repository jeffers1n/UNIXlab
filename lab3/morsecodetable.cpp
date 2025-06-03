#include "morsecodetable.h"

MorseCodeTable::MorseCodeTable() {
    table['A'] = ".-";    table['B'] = "-...";  table['C'] = "-.-.";
    table['D'] = "-..";   table['E'] = ".";    table['F'] = "..-.";
    table['G'] = "--.";   table['H'] = "...."; table['I'] = "..";
    table['J'] = ".---";  table['K'] = "-.-";  table['L'] = ".-..";
    table['M'] = "--";    table['N'] = "-.";   table['O'] = "---";
    table['P'] = ".--.";  table['Q'] = "--.-"; table['R'] = ".-.";
    table['S'] = "...";   table['T'] = "-";    table['U'] = "..-";
    table['V'] = "...-";  table['W'] = ".--";  table['X'] = "-..-";
    table['Y'] = "-.--";  table['Z'] = "--..";
    table['1'] = ".----"; table['2'] = "..---"; table['3'] = "...--";
    table['4'] = "....-"; table['5'] = "....."; table['6'] = "-....";
    table['7'] = "--..."; table['8'] = "---.."; table['9'] = "----.";
    table['0'] = "-----";
}

bool MorseCodeTable::contains(QChar c) const {
    return table.contains(c);
}

QString MorseCodeTable::value(QChar c) const {
    return table.value(c);
}
