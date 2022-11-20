#include "Queen.h"
Queen::Queen(int width, int height, int horizontalIndex, int verticalIndex) {
    float movement=height/10+0.5;
    QPixmap pixmap(":/images/queen");
    pixmap=pixmap.scaled(movement,movement);
    setPixmap(pixmap);
    setPos(movement*horizontalIndex+movement+(width-height)/2,movement+movement*verticalIndex);
}