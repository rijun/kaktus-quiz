from PySide2.QtCore import Slot
from PySide2.QtWidgets import QApplication, QMainWindow, QMessageBox

from quiz_creator.ui_mainwindow import Ui_MainWindow


class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        # Setup signals and slots
        self.ui.cat1EditButton.clicked.connect(self.show_cat_edit)
        self.ui.cat2EditButton.clicked.connect(self.show_cat_edit)
        self.ui.cat3EditButton.clicked.connect(self.show_cat_edit)
        self.ui.cat4EditButton.clicked.connect(self.show_cat_edit)
        self.ui.cat5EditButton.clicked.connect(self.show_cat_edit)
        self.ui.cat6EditButton.clicked.connect(self.show_cat_edit)

        # Setup action handlers
        self.ui.actionAbout.triggered.connect(self.about)
        self.ui.actionAboutQt.triggered.connect(QApplication.aboutQt)

    @Slot()
    def show_cat_edit(self):
        category_name = self.sender().objectName().rstrip('EditButton')
        print(category_name)

    @Slot()
    def about(self):
        QMessageBox.about(self, self.tr("About Kaktus Quiz Creator"),
                          self.tr("<b>Kaktus Quiz Creator</b>"))
