#ifndef JAUDIO_H
#define JAUDIO_H

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class jAudio;
}

class jAudio : public QMainWindow
{
    Q_OBJECT

public:
    explicit jAudio(QWidget *parent = 0);

    ~jAudio();

private:
    Ui::jAudio *ui;

private slots:
    void jSetup (void);
    void jInfo (QString);
    void jFillComboBox(QComboBox* comboBox, QStringList data);
    void on_bRecord_clicked();
};

#endif // JAUDIO_H
