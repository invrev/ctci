
class OnlineBookSys {
    Library l;

    //To serach user efficintly by firstname,lastname ?
    List<User> user;
    void addUser(User u);
    
}

class User {
    Name name;
    void subscribeLib ();
    void unsubscribeLib();
    Book claimBook (Book b);
    void returnBook (Book b);
    Book searchBook (string name);
    payFine(int sum);
    paySubscription (int sum);
}

class Library {
    Map <string,List<Book> bookMap;
    Map <string,List<CD> CD;
    void addBook (Book b);
    void removeBook (Book b);
    void upgradeBook(Book b);
}

class enum BookType  {
    BookType ()
}

class Name {
    string firstName;
    string lastName;
}

class Price {
  float subPrice;
}

class CD {
    CDType cd;
}

class Book  {
    BookType t;
    string ISBN;
    string bookName;
    Name author;
    Price price;
}
