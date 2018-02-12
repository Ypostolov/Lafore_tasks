
class Book
{
    char* booksName;
    int booksIndex;
    int abonentsIndex;

public:
    Book()
    {
        booksName = "";
        booksIndex = 0;
        abonentsIndex = 0;
    }
    Book(char* inBooksName, int inBooksIndex)
    {
        booksName = inBooksName;
        booksIndex = inBooksIndex;
        abonentsIndex = 0;
    }

        
    int getBooksIndex()
    {
        return booksIndex;
    }

    void takenByAbonent(int inAbonentIndex)
    {
        abonentsIndex = inAbonentIndex;
    }
    void returnedByAbonent()
    {
        abonentsIndex = 0;
    }


};

class Abonent
{
    char* name;
    int  index;
    int * BooksIndexes;
    int booksCapasity;

public:

    Abonent(char* inAbonentsName, int inBooksCapasity, int inIndex)
    {
        name = inAbonentsName;
        index = inIndex;
        booksCapasity = inBooksCapasity;
        BooksIndexes = new int[booksCapasity];
        for (int i = 0; i < booksCapasity; i++)
        {
            BooksIndexes[i] = 0;
        }
    }

    ~Abonent()
    {
        delete BooksIndexes;
    }

    int getAbonIndex()
    {
        return index;
    }
    void  takeTheBook(int inBooksIndex)
    {
        for (int i = 0; i < booksCapasity; i++)
        {
            if (BooksIndexes[i] == 0)
            {
                BooksIndexes[i] = inBooksIndex;
            }
        }
    }
    void reternTheBook(int inBooksIndex)
    {
        for (int i = 0; i < booksCapasity; i++)
        {
            if (BooksIndexes[i] == inBooksIndex)
            {
                BooksIndexes[i];
            }
        }
    }
};



void main()
{
    Book fond[4];
    fond[0] = Book("A", 9);
    fond[1] = Book("B", 8);
    fond[2] = Book("C", 5);
    fond[3] = Book("A", 100);
    
    Abonent petia("Petia", 2, 9);
    Abonent vasia("Vasia", 2, 7);

    petia.takeTheBook(fond[0].getBooksIndex());
    fond[0].takenByAbonent(petia.getAbonIndex());

    petia.takeTheBook(fond[2].getBooksIndex());
    fond[2].takenByAbonent(petia.getAbonIndex());

    vasia.takeTheBook(fond[3].getBooksIndex());
    fond[3].takenByAbonent(vasia.getAbonIndex());

    petia.reternTheBook(fond[2].getBooksIndex());
    fond[2].returnedByAbonent();

}