#include "fm_editar.h"
#include <QtSql>
#include "ui_fm_editar.h"
#include <QMessageBox>

static int id;
fm_editar::fm_editar(QWidget *parent,int id_contato) :
    QDialog(parent),
    ui(new Ui::fm_editar)
{
    ui->setupUi(this);
        id=id_contato;
    QSqlQuery query;
    if(query.exec("select * from tb_contatos where id_contato="+QString::number(id_contato))){
        query.first();
        ui->ln_nome->setText(query.value(1).toString());
        ui->ln_tel->setText(query.value(2).toString());
        ui->ln_email->setText(query.value(3).toString());
    }
    else{
        QMessageBox::warning(this,"erro","Não foi possivel realizar a operação");
    }
}

fm_editar::~fm_editar()
{
    delete ui;
}

void fm_editar::on_btn_gravar_clicked()
{
    QString nome = ui->ln_nome->text();
    QString tel = ui->ln_tel->text();
    QString email = ui->ln_email->text();

    QSqlQuery query;
    if(query.exec("update tb_contatos set nome_contato='"+nome+"',telefone_contato='"+tel+"',email_contato='"+email+"' where id_contato="+QString::number(id))){
        qDebug() << query.lastError().text();
        this->close();

    }
    else {
        QMessageBox::warning(this,"erro","falha");
    }
}


void fm_editar::on_btn_cancelar_clicked()
{
    this->close();
}

