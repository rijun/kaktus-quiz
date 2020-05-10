# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'question_editor.ui'
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
        Dialog.resize(433, 238)
        self.verticalLayout = QVBoxLayout(Dialog)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.formLayout = QFormLayout()
        self.formLayout.setObjectName(u"formLayout")
        self.questionLabel = QLabel(Dialog)
        self.questionLabel.setObjectName(u"questionLabel")

        self.formLayout.setWidget(0, QFormLayout.LabelRole, self.questionLabel)

        self.questionLineEdit = QLineEdit(Dialog)
        self.questionLineEdit.setObjectName(u"questionLineEdit")

        self.formLayout.setWidget(0, QFormLayout.FieldRole, self.questionLineEdit)

        self.answerLabel = QLabel(Dialog)
        self.answerLabel.setObjectName(u"answerLabel")

        self.formLayout.setWidget(1, QFormLayout.LabelRole, self.answerLabel)

        self.answerLineEdit = QLineEdit(Dialog)
        self.answerLineEdit.setObjectName(u"answerLineEdit")

        self.formLayout.setWidget(1, QFormLayout.FieldRole, self.answerLineEdit)

        self.option1Label = QLabel(Dialog)
        self.option1Label.setObjectName(u"option1Label")

        self.formLayout.setWidget(2, QFormLayout.LabelRole, self.option1Label)

        self.option1LineEdit = QLineEdit(Dialog)
        self.option1LineEdit.setObjectName(u"option1LineEdit")

        self.formLayout.setWidget(2, QFormLayout.FieldRole, self.option1LineEdit)

        self.option2Label = QLabel(Dialog)
        self.option2Label.setObjectName(u"option2Label")

        self.formLayout.setWidget(3, QFormLayout.LabelRole, self.option2Label)

        self.option2LineEdit = QLineEdit(Dialog)
        self.option2LineEdit.setObjectName(u"option2LineEdit")

        self.formLayout.setWidget(3, QFormLayout.FieldRole, self.option2LineEdit)

        self.option4Label = QLabel(Dialog)
        self.option4Label.setObjectName(u"option4Label")

        self.formLayout.setWidget(4, QFormLayout.LabelRole, self.option4Label)

        self.option3LineEdit = QLineEdit(Dialog)
        self.option3LineEdit.setObjectName(u"option3LineEdit")

        self.formLayout.setWidget(4, QFormLayout.FieldRole, self.option3LineEdit)


        self.verticalLayout.addLayout(self.formLayout)

        self.buttonBox = QDialogButtonBox(Dialog)
        self.buttonBox.setObjectName(u"buttonBox")
        self.buttonBox.setOrientation(Qt.Horizontal)
        self.buttonBox.setStandardButtons(QDialogButtonBox.Cancel|QDialogButtonBox.Ok)

        self.verticalLayout.addWidget(self.buttonBox)


        self.retranslateUi(Dialog)
        self.buttonBox.accepted.connect(Dialog.accept)
        self.buttonBox.rejected.connect(Dialog.reject)

        QMetaObject.connectSlotsByName(Dialog)
    # setupUi

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(QCoreApplication.translate("Dialog", u"Question Editor", None))
        self.questionLabel.setText(QCoreApplication.translate("Dialog", u"Question", None))
        self.answerLabel.setText(QCoreApplication.translate("Dialog", u"Answer", None))
        self.option1Label.setText(QCoreApplication.translate("Dialog", u"Option", None))
        self.option2Label.setText(QCoreApplication.translate("Dialog", u"Option", None))
        self.option4Label.setText(QCoreApplication.translate("Dialog", u"Option", None))
    # retranslateUi

