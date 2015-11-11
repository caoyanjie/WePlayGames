#ifndef SPIDERCARD_H
#define SPIDERCARD_H

#include <QWidget>
#include <QMap>
class QLabel;
class QPropertyAnimation;
class QParallelAnimationGroup;
class QSequentialAnimationGroup;
class Card;
class SpiderCard : public QWidget
{
    Q_OBJECT
public:
    explicit SpiderCard(int width1, int height1, QWidget *parent = 0);

private:
    QLabel *labSourceSpider[4];
    Card *card[54];
    QPropertyAnimation *animationDown[4];
    QPropertyAnimation *animationSplit[4];
    QPropertyAnimation *animationSeparate[54];
    QParallelAnimationGroup *animationDownGroup;
    QParallelAnimationGroup *animationSplitGroup;
    QSequentialAnimationGroup *animationSeparateGroup;

    QMap<QLabel*, QString> cardNumber;

    const int CARDWIDTH;
    const int CARDHEIGHT;
    int currentNum;

signals:

public slots:

private slots:
    void separateCards();
    void assignCards();
    void showNumber();
};

#endif // SPIDERCARD_H
