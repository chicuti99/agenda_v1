#ifndef FM_EDITAR_H
#define FM_EDITAR_H

#include <QDialog>

namespace Ui {
class fm_editar;
}

class fm_editar : public QDialog
{
    Q_OBJECT

public:
    explicit fm_editar(QWidget *parent = nullptr,int id_contato=0);
    ~fm_editar();

private slots:
    void on_btn_gravar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::fm_editar *ui;
};

#endif // FM_EDITAR_H
