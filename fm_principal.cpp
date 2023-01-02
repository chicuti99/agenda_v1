#include "fm_principal.h"
#include "ui_fm_principal.h"
#include "fm_pesquisa.h"
#include "fm_contatos.h"
#include "ui_fm_contatos.h"
fm_principal::fm_principal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_principal)
{
    ui->setupUi(this);
}

fm_principal::~fm_principal()
{
    delete ui;
}

void fm_principal::on_btn_novo_clicked()
{
    fm_contatos f_contatos;
    f_contatos.exec();
}


void fm_principal::on_btn_pesquisar_clicked()
{
    fm_pesquisa pesquisacontatos;
    pesquisacontatos.exec();
}

