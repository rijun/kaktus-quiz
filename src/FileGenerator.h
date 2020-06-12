#ifndef FILEGENERATOR_H
#define FILEGENERATOR_H

#include <string>

class FileGenerator
{
public:
    FileGenerator();
    static bool generateQuiz(const std::string &quizData, const std::string &templateFile);
};

#endif // FILEGENERATOR_H
