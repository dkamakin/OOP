#ifndef FAQWINDOW_H
#define FAQWINDOW_H

#include <QDialog>

namespace Ui {
class FAQwindow;
}

using sFAQWindow = std::shared_ptr <class FAQwindow>;

class FAQwindow : public QDialog {
    Q_OBJECT

public:
    explicit FAQwindow(QWidget *parent = nullptr);
    ~FAQwindow();

private:
    Ui::FAQwindow *ui;
};

#endif // FAQWINDOW_H
