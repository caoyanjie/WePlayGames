#ifndef WEPLAYGAMES_H
#define WEPLAYGAMES_H

#include <QWidget>
class QLabel;
class QPushButton;
class QToolButton;
class QComboBox;
class QLineEdit;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class WindowTools;
class GameArea;
class WePlayGames : public QWidget
{
    Q_OBJECT

public:
    WePlayGames(QWidget *parent = 0);
    ~WePlayGames();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    QLabel *labFram;

    //title
    QLabel *labWindowTitle;
    WindowTools *windowTools;

    //tool
    QLabel *labToolFram;
    QComboBox *cbxGames;
    QPushButton *pbnGameRule;
    QLabel *labParticipants;
    QToolButton *tbnReady;
    QLabel *labUsername;
    QLineEdit *lnUsername;
    QPushButton *pbnApply;
    QHBoxLayout *layoutApply;

    //game area
    GameArea *gameArea;

    //title
    QHBoxLayout *layoutWindowTitle;
    QHBoxLayout *layoutTool;
    QVBoxLayout *layoutFram;
    QGridLayout *layoutTop;

    QPoint offset;

private slots:
    void startPlay();
};

#endif // WEPLAYGAMES_H
