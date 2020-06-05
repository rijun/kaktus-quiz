#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "quizmodel.h"

#include <QMessageBox>
#include <QFile>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QuizModel *model = new QuizModel();

    ui->questionView->setModel(model);
//    for (int column = 0; column < model->columnCount(); ++column) {
//        ui->questionView->resizeColumnToContents(column);
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insertRow()
{
    return;
}

/* Action slots */

void MainWindow::on_actionAboutQt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About Kaktus Quiz Creator",
                       "<p>Kaktus Quiz Creator uses open source software.</p>"
                       "<ul>"
                       "<li><a href='https://github.com/feathericons/feather'>Feather</a></li>"
                       "</ul>"
                       "<hl>"
                       "<h4>Feather</h4>"
                       "The MIT License (MIT)"
                       "<br>"
                       "Copyright (c) 2013-2017 Cole Bemis"
                       "<br>"
                       "Permission is hereby granted, free of charge, to any person obtaining a copy"
                       "of this software and associated documentation files (the \"Software\"), to deal"
                       "in the Software without restriction, including without limitation the rights"
                       "to use, copy, modify, merge, publish, distribute, sublicense, and/or sell"
                       "copies of the Software, and to permit persons to whom the Software is"
                       "furnished to do so, subject to the following conditions:"
                       "<br>"
                       "The above copyright notice and this permission notice shall be included in all"
                       "copies or substantial portions of the Software."
                       "<br>"
                       "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR"
                       "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,"
                       "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE"
                       "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER"
                       "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,"
                       "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE"
                       "SOFTWARE.");
}

/* Button slots */

void MainWindow::on_generateButton_clicked()
{
    qDebug() << "Generation";
}

void MainWindow::on_addButton_clicked()
{
    insertRow();
}
