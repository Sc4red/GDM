#ifndef USTAWIENIA_H
#define USTAWIENIA_H

#include <QDialog>

namespace Ui {
class ustawienia;
}

class ustawienia : public QDialog
{
    Q_OBJECT

public:
    explicit ustawienia(QWidget *parent = nullptr);
    ~ustawienia();

private:
    Ui::ustawienia *ui;
};

#endif // USTAWIENIA_H
