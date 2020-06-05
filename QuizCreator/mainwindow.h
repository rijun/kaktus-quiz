#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "quizitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QModelIndex;
class QuizModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

    void on_actionAboutQt_triggered();

    void on_generateButton_clicked();

    void on_addButton_clicked();
    void on_editButton_clicked();

    void showQuizEditor(const QModelIndex &index);
    void editQuizModel(int result);

private:
    Ui::MainWindow *ui;
    QuizModel *m_model;
};
#endif // MAINWINDOW_H
