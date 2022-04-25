#include "valikko.h"
#include <QDebug>
#include "ui_valikko.h"


Valikko::Valikko(QString id,  QWidget *parent) :

    QDialog(parent),
    ui(new Ui::Valikko)
{
    ui->setupUi(this);
    idtili=id;
    objPankki=new Pankki;
    objNosto=new Nosto(idtili);
    //objMainWindow=new MainWindow;

    objTimer= new QTimer;//ajastin 13_12
    connect(objTimer,SIGNAL(timeout()),this,SLOT(stopSLOT()));//ajastin 13_12
    counter=0;
    objTimer->start(8000);
    QString site_url="http://localhost:3000/asiakas/"+id;
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaAsiakasTiedotManager = new QNetworkAccessManager(this);
    connect(naytaAsiakasTiedotManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(naytaAsiakasTiedotSlot(QNetworkReply*)));
    reply = naytaAsiakasTiedotManager->get(request);

}

void Valikko::setId(const QString &value)
{
    idtili = value;
}

Valikko::~Valikko()
{
    delete ui;
}

void Valikko::stopSLOT()
{

    qDebug()<< "Aika =  " +counter;
    counter++;
    if(counter==1)
    {
        objTimer->stop();
        delete objTimer;
        objTimer=nullptr;
        this->close();
    }
}
void Valikko::on_btnNosto_clicked()
{
    objTimer->stop();
    //this -> close();
    objNosto->setId(idtili);
    objNosto->show();
}



void Valikko::on_btnSaldo_clicked()
{
    objTimer->start(8000);//ajastin 14-12
    QJsonObject json;
    QString site_url="http://localhost:3000/tili/"+idtili;
    //qDebug()<<"saldo="+idtili;
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaSaldoManager = new QNetworkAccessManager(this);
    connect(naytaSaldoManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(naytaSaldoSlot(QNetworkReply*)));
    reply = naytaSaldoManager->get(request);

}

void Valikko::naytaSaldoSlot(QNetworkReply *reply)
{


    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString saldo;
    foreach (const QJsonValue &value, json_array) {
    QJsonObject json_obj = value.toObject();
    //QString::number();
    saldo+=QString("Tilisi saldo on")+" "+QString::number(json_obj["saldo"].toInt())+"€";
    }
    ui->textEditNaytaAsiakasTiedot->setText(saldo);


}

void Valikko::on_btnSiirto_clicked()
{
    objTimer->stop();
    objPankki->setId(idtili);
    objPankki->show();
}

void Valikko::on_btnTapahtumat_clicked()
{
    objTimer->start(8000);//ajastin 14-12
    QString site_url="http://localhost:3000/tilitapahtumat/"+idtili;
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaTilitapahtumatManager = new QNetworkAccessManager(this);
    connect(naytaTilitapahtumatManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(naytaTilitapahtumatSlot(QNetworkReply*)));
    reply = naytaTilitapahtumatManager->get(request);
}
void Valikko::naytaTilitapahtumatSlot (QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString tilitapahtumat;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        tilitapahtumat+=QString("Tapahtuma")+" "+json_obj["tapahtuma"].toString()+"| Määrä "+QString::number(json_obj["summa"].toInt())+"€ | Aika "+json_obj["pvm"].toString()+"\r";
    }
    ui->textEditNaytaAsiakasTiedot->setText(tilitapahtumat);
}

void Valikko::on_btnKirjauduUlos_clicked()
{
    this->close();
}

void Valikko::on_btnNaytaAsiakasTiedot_clicked()
{
    QString site_url="http://localhost:3000/asiakas/"+idtili;
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaAsiakasTiedotManager = new QNetworkAccessManager(this);
    connect(naytaAsiakasTiedotManager, SIGNAL(finished(QNetworkReply*)), this,
            SLOT(naytaAsiakasTiedotSlot(QNetworkReply*)));
    reply = naytaAsiakasTiedotManager->get(request);
}

void Valikko::naytaAsiakasTiedotSlot(QNetworkReply *reply)
{
    //qDebug()<<json_doc;
    //QString asiakas=json_doc["enimi"].toString()+" : "+json_doc["snimi"].toString()+" : "+json_doc["osoite"].toString()+" : "+json_doc["puhno"].toString();
    //ui->textEditNaytaAsiakasTiedot->setText(asiakas);
//}

    //qDebug()<<json_doc;
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString asiakas;
    foreach (const QJsonValue &value, json_array) {
    QJsonObject json_obj = value.toObject();
    asiakas+=QString(json_obj["enimi"].toString())+" "+json_obj["snimi"].toString()+"\r";
    }
    ui->labelMainTitleNimi->setText(asiakas);
}
