from PySide2.QtWidgets import QDialog

from quiz_creator.ui_classes.ui_question_editor import Ui_Dialog


class QuestionDialog(QDialog):
    def __init__(self):
        super(QuestionDialog, self).__init__()
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)
