#include "admintabwidget.h"
#include "ui_admintabwidget.h"

AdminTabWidget::AdminTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::AdminTabWidget)
{
    ui->setupUi(this);
}

AdminTabWidget::~AdminTabWidget()
{
    delete ui;
}
