#include "managertabwidget.h"
#include "ui_managertabwidget.h"

ManagerTabWidget::ManagerTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::ManagerTabWidget)
{
    // Устанавливаем форму и позицию вкладок
    this->setTabShape(QTabWidget::Triangular);
    this->setTabPosition(QTabWidget::North);

    // Добавляем вкладку Заказы
    ui_Orders = new OrdersForm;

    this->addTab(ui_Orders, "Заказы");

    // Сигналы окна заказов
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

// Метод инициализации виджета менеджера базой данных
void ManagerTabWidget::initManagerWithDB(const QString &DBFilePath)
{
    db_manager.connectToDatabase(DBFilePath); // подключаемся к БД
    ui_Orders->createOrdersModel(db_manager.mw_db); // создаем модель таблицы в окне заказов
}

// Метод создания нового заказа
void ManagerTabWidget::createNewOrder()
{
    QString ordername = ui_Orders->getName(); // получаем имя заказа
    // Проверка на пустое поле
    if(ordername.isEmpty())
        QMessageBox::warning(this, "Ошибка", "Поле имя не должно быть пустым!");
    else
    {
        QList<QString> params = db_manager.createNewOrder(ordername); // получаем данные о заказе
        createOrderTab(params); // создаем вкладку заказа на основе параметров заказа
    }
}

// Метод открытия заказа
void ManagerTabWidget::openOrder()
{
    QString orderid = ui_Orders->getID(); // получаем id

    // Проверка на пустое поле
    if(orderid.isEmpty())
        QMessageBox::warning(this, "Ошибка", "Поле id не должно быть пустым!");
    else
    {
        // Заказ должен быть в БД
        if(db_manager.mw_db.tables().contains(orderid))
        {
            QList<QString> params = db_manager.getOrderParams(orderid); // получаем параметры заказа
            createOrderTab(params); // создаем вкладку заказа
        }
        else QMessageBox::critical(this, "Ошибка", "Заказ не найден!");
    }
}

// Метод добавления новой печати
void ManagerTabWidget::addPrint()
{
    OrderForm *form = (OrderForm*) sender(); // определяем объект, который вызвал сигнал
    QString orderid = form->getID(); // получаем id заказа
    QList<QString> params = form->getPrintParams(); // получаем параметры новой печати
    qDebug() << "adding Print accepted " << orderid << " " << params;
    db_manager.addPrint(orderid, params); // запрос в БД
}

// Метод удаления печати
void ManagerTabWidget::deletePrint()
{
    OrderForm *form = (OrderForm*) sender(); // определяем объект, который вызвал сигнал
    QString orderid = form->getID(); // получаем id заказа
    QString printid = form->getPrintId(); // получаем id печати
    qDebug() << "deleting Print accepted order " << orderid << " print " << printid;
    db_manager.deletePrint(orderid, printid); // запрос в БД
}

// Метод расчета стоимости заказа
void ManagerTabWidget::findCost()
{
    OrderForm *form = (OrderForm*) sender();
    QString orderid = form->getID();
    double cost = db_manager.findCost(orderid);
    QMessageBox::information(this, QString("стоимость заказа %1").arg(orderid), QString("Стоимость заказа: %1 р").arg(cost));
}

// Метод создания вкладки заказа
void ManagerTabWidget::createOrderTab(const QList<QString> &params)
{
    ui_Order = new OrderForm; // создаем окно работы с заказом
    // Подключаем сигналы окна
    connect(ui_Order, SIGNAL(closeTab()),
            this, SLOT(closeOrder()));
    connect(ui_Order, SIGNAL(addPrint()),
            this, SLOT(addPrint()));
    connect(ui_Order, SIGNAL(deletePrint()),
            this, SLOT(deletePrint()));
    connect(ui_Order, SIGNAL(findCost_button()),
            this, SLOT(findCost()));
    connect(ui_Order, SIGNAL(finishOrder_clicked()),
            this, SLOT(finishOrder()));
    connect(ui_Order, SIGNAL(deleteOrder_clicked()),
            this, SLOT(deleteOrder()));
    // Добавляем вкладку
    this->addTab(ui_Order, QString("Заказ id %1").arg(params[0]));
    ui_Order->createOrderModel(db_manager.mw_db, params[0]); // создаем модель таблицы
    ui_Order->setlabel(params); // делаем заголовок
    ui_Order->connectComboBox(db_manager.getPlasticNames()); // устанавливаем пластики в комбобокс
}

// Метод закрытия вкладки с заказом
void ManagerTabWidget::closeOrder()
{
    this->removeTab(currentIndex());
}

// Метод завершения заказа
void ManagerTabWidget::finishOrder()
{
    OrderForm *form = (OrderForm*) sender(); // определяем объект отправивший запрос
    QString orderid = form->getID();
    double income = db_manager.findIncome(orderid); // получаем доход
    QMessageBox::information(this, QString("Заказ %1 завершен").arg(orderid), QString("Доход с заказа: %1 р").arg(income));
    this->removeTab(currentIndex()); // закрываем текущую кладку
    delete (OrderForm*) sender(); // удаляем объект
    db_manager.deleteOrder(orderid); // удаляем заказ из БД
    ui_Orders->refresh();
}

// Метод удаления заказа
void ManagerTabWidget::deleteOrder()
{
    OrderForm *form = (OrderForm*) sender();
    QString orderid = form->getID();
    double consumtion = db_manager.findConsumtion(orderid); // получем убытки
    QMessageBox::information(this, QString("Заказ %1 удален").arg(orderid), QString("Убытки: %1 р").arg(consumtion));
    this->removeTab(currentIndex());
    delete (OrderForm*) sender();
    db_manager.deleteOrder(orderid);
    ui_Orders->refresh();
}

//-------------------МЕТОДЫ ДЛЯ АДМИНА-------------------//
// Метод добавления пользователя
bool ManagerTabWidget::addUser(const QList<QString> params)
{
    if(db_manager.searchUser(params[0]))
    {
        return false;
    }
    db_manager.addUser(params);
    return true;
}

// Метод удаления пользователя
void ManagerTabWidget::deleteUser(const QString username)
{
    db_manager.deleteUser(username);
}

// Метод нахождения общего дохода
void ManagerTabWidget::findAllIncome()
{
    double allIncome = db_manager.findAllIncome();
    QMessageBox::information(this, "Общий доход", QString("Общий доход равен: %1").arg(allIncome));
}

// Метод добавления пластика
bool ManagerTabWidget::addPlastic(const QString &name, const QString &cost)
{
    if(db_manager.findPlastic(name))
        return false;
    db_manager.addPlastic(name, cost.toDouble());
    return true;
}

// Метод удаления пластика
void ManagerTabWidget::delPlastic(const QString &name)
{
    db_manager.deletePlastic(name);
}
