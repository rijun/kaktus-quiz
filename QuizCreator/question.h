#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QVector>

struct Question {
    QString questionText;
    QString answerText;
    QVector<QString> optionsText;
    unsigned int difficulty;
    unsigned int category;
};

#endif // QUESTION_H
