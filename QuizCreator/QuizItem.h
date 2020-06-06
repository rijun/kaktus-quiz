#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <QString>
#include <QVector>
#include <QMetaType>

struct QuizItem
{
    QString question  = "";
    QString answer = "";
    QVector<QString> options { "", "", "" };
    unsigned int category = 0;
    unsigned int difficulty = 0;
};

Q_DECLARE_METATYPE(QuizItem)

#endif // QUIZITEM_H
