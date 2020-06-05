﻿#include "item_editor.h"
#include "ui_item_editor.h"

ItemEditor::ItemEditor(QWidget *parent, const QVector<QString> *catListPtr, const QVector<QString> *diffListPtr) :
    QDialog(parent), ui(new Ui::ItemEditor), m_categoryListPtr(catListPtr), m_difficultyListPtr(diffListPtr)
{
    ui->setupUi(this);

    for (QString cat : *m_categoryListPtr) {
        ui->categoryComboBox->addItem(cat);
    }

    for (QString diff : *m_difficultyListPtr) {
        ui->difficultyComboBox->addItem(diff);
    }
}

ItemEditor::~ItemEditor()
{
    delete ui;
}

void ItemEditor::setQuizItem(const QuizItem &item)
{
    m_quizItem = item;
    ui->questionLineEdit->setText(m_quizItem.question);
    ui->answerLineEdit->setText(m_quizItem.answer);
    ui->option1LineEdit->setText(m_quizItem.options.at(0));
    ui->option2LineEdit->setText(m_quizItem.options.at(1));
    ui->option3LineEdit->setText(m_quizItem.options.at(2));
    ui->categoryComboBox->setCurrentIndex(m_quizItem.category);
    ui->difficultyComboBox->setCurrentIndex(m_quizItem.difficulty);
}

QuizItem ItemEditor::quizItem()
{
    m_quizItem.question = ui->questionLineEdit->text();
    m_quizItem.answer = ui->answerLineEdit->text();
    m_quizItem.options.replace(0, ui->option1LineEdit->text());
    m_quizItem.options.replace(1, ui->option2LineEdit->text());
    m_quizItem.options.replace(2, ui->option3LineEdit->text());
    m_quizItem.category = ui->categoryComboBox->currentIndex();
    m_quizItem.difficulty = ui->difficultyComboBox->currentIndex();
    return m_quizItem;
}
