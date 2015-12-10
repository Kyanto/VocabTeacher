#include "category.hpp"

Category::Category(string name){
    m_name = name;
    m_i = 0 ;
    ifstream fp(("english/"+m_name+".txt").c_str(), ios::in);
    string buffer;
    cout << "Loading... ";
    while(fp>>buffer){
            m_words[0][m_i] = buffer;
            fp>>buffer;
            m_words[1][m_i] = buffer;
            m_i++;
    }
    cout << "done." << endl;
}

void Category::save(){
    cout << "Saving... ";
    ofstream fp(("english/"+m_name+".txt").c_str(), ios::trunc);
    for(int i=0; i<m_i; i++){
        fp << m_words[0][i] << endl;
        fp << m_words[1][i] << endl;
    }
    cout << "done." << endl;
}

void Category::setWord(string fo, string fr){
    m_words[0][m_i] = fo;
    m_words[1][m_i++] = fr;
}

void Category::printWords(){
    for(int i=0; i<m_i; i++) {
        cout << i+1 << " - " << m_words[0][i] << endl;
        for(int j=0; j<i/10; j++) cout << " ";
        cout << "  - " << m_words[1][i] << endl;
    }
    cout << "Press Enter key..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

string Category::getName(){
    return m_name;
}

int Category::getNb(){
    return m_i;
}

void Category::mix(){
    srand(time(NULL));
    string tmp, tmp2;
    int x ;
    for(int i=0; i<m_i; i++){
        tmp = m_words[0][i];
        tmp2 = m_words[1][i];
        x = rand()%m_i;
        m_words[0][i] = m_words[0][x];
        m_words[1][i] = m_words[1][x];
        m_words[0][x] = tmp;
        m_words[1][x] = tmp2;
    }
}

void Category::askWords(){

    mix() ;

    int score = 0, errors[m_i] ;
    for(int i=0; i<m_i; i++) errors[i] = 0 ;
    string ans ;
    for(int i=0; i<m_i; i++){
        cout << "- " << m_words[0][i] << " ?" << endl;
        cin >> ans ;
        if(ans==m_words[1][i]) score++;
        else    errors[i] = 1;
    }

    cout << endl << "Score : " << score << "/" << m_i << endl;
    if(score==m_i) cout << "Wow ! Perfect ! Can you do the same with another category ?" << endl << endl;
    else{
        if (score>=(m_i-score)) cout << "Not bad, not bad at all ! Retry to improve yourself !" << endl << endl;
        else cout << "I'm sure you can do better !" << endl << endl;
        cout << "=== Correction time ===" << endl;
        for(int i=0; i<m_i; i++)
            if(errors[i]){
                cout << m_words[0][i] << " -> " << m_words[1][i] << endl;
            }
        cout << endl;
    }
}

void Category::addWords(){
        string fo, fr;
        cout << "(0 to leave)" << endl;
        cout << "Foreign word : ";
        cin >> fo;
        cout << "French word : ";
        cin >> fr;
        while(fo!="0" && fr!="0"){
            transform(fo.begin(), fo.end(), fo.begin(), ::tolower);
            transform(fr.begin(), fr.end(), fr.begin(), ::tolower);
            setWord(fo, fr);
            cout << "Foreign word : ";
            cin >> fo;
            if(fo!="0"){
                cout << "French word : ";
                cin >> fr;
            }
        }
        save();
}

void Category::deleteWords(){
    int indice;
    cout << "Enter the number of the couple of words you want to delete." << endl << "(If you do not know it, check \"See words\")" << endl;
    cout << "(0 to leave)" << endl << "num : ";
    while(!(cin >> indice)){
        cin.clear() ;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "num : ";
    }

    while(indice){
        if(indice>=1 && indice<=m_i){
            cout << m_words[0][indice-1] << "/" << m_words[1][indice-1] << " deleted." << endl;
            m_i-=1;
        }
        for(int i=indice; i<m_i+1; i++){
            m_words[0][i-1] = m_words[0][i];
            m_words[1][i-1] = m_words[1][i];
        }
        cout << "num : ";
        while(!(cin >> indice)){
            cin.clear() ;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "num : ";
        }
    }
    save();
}
