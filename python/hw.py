# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'hw.ui'
#
# Created: Thu Nov  6 15:11:44 2014
#      by: PyQt5 UI code generator 5.3.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Window(object):
    def setupUi(self, Window):
        Window.setObjectName("Window")
        Window.resize(171, 61)
        self.verticalLayout = QtWidgets.QVBoxLayout(Window)
        self.verticalLayout.setObjectName("verticalLayout")
        self.button = QtWidgets.QPushButton(Window)
        self.button.setObjectName("button")
        self.verticalLayout.addWidget(self.button)

        self.retranslateUi(Window)
        QtCore.QMetaObject.connectSlotsByName(Window)

    def retranslateUi(self, Window):
        _translate = QtCore.QCoreApplication.translate
        Window.setWindowTitle(_translate("Window", "Hello World"))
        self.button.setText(_translate("Window", "Test"))

