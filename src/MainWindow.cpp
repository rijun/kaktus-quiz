#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QuizModel.h"
#include "ItemEditor.h"
#include "LicenseTexts.h"
#include "FileGenerator.h"

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_model(new QuizModel),
      m_itemEditor(new ItemEditor(this, &m_model->categoryList(), &m_model->difficultyList()))
{
    ui->setupUi(this);

    ui->questionView->setModel(m_model);
    // ui->questionView->resizeColumnsToContents();
    ui->questionView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->questionView->setSelectionMode(QAbstractItemView::SingleSelection);

    // Build progress bar list
    m_progressBarList.resize(m_model->numberOfCategories());
    for (QObject *obj : ui->progressGroupBox->children()) {
        if(QProgressBar *pb = qobject_cast<QProgressBar*>(obj)) {
            QRegularExpressionMatch match = QRegularExpression("\\d").match(obj->objectName());
            m_progressBarList.replace(match.captured(0).toInt() - 1, pb);
        }
    }

    // Connect signals and slots
    connect(ui->questionView, &QAbstractItemView::doubleClicked, this, &MainWindow::showQuizEditor);
    connect(m_itemEditor, &QDialog::finished, this, &MainWindow::editQuizModel);
    connect(m_model, &QuizModel::quizDataChanged, this, &MainWindow::updateQuizState);
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
    QMessageBox::about(this, "About Kaktus Quiz Creator", LicenseTexts::aboutText);
}

/* Button slots */

void MainWindow::on_generateButton_clicked()
{
//    QFileDialog dialog(this, tr("Select folder to store quiz"), "~");
//    dialog.setFileMode(QFileDialog::Directory);
//    dialog.setOption(QFileDialog::ShowDirsOnly);
//    QString fileName;
//    if (dialog.exec()) {
//        fileName = dialog.selectedFiles()[0];
//    } else {
//        return;
//    }

    QJsonArray quizDataList;

    for (int i = 0; i < m_model->rowCount(); ++i) {
        QuizItem quizItem = m_model->quizItemAt(i);

        // if (!quizItem.complete) { continue; }

        QJsonObject quizObj;
        quizObj.insert("question", quizItem.question);
        quizObj.insert("answer", quizItem.answer);
        quizObj.insert("options", QJsonArray::fromStringList(quizItem.options.toList()));
        quizObj.insert("category", quizItem.category);
        quizObj.insert("difficulty", quizItem.difficulty);
        quizDataList.append(quizObj);
    }

    QJsonDocument quizData = QJsonDocument(quizDataList);

    QFile templateFile(":/templates/quiz_item.html");
    if (!templateFile.open(QIODevice::ReadOnly | QIODevice::Text)) { return; }

    if (FileGenerator::generateQuiz(quizData.toJson(QJsonDocument::Compact).toStdString(), templateFile.readAll().toStdString(), ".")) {
        qDebug() << "Success!";
    } else {
        qDebug() << "Fail!";
    }

    templateFile.close();
}

void MainWindow::on_addButton_clicked()
{
    m_model->insertRow(m_model->rowCount());
    showQuizEditor(m_model->index(m_model->rowCount() - 1, 0));
}

void MainWindow::on_delButton_clicked()
{
    m_model->removeRow(ui->questionView->currentIndex().row());
}

void MainWindow::on_editButton_clicked()
{
    showQuizEditor(ui->questionView->currentIndex());
}

void MainWindow::showQuizEditor(const QModelIndex &index)
{
    m_currentIndex = index;
    m_itemEditor->setQuizItem(m_model->quizItemAt(m_currentIndex));
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

void MainWindow::updateQuizState(int category, int difficulty)
{
    int amountOfQuestions = 0;
    for (int i = 0; i < m_model->numberOfDifficulties(); ++i) {
        amountOfQuestions += m_model->quizItemCount(category, i);
    }
    qDebug() << amountOfQuestions / m_model->maxQuestionsPerCategory() * 100;
    m_progressBarList.at(category)->setValue(amountOfQuestions * 100 / m_model->maxQuestionsPerCategory());
}

void MainWindow::renameCategories()
{
    // QObjectList labelList =

    for (const QObject *obj : ui->progressGroupBox->children()) {
        qDebug() << obj->objectName();
    }
}
