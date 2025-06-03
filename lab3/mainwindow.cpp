#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "morseconverter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    morseConverter = new MorseConverter(this);
    connect(ui->convertButton, &QPushButton::clicked, this, &MainWindow::onConvertClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onConvertClicked()
{
    QString text = ui->inputText->text().toUpper();
    QString morseCode = morseConverter->convertToMorse(text);
    ui->morseCodeLabel->setText(morseCode);
    morseConverter->startVisualization(text, ui->lampLabel);
}
