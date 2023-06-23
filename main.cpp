/*
Name: Mariam Ashraf Amin          ID:20200520
Name: Reem Ayman Abd El-fattah    ID:20200186
*/

#include <iostream>
#include <windows.h>
using namespace std;

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

class ColoredBox
        {
private:
            char **box;
            char Character;
            int length;
            int width;
            int Color;
            static int maxArea;

public:
            //parameterized constructor
            ColoredBox (int l , int w ,int col =15, char ch='#')
            {
                length =l;
                width =w;
                Color = col;
                Character =ch;

                box  = new char *[length];
                for (int row = 0; row < length; row++)
                {
                    box [row] = new char [width];
                    for (int column = 0; column < width; column++)
                    {
                        box [row][column]=Character;
                    }
                }

                if (maxArea<length*width)
                    maxArea=length*width;
            }

            //Character setter Function
            void setCharacter(char ch)
            {
                Character = ch;
            }
            //Character getter Function
            char getCharacter ()
            {
                return Character;
            }

            //Color setter Function
            void setColor(int col)
            {
                Color=col;
            }

            //Color getter Function
            int getColor()
            {
                return Color;
            }

            //display function
            void display ()
            {
                for (int row = 0; row < length; row++)
                {
                    for (int column = 0; column < width; column++)
                    {
                        SetColor(Color);
                        cout << box[row][column];
                    }
                    cout<<endl;
                }
                SetColor(15);
            }

            //displayTransposed function
            void displayTransposed ()
            {
                int counter=0;
                for (int row = 0; row < length; row++)
                {
                    for (int column = 0; column < width; column++)
                    {
                        SetColor(Color);
                        counter++;
                        cout<<box[row][column];
                        if (counter%length==0)
                            cout<<endl;
                    }
                }
                SetColor(15);
            }

            //displayWider function
            void displayWider ()
            {
                for (int row = 0; row < length; row++)
                {
                    for (int column = 0; column < width; column++)
                    {
                        SetColor(Color);
                        if (column<width-1)
                            cout << box[row][column]<<" ";
                        else
                            cout << box[row][column];
                    }
                    cout<<endl;
                }
                SetColor(15);
            }

            //displayChess function
            void displayChess (int C)
            {
                for (int row = 0; row < length; row++)
                {
                    for (int column = 0; column < width; column++)
                    {
                        if ((row+column)%2==0) {
                            SetColor(Color);
                        }
                        else {
                            SetColor(C);
                        }
                        cout << box[row][column];
                    }
                    cout<<endl;
                }
                SetColor(15);
            }

            //getArea Function
            int getArea ()
            {
                return length*width;
            }

            //getMaxArea Function
            static int getMaxArea ()
            {
                return maxArea;
            }

            //destructor
            ~ ColoredBox()
            {
                for (int row = 0; row < length; row++)
                {
                    delete[] box[row];
                    box[row] = 0;
                }
            }
        };

int ColoredBox::maxArea=0;

int main()
{
    int len,wid,col,col2;
    char boxChar;
    cout<<"Enter length and width of the box separated by a space: ";
    cin>>len>>wid;
    ColoredBox* cb1;
    cb1 = new ColoredBox(len,wid);
    cb1->display();
    cout<<"Set the box to another color: ";
    cin>>col;
    cb1->setColor(col);
    cout<<"Displaying Transposed: "<<endl;
    cb1->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb1->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb1->displayChess(col2);
    cout<<endl<<"Area="<<cb1->getArea();
    cout<<endl<<"Max Area="<<cb1->getMaxArea();
    delete cb1;

    cout<<"Enter length,width,color,character of the box separated by spaces: ";
    cin>>len>>wid>>col>>boxChar;
    ColoredBox* cb2;
    cb2 = new ColoredBox(len,wid,col,boxChar);
    cb2->display();
    cout<<"Displaying Transposed: "<<endl;
    cb2->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb2->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb2->displayChess(col2);
    cout<<"Displaying original again:"<<endl;
    cb2->display();
    cout<<endl<<"Area="<<cb2->getArea();
    cout<<endl<<"Max Area="<<cb2->getMaxArea();
    delete cb2;
    return 0;
}

