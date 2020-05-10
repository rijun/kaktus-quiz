# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'category_edit.ui'
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


class Ui_Dialog(object):
    def setupUi(self, Dialog):
        if not Dialog.objectName():
            Dialog.setObjectName(u"Dialog")
        Dialog.resize(717, 487)
        self.gridLayout = QGridLayout(Dialog)
        self.gridLayout.setObjectName(u"gridLayout")
        self.hardGroupBox = QGroupBox(Dialog)
        self.hardGroupBox.setObjectName(u"hardGroupBox")
        self.verticalLayout_3 = QVBoxLayout(self.hardGroupBox)
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.listWidget_3 = QListWidget(self.hardGroupBox)
        self.listWidget_3.setObjectName(u"listWidget_3")

        self.verticalLayout_3.addWidget(self.listWidget_3)

        self.horizontalLayout_3 = QHBoxLayout()
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.horizontalSpacer_3 = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.horizontalLayout_3.addItem(self.horizontalSpacer_3)

        self.addHardButton = QToolButton(self.hardGroupBox)
        self.addHardButton.setObjectName(u"addHardButton")
        icon = QIcon()
        iconThemeName = u"list-add"
        if QIcon.hasThemeIcon(iconThemeName):
            icon = QIcon.fromTheme(iconThemeName)
        else:
            icon.addFile(u".", QSize(), QIcon.Normal, QIcon.Off)
        
        self.addHardButton.setIcon(icon)

        self.horizontalLayout_3.addWidget(self.addHardButton)

        self.removeHardButton = QToolButton(self.hardGroupBox)
        self.removeHardButton.setObjectName(u"removeHardButton")
        icon1 = QIcon()
        iconThemeName = u"list-remove"
        if QIcon.hasThemeIcon(iconThemeName):
            icon1 = QIcon.fromTheme(iconThemeName)
        else:
            icon1.addFile(u".", QSize(), QIcon.Normal, QIcon.Off)
        
        self.removeHardButton.setIcon(icon1)

        self.horizontalLayout_3.addWidget(self.removeHardButton)


        self.verticalLayout_3.addLayout(self.horizontalLayout_3)


        self.gridLayout.addWidget(self.hardGroupBox, 0, 2, 1, 1)

        self.easyGroupBox = QGroupBox(Dialog)
        self.easyGroupBox.setObjectName(u"easyGroupBox")
        self.verticalLayout = QVBoxLayout(self.easyGroupBox)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.listWidget = QListWidget(self.easyGroupBox)
        self.listWidget.setObjectName(u"listWidget")

        self.verticalLayout.addWidget(self.listWidget)

        self.horizontalLayout = QHBoxLayout()
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.horizontalSpacer = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.horizontalLayout.addItem(self.horizontalSpacer)

        self.removeEasyButton = QToolButton(self.easyGroupBox)
        self.removeEasyButton.setObjectName(u"removeEasyButton")
        icon2 = QIcon(QIcon.fromTheme(u"list-add"))
        self.removeEasyButton.setIcon(icon2)

        self.horizontalLayout.addWidget(self.removeEasyButton)

        self.addEasyButton = QToolButton(self.easyGroupBox)
        self.addEasyButton.setObjectName(u"addEasyButton")
        icon3 = QIcon(QIcon.fromTheme(u"list-remove"))
        self.addEasyButton.setIcon(icon3)

        self.horizontalLayout.addWidget(self.addEasyButton)


        self.verticalLayout.addLayout(self.horizontalLayout)


        self.gridLayout.addWidget(self.easyGroupBox, 0, 0, 1, 1)

        self.mediumGroupBox = QGroupBox(Dialog)
        self.mediumGroupBox.setObjectName(u"mediumGroupBox")
        self.verticalLayout_2 = QVBoxLayout(self.mediumGroupBox)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.listWidget_2 = QListWidget(self.mediumGroupBox)
        self.listWidget_2.setObjectName(u"listWidget_2")

        self.verticalLayout_2.addWidget(self.listWidget_2)

        self.horizontalLayout_2 = QHBoxLayout()
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.horizontalSpacer_2 = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.horizontalLayout_2.addItem(self.horizontalSpacer_2)

        self.addMediumButton = QToolButton(self.mediumGroupBox)
        self.addMediumButton.setObjectName(u"addMediumButton")
        self.addMediumButton.setIcon(icon)

        self.horizontalLayout_2.addWidget(self.addMediumButton)

        self.removeMediumButton = QToolButton(self.mediumGroupBox)
        self.removeMediumButton.setObjectName(u"removeMediumButton")
        self.removeMediumButton.setIcon(icon1)

        self.horizontalLayout_2.addWidget(self.removeMediumButton)


        self.verticalLayout_2.addLayout(self.horizontalLayout_2)


        self.gridLayout.addWidget(self.mediumGroupBox, 0, 1, 1, 1)

        self.extremeGroupBox = QGroupBox(Dialog)
        self.extremeGroupBox.setObjectName(u"extremeGroupBox")
        self.verticalLayout_4 = QVBoxLayout(self.extremeGroupBox)
        self.verticalLayout_4.setObjectName(u"verticalLayout_4")
        self.listWidget_4 = QListWidget(self.extremeGroupBox)
        self.listWidget_4.setObjectName(u"listWidget_4")

        self.verticalLayout_4.addWidget(self.listWidget_4)

        self.horizontalLayout_4 = QHBoxLayout()
        self.horizontalLayout_4.setObjectName(u"horizontalLayout_4")
        self.horizontalSpacer_4 = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.horizontalLayout_4.addItem(self.horizontalSpacer_4)

        self.addExtremeButton = QToolButton(self.extremeGroupBox)
        self.addExtremeButton.setObjectName(u"addExtremeButton")
        self.addExtremeButton.setIcon(icon)

        self.horizontalLayout_4.addWidget(self.addExtremeButton)

        self.removeExtremeButton = QToolButton(self.extremeGroupBox)
        self.removeExtremeButton.setObjectName(u"removeExtremeButton")
        self.removeExtremeButton.setIcon(icon1)

        self.horizontalLayout_4.addWidget(self.removeExtremeButton)


        self.verticalLayout_4.addLayout(self.horizontalLayout_4)


        self.gridLayout.addWidget(self.extremeGroupBox, 0, 3, 1, 1)

        self.buttonBox = QDialogButtonBox(Dialog)
        self.buttonBox.setObjectName(u"buttonBox")
        self.buttonBox.setOrientation(Qt.Horizontal)
        self.buttonBox.setStandardButtons(QDialogButtonBox.Cancel|QDialogButtonBox.Ok)

        self.gridLayout.addWidget(self.buttonBox, 1, 2, 1, 2)


        self.retranslateUi(Dialog)
        self.buttonBox.accepted.connect(Dialog.accept)
        self.buttonBox.rejected.connect(Dialog.reject)

        QMetaObject.connectSlotsByName(Dialog)
    # setupUi

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"Dialog", None))
        self.hardGroupBox.setTitle(QCoreApplication.translate("Dialog", u"Hard", None))
        self.addHardButton.setText(QCoreApplication.translate("Dialog", u"...", None))
        self.removeHardButton.setText(QCoreApplication.translate("Dialog", u"...", None))
        self.easyGroupBox.setTitle(QCoreApplication.translate("Dialog", u"Easy", None))
        self.removeEasyButton.setText(QCoreApplication.translate("Dialog", u"...", None))
        self.addEasyButton.setText(QCoreApplication.translate("Dialog", u"...", None))
        self.mediumGroupBox.setTitle(QCoreApplication.translate("Dialog", u"Medium", None))
        self.addMediumButton.setText(QCoreApplication.translate("Dialog", u"...", None))
        self.removeMediumButton.setText(QCoreApplication.translate("Dialog", u"...", None))
        self.extremeGroupBox.setTitle(QCoreApplication.translate("Dialog", u"Extreme", None))
        self.addExtremeButton.setText(QCoreApplication.translate("Dialog", u"...", None))
        self.removeExtremeButton.setText(QCoreApplication.translate("Dialog", u"...", None))
    # retranslateUi

