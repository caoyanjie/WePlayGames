#include "gamearea.h"
#include "spidercard.h"
#include <QLabel>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDebug>

GameArea::GameArea(QWidget *parent) :
    QWidget(parent)
{
    //left
    labStretch = new QLabel(" ");
    labStretch->setFixedHeight(13);
    labPlayArea = new QLabel;

    //right
    labParticipantsTitle = new QLabel("游戏参与者：");
    labParticipantsTitle->setAlignment(Qt::AlignCenter);
    participants = new QTextBrowser;
    labRanking = new QLabel("排行榜");
    labRanking->setAlignment(Qt::AlignCenter);
    ranking = new QTextBrowser;
    labParticipantsTitle->setFixedWidth(200);
    participants->setFixedWidth(200);
    labRanking->setFixedWidth(200);
    ranking->setFixedWidth(200);

    //left layout
    layoutPlayArea = new QVBoxLayout;
    layoutPlayArea->addWidget(labStretch);
    layoutPlayArea->addWidget(labPlayArea);

    //play area
    play = new QGridLayout;
    labPlayArea->setLayout(play);

    //right layout
    layoutParticipants = new QVBoxLayout;
    layoutParticipants->addWidget(labParticipantsTitle);
    layoutParticipants->addWidget(participants);
    layoutParticipants->addWidget(labRanking);
    layoutParticipants->addWidget(ranking);

    layoutTop = new QHBoxLayout;
    layoutTop->addLayout(layoutPlayArea);
    layoutTop->addLayout(layoutParticipants);
    layoutTop->setMargin(0);
    this->setLayout(layoutTop);

    //stylesheet
    labPlayArea->setObjectName("labPlayArea");
    labParticipantsTitle->setObjectName("labParticipantsTitle");
    participants->setObjectName("participants");
    labRanking->setObjectName("labRanking");
    ranking->setObjectName("ranking");

    this->setStyleSheet(
                "#labPlayArea{"
                    "border: 1px solid white;"
                "}"
                "#labParticipantsTitle, #labRanking{"
                    "color: white;"
                "}"
                "#participants, #ranking{"
                    "background: rgba(0, 0, 0, 0);"
                "}"
                );
}

void GameArea::startPlay()
{
    if (spiderCard != 0)
    {
        spiderCard->show();
    }
    else
    {
        spiderCard = new SpiderCard(labPlayArea->width(), labPlayArea->height());
        spiderCard->show();
        play->addWidget(spiderCard);
    }
}
