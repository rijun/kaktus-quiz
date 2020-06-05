#ifndef QUIZMODEL_H
#define QUIZMODEL_H

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>

#include "quizitem.h"

constexpr int COLS = 3;

class QuizModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    QuizModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QuizItem quizItemAt(const QModelIndex &index) const;
    // void storeQuizItemAt(const QModelIndex &index);

    const QVector<QString> &categoryList() const;
    const QVector<QString> &difficultyList() const;

private:
    enum class ColumnNames { Category, Difficulty, Question };

    QVector<QuizItem> m_data;

    const QVector<QString> m_categoryList { "Wissenschaft", "Kultur", "Religion", "Erdkunde", "Zeitgeschehen", "Allgemein" };
    const QVector<QString> m_difficultyList { "Easy", "Medium", "Hard", "Extreme" };
};

#endif // QUIZMODEL_H
