#include <QtGui>
#include <QGraphicsScene>
#include <QDialog>
#include <QVector>


namespace Ui {
class TimeGrab;
}

class TimeGrab : public QDialog
{
    Q_OBJECT

public:
    explicit TimeGrab(QWidget *parent = 0);
    TimeGrab(QVector<QString> & petInfo, int petNumber, QString name, QString token);
    ~TimeGrab();
    int GetTime();
    void Clock_Menu();
    void level_up();
    void setHunger(int hungr);
    void setHappiness(int happiness);
    void setLevel(int levl);
    void updateVector();
    void updateFile(QString name);
    int convertToInt(QString x);
    QString convertoString(int x);


private slots:
    void showtime();
    void on_Start_clicked();

    void on_Pause_clicked();

    void on_Continue_clicked();

    void on_End_clicked();

    void on_MainMenu_clicked();

protected:
    //void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    Ui::TimeGrab *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QString username;
    QVector<QString> pets;
    int petNumber;
    int hungerz;
    int happines_s;
    int level;
    int totalTokens;

    int hours;
    int minutes;
    int seconds;
    int tokens;
    double happiness;
    double hunger;


    int current_level_experience;
    int total_experience;
    int current_level;
};
