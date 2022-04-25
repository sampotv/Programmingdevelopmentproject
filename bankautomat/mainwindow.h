#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "pankki.h"
//#include "nosto.h"
#include "valikko.h"

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Muuttuja käyttäjän id:n tallentamiseen
    int korttiID;
    int yritykset = 0;

private slots:

    void loginSlot (QNetworkReply *reply);
    void on_btnLogin_clicked();
    void numberPressed();
    void clearButtonPressed();



private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    Valikko *objValikko;
    QString idtili;
    int id;

};
#endif // MAINWINDOW_H
