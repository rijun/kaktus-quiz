#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <QString>
#include <QVector>

struct QuizItem
{
    QuizItem() {};
    QString question;
    QString answer;
    QVector<QString> options;
    int difficulty;
};

#endif // QUIZITEM_H
