
#include "StartBackground.h"
StartBackground::StartBackground(QGraphicsItem* parent): QGraphicsPixmapItem(parent){}
void StartBackground::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsPixmapItem::paint(painter,option,widget);
    if(!initialized){
        auto sceneWidth=scene()->sceneRect().width();
        auto sceneHeight=scene()->sceneRect().height();
        QPixmap pixmap(":/images/startBG");
        pixmap=pixmap.scaled(sceneWidth,sceneHeight,Qt::KeepAspectRatioByExpanding);
        setPixmap(pixmap);
        setPos(0,0);
        initialized= true;
    }

}