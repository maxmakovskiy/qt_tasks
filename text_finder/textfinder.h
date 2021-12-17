#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>
#include <fstream>
#include <string>
#include <exception>
#include <QString>
#include <QTextDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class TextFinder; }
QT_END_NAMESPACE

class TextFinder : public QWidget
{
    Q_OBJECT

public:
    TextFinder(QWidget *parent = nullptr);
    ~TextFinder();

private slots:
    void on_findButton_clicked();

private:
    Ui::TextFinder *ui;
    void loadTextFromFile(const std::string& filename);
};
#endif // TEXTFINDER_H
