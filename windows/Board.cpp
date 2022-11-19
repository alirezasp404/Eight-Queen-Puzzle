

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
    black=new ChessBoard(width(), height());
    scene->addItem(black);
}


Board::~Board(){
    delete background;
    delete scene;
}
