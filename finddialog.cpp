/*
 * author:stardust
 * date:2022-03-22
 *
 * the implementation of class FindDialog using modern c++ and Qt6
 */
#include "finddialog.h"
#include <QtWidgets>

FindDialog::FindDialog(QWidget *parent)
    : QDialog{parent},
      _label {new QLabel(tr("Find &what"))},
      _lineEdit {new QLineEdit()},
      _caseCheckBox {new QCheckBox(tr("Match &case"))},
      _backwardCheckBox {new QCheckBox(tr("Search &backward"))},
      _findButton {new QPushButton(tr("Find"))},
      _closeButton {new QPushButton(tr("Close"))}
{
    _label->setBuddy(_lineEdit);

    _findButton -> setEnabled(false);
    _findButton -> setDefault(true);

    QHBoxLayout *topleftLayout = new QHBoxLayout();
    topleftLayout ->addWidget(_label);
    topleftLayout ->addWidget(_lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout ->addLayout(topleftLayout);
    leftLayout ->addWidget(_caseCheckBox);
    leftLayout ->addWidget(_backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout ->addWidget(_findButton);
    rightLayout ->addWidget(_closeButton);
    rightLayout ->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout ->addLayout(leftLayout);
    mainLayout ->addLayout(rightLayout);

    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());

    connect(_lineEdit, &QLineEdit::textChanged,
            this, &FindDialog::enableFindButton);
    connect(_findButton, &QPushButton::clicked,
            this, &FindDialog::findClicked);
    connect(_closeButton, &QPushButton::clicked,
            this, &FindDialog::close);
}

FindDialog::~FindDialog()
{

}

void FindDialog::enableFindButton(const QString &text)
{
    _findButton ->setEnabled(!(text.isEmpty()));
}

void FindDialog::findClicked()
{
    Qt::CaseSensitivity cs =
            _caseCheckBox->isChecked() ? Qt::CaseSensitive
                                       : Qt::CaseInsensitive;
    if(_caseCheckBox->isChecked())
        cs = Qt::CaseSensitive;
    else
        cs = Qt::CaseInsensitive;

    QString text = _lineEdit->text();
    if(_backwardCheckBox->isChecked()){
        emit findPrevious(text, cs);
        qDebug() << "Singal findPrevious is emitted.";
    }
    else{
        emit findNext(text, cs);
        qDebug() << "Singal findNext is emitted.";
    }

}
