#include "quizmodel.h"
#include "quizitem.h"

QuizModel::QuizModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    for (int i = 0; i < 4; ++i) {
        QuizItem item;
        item.question = QString("Test %1").arg(i + 1);
        item.difficulty = i;
        m_data.append(item);
    }
}

int QuizModel::rowCount(const QModelIndex & /*parent*/) const
{
   return m_data.size();
}

int QuizModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

QVariant QuizModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == static_cast<int>(ColumnNames::QUESTION)) {
            return m_data.at(index.row()).question;
        } else if (index.column() == static_cast<int>(ColumnNames::DIFFICULTY)) {
            return m_diffList.at(m_data.at(index.row()).difficulty);
        } else {
           return QVariant();
        }
    }

    return QVariant();
}
