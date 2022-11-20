

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
    addDetails();
}


Board::~Board() {
    delete background;
    qDeleteAll(queens);
    delete solution;
    delete showCounter;
    delete guide;
    delete eightQueen;
    delete scene;
}

void Board::addDetails() {
    solution = new Label(100, "white");
    solution->setPlainText("Solution : ");
    solution->setRotation(-90);
    scene->addItem(solution);
    solution->setPos((width() - height()) / 8, height() / 1.1);

    showCounter = new Label(100, "white");
    showCounter->setPlainText(" "+QString::number(counter));
    scene->addItem(showCounter);
    showCounter->setPos((width() - height()) / 6, height() / 5);

    guide = new Label(35, "white");
    guide->setPlainText("Next :\nArrow Right\n\nPrevious :\nArrow Left\n\nReset : Shift\n\nExit : Escape");
    scene->addItem(guide);
    guide->setPos(5*(width() - height()) / 9 + height(), height() / 2.5);

    eightQueen = new Label(50, "white");
    eightQueen->setPlainText("8 Queen\n Puzzle");
    scene->addItem(eightQueen);
    eightQueen->setPos(5*(width() - height()) / 9 + height(), height() / 6);
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
        QString number= counter>=10?QString::number(counter):" "+QString::number(counter);
        showCounter->setPlainText(number);
    } else if (event->key() == Qt::Key::Key_Shift && counter != 0) {
        removeQueen(-1);
        counter = 0;
        showCounter->setPlainText(" "+QString::number(counter));
    }else if (event->key() == Qt::Key::Key_Escape)
        exit(0);
}



