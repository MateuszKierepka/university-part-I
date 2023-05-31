#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_koniec_clicked();

    void on_wyczysc_triggered();

    void on_dodajStrzelca_real_clicked();

    void on_dodajStrzelca_mancity_clicked();

    void on_losuj_clicked();

    void on_zmien_druzyne_1_clicked();

    void on_zmien_druzyne_2_clicked();

private:
    Ui::MainWindow *ui;
    int liczbaGoli_real = 0;
    int liczbaGoli_mancity = 0;
    int lacznie;

    int liczbaPozycji_real = 0;
    int liczbaPozycji_mancity = 0;

    int druzyna_1 = 0;
    int druzyna_2 = 0;

};
#endif // MAINWINDOW_H
