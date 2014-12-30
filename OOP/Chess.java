class Chess {

    Board b;
    Map<Color,List <Piece> > pList;
    Player ps;
     
    void initBoard () {

    }

    void play () {

    }

    
}

class Board {
    int row;
    int col;
}

class enum Color {
   BLACK(0),WHITE(1)
}

class enum PieceType {
    PAWN(1),KNIGHT(2),ROOK(3),BISHOP(4),QUEEN(5),KING(6)
}

class enum Direction {
    LEFT(0),RIGHT(1)
}

class Piece {
   int color;
   Direction direction;
   PieceType pieceType;
   int limit;
   void move (int from,int to);
}

class Pawn extends Piece {
    
    Pawn (int rank) {
        this.rank = rank;
    }
    void move (int from,int to) {

    }

}
