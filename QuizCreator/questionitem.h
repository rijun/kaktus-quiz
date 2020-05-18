#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QVariant>
#include <QVector>

class QuestionItem
{
public:
    explicit QuestionItem(const QVector<QVariant> &data, QuestionItem *parentItem = nullptr);
    ~QuestionItem();

    void appendChild(QuestionItem *child);

    QuestionItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    QuestionItem *parentItem();

private:
    QVector<QuestionItem*> m_childItems;
    QVector<QVariant> m_itemData;
    QuestionItem *m_parentItem;
};

#endif // QUESTION_H
