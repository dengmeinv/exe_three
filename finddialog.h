/**
 * author:stardust
 * date:2020-03-03
 * the Declaration of class FindDialog
*/
#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

//class QLabel;
//class QLineEdit;
//class QCheckBox;
//class QPushButton;
//class QString;

class FindDialog : public QDialog
{
    Q_OBJECT
public:
    FindDialog(QWidget *parent = nullptr);
    ~FindDialog();
signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void enableFindButton(const QString &text);
    void findClicked();

//private:
//    QLabel *_label = nullptr;
//    QLineEdit *_lineEdit = nullptr;
//    QCheckBox *_caseCheckBox = nullptr;
//    QCheckBox *_backwardCheckBox = nullptr;
//    QPushButton *_findButton = nullptr;
//    QPushButton *_closeButton = nullptr;
};

#endif // FINDDIALOG_H
