#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>

#include "QuizItem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QModelIndex;
class QProgressBar;
class QLabel;
class QuizModel;
class ItemEditor;

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
    void on_delButton_clicked();
    void on_editButton_clicked();

    void showQuizEditor(const QModelIndex &index);
    void editQuizModel(int result);
    void updateQuizState(int category, int difficulty);

private:
    Ui::MainWindow *ui;
    QuizModel *m_model;
    ItemEditor *m_itemEditor;
    QModelIndex m_currentIndex;
    QVector<QProgressBar*> m_progressBarList;
    QVector<QVector<QLabel*>> m_labelList;

    const QVector<QString> labelPresets { "%1/%2", "%1/%2", "%1/%2", "%1/%2" };

    void renameCategories();
};
#endif // MAINWINDOW_H
