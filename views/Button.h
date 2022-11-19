

#ifndef INC_8_QUEEN_BUTTON_H
#define INC_8_QUEEN_BUTTON_H
#include <QGraphicsTextItem>



class Button : public QGraphicsTextItem {
Q_OBJECT
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int width;
    int height;
public:
    Button(int width,int height);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
signals:
    void press();
};


#endif //INC_8_QUEEN_BUTTON_H
