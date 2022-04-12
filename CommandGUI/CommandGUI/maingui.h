# Author: Usman Khan
# Date: 2021-10-5
//header file for GUI

#ifndef MAINGUI_H
#define MAINGUI_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>
#include <QListWidgetItem>
#include <boost/process.hpp>
QT_BEGIN_NAMESPACE
namespace Ui { class MainGui; }
QT_END_NAMESPACE
using namespace boost::process;
class MainGui : public QMainWindow
{
    Q_OBJECT

public:
    MainGui(QWidget *parent = nullptr);
    ~MainGui();

private slots:
    void on_btn_execute_clicked();

    void on_list_histopry_itemClicked(QListWidgetItem *item);

private:
    Ui::MainGui *ui;
    // streem;
    QProcess process;
    QMap<QString,int> *store;
    QMap<QString,QString> *command_store;
};
#endif // MAINGUI_H
