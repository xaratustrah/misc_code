import sys
from PyQt5.QtWidgets import QApplication, QDialog
from ui_playdialog import Ui_PlayDialog

app = QApplication(sys.argv)
window = QDialog()
ui = Ui_PlayDialog()
ui.setupUi(window)

window.show()
sys.exit(app.exec_())
