#include "ustawienia.h"
#include "ui_ustawienia.h"

ustawienia::ustawienia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ustawienia)
{
    ui->setupUi(this);
}

ustawienia::~ustawienia()
{
    delete ui;
}
