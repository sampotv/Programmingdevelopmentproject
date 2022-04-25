#ifndef TAPAHTUMAT_H
#define TAPAHTUMAT_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Tapahtumat;
}

class Tapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit Tapahtumat(QWidget *parent = nullptr);
    ~Tapahtumat();

private slots:
    void on_btnTapahtumat2_clicked();
    void tapahtumatSlot(QNetworkReply *reply);

private:
    Ui::Tapahtumat *ui;
    QNetworkAccessManager *tapahtumatManager;
    QNetworkReply *reply;
};

#endif // TAPAHTUMAT_H
