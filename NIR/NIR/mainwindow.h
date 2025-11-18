#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <string>
#include "file.h"
#include "settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void on_OPEN_ALL_clicked();

    void on_APPLY_clicked();

    void on_SAVE_ALL_clicked();

    void on_GET_clicked();

    void on_APPLY_GENERATION_clicked();

    void on_SAVE_GENERATION_ALL_clicked();

    void on_GET_GENERATION_clicked();

private:
    QString name = " ";
    QString name2 = " ";
    QString name_generate = " ";
    Ui::MainWindow *ui;
    File *parser = nullptr;
};

#endif // MAINWINDOW_H
