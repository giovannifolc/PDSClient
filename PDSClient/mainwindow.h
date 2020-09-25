#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <client.h>
#include <filesselection.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void login_refused();

private slots:
    void on_loginButton_clicked();
    void on_registrationButton_clicked();
    void onLoginSuccess();
private:
    Ui::MainWindow *ui;
    Client *client;
};
#endif // MAINWINDOW_H
