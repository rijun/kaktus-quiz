#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "questionitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

    void on_actionAboutQt_triggered();

private:
    Ui::MainWindow *ui;
    QVector<QuestionItem> m_questionList;
};
#endif // MAINWINDOW_H
