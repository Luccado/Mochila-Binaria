#include <iostream>
#include <climits>
#include <string.h>

#define INF INT_MAX/2

using namespace std;


int memo[10001][10001];

int n;

int mochila(int i, int c,int&l){

    
    if(c < 0) return -INF;                  //se chegar em capacidade negativa na mochila
    if(i == n) return 0;                    //se chegar no ultimo item
    if(memo[i][c]!=-1) return memo[i][c];   //tem no memo

    //não pegar o item
    int r1 = mochila(i+1, c, l);
    
    //pegar o item
    //int r2 = l[i][2] + mochila(i+1, c-l[i][1], l);


}

int main(){

    memset(memo, -1, sizeof memo);

    cout << "Probleminha da mochilinha binarie" << endl;

    int N, C; //Numero de itens, Capacidade Mochila
    cin >> N >> C;

    int item_list[N][2]; //Lista com todos os itens: [ID, Peso, Valor]

    n = N;
    //Lendo todos os itens
    for(int i = 0; i < N; i++) cin >> item_list[i][0] >> item_list[i][1] >> item_list[i][2];
    
    int max_profit = mochila(0, C,**item_list);

    cout << "O maior lucro possivel foi de: " << max_profit << endl;


    return 0;
}