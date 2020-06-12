#include "QuizModel.h"
#include "QuizItem.h"

#include <QDebug>

QuizModel::QuizModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    for (int i = 0; i < 4; ++i) {
        QuizItem item;
        item.question = QString("Test %1").arg(i + 1);
        item.category = i;
        item.difficulty = i;
        m_data.append(item);
    }
}

int QuizModel::rowCount(const QModelIndex &) const
{
   return m_data.size();
}

int QuizModel::columnCount(const QModelIndex &) const
{
    return COLS;
}

QVariant QuizModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Category");
        case 1:
            return tr("Difficulty");
        case 2:
            return tr("Question");
        }
    }
    return QVariant();
}

QVariant QuizModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == static_cast<int>(ColumnNames::Category)) {
            int idx = m_data.at(index.row()).category;
            return m_categoryList.at(idx);
        } else if (index.column() == static_cast<int>(ColumnNames::Difficulty)) {
            return m_difficultyList.at(m_data.at(index.row()).difficulty);
        } else if (index.column() == static_cast<int>(ColumnNames::Question)) {
            return m_data.at(index.row()).question;
        }
    }
    return QVariant();
}

bool QuizModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::EditRole) {
        if (!checkIndex(index)) { return false; }

        m_data.replace(index.row(), value.value<QuizItem>());

        emit dataChanged(index, index, {Qt::DisplayRole});
        emit quizDataChanged(m_data.at(index.row()).category, m_data.at(index.row()).difficulty);

        return true;
    }
    return false;
}

bool QuizModel::insertRow(int row, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row);
    m_data.append(QuizItem());
    endInsertRows();
    return true;
}

bool QuizModel::removeRow(int row, const QModelIndex &parent)
{
    if (m_data.isEmpty()) { return false; };

    int cat = m_data.at(row).category;
    int diff = m_data.at(row).difficulty;

    beginRemoveRows(parent, row, row);
    m_data.remove(row);
    endRemoveRows();

    emit quizDataChanged(cat, diff);

    return true;
}

Qt::ItemFlags QuizModel::flags(const QModelIndex &index) const
{
    (void) index;   // Suppress warning
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

QuizItem QuizModel::quizItemAt(const int &row) const
{
    if (row >= m_data.size()) { return QuizItem(); }
    return m_data.at(row);
}

QuizItem QuizModel::quizItemAt(const QModelIndex &index) const
{
    return m_data.at(index.row());
}

const QVector<QString> &QuizModel::categoryList() const
{
    return m_categoryList;
}

const QVector<QString> &QuizModel::difficultyList() const
{
    return m_difficultyList;
}

int QuizModel::numberOfCategories()
{
    return m_categoryList.size();
}

int QuizModel::numberOfDifficulties()
{
    return m_difficultyList.size();
}

int QuizModel::quizItemCount(int category, int difficulty)
{
    int counter = 0;
    for (const QuizItem &item : m_data) {
        if (item.category == category && item.difficulty == difficulty) {
            ++counter;
        }
    }
    return counter;
}

int QuizModel::maxQuestionsPerCategory()
{
    int questions = 0;
    for (int max : m_maxQuestionsPerDifficulty) {
        questions += max;
    }
    return questions;
}
