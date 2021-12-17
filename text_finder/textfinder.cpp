#include "textfinder.h"
#include "./ui_textfinder.h"

TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    loadTextFromFile("/home/xemerius/devs/tasks/text_finder/sample.txt");
}

TextFinder::~TextFinder()
{
    delete ui;
}


void TextFinder::on_findButton_clicked()
{
    QString target = ui->lineEdit->text();
    ui->textEdit->find(target, QTextDocument::FindWholeWords);
}

void TextFinder::loadTextFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("failed to open : " + filename);
    }

    std::string content;
    char tmpChar;
    while(file >> std::noskipws >> tmpChar)
    {
        content += tmpChar;
    }
    
    ui->textEdit->setPlainText(QString::fromStdString(content));
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);


}
