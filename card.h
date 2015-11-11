#ifndef CARD_H
#define CARD_H

#include <QWidget>
class QLabel;
class QPropertyAnimation;
class Card : public QWidget
{
    Q_OBJECT
public:
    explicit Card(QWidget *parent = 0);

    void setOldPos(QPoint pos);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QLabel *labBg;

    QPoint oldPos;

    QPropertyAnimation *backAnimation;

    QPoint offset;

    const int CARDWIDTH;
    const int CARDHEIGHT;

signals:

public slots:

private slots:

};

#endif // CARD_H
