#include "FileGenerator.h"
#include "lib/inja.hpp"
#include "lib/json.hpp"

FileGenerator::FileGenerator()
{

}

bool FileGenerator::generateQuiz(const std::string &quizData, const std::string &templateFile, const std::string &targetFolder)
{
    nlohmann::json j = nlohmann::json::parse(quizData);
    inja::Environment env;

//    try {
      inja::Template temp = env.parse(templateFile);
      env.write(temp, j[0], targetFolder + "/test.html");


//        std::string result = env.render("{{ question }}", j);
//        std::cout << result;
//    } catch (std::runtime_error) {
//        return false;
//    }

    // Render a string with json data

    return true;
}
