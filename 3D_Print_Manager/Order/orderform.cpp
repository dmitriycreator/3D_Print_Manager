#include "orderform.h"
#include "ui_orderform.h"

OrderForm::OrderForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderForm)
{
    ui->setupUi(this);
}

OrderForm::~OrderForm()
{
    delete model;
    delete ui;
}

// Метод создания модели таблицы заказов
void OrderForm::createOrderModel(const QSqlDatabase &db, const QString &orderid)
{
    m_orderid = orderid; // получаем id заказа
    model = new QSqlTableModel(this, db); // создание модели на основе БД

    model->setTable(orderid); // подключение к таблице заказа
    model->select();

    // Выбор стратегии изменения
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->tableView_Order->setModel(model); // устанавливаем модель в таблицу

    // Заголовки
    model->setHeaderData(0, Qt::Horizontal, "Id");
    model->setHeaderData(1, Qt::Horizontal, "Имя");
    model->setHeaderData(2, Qt::Horizontal, "Кол-во");
    model->setHeaderData(3, Qt::Horizontal, "Вес");
    model->setHeaderData(4, Qt::Horizontal, "Время печати");
    model->setHeaderData(5, Qt::Horizontal, "Пластик");
    model->setHeaderData(6, Qt::Horizontal, "Брак");
    model->setHeaderData(7, Qt::Horizontal, "Сделана");
    model->setHeaderData(8, Qt::Horizontal, "Коэф. надбавки");

    setCheckBoxes(); // делаем чекбоксы
}

void OrderForm::connectComboBox(const QList<QString> &items)
{
    int count = ui->comboBox_Plastic->count();
    for(int i = 0; i < count; i++)
        ui->comboBox_Plastic->removeItem(i);
    ui->comboBox_Plastic->addItems(items);
}

// Метод установления чекбоксов в таблицу
void OrderForm::setCheckBoxes()
{
    for (int i = 0; i < model->rowCount(); i++)
    {
        // Создание чекбоксов для брак
        QWidget *widget_defective = new QWidget();
        QCheckBox *chBox_defective = new QCheckBox();
        QHBoxLayout *layout_defective = new QHBoxLayout();
        layout_defective->setMargin(0);
        layout_defective->setSpacing(0);
        layout_defective->addWidget(chBox_defective);
        layout_defective->setAlignment(Qt::AlignCenter);
        widget_defective->setLayout(layout_defective);
        ui->tableView_Order->setIndexWidget(model->index(i, 6), widget_defective);

        if(model->data(model->index(i, 6)).toString() == "да") // делаем значение чекбокса
            chBox_defective->setChecked(true);
        else chBox_defective->setChecked(false);

        // Соединяем сигнал со слотом
        connect(chBox_defective, SIGNAL(clicked(bool)),
                this, SLOT(chBox_defectiveChecked(bool)));

        // Создание чекбоксов для сделана
        QWidget *widget_done = new QWidget();
        QCheckBox *chBox_done = new QCheckBox();
        QHBoxLayout *layout_done = new QHBoxLayout();
        layout_done->setMargin(0);
        layout_done->setSpacing(0);
        layout_done->addWidget(chBox_done);
        layout_done->setAlignment(Qt::AlignCenter);
        widget_done->setLayout(layout_done);
        ui->tableView_Order->setIndexWidget(model->index(i, 7), widget_done);

        if(model->data(model->index(i, 7)).toString() == "да") // делаем значение чекбокса
            chBox_done->setChecked(true);
        else chBox_done->setChecked(false);

        // Соединяем сигнал со слотом
        connect(chBox_done, SIGNAL(clicked(bool)),
                this, SLOT(chBox_doneChecked(bool)));
    }
}

// Слоты чекбоксов
void OrderForm::chBox_defectiveChecked(bool isChecked) // щелчок по чекбоксу брак в таблице
{
    QCheckBox *widget = qobject_cast<QCheckBox*>(sender());

    for (int i = 0; i < model->rowCount(); i++)
    {
        if(ui->tableView_Order->indexWidget(model->index(i, 6)) != NULL)
        {
            QWidget *cellWidget = qobject_cast<QWidget*>(ui->tableView_Order->indexWidget(model->index(i, 6)))->layout()->itemAt(0)->widget();
                        if( widget == qobject_cast<QCheckBox*>(cellWidget) )
                        {
                            if( isChecked )
                                model->setData( model->index(i, 6), "да");
                            else
                                model->setData( model->index(i, 6), "нет");

                            model->submitAll();
                        }
        }
    }
}

