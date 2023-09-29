#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string.h>

#define INF INT_MAX/2

using namespace std;


int memo[10001][10001];

int n;

int mochila(int i, int c,vector<vector<int>>& l){

    
    if(c < 0) return -INF;                  //se chegar em capacidade negativa na mochila
    if(i == n) return 0;                    //se chegar no ultimo item
    if(memo[i][c]!=-1) return memo[i][c];   //tem no memo

    //não pegar o item
    int r1 = mochila(i+1, c, l);
    
    //pegar o item
    int r2 = l[i][2] + mochila(i+1, c-l[i][1], l);

    return memo[i][c] = max(r1,r2);


}

int porValor(int c, vector<vector<int>>& l){

    sort(l.begin(),l.end());
    /*
    for(int i = 0; i < n; i++){
        cout << "id: " << l[i][0] << endl;
        cout << "Peso: " << l[i][1] << endl;
        cout << "Valor: " << l[i][2] << endl;
        cout << "-------------" << endl;
    }
    */

    int lucro = 0;
    cout << "++++++++++++DEBUG++++++++++++" << endl;
    
    for(int i = 1; i < n; i++){
        cout << "id: " << l[i][0] << endl;
        cout << "Peso: " << l[i][1] << endl;
        cout << "Valor: " << l[i][2] << endl;

        if(l[i][1] <= c){
            lucro += l[i][2];
            c -= l[i][1];

            cout << "Lucro: " << lucro << endl;
        }
        cout << "-------------" << endl;

    }
    
    return lucro;
}

int main(){

    memset(memo, -1, sizeof memo);

    int N, C; //Numero de itens, Capacidade Mochila
    cin >> N >> C;
    
    //Lista com todos os itens: [ID, Peso, Valor]
    vector<vector<int>> item_list(N, vector<int>(3));
    

    n = N;

    //Lendo todos os itens
    for(int i = 0; i < N; i++) cin >> item_list[i][0] >> item_list[i][1] >> item_list[i][2];
    
    int max_profit = mochila(0, C, item_list);

    int porValor_profit = porValor(C, item_list);

    cout <<"======================================="<< endl;

    cout << "Programacao Dinamica" << endl;
    cout << "O maior lucro possivel foi de: " << max_profit << endl;
    cout << "--------------------------------------" << endl;


    cout << "Guloso, porValor" << endl;
    cout << "O lucro obtido foi de: " << porValor_profit << endl;
    cout << "--------------------------------------" << endl;



    return 0;
}