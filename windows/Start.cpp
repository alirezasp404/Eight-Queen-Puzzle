
#include "Start.h"

Start::Start() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    setScene(scene);
    background = new StartBackground();
    scene->addItem(background);
    button = new Button(300, 150);
    button->setPlainText("         START 8 QUEEN");
    scene->addItem(button);
    button->setPos(width() / 2.5, height() / 1.5);
    connect(button, &Button::press, this, &Start::start);

}

Start::~Start() {
    delete button;
    delete background;
    delete scene;

}

void Start::start() {
    close();
}