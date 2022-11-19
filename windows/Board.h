

#ifndef INC_8_QUEEN_BOARD_H
#define INC_8_QUEEN_BOARD_H


#include <QGraphicsView>
#include <QKeyEvent>
#include "../views/Background.h"
#include "../views/ChessBoard.h"

class Board : public QGraphicsView {
private:
    QGraphicsScene *scene;
    Background *background;
    ChessBoard *black;
    int numOfQueens=8;
public:
    Board();

    ~Board();


};


#endif //INC_8_QUEEN_BOARD_H
