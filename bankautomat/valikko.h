#ifndef VALIKKO_H
#define VALIKKO_H

#include "nosto.h"
#include "pankki.h"
#include <QDebug>
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QTimer>


namespace Ui {
class Valikko;
}

class Valikko : public QDialog
{
    Q_OBJECT

public:

    explicit Valikko(QString id, QWidget *parent = nullptr);
    //explicit Valikko(int idtili, QWidget *parent = nullptr);

    void setId(const QString &value);

    ~Valikko();

public slots:


private slots:
    void stopSLOT();//ajastin 13_12
    void on_btnNosto_clicked();

    void on_btnSaldo_clicked();
    void naytaSaldoSlot(QNetworkReply *reply);

    void on_btnSiirto_clicked();

    void on_btnTapahtumat_clicked();

    void on_btnKirjauduUlos_clicked();

    void on_btnNaytaAsiakasTiedot_clicked();
    void naytaAsiakasTiedotSlot (QNetworkReply *reply);
    void naytaTilitapahtumatSlot (QNetworkReply *reply);


private:
    Ui::Valikko *ui;
    Pankki *objPankki;
    Nosto *objNosto;
    QNetworkAccessManager *naytaAsiakasTiedotManager;
    QNetworkAccessManager *naytaTilitapahtumatManager;
    QNetworkAccessManager *naytaSaldoManager;
    QNetworkReply *reply;
    int valinta;
    QString idtili;
    int counter;//ajastin 13_12
    QTimer *objTimer; //Ajastin 13_12
};

#endif // VALIKKO_H
