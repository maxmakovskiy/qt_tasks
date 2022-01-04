#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <memory>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    
    auto window = std::make_unique<QWidget>();
    window->setWindowTitle("Enter your age");
    
    auto spinBox = std::make_unique<QSpinBox>();
    auto slider = std::make_unique<QSlider>(Qt::Horizontal);
    auto layout = std::make_unique<QHBoxLayout>(); 

    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    QObject::connect(spinBox.get(), SIGNAL(valueChanged(int)),
                     slider.get(), SLOT(setValue(int)));
    QObject::connect(slider.get(), SIGNAL(valueChanged(int)),
                     spinBox.get(), SLOT(setValue(int)));
    
    spinBox->setValue(55);
    
    layout->addWidget(spinBox.get());
    layout->addWidget(slider.get());
    window->setLayout(layout.get());
    window->show();

    return app.exec();
}

