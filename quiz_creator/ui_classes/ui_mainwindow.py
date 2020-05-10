# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mainwindow.ui'
##
## Created by: Qt User Interface Compiler version 5.14.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import (QCoreApplication, QDate, QDateTime, QMetaObject,
    QObject, QPoint, QRect, QSize, QTime, QUrl, Qt)
from PySide2.QtGui import (QBrush, QColor, QConicalGradient, QCursor, QFont,
    QFontDatabase, QIcon, QKeySequence, QLinearGradient, QPalette, QPainter,
    QPixmap, QRadialGradient)
from PySide2.QtWidgets import *


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(421, 341)
        self.actionExit = QAction(MainWindow)
        self.actionExit.setObjectName(u"actionExit")
        icon = QIcon(QIcon.fromTheme(u"application-exit"))
        self.actionExit.setIcon(icon)
        self.actionAboutQt = QAction(MainWindow)
        self.actionAboutQt.setObjectName(u"actionAboutQt")
        self.actionAbout = QAction(MainWindow)
        self.actionAbout.setObjectName(u"actionAbout")
        icon1 = QIcon(QIcon.fromTheme(u"dialog-information"))
        self.actionAbout.setIcon(icon1)
        self.mainLayout = QWidget(MainWindow)
        self.mainLayout.setObjectName(u"mainLayout")
        self.gridLayout = QGridLayout(self.mainLayout)
        self.gridLayout.setObjectName(u"gridLayout")
        self.cat6ProgressBar = QProgressBar(self.mainLayout)
        self.cat6ProgressBar.setObjectName(u"cat6ProgressBar")
        self.cat6ProgressBar.setValue(24)

        self.gridLayout.addWidget(self.cat6ProgressBar, 6, 1, 1, 1)

        self.cat4Label = QLabel(self.mainLayout)
        self.cat4Label.setObjectName(u"cat4Label")

        self.gridLayout.addWidget(self.cat4Label, 4, 0, 1, 1)

        self.cat1Label = QLabel(self.mainLayout)
        self.cat1Label.setObjectName(u"cat1Label")

        self.gridLayout.addWidget(self.cat1Label, 1, 0, 1, 1)

        self.cat3ProgressBar = QProgressBar(self.mainLayout)
        self.cat3ProgressBar.setObjectName(u"cat3ProgressBar")
        self.cat3ProgressBar.setValue(24)

        self.gridLayout.addWidget(self.cat3ProgressBar, 3, 1, 1, 1)

        self.cat2Label = QLabel(self.mainLayout)
        self.cat2Label.setObjectName(u"cat2Label")

        self.gridLayout.addWidget(self.cat2Label, 2, 0, 1, 1)

        self.cat5Label = QLabel(self.mainLayout)
        self.cat5Label.setObjectName(u"cat5Label")

        self.gridLayout.addWidget(self.cat5Label, 5, 0, 1, 1)

        self.buttonLayout = QHBoxLayout()
        self.buttonLayout.setObjectName(u"buttonLayout")
        self.configButton = QPushButton(self.mainLayout)
        self.configButton.setObjectName(u"configButton")

        self.buttonLayout.addWidget(self.configButton)

        self.horizontalSpacer = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.buttonLayout.addItem(self.horizontalSpacer)

        self.generateButton = QPushButton(self.mainLayout)
        self.generateButton.setObjectName(u"generateButton")
        self.generateButton.setEnabled(False)

        self.buttonLayout.addWidget(self.generateButton)


        self.gridLayout.addLayout(self.buttonLayout, 7, 0, 1, 3)

        self.cat2ProgressBar = QProgressBar(self.mainLayout)
        self.cat2ProgressBar.setObjectName(u"cat2ProgressBar")
        self.cat2ProgressBar.setValue(24)

        self.gridLayout.addWidget(self.cat2ProgressBar, 2, 1, 1, 1)

        self.cat5ProgressBar = QProgressBar(self.mainLayout)
        self.cat5ProgressBar.setObjectName(u"cat5ProgressBar")
        self.cat5ProgressBar.setValue(24)

        self.gridLayout.addWidget(self.cat5ProgressBar, 5, 1, 1, 1)

        self.cat3Label = QLabel(self.mainLayout)
        self.cat3Label.setObjectName(u"cat3Label")

        self.gridLayout.addWidget(self.cat3Label, 3, 0, 1, 1)

        self.cat4ProgressBar = QProgressBar(self.mainLayout)
        self.cat4ProgressBar.setObjectName(u"cat4ProgressBar")
        self.cat4ProgressBar.setValue(24)

        self.gridLayout.addWidget(self.cat4ProgressBar, 4, 1, 1, 1)

        self.cat1EditButton = QPushButton(self.mainLayout)
        self.cat1EditButton.setObjectName(u"cat1EditButton")

        self.gridLayout.addWidget(self.cat1EditButton, 1, 2, 1, 1)

        self.cat6Label = QLabel(self.mainLayout)
        self.cat6Label.setObjectName(u"cat6Label")

        self.gridLayout.addWidget(self.cat6Label, 6, 0, 1, 1)

        self.cat1ProgressBar = QProgressBar(self.mainLayout)
        self.cat1ProgressBar.setObjectName(u"cat1ProgressBar")
        self.cat1ProgressBar.setValue(24)

        self.gridLayout.addWidget(self.cat1ProgressBar, 1, 1, 1, 1)

        self.cat2EditButton = QPushButton(self.mainLayout)
        self.cat2EditButton.setObjectName(u"cat2EditButton")

        self.gridLayout.addWidget(self.cat2EditButton, 2, 2, 1, 1)

        self.cat3EditButton = QPushButton(self.mainLayout)
        self.cat3EditButton.setObjectName(u"cat3EditButton")

        self.gridLayout.addWidget(self.cat3EditButton, 3, 2, 1, 1)

        self.cat4EditButton = QPushButton(self.mainLayout)
        self.cat4EditButton.setObjectName(u"cat4EditButton")

        self.gridLayout.addWidget(self.cat4EditButton, 4, 2, 1, 1)

        self.cat5EditButton = QPushButton(self.mainLayout)
        self.cat5EditButton.setObjectName(u"cat5EditButton")

        self.gridLayout.addWidget(self.cat5EditButton, 5, 2, 1, 1)

        self.cat6EditButton = QPushButton(self.mainLayout)
        self.cat6EditButton.setObjectName(u"cat6EditButton")

        self.gridLayout.addWidget(self.cat6EditButton, 6, 2, 1, 1)

        MainWindow.setCentralWidget(self.mainLayout)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 421, 30))
        self.menuFile = QMenu(self.menubar)
        self.menuFile.setObjectName(u"menuFile")
        self.menuHelp = QMenu(self.menubar)
        self.menuHelp.setObjectName(u"menuHelp")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.menubar.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuHelp.menuAction())
        self.menuFile.addAction(self.actionExit)
        self.menuHelp.addAction(self.actionAboutQt)
        self.menuHelp.addAction(self.actionAbout)

        self.retranslateUi(MainWindow)
        self.actionExit.triggered.connect(MainWindow.close)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Kaktus Quiz Studio", None))
        self.actionExit.setText(QCoreApplication.translate("MainWindow", u"Quit", None))
