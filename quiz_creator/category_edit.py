from PySide2.QtWidgets import QDialog

from quiz_creator.ui_classes.ui_category_edit import Ui_Dialog


class CategoryEdit(QDialog):
    def __init__(self, category_name):
        super(CategoryEdit, self).__init__()
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)
