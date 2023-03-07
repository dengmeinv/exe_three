/*
 * author:stardust
 * date:2022-03-22
 * the Declaration of class FindDialog
 */
#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QCheckBox;
class QPushButton;
class QString;

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = nullptr);

//    /*可以添加下面的4个函数，以表明不需要对该图形对象进行复制和赋值,
//     *但是，也可以不用添加，因为其基类，如QObject和QWidget，已经禁止了复制和赋值的操作
//     *子类如果想做复制和赋值操作，就会报错。
//     */
//    FindDialog(const FindDialog &) = delete;
//    FindDialog(FindDialog &&) = delete;

//    FindDialog &operator=(const FindDialog &) = delete;
//    FindDialog &operator=(FindDialog &&) = delete;

    ~FindDialog();
signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void enableFindButton(const QString &text);
    void findClicked();

private:
    QLabel *_label = nullptr;
    QLineEdit *_lineEdit = nullptr;
    QCheckBox *_caseCheckBox = nullptr;
    QCheckBox *_backwardCheckBox = nullptr;
    QPushButton *_findButton = nullptr;
    QPushButton *_closeButton = nullptr;
};

#endif // FINDDIALOG_H
