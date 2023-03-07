/**
 * author:stardust
 * date:2022-03-07
 * find dialog in main()
*/

#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <memory>
#include <iostream>
using std::cerr;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    auto window{std::make_unique<QWidget>()};

    window->setWindowTitle("Find");

    QLabel *label = new QLabel("Find &what");
    QLineEdit *lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    QCheckBox *caseCheckBox = new QCheckBox("Match &case");
    QCheckBox *backwardCheckBox = new QCheckBox("Search &backward");

    QPushButton *findButton = new QPushButton("&Find");
    findButton->setDefault(true);
    findButton->setEnabled(false);

    QPushButton *closeButton = new QPushButton("Close");

    QObject::connect(lineEdit, &QLineEdit::textChanged,
                     [findButton](const QString &text){
        findButton->setEnabled(!text.isEmpty());
        cerr << "lineEdit textChanged...\n";
    });

    QObject::connect(closeButton, &QPushButton::clicked,
                     [&](){
        if(label){
            delete label;
            label = nullptr;
        }
    });


    QObject::connect(findButton,SIGNAL(clicked()),findButton,SLOT(findClicked()));
    //    QObject::connect(closeButton,SIGNAL(clicked()),closeButton,SLOT(close()));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout-> addWidget(label);
    topLeftLayout-> addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout-> addWidget(findButton);
    rightLayout-> addWidget(closeButton);
    rightLayout-> addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout-> addLayout(leftLayout);
    mainLayout-> addLayout(rightLayout);

    window->setLayout(mainLayout);

    //    setFixedHeight(sizeHint().height());
    window->show();

    return app.exec();
}
