#ifndef ITEM_EDITOR_H
#define ITEM_EDITOR_H

#include <QDialog>

#include "QuizItem.h"

namespace Ui {
class ItemEditor;
}

class ItemEditor : public QDialog
{
    Q_OBJECT

public:
    explicit ItemEditor(QWidget *parent, const QVector<QString> *catListPtr = nullptr, const QVector<QString> *diffListPtr = nullptr);
    ~ItemEditor();

    void setQuizItem(const QuizItem &item);
    QuizItem quizItem();

private:
    Ui::ItemEditor *ui;
    QuizItem m_quizItem;

    const QVector<QString> *m_categoryListPtr;
    const QVector<QString> *m_difficultyListPtr;
};

#endif // ITEM_EDITOR_H
