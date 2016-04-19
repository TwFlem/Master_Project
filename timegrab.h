#include <QtGui>

namespace Ui {
class TimeGrab;
}

class TimeGrab : public QDialog
{
    Q_OBJECT

public:
    explicit TimeGrab(QWidget *parent = 0);
    ~TimeGrab();
    int GetTime();
    void Clock_Menu();
    void level_up();

private slots:
    void showtime();
    void on_Start_clicked();

    void on_Pause_clicked();

    void on_Continue_clicked();

    void on_End_clicked();

protected:
    //void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    Ui::TimeGrab *ui;
    QGraphicsScene *scene;
    QTimer *timer;

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

#endif // TIMEGRAB_H
