#include "fm_contatos.h"
#include "ui_fm_contatos.h"
#include <QMessageBox>
#include <QDebug>
#include <QtSql>

fm_contatos::fm_contatos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_contatos)
{
    ui->setupUi(this);
}

fm_contatos::~fm_contatos()
{
    delete ui;
}




void fm_contatos::on_btn_novo_clicked()
{
    QString nome = ui->txt_nome->text();
    QString tel =ui->txt_tel->text();
    QString email = ui->txt_email->text();

    QSqlQuery query;
    if(query.exec("insert into tb_contatos (nome_contato,telefone_contato,email_contato) values('"+nome+"','"+tel+"','"+email+"')")){
        qDebug() << query.lastError().text();
        QMessageBox::information(this,"SUCESSO","Registro gravado com sucesso");
        ui->txt_nome->clear();
        ui->txt_email->clear();
        ui->txt_tel->clear();
        ui->txt_nome->setFocus();
    }

    else {
        qDebug() << query.lastError().text();
        qDebug() << "erro ";
    }
}
