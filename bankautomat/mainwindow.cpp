#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Kirjautumisnäytön numeropainikkeiden array
    QPushButton *numButtons[10];
    for (int i = 0; i < 10; ++i) {
        QString numButtonName = "Button_" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(numButtonName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(numberPressed()));
    }
    connect(ui->Button_Clear, SIGNAL(released()), this,
            SLOT(clearButtonPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
    ui=nullptr;
    //delete objPankki;
    //objPankki=nullptr;
}

void MainWindow::numberPressed() {
    QPushButton *button = (QPushButton *)sender();
    QString buttonValue = button->text();
    QString currentPasswordValue = ui->lineEditPassword->text();
    if ((currentPasswordValue == "")) {
        ui->lineEditPassword->setText(buttonValue);
} else {
        QString newPasswordValue = currentPasswordValue + buttonValue;
        ui->lineEditPassword->setText(newPasswordValue);
    }
}

void MainWindow::clearButtonPressed() {
    ui->lineEditPassword->setText("");
}

void MainWindow::on_btnLogin_clicked()
{
    QJsonObject json; //luodaan JSON objekti ja lisätään data
    json.insert("idKortti",ui->lineEditUsername->text());
    json.insert("pin",ui->lineEditPassword->text());
    QString site_url="http://localhost:3000/login";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));
    reply = loginManager->post(request, QJsonDocument(json).toJson());
}

void MainWindow::loginSlot(QNetworkReply *reply)
{

    QByteArray response_data=reply->readAll();
    //qDebug()<<"response"+response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();

    foreach (const QJsonValue &value, json_array)
         {
           QJsonObject json_obj = value.toObject();
           idtili+=QString::number(json_obj["idKortti"].toInt());
         }
        if (response_data!="false"){
            ui->labelLoginDebug->setText("Kirjautumistiedot oikein, avataan pankki.");
            //qDebug()<<"Oikea tunnus ...avaa form";
            QThread::msleep(2000);
            //this->close();
            Valikko *objValikko=new Valikko(response_data);
            //objValikko->setId(response_data);
            qDebug() << response_data;
            //ui->labelLoginDebug->setText("");
            objValikko->show();
            ui -> lineEditUsername->setText("");
            ui -> lineEditPassword->setText("");
            ui->labelLoginDebug->setText("");

        }
        else if (response_data!="true" && yritykset <2){
            //qDebug()<<"Väärä tunnus";
            ui->labelLoginDebug->setText("PIN-koodi väärin, tarkista PIN.");
            //QThread::msleep(2000);
           yritykset++;
}


        else {
            ui->lineEditPassword->setText("");
            ui->lineEditUsername->setText("");
            qDebug()<<"tunnus 3x väärin, suljetaan";
            ui->labelLoginDebug->setText("Syötit tunnuksen liian monesti väärin, suljetaan!");
            QThread::msleep(2000);
                this->close();
}
}

