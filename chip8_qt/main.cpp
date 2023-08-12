//#include "QWindow.h"
#include "Renderer.h"
#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QWidget window;
//    window.setFixedSize(640, 320);

//    QProgressBar *progressBar = new QProgressBar(&window);
//    progressBar->setRange(0, 100);
//    progressBar->setValue(0);
//    progressBar->setGeometry(10, 10, 180, 30);

//    QSlider *slider = new QSlider(&window);
//    slider->setOrientation(Qt::Horizontal);
//    slider->setRange(0, 100);
//    slider->setGeometry(10,40,180,30);

//    QObject::connect(slider, SIGNAL(valueChanged(int)), progressBar, SLOT (setValue(int)));

//    window.show();

    Renderer renderer;
    renderer.setFixedSize(640, 320);
    renderer.testRender();
    renderer.show();
    return a.exec();
}
