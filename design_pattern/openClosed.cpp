#include<iostrea>


//Open closed principle
struct Database {
    static enum Type {ORACLE,MYSQL};
    Type type;
};


struct Oracle {
    Database db; 
};


struct MySql {
    Database db;
};

void open (Database &db) {
    if (db.type == Database::ORACLE) {
        openOracle();
    } else if(db.type == Database::MYSQL) {
        openSQL();
    }
}

class Database {
    public :
        virtual void openDatabase () = 0;
}

class Mysql : public Database {
    public :
        virtual void openDatabase () = 0;
}


class Oracle : public Database {
    public :
        virtual void openDatabase () = 0;
}

void open (Database &db) {
    db.openDatabase();
}




