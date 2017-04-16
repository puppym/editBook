#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QtGui>

class QLineEdit;
class QDialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool loadFile(const QString &fileName);
    void newFile();
    bool maybeSave();
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
private slots:
    void on_action_new_triggered();
    void on_action_save_triggered();
    void on_action_saveas_triggered();
    void on_action_open_triggered();
    void on_action_close_triggered();
    void on_action_exit_triggered();
    void on_action_undo_triggered();
    void on_action_cut_triggered();
    void on_action_copy_triggered();
    void on_action_paste_triggered();
    void showFindText();
    void changeTextFont();
    void changeBackgroundColor();
    void on_action_find_triggered();
    void on_action_font_triggered();

    void on_action_color_triggered();

private:
    Ui::MainWindow *ui;
    //文件是否被保存
    bool isUntitled;
    //保存的路径
    QString curFile;
    //查找对话框
    QLineEdit *findLineEdit;
    QDialog *findDlg;
    //设置字体
    QFontComboBox *font_Combox;
    QDialog *fontDlg;
    QFont font;
    //设置背景颜色
    QColorDialog *colorDlg;

protected:
    void closeEvent(QCloseEvent *event);

};

#endif // MAINWINDOW_H
