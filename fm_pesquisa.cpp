#include "fm_pesquisa.h"
#include "ui_fm_pesquisa.h"
#include <QtSql>
#include <QMessageBox>
#include "fm_editar.h"

fm_pesquisa::fm_pesquisa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_pesquisa)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("select * from tb_contatos ");
    if(query.exec()){
        int cont = 0;
        ui->tw_contatos->setColumnCount(4);
        while(query.next()){
            ui->tw_contatos->insertRow(cont);
            ui->tw_contatos->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tw_contatos->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tw_contatos->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tw_contatos->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));

            ui->tw_contatos->setRowHeight(cont,25);

            cont++;
        }

        ui->tw_contatos->setColumnWidth(0,30);
        ui->tw_contatos->setColumnWidth(1,150);
        ui->tw_contatos->setColumnWidth(3,200);
        QStringList cabecalhos={"ID","Nome","Telefone","Email"};
        ui->tw_contatos->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_contatos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_contatos->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_contatos->verticalHeader()->setVisible(false);
        ui->tw_contatos->setStyleSheet("QTableView{selection-background-color:blue}");

    }

    else{
        QMessageBox::warning(this,"erro","Não foi possivel realizar a consulta");
    }
}

fm_pesquisa::~fm_pesquisa()
{
    delete ui;
}

void fm_pesquisa::on_btn_excluir_clicked()
{
    int linha = ui->tw_contatos->currentRow();
    QString id = ui->tw_contatos->item(linha,0)->text();
    QSqlQuery query;
    if(query.exec("delete from tb_contatos where id_contato = '"+id+"'")){
        qDebug() << query.lastError().text();
        ui->tw_contatos->removeRow(linha);
        QMessageBox::warning(this,"Sucesso","arquivo excluido com sucesso");
    }

    else {
        QMessageBox::warning(this,"Falha","Erro ao excluir arquivo");
    }


}


void fm_pesquisa::on_btn_editar_clicked()
{   int linha = ui->tw_contatos->currentRow();
    int id = ui->tw_contatos->item(linha,0)->text().toInt();
    fm_editar editar(this,id);
    editar.exec();
    QSqlQuery query;
    query.prepare("select * from tb_contatos where id_contato="+QString::number(id));
    if(query.exec()){
        query.first();
        ui->tw_contatos->setItem(linha,1,new QTableWidgetItem(query.value(1).toString()));
        ui->tw_contatos->setItem(linha,2,new QTableWidgetItem(query.value(2).toString()));
        ui->tw_contatos->setItem(linha,3,new QTableWidgetItem(query.value(3).toString()));
    }


}

