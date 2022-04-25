#include "tapahtumat.h"
#include "ui_tapahtumat.h"

Tapahtumat::Tapahtumat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tapahtumat)
{
    ui->setupUi(this);
}

Tapahtumat::~Tapahtumat()
{
    delete ui;
}

void Tapahtumat::on_btnTapahtumat2_clicked()
{
   /* QJsonObject json; //luodaan JSON objekti ja lisätään data


    //json.insert("id",ui->teTapahtumatID->text());
    QString site_url="http://localhost:3000/siirto/tapahtuma/1";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    tapahtumatManager = new QNetworkAccessManager(this);
    connect(tapahtumatManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(tapahtumatSlot(QNetworkReply*)));
    reply = tapahtumatManager->post(request, QJsonDocument(json).toJson());*/
}

