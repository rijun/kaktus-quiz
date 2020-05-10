from quiz_creator.quiz_category import QuizCategory


class Quiz:
    def __init__(self):
        category_names = [
            "Wissenschaft",
            "Glaube",
            "Kultur",
            "Zeitgeschehen",
            "Erdkunde",
            "Allgemein"
        ]

        # Create quiz categories
        self.__categories = {}
        for i, name in enumerate(category_names):
            self.__categories[f"cat{i+1}"] = QuizCategory(name)

    def category(self, index):
        return self.__categories.get(index)
