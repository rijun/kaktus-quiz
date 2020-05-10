from PySide2.QtCore import Slot
from PySide2.QtWidgets import QDialog

from quiz_creator.ui_classes.ui_category_editor import Ui_Dialog
from quiz_creator.question_editor import QuestionDialog


class CategoryEditor(QDialog):
    def __init__(self, category_name):
        super(CategoryEditor, self).__init__()
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)

        # Setup signals and slots
        self.ui.addEasyButton.clicked.connect(self.show_add_dialog)
        self.ui.addMediumButton.clicked.connect(self.show_add_dialog)
        self.ui.addHardButton.clicked.connect(self.show_add_dialog)
        self.ui.addExtremeButton.clicked.connect(self.show_add_dialog)

    @Slot()
    def show_add_dialog(self):
        add_dialog = QuestionDialog()
        ret = add_dialog.exec()
