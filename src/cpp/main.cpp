#include "New_Qt_Project.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    New_Qt_Project window;
    window.show();
    return app.exec();
}
