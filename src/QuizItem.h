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
    int category = 0;
    int difficulty = 0;
    bool complete = false;
};

Q_DECLARE_METATYPE(QuizItem)

#endif // QUIZITEM_H