void OrderForm::chBox_doneChecked(bool isChecked) // щелчок по чекбоксу сделана в таблице
{
    QCheckBox *widget = qobject_cast<QCheckBox*>(sender());

    for (int i = 0; i < model->rowCount(); i++)
    {
        if(ui->tableView_Order->indexWidget(model->index(i, 7)) != NULL)
        {
            QWidget *cellWidget = qobject_cast<QWidget*>(ui->tableView_Order->indexWidget(model->index(i, 7)))->layout()->itemAt(0)->widget();
                        if( widget == qobject_cast<QCheckBox*>(cellWidget) )
                        {
                            if( isChecked )
                                model->setData( model->index(i, 7), "да");
                            else
                                model->setData( model->index(i, 7), "нет");

                            model->submitAll();
                        }
        }
    }
}

void OrderForm::on_toolButton_close_clicked()
{
    emit closeTab();
}

// Метод установления пояснительной надписи заказа
void OrderForm::setlabel(QList<QString> params)
{
    ui->label_Order->setText(QString("Заказ id: %1  имя: %2  дата создания: %3").arg(params[0], params[1], params[2]));
}

void OrderForm::on_pushButton_addPrint_clicked()
{
    // Создаем переменные
    QString ordername = ui->lineEdit_addName->text();
    double amount = ui->spinBox_addAmount->value();
    double time = ui->doubleSpinBox_addWeight->value();
    double weight = ui->doubleSpinBox_addWeight->value();
    double premium_rate = ui->doubleSpinBox_PremiumRate->value();
    // Значения чекбоксов
    bool defective = ui->checkBox_Defective->checkState();
    bool done = ui->checkBox_Done->checkState();
    // Определяем строки исходя из значений чекбоксов
    QString def_text;
    if(defective)
        def_text = "да";
    else def_text = "нет";
    QString done_text;
    if(done)
        done_text = "да";
    else done_text = "нет";

    if(ordername.isEmpty()) // проверка на пустое поле Имя
    {
        QMessageBox::warning(this, "Ошибка", "поле имя не должно быть пустым!");
        return;
    }
    if(amount == 0 || time == 0 || weight == 0 || premium_rate == 0) // проверка на значения равные нулю
    {
        QMessageBox::warning(this, "Ошибка", "значения численных полей должны быть больше нуля!");
        return;
    }

    /* Параметры
     * params[0] - имя
     * params[1] - кол-во
     * params[2] - вес
     * params[3] - время печати
     * params[4] - пластик
     * params[5] - брак
     * params[6] - сделана
     * params[7] - коэффициент надбавки */
    // Создаем параметры новой печати
    params = {
       ordername,
       QString::number(amount),
       QString::number(weight),
       QString::number(time),
       ui->comboBox_Plastic->currentText(),
       def_text,
       done_text,
       QString::number(premium_rate)
    };
    qDebug() << "request adding Print " << params;
    emit addPrint(); // сигнал к созданию новой печати
    model->select(); // обновляем таблицу
    setCheckBoxes(); // добавляем чекбоксы
}

QString OrderForm::getID() // метод получения id заказа
{
    return m_orderid;
}

QList<QString> OrderForm::getPrintParams() // метод получения параметров печати из формы
{
    return params;
}

void OrderForm::on_lineEdit_deleteID_textEdited(const QString &arg1)
{
    m_printid = arg1;
}


void OrderForm::on_pushButton_deletePrint_clicked()
{
    if(m_printid.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Поле id не должно быть пустым");
        return;
    }
    emit deletePrint(); // сигнал к удалению печати
    model->select(); // обновляем таблицу
    setCheckBoxes(); // добавляем чекбоксы
}

QString OrderForm::getPrintId() // метод получения id печати на удаление
{
    return m_printid;
}

void OrderForm::on_pushButton_findCost_clicked()
{
    emit findCost_button();
}


void OrderForm::on_pushButton_finish_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Завершить?", "Вы уверены что хотите завершить заказ?", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
        emit finishOrder_clicked();
}


void OrderForm::on_pushButton_deleteOrder_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Удалить?", "Вы уверены что хотите удалить заказ?", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
        emit deleteOrder_clicked();
}

