#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QTextStream>
#include <ctime>
#include <cstdlib>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Mateusz/Desktop/project/RealMadrid.png");
    QPixmap pix2("C:/Users/Mateusz/Desktop/project/ManchesterCity.png");

    ui->label_real->setPixmap(pix);
    ui->label_mancity->setPixmap(pix2);

    ui->dodajStrzelca_mancity->setVisible(false);
    ui->dodajStrzelca_real->setVisible(false);
    ui->label_nazwiskostrzelcy_mancity->setVisible(false);
    ui->label_nazwiskostrzelcy_real->setVisible(false);
    ui->strzelec_mancity->setVisible(false);
    ui->strzelec_real->setVisible(false);
    ui->strzelcy_real->setVisible(false);
    ui->strzelcy_mancity->setVisible(false);

    QPixmap sciezka("C:/Users/Mateusz/Desktop/project/tlo.jpg");
    ui->tlo->setScaledContents(true);
    ui->tlo->setPixmap(sciezka);
}

int gen_liczb(int a, int b){
    return rand () % (b - a + 1) + a;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_koniec_clicked()
{
    ui->wylosuj_wynik->setVisible(false);
    ui->koniec->setVisible(false);
    ui->losuj->setVisible(false);

    ui->dodajStrzelca_mancity->setVisible(true);
    ui->dodajStrzelca_real->setVisible(true);
    ui->label_nazwiskostrzelcy_mancity->setVisible(true);
    ui->label_nazwiskostrzelcy_real->setVisible(true);
    ui->strzelec_mancity->setVisible(true);
    ui->strzelec_real->setVisible(true);
    ui->strzelcy_real->clear();
    ui->strzelcy_mancity->clear();
    ui->strzelcy_real->setVisible(true);
    ui->strzelcy_mancity->setVisible(true);
}


void MainWindow::on_wyczysc_triggered()
{
    liczbaGoli_real = 0;
    liczbaGoli_mancity = 0;
    ui->licznik_real->setText(QString::number(liczbaGoli_real));
    ui->licznik_mancity->setText(QString::number(liczbaGoli_mancity));

    ui->koniec->setVisible(true);
    ui->wylosuj_wynik->setVisible(true);
    ui->losuj->setVisible(true);
    ui->lacznieBramek->setText("0");

    liczbaPozycji_real = 0;
    liczbaPozycji_mancity = 0;
    ui->strzelcy_real->setVisible(false);
    ui->strzelcy_mancity->setVisible(false);
    ui->label_nazwiskostrzelcy_real->setVisible(false);
    ui->label_nazwiskostrzelcy_mancity->setVisible(false);
    ui->strzelec_real->setVisible(false);
    ui->strzelec_mancity->setVisible(false);
    ui->dodajStrzelca_real->setVisible(false);
    ui->dodajStrzelca_mancity->setVisible(false);
}


void MainWindow::on_dodajStrzelca_real_clicked()
{
    if(liczbaPozycji_real < liczbaGoli_real){
        QString nazwisko = ui->strzelec_real->text();
        ui->strzelcy_real->append(nazwisko);
        liczbaPozycji_real++;
    }
}


void MainWindow::on_dodajStrzelca_mancity_clicked()
{
    if(liczbaPozycji_mancity < liczbaGoli_mancity){
        QString nazwisko = ui->strzelec_mancity->text();
        ui->strzelcy_mancity->append(nazwisko);
        liczbaPozycji_mancity++;
    }
}


void MainWindow::on_losuj_clicked()
{
    liczbaGoli_real = gen_liczb(0, 5);
    ui->licznik_real->setText(QString::number(liczbaGoli_real));

    liczbaGoli_mancity = gen_liczb(0, 5);
    ui->licznik_mancity->setText(QString::number(liczbaGoli_mancity));

    ui->lacznieBramek->setText(QString::number(liczbaGoli_real + liczbaGoli_mancity));
}


void MainWindow::on_zmien_druzyne_1_clicked()
{
    if (liczbaGoli_real != 0 || liczbaGoli_mancity != 0){
        QMessageBox::warning(this, "Ostrzeżenie", "Nie można teraz dokonać zmiany drużyny", QMessageBox::Ok);
    }
    else{
        if(druzyna_1 == 0){
            QPixmap pix3("C:/Users/Mateusz/Desktop/project/FCBarcelona.png");
            ui->label_real->setPixmap(pix3);
            ui->label_podpis_real->setText("FC Barcelona");
            druzyna_1 = 1;
        }
        else if (druzyna_1 == 1){
            QPixmap pix("C:/Users/Mateusz/Desktop/project/RealMadrid.png");
            ui->label_real->setPixmap(pix);
            ui->label_podpis_real->setText("Real Madryt");
            druzyna_1 = 0;
        }
    }
}

void MainWindow::on_zmien_druzyne_2_clicked()
{
    if (liczbaGoli_real != 0 || liczbaGoli_mancity != 0){
        QMessageBox::warning(this, "Ostrzeżenie", "Nie można teraz dokonać zmiany drużyny", QMessageBox::Ok);
    }
    else{
        if(druzyna_2 == 0){
        QPixmap pix4("C:/Users/Mateusz/Desktop/project/BayernMonachium.png");
            ui->label_mancity->setPixmap(pix4);
            ui->label_podpis_mancity->setText("Bayern Monachium");
            druzyna_2 = 1;
        }
        else if (druzyna_2 == 1){
        QPixmap pix2("C:/Users/Mateusz/Desktop/project/ManchesterCity.png");
            ui->label_mancity->setPixmap(pix2);
            ui->label_podpis_mancity->setText("Manchester City");
            druzyna_2 = 0;
        }
    }
}

