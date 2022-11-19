
#include "ChessBoard.h"
ChessBoard::ChessBoard(int width, int height) {
    QPixmap pixmap(":/images/chessboard");
    pixmap=pixmap.scaled(height,height);
    setPixmap(pixmap);
    setPos((width-height)/2,0);
}
