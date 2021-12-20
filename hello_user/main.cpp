#include <QApplication>
#include <QPushButton>
#include <memory>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    auto button = std::make_unique<QPushButton>("Quit");
    
    QObject::connect(button.get(), SIGNAL(clicked()),
            &app, SLOT(quit()));
    
    button->show();

    return app.exec();
}

