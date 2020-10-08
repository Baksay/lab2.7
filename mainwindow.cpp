#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"


void MainWindow::addVariant() {
    QString str = lineEdit->text();
    lineEdit->clear();
    comboBox->addItem(str);
}

void MainWindow::displayText(const QString& str) {
    statusBar->clearMessage();
    statusBar->showMessage(str);
}

void MainWindow::closeEvent(QCloseEvent* event) {

    Dialog* dialog = new Dialog(this);
    dialog->setWindowTitle("Close event");
    switch (dialog->exec()) {

    case QDialog::Accepted:
        break;

    case QDialog::Rejected:
        dialog->close();
        event->ignore();
        delete dialog;
        break;
    }
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("lab7 version 1.0");
    widget = new QWidget();
    widget->setMinimumSize({ 450,300 });
    widget->setMaximumSize({ 450,300 });
    setMinimumSize({ 500,350 });
    setMaximumSize({ 500,350 });
    grid = new QGridLayout();

    label1 = new QLabel("If you want to change message in status bar\nchoose the option in combo box.\n\n"
        "If you want to add new option in comboBox\ninput its name in the lineEdit and push the button");
    lineEdit = new QLineEdit();

    pushButton = new QPushButton("Add new option");

    comboBox = new QComboBox();
    comboBox->addItem("Test item");

    connect(pushButton, SIGNAL(clicked()), this, SLOT(addVariant()));

    statusBar = new QStatusBar();

    grid->addWidget(label1, 0, 0);
    grid->addWidget(lineEdit, 1, 0);
    grid->addWidget(pushButton, 1, 1);
    grid->addWidget(comboBox, 2, 0);
    grid->addWidget(statusBar, 2, 1);
    connect(comboBox, SIGNAL(textActivated(const QString&)), this, SLOT(displayText(const QString&)));
    statusBar->showMessage("Test item");
    widget->setLayout(grid);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

