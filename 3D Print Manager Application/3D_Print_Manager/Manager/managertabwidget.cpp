#include "managertabwidget.h"
#include "ui_managertabwidget.h"

ManagerTabWidget::ManagerTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::ManagerTabWidget)
{
    this->setTabShape(QTabWidget::Triangular);
    this->setTabPosition(QTabWidget::North);

    ui_Orders = new OrdersForm;

    this->addTab(ui_Orders, "Заказы");

    connect(ui_Orders, SIGNAL(tabcreateNewOrder()),
            this, SLOT(createNewOrder()));
    connect(ui_Orders, SIGNAL(tabopenOrder()),
            this, SLOT(openOrder()));
    ui->setupUi(this);
}

ManagerTabWidget::~ManagerTabWidget()
{
    delete ui_Order;
    delete ui_Orders;
    delete ui;
}

void ManagerTabWidget::initManagerWithDB(const QString &DBFilePath)
{
    db_manager.connectToDatabase(DBFilePath);
    ui_Orders->createOrdersModel(db_manager.mw_db);
}

void ManagerTabWidget::createNewOrder()
{
    QString ordername = ui_Orders->getName();
    if(ordername.isEmpty())
        QMessageBox::warning(this, "Ошибка", "Поле имя не должно быть пустым!");
    else
    {
        QList<QString> params = db_manager.createNewOrder(ordername);
        createOrderTab(params);
    }
}

void ManagerTabWidget::openOrder()
{
    QString orderid = ui_Orders->getID();
    if(orderid.isEmpty())
        QMessageBox::warning(this, "Ошибка", "Поле id не должно быть пустым!");
    else
    {
        if(db_manager.mw_db.tables().contains(orderid))
        {
            QList<QString> params = db_manager.getOrderParams(orderid);
            createOrderTab(params);
        }
        else QMessageBox::critical(this, "Ошибка", "Заказ не найден!");
    }
}

void ManagerTabWidget::createOrderTab(const QList<QString> &params)
{
    ui_Order = new OrderForm;
    connect(ui_Order, SIGNAL(closeTab()),
            this, SLOT(closeOrder()));
    this->addTab(ui_Order, QString("Заказ id %1").arg(params[0]));
    ui_Order->createOrderModel(db_manager.mw_db, params[0]);
    ui_Order->setlabel(params);
}

void ManagerTabWidget::closeOrder()
{
    this->removeTab(currentIndex());
}
