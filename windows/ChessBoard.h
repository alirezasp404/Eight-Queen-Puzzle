

#ifndef INC_8_QUEEN_CHESSBOARD_H
#define INC_8_QUEEN_CHESSBOARD_H


#include <QGraphicsView>
#include "../views/Background.h"

class ChessBoard : public QGraphicsView {
private:
    QGraphicsScene *scene;
    Background* background;
public:
    ChessBoard();
    ~ChessBoard();
};


#endif //INC_8_QUEEN_CHESSBOARD_H
