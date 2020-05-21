#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <QVariant>
#include <QVector>

class QuizItem
{
public:
    explicit QuizItem(const QVector<QVariant> &data, QuizItem *parent = nullptr);
    ~QuizItem();

    QuizItem *child(int number);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    bool insertChildren(int position, int count, int columns);
    bool insertColumns(int position, int columns);
    QuizItem *parent();
    bool removeChildren(int position, int count);
    bool removeColumns(int position, int columns);
    int childNumber() const;
    bool setData(int column, const QVariant &value);

private:
    QVector<QuizItem*> childItems;
    QVector<QVariant> itemData;
    QuizItem *parentItem;
};

#endif // QUIZITEM_H
