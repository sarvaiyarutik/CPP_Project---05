#include <iostream>
using namespace std;

// Abstract Base Class
class LibraryItem
{

private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return dueDate;
    }

    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem()
    {
    }
};

class Book : public LibraryItem
{

private:
    int p;

public:
    Book(string t, string a, string d, int pages)
        : LibraryItem(t, a, d)
    {

        if (pages <= 0)
        {
            throw "Invalid Pages!";
        }

        p = pages;
    }

    void checkOut() override
    {
        cout << "Book Checked Out Successfully" << endl;
    }

    void returnItem() override
    {
        cout << "Book Returned Successfully" << endl;
    }

    void displayDetails() override
    {

        cout << "\n----- Book Details -----" << endl;
        cout << "Title     : " << getTitle() << endl;
        cout << "Author    : " << getAuthor() << endl;
        cout << "Due Date  : " << getDueDate() << endl;
        cout << "Pages     : " << p << endl;
    }
};

class DVD : public LibraryItem
{

private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {

        if (dur <= 0)
        {
            throw "Invalid Duration!";
        }

        duration = dur;
    }

    void checkOut() override
    {
        cout << "DVD Checked Out Successfully" << endl;
    }

    void returnItem() override
    {
        cout << "DVD Returned Successfully" << endl;
    }

    void displayDetails() override
    {

        cout << "\n----- DVD Details -----" << endl;
        cout << "Title      : " << getTitle() << endl;
        cout << "Author     : " << getAuthor() << endl;
        cout << "Due Date   : " << getDueDate() << endl;
        cout << "Duration   : " << duration << " Minutes" << endl;
    }
};

class Magazine : public LibraryItem
{

private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d)
    {

        if (issue <= 0)
        {
            throw "Invalid Issue Number!";
        }

        issueNumber = issue;
    }

    void checkOut() override
    {
        cout << "Magazine Checked Out Successfully" << endl;
    }

    void returnItem() override
    {
        cout << "Magazine Returned Successfully" << endl;
    }

    void displayDetails() override
    {

        cout << "\n----- Magazine Details -----" << endl;
        cout << "Title         : " << getTitle() << endl;
        cout << "Author        : " << getAuthor() << endl;
        cout << "Due Date      : " << getDueDate() << endl;
        cout << "Issue Number  : " << issueNumber << endl;
    }
};

int main()
{

    LibraryItem *libraryItems[100];

    int count = 0;
    int choice;

    do
    {

        cout << "\n===== Library Management System =====" << endl;

        cout << "1. Add Book" << endl;
        cout << "2. Add DVD" << endl;
        cout << "3. Add Magazine" << endl;
        cout << "4. Display All Items" << endl;
        cout << "5. Check Out Item" << endl;
        cout << "6. Return Item" << endl;
        cout << "0. Exit" << endl;

        cout << "\nEnter Your Choice : ";
        cin >> choice;

        try
        {

            if (choice == 1)
            {

                string title, author, dueDate;
                int pages;

                cin.ignore();

                cout << "Enter Book Title : ";
                getline(cin, title);

                cout << "Enter Author Name : ";
                getline(cin, author);

                cout << "Enter Due Date : ";
                getline(cin, dueDate);

                cout << "Enter Pages : ";
                cin >> pages;

                libraryItems[count] =
                    new Book(title, author, dueDate, pages);

                count++;

                cout << "Book Added Successfully" << endl;
            }

            else if (choice == 2)
            {

                string title, author, dueDate;
                int duration;

                cin.ignore();

                cout << "Enter DVD Title : ";
                getline(cin, title);

                cout << "Enter Author Name : ";
                getline(cin, author);

                cout << "Enter Due Date : ";
                getline(cin, dueDate);

                cout << "Enter Duration : ";
                cin >> duration;

                libraryItems[count] =
                    new DVD(title, author, dueDate, duration);

                count++;

                cout << "DVD Added Successfully" << endl;
            }

            else if (choice == 3)
            {

                string title, author, dueDate;
                int issue;

                cin.ignore();

                cout << "Enter Magazine Title : ";
                getline(cin, title);

                cout << "Enter Author Name : ";
                getline(cin, author);

                cout << "Enter Due Date : ";
                getline(cin, dueDate);

                cout << "Enter Issue Number : ";
                cin >> issue;

                libraryItems[count] =
                    new Magazine(title, author, dueDate, issue);

                count++;

                cout << "Magazine Added Successfully" << endl;
            }

            else if (choice == 4)
            {

                if (count == 0)
                {
                    cout << "No Items Found!" << endl;
                }
                else
                {

                    for (int i = 0; i < count; i++)
                    {
                        libraryItems[i]->displayDetails();
                    }
                }
            }

            else if (choice == 5)
            {

                int index;

                cout << "Enter Item Number : ";
                cin >> index;

                if (index < 0 || index >= count)
                {
                    throw "Invalid Item Number!";
                }

                libraryItems[index]->checkOut();
            }

            else if (choice == 6)
            {

                int index;

                cout << "Enter Item Number : ";
                cin >> index;

                if (index < 0 || index >= count)
                {
                    throw "Invalid Item Number!";
                }

                libraryItems[index]->returnItem();
            }

            else if (choice == 0)
            {
                cout << "Program Ended..." << endl;
            }

            else
            {
                cout << "Invalid Choice!" << endl;
            }
        }

        catch (const char *msg)
        {
            cout << "Exception : " << msg << endl;
        }

        catch (...)
        {
            cout << "General Exception Handled!" << endl;
        }

    } while (choice != 0);

    for (int i = 0; i < count; i++)
    {
        delete libraryItems[i];
    }

    return 0;
}