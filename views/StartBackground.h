

#ifndef INC_8_QUEEN_STARTBACKGROUND_H
#define INC_8_QUEEN_STARTBACKGROUND_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class StartBackground : public QGraphicsPixmapItem{

public:
    bool initialized{false};
    StartBackground(QGraphicsItem *parent=nullptr);
    void  paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif //INC_8_QUEEN_STARTBACKGROUND_H
