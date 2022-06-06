#ifndef ADMINTABWIDGET_H
#define ADMINTABWIDGET_H

#include <QTabWidget>

namespace Ui {
class AdminTabWidget;
}

class AdminTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit AdminTabWidget(QWidget *parent = nullptr);
    ~AdminTabWidget();

private:
    Ui::AdminTabWidget *ui;
};

#endif // ADMINTABWIDGET_H
