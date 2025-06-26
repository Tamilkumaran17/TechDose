#include <bits/stdc++.h>
using namespace std;

class Book{
    private: 

        string title;
        bool isIssued;

    public:
        Book(string t) : title(t), isIssued(false){}

        string getTitle() const
        {
            return title;
        }

        bool getIssued() const
        {
            return isIssued;
        }

        void setIssued(bool status)
        {
            isIssued = status;
        }
};

class Library{
    private:
        list<Book> Books;

    public:
        void addBook(const Book& book)
        {
            Books.push_back(book);
        }

        void showArrivalBooks()
        {
            cout<<"Books in library : "<<endl;

            for(auto book : Books)
            {
                cout<<"- "<<book.getTitle();
                if(book.getIssued())
                cout<< " (Issued)";

                cout<<endl;

            }cout<<endl;
        }

        bool issuedBooks(string title)
        {
            for(auto& book: Books)
            {
                if(book.getTitle()==title)
                {
                    if(!book.getIssued())
                    {
                        book.setIssued(true);
                        return true; 
                    }

                    return false;
                }
            }

            return false;
        }

};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Library lib;

    cout << "Enter book titles (type 'exit' to stop):\n";

    while(true)
    {
        string s;
        getline(cin,s);
        if(s=="exit" || s.empty())
        break;

        lib.addBook(Book(s));
    }

    // lib.addBook(Book("The war of legends"));
    // lib.addBook(Book("Game of throns"));
    // lib.addBook(Book("Lord of the rings"));
    // lib.addBook(Book("Fifty shades of gray"));

    lib.showArrivalBooks();

    cout<<"Enter the book title to issue : ";
    string title;
    getline(cin,title);

    if(lib.issuedBooks(title))
    cout<<"Successfully issued the book "<<title<<endl;
    else 
    cout<<"Failed in process"<<endl;

    cout<<"After issued the books"<<endl;

    lib.showArrivalBooks();

}

