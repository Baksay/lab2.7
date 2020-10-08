#include "dialog.h"
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>

Dialog::Dialog(QWidget* parent) : QDialog(parent)
{
    setModal(true);
    QBoxLayout* layout = new QHBoxLayout();

    QLabel* info = new QLabel("Do you want to close?");
    layout->addWidget(info);

    QPushButton* applyButton = new QPushButton("Close");
    connect(applyButton, SIGNAL(clicked()), this, SLOT(accept()));
    layout->addWidget(applyButton);

    QPushButton* cancelButton = new QPushButton("Cancel");
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    layout->addWidget(cancelButton);

    setLayout(layout);
};
