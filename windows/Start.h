
#ifndef INC_8_QUEEN_START_H
#define INC_8_QUEEN_START_H
#include "QGraphicsView"
#include "../views/StartBackground.h"
#include "../views/Button.h"

    class Start : public QGraphicsView {

    private:
        QGraphicsScene *scene;
        StartBackground *background;
        Button *button;

    public:
        Start();
        ~Start();
    public slots:
                void start();
    };


#endif //INC_8_QUEEN_START_H
