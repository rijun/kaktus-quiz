#include "quizitem.h"

QuizItem::QuizItem(const QVector<QVariant> &data, QuizItem *parent)
    : itemData(data),
      parentItem(parent)
{}

QuizItem::~QuizItem()
{
    qDeleteAll(childItems);
}

QuizItem *QuizItem::child(int number)
{
    if (number < 0 || number >= childItems.size()) {
        return nullptr;
    }
    return childItems.at(number);
}

int QuizItem::childCount() const
{
    return childItems.count();
}

int QuizItem::childNumber() const
{
    if (parentItem) {
        return parentItem->childItems.indexOf(const_cast<QuizItem*>(this));
    }
    return 0;
}

int QuizItem::columnCount() const
{
    return itemData.count();
}

QVariant QuizItem::data(int column) const
{
    if (column < 0 || column >= itemData.size()) {
        return QVariant();
    }
    return itemData.at(column);
}

bool QuizItem::insertChildren(int position, int count, int columns)
{
    if (position < 0 || position > childItems.size()) {
        return false;
    }

    for (int row = 0; row < count; ++row) {
        QVector<QVariant> data(columns);
        QuizItem *item = new QuizItem(data, this);
        childItems.insert(position, item);
    }

    return true;
}

bool QuizItem::insertColumns(int position, int columns)
{
    if (position < 0 || position > itemData.size()) {
        return false;
    }

    for (int column = 0; column < columns; ++column) {
        itemData.insert(position, QVariant());
    }

    for (QuizItem *child : qAsConst(childItems)) {
        child->insertColumns(position, columns);
    }

    return true;
}

QuizItem *QuizItem::parent()
{
    return parentItem;
}

bool QuizItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > childItems.size()) {
        return false;
    }

    for (int row = 0; row < count; ++row) {
        delete childItems.takeAt(position);
    }

    return true;
}

bool QuizItem::removeColumns(int position, int columns)
{
    if (position < 0 || position + columns > itemData.size()) {
        return false;
    }

    for (int column = 0; column < columns; ++column) {
        itemData.remove(position);
    }

    for (QuizItem *child : qAsConst(childItems)) {
        child->removeColumns(position, columns);
    }

    return true;
}

bool QuizItem::setData(int column, const QVariant &value)
{
    if (column < 0 || column >= itemData.size()) {
        return false;
    }

    itemData[column] = value;
    return true;
}
