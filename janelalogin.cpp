#include "janelalogin.h"
#include "ui_janelalogin.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QFile>
#include <iostream>

static QSqlDatabase bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");

janelaLogin::janelaLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::janelaLogin)
{
    ui->setupUi(this);

    bancoDeDados.setDatabaseName("C:/Users/Usuario/Documents/estudos/c++/QTcreator/agenda_v1/banco_de_dados/login.db");
    if(!bancoDeDados.open()){
        ui->label->setText("Não foi possivel abrir o banco de dados");
    }
    else{
        ui->label->setText("banco de dados aberto com sucesso");
    }
     /*QSqlQuery reserva;
    if(!reserva.exec("CREATE TABLE tb_contatos (id_contato       INTEGER      PRIMARY KEY AUTOINCREMENT NOT NULL,nome_contato     VARCHAR (30) NOT NULL,telefone_contato VARCHAR (15) NOT NULL,email_contato    VARCHAR (50) NOT NULL)")){
         qDebug() << reserva.lastError().text();
    }*/

}

janelaLogin::~janelaLogin()
{
    delete ui;
}


void janelaLogin::on_btn_login_clicked()
{



    QString username ="tutu"; //ui->txt_username ->text();
    QString senha ="123"; //ui -> txt_senha->text();
    if(!bancoDeDados.isOpen()) {
        qDebug() << "banco de dados não aberto";
        return;
    }


    else{
         ui->label->setText("banco existe");
    }

    QSqlQuery query;

    ui->txt_username->setFocus();

    if(query.exec( "SELECT * FROM tb_logins WHERE usename='"+username+"' AND senha='"+senha+"'"))

    {
        qDebug() << query.lastError().text();
        int cont = 0;
        while(query.next()){
            cont++;
        }

        if(cont > 0 ){
            this->close();
            fm_principal f_principal;
            f_principal.setModal(true);
            f_principal.exec();
        }

        else {
            ui->label->setText("Usuario não encontrado");
            ui->txt_username->clear();
            ui->txt_senha->clear();
            ui->txt_username->setFocus();
        }


    }

    else{
        ui->label->setText("Falha ao abrir banco de dados");
        ui->txt_username->clear();
        ui->txt_senha->clear();
        ui->txt_username->setFocus();
    }
}

