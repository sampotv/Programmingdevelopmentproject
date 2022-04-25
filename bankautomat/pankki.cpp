#include "pankki.h"
#include "ui_pankki.h"

Pankki::Pankki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pankki)
{

    ui->setupUi(this);

}

Pankki::~Pankki()
{
    delete ui;
}

void Pankki::setId(const QString &value)
{
    idtili = value;
    ui->laOmatilinro->setText(idtili);
}

void Pankki::on_btnDebit_clicked()
{
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("id1",ui->laOmatilinro->text());
    json.insert("id2",ui->leDebitSaaja->text());
    json.insert("summa",ui->leDebitSumma->text());
    QString site_url="http://localhost:3000/siirto/debit_transfer";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    debitManager = new QNetworkAccessManager(this);
    connect(debitManager, SIGNAL(finished(QNetworkReply*)), this,
            SLOT(debitSlot(QNetworkReply*)));
    reply = debitManager->post(request, QJsonDocument(json).toJson());
}

void Pankki::debitSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    if(response_data == "1"){
        ui->labelDebitInfo->setText("Siirto onnistui");
        ui->leDebitSaaja->setText("");
        ui->leDebitSumma->setText("");
    }
    else {
        ui->labelDebitInfo->setText("Siirto epäonnistui");
        ui->leDebitSaaja->setText("");
        ui->leDebitSumma->setText("");
    }
}




void Pankki::on_btnCredit_clicked()
{

}

void Pankki::creditSlot(QNetworkReply *reply)
{

}

void Pankki::on_btnLogoutPankki_clicked()
{
    this->close();
}
