#ifndef PANKKI_H
#define PANKKI_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Pankki;
}

class Pankki : public QDialog
{
    Q_OBJECT

public:
    explicit Pankki(QWidget *parent = nullptr);
    void setId(const QString &value);
    ~Pankki();

private slots:
    void on_btnDebit_clicked();
    void on_btnCredit_clicked();

    void creditSlot(QNetworkReply *reply);
    void debitSlot(QNetworkReply *reply);

    void on_btnLogoutPankki_clicked();

private:
    Ui::Pankki *ui;
    QNetworkAccessManager *creditManager;
    QNetworkAccessManager *debitManager;
    QNetworkReply *reply;
    QString idtili;
    QTimer *objTimer; //Ajastin 13_12
};

#endif // PANKKI_H
