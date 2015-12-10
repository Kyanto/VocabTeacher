#include "main.hpp"

int main()
{
    string buffer;
    int menu_choice, cat_choice, edit_choice, i=0, old_choice=1;
    string cats[cat_nb];
    ifstream fichier("english/categories.txt", ios::in);
    while(fichier >> buffer)    cats[i++] = buffer;
    cout << "Vocabulary Teacher" << endl << "Welcome !" << endl << endl;
    Category cat(cats[old_choice-1]) ;
    bool again = true, menu = true;

    do{
        again = true;
        cout << "=== Main menu ===" << endl << "1 - Play" << endl << "2 - Display" << endl << "3 - Edit" << endl << endl << "0 - Leave" << endl << endl << "Your choice : ";
        while(!(cin >> menu_choice)){
                    cin.clear() ;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Your choice : ";
        }
        if(menu_choice==1 || menu_choice==2 || menu_choice==3){
            do{
                cout << endl << "=== Categories ===" << endl ;
                for(i=0; i<cat_nb; i++){
                    cout << i+1 << " - " << cats[i] << endl;
                }
                cout << endl << "0 - Back" << endl;
                cout << endl << "Choose one : ";
                while(!(cin >> cat_choice)){
                    cin.clear() ;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Choose one : ";
                }
                cout << endl;
                if(cat_choice>=1 && cat_choice<=cat_nb){
                    if(cat_choice!=old_choice){
                        cat = Category(cats[cat_choice-1]);
                        old_choice = cat_choice;
                    }
                    cout << "--- Category : " << cat.getName() << " ---" << endl;
                    switch(menu_choice){
                        case 1 :
                            cat.askWords();
                            break;
                        case 2 :
                            cat.printWords();
                            break;
                        case 3 :
                            do{
                                cout << endl << "=== Edit menu ===" << endl << "1 - See words" << endl << "2 - Add word" << endl << "3 - Delete word" << endl << endl << "0 - Back" << endl << endl << "Your choice : ";
                                while(!(cin >> edit_choice)){
                                    cin.clear() ;
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "Your choice : ";
                                }
                                switch(edit_choice){
                                    case 1 :
                                        cat.printWords();
                                        break;
                                    case 2 :
                                        cat.addWords();
                                        break;
                                    case 3 :
                                        cat.deleteWords();
                                        break;
                                    default:
                                        break;
                                }
                            }while(edit_choice);
                            break;
                    }
                }else if(!cat_choice){
                    again=false;
                }
            }while(again);
        }else if(!menu_choice) menu=false;
    }while(menu);

    cout << endl << "See you next time !" << endl;
    fichier.close();
    return 0;
}
