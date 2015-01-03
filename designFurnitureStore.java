

//Wooden chair
//Wooden table
//steel chair 
//steel table


public Furniture {
    bool canFold;
    int numberOfLegs; 
}

public Chair extends Furniture { 
   
}


public Table extends Furniture {
    int numberOfLegs; 
}

public WoodenTable extends Table {

}

public WoodenChair extends Chair {

}


public interface Testable {
    bool testWater(Furniture f);

    bool testFire (Furniture f);

}

class FurntureStore implements Testable {
    private WoodenChair wChair;


    //can we test simulatneously or one after another
    bool testWater (Furniture f) {

    }

    bool testFire(Funiture f) {

    }

    
}
