#include "FileGenerator.h"
#include "lib/inja.hpp"
#include "lib/json.hpp"

#include <QDebug>

FileGenerator::FileGenerator()
{

}

bool FileGenerator::generateQuiz(const std::string &quizData, const std::string &templateFile, const std::string &targetFolder)
{
    inja::Environment env;

    try {
        inja::Template temp = env.parse(templateFile);
        env.write(temp, nlohmann::json::parse(quizData)[0], targetFolder + "/test.html");
    } catch (std::runtime_error) {
        return false;
    }

    return true;
}
