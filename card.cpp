#include "card.h"
#include <QLabel>
#include <QMouseEvent>
#include <QPropertyAnimation>

Card::Card(QWidget *parent) :
    QWidget(parent)
  ,CARDWIDTH(70)
  ,CARDHEIGHT(107)
{
    this->setFixedSize(CARDWIDTH, CARDHEIGHT);
    labBg = new QLabel(this);
    labBg->setFixedSize(CARDWIDTH, CARDHEIGHT);
    labBg->setStyleSheet("border-image");

    backAnimation = new QPropertyAnimation(this, "pos");
    backAnimation->setDuration(500);
}

void Card::setOldPos(QPoint pos)
{
    oldPos = pos;
}

void Card::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        offset = event->globalPos() - this->pos();
    }
}

void Card::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        this->raise();
        this->move(event->globalPos() - offset);
    }
}

void Card::mouseReleaseEvent(QMouseEvent *event)
{
    backAnimation->setStartValue(this->pos());
    backAnimation->setEndValue(oldPos);
    backAnimation->start();
}
