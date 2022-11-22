

#ifndef INC_8_QUEEN_BOARD_H
#define INC_8_QUEEN_BOARD_H


#include <QGraphicsView>
#include "../views/Background.h"
#include "../views/ChessBoard.h"
#include "../views/Queen.h"
#include "../views/Label.h"
#include <QKeyEvent>

class Board : public QGraphicsView {
private:
    QGraphicsScene *scene;
    Background *background;
    ChessBoard *black;
    QList<Queen *> queens;
    Label *solution;
    Label *showCurrentSolution;
    Label *guide;
    Label *eightQueen;
    int numOfQueens{8};
    int currentSolution{-1};
    int boardHeight, boardWidth;

public:
    Board();

    ~Board();

    void addQueen(int);

    void removeQueen();

    void addDetails();

    static bool possible(int *, int);

    void n_queen(int *, int, int);

protected:
    void keyPressEvent(QKeyEvent *event) override;
};


#endif //INC_8_QUEEN_BOARD_H
