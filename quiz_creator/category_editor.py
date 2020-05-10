import copy

from PySide2.QtCore import Slot
from PySide2.QtWidgets import QDialog

from quiz_creator.quiz_category import QuizCategory
from quiz_creator.question import Question

# UI class imports
from quiz_creator.ui_classes.ui_category_editor import Ui_Dialog
from quiz_creator.question_editor import QuestionDialog


class CategoryEditor(QDialog):
    def __init__(self, category: QuizCategory):
        super(CategoryEditor, self).__init__()
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)

        self.__category = copy.deepcopy(category)

        # Setup signals and slots
        self.ui.addEasyButton.clicked.connect(self.show_add_dialog)
        self.ui.addMediumButton.clicked.connect(self.show_add_dialog)
        self.ui.addHardButton.clicked.connect(self.show_add_dialog)
        self.ui.addExtremeButton.clicked.connect(self.show_add_dialog)

        # Initialize question lists
        self.ui.easyListWidget.addItems(self.__category.easy)
        self.ui.mediumListWidget.addItems(self.__category.medium)
        self.ui.hardListWidget.addItems(self.__category.hard)
        self.ui.extremeListWidget.addItems(self.__category.extreme)

    @Slot()
    def show_add_dialog(self):
        add_dialog = QuestionDialog()
        exit_ok = add_dialog.exec()

        if exit_ok:
            difficulty = self.sender().objectName().rstrip('Button').lstrip('add')
            q = Question()
            q.question = add_dialog.ui.questionLineEdit.text()
            q.answer = add_dialog.ui.answerLineEdit.text()
            q.options.append(add_dialog.ui.option1LineEdit.text())
            q.options.append(add_dialog.ui.option2LineEdit.text())
            q.options.append(add_dialog.ui.option3LineEdit.text())
            self.__category.questions[difficulty].append(q)
