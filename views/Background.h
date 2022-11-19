
#ifndef INC_8_QUEEN_BACKGROUND_H
#define INC_8_QUEEN_BACKGROUND_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Background : public QGraphicsPixmapItem{

public:
    bool initialized{false};
    Background(QGraphicsItem *parent=nullptr);
    void  paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif //INC_8_QUEEN_BACKGROUND_H
