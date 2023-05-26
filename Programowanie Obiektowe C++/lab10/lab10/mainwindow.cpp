#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->a->setVisible(false);
    ui->operacja->setVisible(false);
    ui->b->setVisible(false);
    ui->oblicz->setVisible(false);
    ui->wynik->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_oblicz_clicked()
{
    if(ui->operacja->currentIndex() == 0)
        ui->wynik->setText(QString::number(ui->a->text().toFloat() + ui->b->text().toFloat()));
    if(ui->operacja->currentIndex() == 1)
        ui->wynik->setText(QString::number(ui->a->text().toFloat() - ui->b->text().toFloat()));
    if(ui->operacja->currentIndex() == 2)
        ui->wynik->setText(QString::number(ui->a->text().toFloat() * ui->b->text().toFloat()));
    if(ui->operacja->currentIndex() == 3)
        ui->wynik->setText(QString::number(ui->a->text().toFloat() / ui->b->text().toFloat()));
}


void MainWindow::on_pokaz_autora_toggled(bool checked)
{
    if(checked){
        ui->autor->setText("Mateusz Kierepka");
    }
    else{
        ui->autor->setText("???");
    }
}


void MainWindow::on_kalendarz_clicked(const QDate &date)
{
    ui->data->setText(date.toString());
}


void MainWindow::on_suwak_actionTriggered(int action)
{
    ui->label_suwak->setText(QString::number(ui->suwak->value()));
}


void MainWindow::on_dodaj_clicked()
{
    QString nazwisko = ui->nazwisko->text();
    ui->notes->append(nazwisko);
}


void MainWindow::on_pushButton_clicked()
{
    QString liczba = ui->liczba->text(); //pobranie liczby z komponentu lineEdit

    ui->lista->addItem(liczba); //dodanie do listWidget

    int liczbaPozycji = ui->lista->count();
    ui->label_liczbaPozycji->setText(QString::number(liczbaPozycji)); //wyświetlenie ilości liczb

    int suma = 0;
    for(int i=0; i<liczbaPozycji; i++){
        QString lista = ui->lista->item(i)->text();
        suma += lista.toInt();
    }

    ui->suma->setText(QString::number(suma)); //wyświetlenie sumy liczb
}


void MainWindow::on_wyczysc_clicked()
{
    ui->lista->clear();
}


void MainWindow::on_plusplus_clicked()
{
    int liczba = ui->dane2->value(); //pobranie liczby z komponentu spinBox

    ui->lista->addItem(QString::number(liczba)); //dodanie do listWidget

    int liczbaPozycji = ui->lista->count();
    ui->label_liczbaPozycji->setText(QString::number(liczbaPozycji)); //wyświetlenie ilości liczb

    int suma=0;
    for(int i=0; i<liczbaPozycji; i++){
        QString listaa = ui->lista->item(i)->text();
        suma += listaa.toInt();
    }
    ui->suma->setText(QString::number(suma)); //wyświetlenie sumy liczb
}


void MainWindow::on_zapis_clicked()
{
    QFile file("notes.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug () << "Could not open file for writing";
        return;
    }

    QTextStream out(&file);
    out<<ui->notes->toPlainText();

    file.flush();
    file.close();
}


void MainWindow::on_pusty_clicked()
{
    ui->notes->clear();
}


void MainWindow::on_odczyt_clicked()
{
    QFile file("notes.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug () << "Could not open the file for reading";
        return;
    }

    QTextStream in(&file);
    QString myText = in.readAll();
    ui->notes->setPlainText(myText);

    /*  QTextStream in(&file);
     *  while(!in.atEnd()) {
     *      QString line = in.readLine();
     *      ui->notes->append(line);
     *      }
     */

    file.close();
}


void MainWindow::on_czerwony_clicked()
{
    if(ui->czerwony->isChecked()){
        this->setStyleSheet("background-color: red;");
    }
}


void MainWindow::on_zielony_clicked()
{
    if(ui->zielony->isChecked()){
        this->setStyleSheet("background-color: green;");
    }
}


void MainWindow::on_szary_clicked()
{
    if(ui->szary->isChecked()){
        this->setStyleSheet("background-color: grey;");
    }
}

void MainWindow::on_pokaz_triggered()
{
    ui->a->setVisible(true);
    ui->operacja->setVisible(true);
    ui->b->setVisible(true);
    ui->oblicz->setVisible(true);
    ui->wynik->setVisible(true);
}


void MainWindow::on_ukryj_triggered()
{
    ui->a->setVisible(false);
    ui->operacja->setVisible(false);
    ui->b->setVisible(false);
    ui->oblicz->setVisible(false);
    ui->wynik->setVisible(false);
}


void MainWindow::on_actionKopiuj_triggered()
{
    ui->notes->copy();
}


void MainWindow::on_actionWytnij_triggered()
{
    ui->notes->cut();
}

void MainWindow::on_actionWklej_triggered()
{
    ui->notes->paste();
}


void MainWindow::on_actionk1_triggered()
{
    QMessageBox::information(this, "Komunikat 1", "Informacja");
    QMessageBox::warning(this, "Komunikat 1", "Ostrzeżenie!", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
}

void MainWindow::on_actionk2_triggered()
{
    QMessageBox::question(this, "Komunikat 2", "Czy kochasz Informatykę?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
}

