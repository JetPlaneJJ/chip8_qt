#include "Display.h"
#include "Cpu.h"
#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const int fps = 60;
    int fpsInterval{1000 / fps};

    Display display;
    display.setFixedSize(640, 320);
    display.testRender();
    display.show();

    return a.exec();
}