#if QT_CONFIG(shortcut)
        self.actionExit.setShortcut(QCoreApplication.translate("MainWindow", u"Ctrl+Q", None))
#endif // QT_CONFIG(shortcut)
        self.actionAboutQt.setText(QCoreApplication.translate("MainWindow", u"About Qt", None))
        self.actionAbout.setText(QCoreApplication.translate("MainWindow", u"About", None))
        self.cat4Label.setText(QCoreApplication.translate("MainWindow", u"Category 4", None))
        self.cat1Label.setText(QCoreApplication.translate("MainWindow", u"Category 1", None))
        self.cat2Label.setText(QCoreApplication.translate("MainWindow", u"Category 2", None))
        self.cat5Label.setText(QCoreApplication.translate("MainWindow", u"Category 5", None))
        self.configButton.setText(QCoreApplication.translate("MainWindow", u"Configure Quiz", None))
        self.generateButton.setText(QCoreApplication.translate("MainWindow", u"Generate Quiz", None))
        self.cat3Label.setText(QCoreApplication.translate("MainWindow", u"Category 3", None))
        self.cat1EditButton.setText(QCoreApplication.translate("MainWindow", u"Edit", None))
        self.cat6Label.setText(QCoreApplication.translate("MainWindow", u"Category 6", None))
        self.cat2EditButton.setText(QCoreApplication.translate("MainWindow", u"Edit", None))
        self.cat3EditButton.setText(QCoreApplication.translate("MainWindow", u"Edit", None))
        self.cat4EditButton.setText(QCoreApplication.translate("MainWindow", u"Edit", None))
        self.cat5EditButton.setText(QCoreApplication.translate("MainWindow", u"Edit", None))
        self.cat6EditButton.setText(QCoreApplication.translate("MainWindow", u"Edit", None))
        self.menuFile.setTitle(QCoreApplication.translate("MainWindow", u"File", None))
        self.menuHelp.setTitle(QCoreApplication.translate("MainWindow", u"Help", None))
    # retranslateUi

