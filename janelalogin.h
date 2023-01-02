#ifndef JANELALOGIN_H
#define JANELALOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQuery>
#include "fm_principal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class janelaLogin; }
QT_END_NAMESPACE

class janelaLogin : public QMainWindow
{
    Q_OBJECT

public:
    janelaLogin(QWidget *parent = nullptr);
    ~janelaLogin();

private slots:
    void on_btn_login_clicked();

private:
    Ui::janelaLogin *ui;
};
#endif // JANELALOGIN_H
