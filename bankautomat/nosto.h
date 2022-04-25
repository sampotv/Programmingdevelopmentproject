#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Nosto;
}

class Nosto : public QDialog
{
    Q_OBJECT

public:
    explicit Nosto(QString idnosto, QWidget *parent = nullptr);
    void setId(const QString &value);
    ~Nosto();

private slots:
    void naytaNostoSaldoSlot (QNetworkReply *reply);
    void nostoSlot(QNetworkReply *reply);

    void on_btn20_clicked();

    void on_btn40_clicked();

    void on_btn60_clicked();

    void on_btn100_clicked();

    void on_btn200_clicked();

    void on_btn500_clicked();

    void on_btnHyvaksy_clicked();

    void on_btnTakaisin_clicked();

private:
    Ui::Nosto *ui;
    QString idtili;

    QString x;
    QNetworkAccessManager *nostoManager;
    QNetworkAccessManager *naytaNostoSaldoManager;
    QNetworkReply *reply;

};

#endif // NOSTO_H
