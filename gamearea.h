#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QWidget>
class QLabel;
class QTextBrowser;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class SpiderCard;
class GameArea : public QWidget
{
    Q_OBJECT
public:
    explicit GameArea(QWidget *parent = 0);

private:
    //left
    QLabel *labStretch;
    QLabel *labPlayArea;
    SpiderCard *spiderCard;

    //right
    QLabel *labParticipantsTitle;
    QTextBrowser *participants;
    QLabel *labRanking;
    QTextBrowser *ranking;
    QGridLayout *play;

    //layout
    QVBoxLayout *layoutPlayArea;
    QVBoxLayout *layoutParticipants;
    QHBoxLayout *layoutTop;

signals:

public slots:

private slots:
    void startPlay();

};

#endif // GAMEAREA_H
