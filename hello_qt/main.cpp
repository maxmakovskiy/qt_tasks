#include <QApplication>
#include <QLabel>
#include <memory>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    auto label = std::make_unique<QLabel>("Hello QT!");
    label->show();

    return app.exec();
}


