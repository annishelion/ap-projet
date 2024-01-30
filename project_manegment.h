#ifndef PROJECT_MANEGMENT_H
#define PROJECT_MANEGMENT_H

#include <QMainWindow>

namespace Ui {
class project_manegment;
}

class project_manegment : public QMainWindow
{
    Q_OBJECT

public:
    explicit project_manegment(QWidget *parent = nullptr);
    ~project_manegment();

private:
    Ui::project_manegment *ui;
};

#endif // PROJECT_MANEGMENT_H
