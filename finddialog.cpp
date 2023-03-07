/**
 * author:stardust
 * date:2023-03-07
 * verstion 0.5
 *
 * the implementation of class FindDialog using modern c++ and Qt6
*/
#include "finddialog.h"
#include <QtWidgets>
#include <QtDebug>

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    QLabel * l = new QLabel(tr("Find &what"));
    l->setObjectName(QString{"label"});

    QLineEdit *le = new QLineEdit();
    le->setObjectName(QString{"lineEdit"});

    l->setBuddy(le);

    QPushButton *fb = new QPushButton(tr("Find"));
    fb->setObjectName(QString{"findButton"});

    QPushButton *cb = new QPushButton(tr("Close"));
    cb->setObjectName(QString{"closeButton"});

    fb -> setEnabled(false);
    fb -> setDefault(true);

    connect(le, &QLineEdit::textChanged,
            this, &FindDialog::enableFindButton);
    connect(fb, &QPushButton::clicked,
            this, &FindDialog::findClicked);
    connect(cb, &QPushButton::clicked,
            this, &FindDialog::close);

    QCheckBox *caseCheckBox = new QCheckBox(tr("Match &case"));
    caseCheckBox->setObjectName(QString{"caseCheckBox"});

    QCheckBox *backwardCheckBox = new QCheckBox(tr("Search &backward"));
    backwardCheckBox->setObjectName(QString{"backwardCheckBox"});

    QHBoxLayout *topleftLayout = new QHBoxLayout();
    topleftLayout ->addWidget(l);
    topleftLayout ->addWidget(le);

    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout ->addLayout(topleftLayout);
    leftLayout ->addWidget(caseCheckBox);
    leftLayout ->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout ->addWidget(fb);
    rightLayout ->addWidget(cb);
    rightLayout ->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout ->addLayout(leftLayout);
    mainLayout ->addLayout(rightLayout);

    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

FindDialog::~FindDialog()
{

}

void FindDialog::enableFindButton(const QString &text)
{
    QPushButton *findButton = findChild<QPushButton*>(QString{"findButton"});
    findButton ->setEnabled(!(text.isEmpty()));
}

void FindDialog::findClicked()
{
    QCheckBox *caseCheckBox = findChild<QCheckBox*>(QString{"caseCheckBox"});
    Qt::CaseSensitivity cs =
            caseCheckBox->isChecked() ? Qt::CaseSensitive
                                       : Qt::CaseInsensitive;
    if(caseCheckBox->isChecked())
        cs = Qt::CaseSensitive;
    else
        cs = Qt::CaseInsensitive;

    QLineEdit *lineEdit = findChild<QLineEdit *>(QString{"lineEdit"});
    QString text = lineEdit->text();

    QCheckBox *backwardCheckBox = findChild<QCheckBox *>(QString{"backwardCheckBox"});
    if(backwardCheckBox->isChecked()){
        emit findPrevious(text, cs);
        qDebug() << "Singal findPrevious is emitted.";
    }
    else{
        emit findNext(text, cs);
        qDebug() << "Singal findNext is emitted.";
    }

}
