#ifndef FM_CONTATOS_H
#define FM_CONTATOS_H
#include <QSqlQuery>
#include <QDialog>


namespace Ui {
class fm_contatos;
}

class fm_contatos : public QDialog
{
    Q_OBJECT

public:
    explicit fm_contatos(QWidget *parent = nullptr);
    ~fm_contatos();

private slots:
    void on_btn_novo_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::fm_contatos *ui;
};

#endif // FM_CONTATOS_H
