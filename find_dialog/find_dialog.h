#ifndef FIND_DIALOG_H_
#define FIND_DIALOG_H_

#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
    // macro
    // need to declare in any class which contains signals and slots
    Q_OBJECT

public:
    FindDialog(QWidget* parent = nullptr);
   
// macro
signals:
    void findNext(const QString& str, Qt::CaseSensitivity cs);
    void findPrev(const QString& str, Qt::CaseSensitivity cs);

// macro
private slots:
    void findClicked();
    void enableFindButton(const QString& text);

private:
    QLabel* label;
    QLineEdit* lineEdit;
    QCheckBox* caseCheckBox;
    QCheckBox* backwardCheckBox;
    QPushButton* findButton;
    QPushButton* closeButton;


};

#endif
