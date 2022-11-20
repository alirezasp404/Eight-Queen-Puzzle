

#ifndef INC_8_QUEEN_BOARD_H
#define INC_8_QUEEN_BOARD_H


#include <QGraphicsView>
#include "../views/Background.h"
#include "../views/ChessBoard.h"
#include "../views/Queen.h"
#include <QKeyEvent>
class Board : public QGraphicsView {
private:
    QGraphicsScene *scene;
    Background *background;
    ChessBoard *black;
    QList<Queen *> queens;
    int numOfQueens = 8;
    int counter=0;
    int boardHeight,boardWidth;

public:
    Board();

    ~Board();

    void addQueen();
    void removeQueen(int);

    static bool possible(int *, int);
    void n_queen(int *, int, int);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    };


#endif //INC_8_QUEEN_BOARD_H
