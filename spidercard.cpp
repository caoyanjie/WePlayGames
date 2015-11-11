#include "spidercard.h"
#include "card.h"
#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QTime>
#include <QDebug>

SpiderCard::SpiderCard(int width, int height, QWidget *parent) :
    QWidget(parent)
  ,CARDWIDTH(70)
  ,CARDHEIGHT(107)
  ,currentNum(0)
{
    this->resize(width, height);
    qsrand(QTime::currentTime().second());

    animationDownGroup = new QParallelAnimationGroup;
    animationSplitGroup = new QParallelAnimationGroup;

    connect(animationDownGroup, SIGNAL(finished()), this, SLOT(separateCards()));
    connect(animationSplitGroup, SIGNAL(finished()), this, SLOT(assignCards()));

    QPoint downStartPoint(200, 20);
    QPoint downEndPoint(this->width()-(CARDWIDTH+60), this->height()-(CARDHEIGHT+60));

    for (int i=0; i<4; ++i)
    {
        // init
        labSourceSpider[i] = new QLabel(this);
        labSourceSpider[i]->setFixedSize(CARDWIDTH, CARDHEIGHT);
        labSourceSpider[i]->setStyleSheet("border-image: url(:Images/0-0);");

        // down animation
        animationDown[i] = new QPropertyAnimation(labSourceSpider[i], "pos");
        animationDown[i]->setDuration(1500);
        animationDown[i]->setStartValue(downStartPoint);
        animationDown[i]->setEndValue(downEndPoint);
        animationDown[i]->setEasingCurve(QEasingCurve::OutBounce);
//        animationDown[i]->setEasingCurve(QEasingCurve::OutInBack);

        // split animation
        animationSplit[i] = new QPropertyAnimation(labSourceSpider[i], "pos");
        animationSplit[i]->setDuration(500);
        animationSplit[i]->setStartValue(downEndPoint);
        animationSplit[i]->setEndValue(QPoint(downEndPoint.x()-i*10, downEndPoint.y()));
        animationSplit[i]->setEasingCurve(QEasingCurve::OutQuad);

        // animation group
        animationDownGroup->addAnimation(animationDown[i]);
        animationSplitGroup->addAnimation(animationSplit[i]);
    }
    animationDownGroup->start();
}

void SpiderCard::separateCards()
{
    animationSplitGroup->start();
}

void SpiderCard::assignCards()
{
    animationSeparateGroup = new QSequentialAnimationGroup;
    QPoint startPoint(20, 20);
    /*
    for (int i=0; i<54; ++i)
    {
        labCard[i] = new QLabel(this);
        labCard[i]->setStyleSheet("border-image: url(:Images/0-0);");
        labCard[i]->move(labSourceSpider[3]->pos());
        labCard[i]->show();

        animationSeparate[i] = new QPropertyAnimation(labCard[i], "pos");
        animationSeparate[i]->setDuration(300);
        if (i % 10 == 0)
        {
            animationSeparate[i]->setStartValue(labCard[i]->pos());
        }
        animationSeparate[i]->setEndValue(QPoint(startPoint.x()+i*30, startPoint.y()));

        animationSeparateGroup->addAnimation(animationSeparate[i]);
    }
    */
    for (int i=0; i<6; ++i)
    {
        for (int j=0; j<10; ++j)
        {
            if (i==5 && j==4)
            {
                break;
            }
            int current = i * 10 + j;

            card[current] = new Card(this);
            card[current]->setFixedSize(CARDWIDTH, CARDHEIGHT);
            card[current]->setStyleSheet("border-image: url(:Images/0-0);");
            card[current]->move(labSourceSpider[3]->pos());
            card[current]->show();

            animationSeparate[current] = new QPropertyAnimation(card[current], "pos");
            animationSeparate[current]->setDuration(70);
            animationSeparate[current]->setStartValue(card[current]->pos());
            animationSeparate[current]->setEndValue(QPoint(startPoint.x()+j*90, startPoint.y()+i*30));
            card[current]->setOldPos(QPoint(startPoint.x()+j*90, startPoint.y()+i*30));
            connect(animationSeparate[current], SIGNAL(finished()), this, SLOT(showNumber()));

            animationSeparateGroup->addAnimation(animationSeparate[current]);
        }
    }
    animationSeparateGroup->start();
}

// 翻开数字
void SpiderCard::showNumber()
{
    if (currentNum > 43)
    {
        int one = rand() % 4 + 1;
        int two = rand() % 13 + 1;
        card[currentNum]->setStyleSheet(tr("border-image: url(:Images/%1-%2);").arg(one).arg(two));
    }
    currentNum++;
}
