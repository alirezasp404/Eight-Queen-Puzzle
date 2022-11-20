

#include "Board.h"
Board::Board() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    setScene(scene);
    background = new Background();
    scene->addItem(background);
    black = new ChessBoard(width(), height());
    scene->addItem(black);
    boardWidth = width();
    boardHeight = height();
    int *array;
    array = new int[numOfQueens];
    n_queen(array, numOfQueens, -1);
    delete[] array;
}


Board::~Board() {
    delete background;
    qDeleteAll(queens);
    delete scene;
}

void Board::addQueen() {
    int number = counter * numOfQueens;
    for (int i = number; i < number + 8; ++i) {
        scene->addItem(queens.at(i));
    }
}

void Board::removeQueen(int add) {
    int number = (counter + add) * numOfQueens;
    for (int i = number; i < number + 8; ++i) {
        scene->removeItem(queens.at(i));
    }
}

bool Board::possible(int *array, int limit) {
    for (int i = 0; i < limit; i++) {
        if ((array[i] == array[limit]) || abs(i - limit) == abs(array[i] - array[limit]))
            return false;
    }
    return true;
}

void Board::n_queen(int *array, int numberOfQueens, int limit) {
    if (possible(array, limit)) {
        if (limit == numberOfQueens - 1) {
            int row = 0;
            for (int i = 0; i < numberOfQueens; i++, row++)
                queens.append(new Queen(boardWidth, boardHeight, array[i], row));
        } else {
            for (int j = 0; j < numberOfQueens; j++) {
                array[limit + 1] = j;
                n_queen(array, numberOfQueens, limit + 1);
            }
        }
    }
}

void Board::keyPressEvent(QKeyEvent *event) {
    QGraphicsView::keyPressEvent(event);
        if (event->key() == Qt::Key::Key_Right && counter < 92) {
            if (counter != 0)
                removeQueen(-1);
            addQueen();
            counter++;
        }
}

