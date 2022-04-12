// Author: Usman Khan
//Date: 2021-10-05
//functionalities of UI contained here

#include "maingui.h"
#include "ui_maingui.h"

MainGui::MainGui(QWidget *parent) //constructor
    : QMainWindow(parent)
    , ui(new Ui::MainGui)
{
    ui->setupUi(this);
    store = new QMap<QString,int>(); // its the vector
    command_store = new QMap<QString,QString>();
}

MainGui::~MainGui()  //destructor
{
    delete ui;
    delete store;
    delete command_store;
}

void MainGui::on_btn_execute_clicked() // event for execute button click
{
    QString command_text;
    QString output;
    command_text = ui->txt_command->text();

    QStringList command_split = command_text.split(' '); // it will give the command keyword at the index 0
    QString command_keyword = command_split[0];

    if (!command_text.isEmpty()){

        //store the output in a string variable and insert the string into output table.

        // Command to execute
        try{
            ipstream pipe_stream;
            child c(command_text.toStdString(), std_out > pipe_stream);

            std::string line;

            while (pipe_stream && std::getline(pipe_stream, line) && !line.empty())
               output += QString::fromUtf8(line.c_str()) +"\n";

            c.wait();
           }catch(process_error err){
            QMessageBox message;
            message.setText("Command Error!");
            message.exec();
        }
    }
    if(!output.isEmpty()){
        ui->list_output->insertItem(0,new QListWidgetItem(output)); // will insert the output of command into the output list at row 0.

        store->insert(command_text,0);
        ui->txt_status->setText("0");

    }else{
        ui->txt_status->setText("-1");
        store->insert(command_text, -1);
    }
    command_store->insert(command_keyword,output);
    int index = store->count();
    ui->list_histopry->clear();
    foreach(QString command, store->keys()){ // will traverse all the command and its values.
        QString final_text;
        final_text = QString::number(index)+ ": " + command + " (" + QString::number(store->value(command)) + ")";
        ui->list_histopry->insertItem(0,new QListWidgetItem(final_text));
        index -= 1;
    }
}

void MainGui::on_list_histopry_itemClicked(QListWidgetItem *item) // event for history item clicked
{
    QString command = item->text().split(' ')[1];
    QMessageBox message;
    message.setText("Command: " + command + "\nOutput: " + command_store->value(command));
    message.exec();

}
