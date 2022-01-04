#include <QtWidgets>
#include "find_dialog.h"

FindDialog::FindDialog
(QWidget* parent)
    : QDialog(parent)
{
// ------ SETUP UI -------------------------------------------
    // tr() - use for translation to another language
    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("March &case"));
    backwardCheckBox = new QCheckBox(tr("Search backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));
// ----------------------------------------------------------- 

// ---- TIE SIGNALS AND SLOTS --------------------------------
    connect(lineEdit, SIGNAL(textChanged(const QString&)),
            this, SLOT(enableFindButton(const QString&)));
    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findClicked()));
    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(close()));
// ----------------------------------------------------------- 

// ---- SETUP LAYOUTS ----------------------------------------
    QHBoxLayout* topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);
    
    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);
    
    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
// ----------------------------------------------------------- 

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}
/*
void 
FindDialog::findNext
(const QString& str, Qt::CaseSensitivity cs)
{
}

void
FindDialog::findPrev
(const QString& str, Qt::CaseSensitivity cs)
{
}
*/

// ---- SLOTS ------------------------------------------------
void
FindDialog::findClicked()
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked()
        ? Qt::CaseSensitive
        : Qt::CaseInsensitive;

    // generate signal whether isChecked()
    // emit - is macro
    if (backwardCheckBox->isChecked()) {
        emit findPrev(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

void
FindDialog::enableFindButton
(const QString& text)
{
    findButton->setEnabled(!text.isEmpty());
}
// ----------------------------------------------------------- 

