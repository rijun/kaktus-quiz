﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "quizmodel.h"
#include "item_editor.h"

#include <QMessageBox>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_model(new QuizModel),
      m_itemEditor(new ItemEditor(this, &m_model->categoryList(), &m_model->difficultyList()))
{
    ui->setupUi(this);

    ui->questionView->setModel(m_model);
    ui->questionView->resizeColumnsToContents();
    ui->questionView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->questionView->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(ui->questionView, &QAbstractItemView::doubleClicked, this, &MainWindow::showQuizEditor);
    connect(m_itemEditor, &QDialog::finished, this, &MainWindow::editQuizModel);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    //insertRow();
}

void MainWindow::on_editButton_clicked()
{
    showQuizEditor(ui->questionView->currentIndex());
}

void MainWindow::showQuizEditor(const QModelIndex &index)
{
    m_currentIndex = index;
    m_itemEditor->setQuizItem(m_model->quizItemAt(index));
    m_itemEditor->open();
}

void MainWindow::editQuizModel(int result)
{
    switch (result) {
    case QDialog::Accepted:
        m_model->setData(m_currentIndex, QVariant::fromValue(m_itemEditor->quizItem()));
        break;
    case QDialog::Rejected:
        break;
    }
}
