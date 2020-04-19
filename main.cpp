#include <QApplication>
#include "BlurWidget.h"
#include "blurpicker.h"
#include "MyBlurEffect.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    BlurWidget wgt;
//    BlurPicker wgt;
    wgt.setFixedSize(400,300);
    wgt.show();

    return  app.exec();
}
