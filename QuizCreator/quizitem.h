#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <QString>
#include <QVector>

struct QuizItem
{
    QString question  = "";
    QString answer ="";
    QVector<QString> options { "", "", "" };
    unsigned int category = 0;
    unsigned int difficulty = 0;
};

#endif // QUIZITEM_H
