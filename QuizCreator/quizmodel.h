#ifndef QUIZMODEL_H
#define QUIZMODEL_H

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>

#include "quizitem.h"

class QuizModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    QuizModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    enum class ColumnNames { QUESTION, DIFFICULTY };

    QVector<QuizItem> m_data;

    const QVector<QString> m_diffList = { "Easy", "Medium", "Hard", "Extreme" };
};

#endif // QUIZMODEL_H
