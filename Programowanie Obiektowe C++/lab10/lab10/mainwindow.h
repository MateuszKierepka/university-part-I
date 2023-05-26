#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_oblicz_clicked();

    void on_pokaz_autora_toggled(bool checked);

    void on_kalendarz_clicked(const QDate &date);

    void on_suwak_actionTriggered(int action);

    void on_dodaj_clicked();

    void on_pushButton_clicked();

    void on_wyczysc_clicked();

    void on_plusplus_clicked();

    void on_zapis_clicked();

    void on_pusty_clicked();

    void on_odczyt_clicked();

    void on_czerwony_clicked();

    void on_zielony_clicked();

    void on_szary_clicked();

    void on_pokaz_triggered();

    void on_ukryj_triggered();

    void on_actionKopiuj_triggered();

    void on_actionWytnij_triggered();

    void on_actionWklej_triggered();

    void on_actionk1_triggered();

    void on_actionk2_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
