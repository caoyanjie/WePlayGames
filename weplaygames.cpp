#include "weplaygames.h"
#include "windowtools.h"
#include "gamearea.h"
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QComboBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMouseEvent>

WePlayGames::WePlayGames(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->resize(1200, 900);

    labFram = new QLabel;

    // window title
    labWindowTitle = new QLabel("We Play Games");
    windowTools = new WindowTools(this);

    layoutWindowTitle = new QHBoxLayout;
    layoutWindowTitle->addStretch(5);
    layoutWindowTitle->addWidget(labWindowTitle);
    layoutWindowTitle->addStretch(4);
    layoutWindowTitle->addWidget(windowTools);

    // tools
    labToolFram = new QLabel;
    labToolFram->setFixedHeight(30);
    cbxGames = new QComboBox;
    cbxGames->addItem(tr("蜘蛛纸牌"));
    cbxGames->addItem(tr("2048"));
    cbxGames->addItem(tr("俄罗斯方块"));
    pbnGameRule = new QPushButton("游戏规则");
    labParticipants = new QLabel("参与者：0 人");
    tbnReady = new QToolButton;
    tbnReady->setToolTip("准备就绪");
    labUsername = new QLabel("用户名：");
    lnUsername = new QLineEdit;
    pbnApply = new QPushButton("申请加入");
    labUsername->setFixedWidth(45);
    lnUsername->setFixedWidth(100);
    pbnApply->setFixedWidth(70);

    layoutApply = new QHBoxLayout;
    layoutApply->addWidget(labUsername);
    layoutApply->addWidget(lnUsername);
    layoutApply->addWidget(pbnApply);
    layoutApply->setSpacing(5);

    layoutTool = new QHBoxLayout;
    layoutTool->addWidget(cbxGames);
    layoutTool->addWidget(pbnGameRule);
    layoutTool->addWidget(labParticipants);
    layoutTool->addStretch();
    layoutTool->addWidget(tbnReady);
    layoutTool->addStretch();
    layoutTool->addLayout(layoutApply);
    layoutTool->setSpacing(30);
    layoutTool->setMargin(5);
    labToolFram->setLayout(layoutTool);

    // game area
    gameArea = new GameArea;

    //layout top
    layoutFram = new QVBoxLayout;
    layoutFram->addLayout(layoutWindowTitle);
    layoutFram->addWidget(labToolFram);
    layoutFram->addWidget(gameArea);
    labFram->setLayout(layoutFram);

    layoutTop = new QGridLayout;
    layoutTop->addWidget(labFram);
    this->setLayout(layoutTop);

    //stylesheet
    labFram->setObjectName("labFram");
    labWindowTitle->setObjectName("labWindowTitle");
    labToolFram->setObjectName("labToolFram");
    cbxGames->setObjectName("cbxGames");
    pbnGameRule->setObjectName("pbnGameRule");
    labParticipants->setObjectName("labParticipants");
    tbnReady->setObjectName("tbnReady");
    labUsername->setObjectName("labUsername");
    this->setStyleSheet(
                "#labFram{"
                    "background: rgba(100, 100, 100, 100);"
                    "border: 1px solid rgba(255, 255, 255, 180);"
                    "border-radius: 5px;"
                "}"
                "#labWindowTitle{"
                    "font-size: 20pt;"
                    "color: red;"
                "}"
                "#labToolFram{"
                    "background: rgba(58, 88, 173, 190);"
                "}"

                "#pbnGameRule{"
//                    "background: rgba(55, 138, 48, 200);"
//                    "background: rgba(0, 0, 255, 40);"
//                    "background: rgba(0, 0, 0, 100);"
                    "background: rgba(25, 30, 255, 200);"
                    "width: 80;"
                    "height: 20;"
                    "border-radius: 10px;"
                    "color: white;"
                "}"
                "#pbnGameRule:hover{"
                    "background: rgba(55, 138, 48, 255);"
                    "background: rgba(17, 20, 169, 255);"
                "}"
                "#pbnGameRule:pressed{"
                    "background: rgba(51, 103, 56, 255);"
                    "background: rgba(25, 30, 255, 200);"
                "}"

                "#tbnReady{"
                    "border-image: url(:Images/ready);"
                "}"
                "#tbnReady:hover{"
                    "border-image: url(:Images/readyHover);"
                "}"
                "#tbnReady:pressed{"
                    "border-image: url(:Images/ready);"
                "}"

                "#labParticipants{"
                    "color: white;"
                "}"

                "#labUsername{"
                    "color: white;"
                "}"
                );

    connect(tbnReady, SIGNAL(clicked()), gameArea, SLOT(startPlay()));
}

WePlayGames::~WePlayGames()
{

}

// 鼠标按下事件（配合移动事件拖动窗口）
void WePlayGames::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        offset = event->globalPos() - this->pos();
    }
}

// 鼠标移动事件（拖动窗口）
void WePlayGames::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        this->move(event->globalPos() - offset);
    }
}

// 鼠标滚轮事件（缩放窗口）
void WePlayGames::wheelEvent(QWheelEvent *event)
{
    const int changes = 40;
    if (event->delta() > 0)
    {
        this->move(this->pos() - QPoint(changes/2, changes/2));
        this->resize(this->size() + QSize(changes, changes));
    }
    else
    {
        this->move(this->pos() + QPoint(changes/2, changes/2));
        this->resize(this->size() - QSize(changes, changes));
    }
}

void WePlayGames::startPlay()
{

}
