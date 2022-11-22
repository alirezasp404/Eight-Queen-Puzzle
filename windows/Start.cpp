
#include "Start.h"
#include "Board.h"

Start::Start() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    setScene(scene);
    background = new StartBackground();
    scene->addItem(background);

    eightQueen = new Label(60, "white");
    eightQueen->setPlainText("Eight\t     Puzzle");
    scene->addItem(eightQueen);
    eightQueen->setPos(width() / 2.95, height() / 5);

    queen = new Queen(width(), height(), 3, 1);
    scene->addItem(queen);
    button = new Button(430, 150);
    button->setPlainText("\t\tSTART");
    scene->addItem(button);
    button->setPos(width() / 2.76, height() / 1.5);
    connect(button, &Button::press, this, &Start::start);

}

Start::~Start() {
    delete button;
    delete background;
    delete eightQueen;
    delete scene;
    delete queen;
}

void Start::start() {
    (new Board())->show();
    close();
}