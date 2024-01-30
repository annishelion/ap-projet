#ifndef ORGAN_MANEGMENT_H
#define ORGAN_MANEGMENT_H

#include <QMainWindow>

namespace Ui {
class organ_manegment;
}

class organ_manegment : public QMainWindow
{
    Q_OBJECT

public:
    explicit organ_manegment(QWidget *parent = nullptr);
    ~organ_manegment();

private slots:
    void on_pushButton_clicked();

    void on_show_my_organization_btn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::organ_manegment *ui;
};

#endif // ORGAN_MANEGMENT_H
