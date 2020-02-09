#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wgt = new QPaintWidget(this);
    ui->verticalLayout->addWidget(wgt);
}

MainWindow::~MainWindow()
{
    wgt->deleteLater();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::string light_x_pos = ui->lightX->text().toStdString();
    std::string light_y_pos = ui->lightY->text().toStdString();
    std::string light_z_pos = ui->lightZ->text().toStdString();

    std::string cam_x_pos = ui->camX->text().toStdString();
    std::string cam_y_pos = ui->camY->text().toStdString();
    std::string cam_z_pos = ui->camZ->text().toStdString();

    std::string turn_x = ui->turnX->text().toStdString();
    std::string turn_y = ui->turnY->text().toStdString();
    std::string turn_z = ui->turnZ->text().toStdString();

    O = {std::stod(cam_x_pos), std::stod(cam_y_pos), std::stod(cam_z_pos)};
    lamp.pos = {std::stod(light_x_pos), std::stod(light_y_pos), std::stod(light_z_pos)};
    angle = {std::stod(turn_x), std::stod(turn_y), std::stod(turn_z)};
    coeff_n = std::stod(ui->lineEdit->text().toStdString());
    isball = ui->checkBox->isChecked();
    update();


}

void MainWindow::on_action_triggered()
{
    QMessageBox msg;
    msg.setText("Программа моделирует стержень в стакане с жидкостью. Имеется возможность изменять показатель преломления и добавлять наконечник в виде шара.\nАвтор: студент ИУ7-54Б Шестаков Андрей");
    msg.exec();
}

void MainWindow::on_action_2_triggered()
{
    qApp->quit();
}
