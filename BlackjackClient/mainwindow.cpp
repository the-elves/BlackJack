
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textBrowser->hide();
    ui->pushButtonHit->hide();
    ui->pushButtonStand->hide();
    connect(&game, SIGNAL(displayMsg(QString)), this, SLOT(displayMsg(QString)));
    connect(&game, SIGNAL(changePlaying(bool)), this, SLOT(changePlaying(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonConnect_clicked()
{
    game.setName(ui->lineEditName->text().trimmed());
    this->setWindowTitle(ui->lineEditName->text().trimmed());
    game.connectToDealer(ui->lineEditIP->text().trimmed(), 1234,ui->lineEditName->text().trimmed());
    ui->pushButtonConnect->hide();
    ui->labelIP->hide();
    ui->labelName->hide();
    ui->lineEditIP->hide();
    ui->lineEditName->hide();
    ui->textBrowser->setVisible(true);
    ui->pushButtonHit->setVisible(true);
    ui->pushButtonStand->setVisible(true);
    changePlaying(true);
}

void MainWindow::displayMsg(QString msg) {
    ui->textBrowser->setText(ui->textBrowser->toPlainText() + "\n" + msg);
}

void MainWindow::changePlaying(bool value) {
    ui->pushButtonHit->setEnabled(value);
    ui->pushButtonStand->setEnabled(value);
}

void MainWindow::on_pushButtonStand_clicked()
{
    game.stand();
}

void MainWindow::on_pushButtonHit_clicked()
{
    game.hit();
}

/*void MainWindow::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "ChatClient", tr("Are you sure?"), QMessageBox::Cancel | QMessageBox::Yes, QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        writeMessage("###close" + ui->lineEditName->text());
        event->accept();
    }
}*/
