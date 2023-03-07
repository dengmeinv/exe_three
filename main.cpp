/*
 * find dialog
 * author:stardust
 * date:2023-03-07
 * verstion 1.0
 *
 */
#include "finddialog.h"
#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto window {std::make_unique<FindDialog>()};
    window->show();

    return a.exec();
}
