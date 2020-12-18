#include "view/faqwindow.h"
#include "ui_faqwindow.h"

FAQwindow::FAQwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FAQwindow) {
    ui->setupUi(this);
}

FAQwindow::~FAQwindow() {
    delete ui;
}
