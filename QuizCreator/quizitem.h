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
    unsigned int category;
    unsigned int difficulty;
};

#endif // QUIZITEM_H
