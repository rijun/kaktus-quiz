#include "questionitem.h"

QuestionItem::QuestionItem(const QVector<QVariant> &data, QuestionItem *parent)
    : m_itemData(data), m_parentItem(parent)
{}

QuestionItem::~QuestionItem()
{
    qDeleteAll(m_childItems);
}

void QuestionItem::appendChild(QuestionItem *item)
{
    m_childItems.append(item);
}

QuestionItem *QuestionItem::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int QuestionItem::childCount() const
{
    return m_childItems.count();
}

int QuestionItem::columnCount() const
{
    return m_itemData.count();
}

QVariant QuestionItem::data(int column) const
{
    if (column < 0 || column >= m_itemData.size())
        return QVariant();
    return m_itemData.at(column);
}

QuestionItem *QuestionItem::parentItem()
{
    return m_parentItem;
}

int QuestionItem::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<QuestionItem*>(this));

    return 0;
}
