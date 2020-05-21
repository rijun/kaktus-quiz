#include "quizmodel.h"
#include "quizitem.h"

QuizModel::QuizModel(const QStringList &categories, const QStringList &difficulties, QObject *parent)
    : QAbstractItemModel(parent)
{
    QVector<QVariant> rootData;
    m_rootItem = new QuizItem(rootData << "");
    setupModelData(categories, difficulties, m_rootItem);
}

QuizModel::~QuizModel()
{
    delete m_rootItem;
}

int QuizModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_rootItem->columnCount();
}

QVariant QuizModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (role != Qt::DisplayRole && role != Qt::EditRole) {
        return QVariant();
    }

    QuizItem *item = getItem(index);

    return item->data(index.column());
}

Qt::ItemFlags QuizModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

QuizItem *QuizModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        QuizItem *item = static_cast<QuizItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return m_rootItem;
}

QVariant QuizModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        return m_rootItem->data(section);
    }

    return QVariant();
}

QModelIndex QuizModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0) {
        return QModelIndex();
    }

    QuizItem *parentItem = getItem(parent);
    if (!parentItem) {
        return QModelIndex();
    }

    QuizItem *childItem = parentItem->child(row);
    if (childItem) {
        return createIndex(row, column, childItem);
    }
    return QModelIndex();
}

bool QuizModel::insertColumns(int position, int columns, const QModelIndex &parent)
{
    beginInsertColumns(parent, position, position + columns - 1);
    const bool success = m_rootItem->insertColumns(position, columns);
    endInsertColumns();

    return success;
}

bool QuizModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    QuizItem *parentItem = getItem(parent);
    if (!parentItem) {
        return false;
    }

    beginInsertRows(parent, position, position + rows - 1);
    const bool success = parentItem->insertChildren(position, rows, m_rootItem->columnCount());
    endInsertRows();

    return success;
}

QModelIndex QuizModel::parent(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return QModelIndex();
    }

    QuizItem *childItem = getItem(index);
    QuizItem *parentItem = childItem ? childItem->parent() : nullptr;

    if (parentItem == m_rootItem || !parentItem) {
        return QModelIndex();
    }

    return createIndex(parentItem->childNumber(), 0, parentItem);
}

bool QuizModel::removeColumns(int position, int columns, const QModelIndex &parent)
{
    beginRemoveColumns(parent, position, position + columns - 1);
    const bool success = m_rootItem->removeColumns(position, columns);
    endRemoveColumns();

    if (m_rootItem->columnCount() == 0) {
        removeRows(0, rowCount());
    }

    return success;
}

bool QuizModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    QuizItem *parentItem = getItem(parent);
    if (!parentItem) {
        return false;
    }

    beginRemoveRows(parent, position, position + rows - 1);
    const bool success = parentItem->removeChildren(position, rows);
    endRemoveRows();

    return success;
}

int QuizModel::rowCount(const QModelIndex &parent) const
{
    const QuizItem *parentItem = getItem(parent);

    return parentItem ? parentItem->childCount() : 0;
}

bool QuizModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole) {
        return false;
    }

    QuizItem *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result) {
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});
    }

    return result;
}

bool QuizModel::setHeaderData(int section, Qt::Orientation orientation,
                              const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal) {
        return false;
    }

    const bool result = m_rootItem->setData(section, value);

    if (result) {
        emit headerDataChanged(orientation, section, section);
    }

    return result;
}

void QuizModel::setupModelData(const QStringList &categories, const QStringList &difficulties, QuizItem *parent)
{
    for (QString category : categories) {
        parent->insertChildren(parent->childCount(), 1, m_rootItem->columnCount());

        QuizItem *currentCategory = parent->child(parent->childCount() - 1);

        currentCategory->setData(0, category);

        for (QString difficulty : difficulties) {
            currentCategory->insertChildren(currentCategory->childCount(), 1, m_rootItem->columnCount());
            currentCategory->child(currentCategory->childCount() - 1)->setData(0, difficulty);
        }
    }
}
