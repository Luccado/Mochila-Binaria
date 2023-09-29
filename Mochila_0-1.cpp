/*
Trabalho da disciplina de Projeto e analise de algoritmos 2023/1

Alunos:
Bruno Belo Comachio,
Luccas Souza Di Oliveira,
Matheus Mello De Azevedo.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <chrono>

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

bool customComparador_Valor(const vector<int>& a, const vector<int>& b){
    return a[2] < b[2];
}

bool customComparador_Peso(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];
}

int porValor(int c, vector<vector<int>>& l){

    sort(l.begin(),l.end(), customComparador_Valor);

    int lucro = 0;
    
    for(int i = n-1; i >= 0; i--){
        if(l[i][1] <= c){
            lucro += l[i][2];
            c -= l[i][1];
        }
    }
    
    return lucro;
}

int porPeso(int c, vector<vector<int>>& l){

    sort(l.begin(),l.end(), customComparador_Peso);

    int lucro = 0;

    for(int i = 0; i < n; i++){
        if(l[i][1] <=c)
        {
            lucro += l[i][2];
            c -= l[i][1];
        }
    }

    return lucro;
}

float desempenho(int re, int ro){
    float valor = (100.0f * ((re - static_cast<float>(ro))/re));
    return valor;
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


    //Começando a medir o tempo para a solução
    //Usando Programação dinamica
    auto t1_comeco = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    int max_profit = mochila(0, C, item_list);

    auto t1_fim = chrono::high_resolution_clock::now();
    
    //Calculando o valor, do fim da execução menos o começo
    //assim obtemos o tempo necessario para a execução
    auto t1_ms = chrono::duration_cast<chrono::milliseconds>(t1_fim - t1_comeco);
    double t1_seg = chrono::duration_cast<chrono::nanoseconds>(t1_fim - t1_comeco).count();
    t1_seg *= 1e-9;


    //Começando a medir o tempo para a solução
    //Usando uma Heuristica Gulosa colocando sempre o item de maior valor
    auto t2_comeco = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    int porValor_profit = porValor(C, item_list);

    auto t2_fim = chrono::high_resolution_clock::now();
    
    auto t2_ms = chrono::duration_cast<chrono::milliseconds>(t2_fim - t2_comeco);
    double t2_seg = chrono::duration_cast<chrono::nanoseconds>(t2_fim - t2_comeco).count();
    t2_seg *= 1e-9;


    //Começando a medir o tempo para a solução
    //Usando uma outra Heuristica Gulosa colocando sempre o item de menor peso 
    auto t3_comeco = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    int porPeso_profit = porPeso(C, item_list);

    auto t3_fim = chrono::high_resolution_clock::now();
    
    auto t3_ms = chrono::duration_cast<chrono::milliseconds>(t3_fim - t3_comeco);
    double t3_seg = chrono::duration_cast<chrono::nanoseconds>(t3_fim - t3_comeco).count();
    t3_seg *= 1e-9;



    cout <<"======================================="<< endl;

    cout << "Programacao Dinamica" << endl;
    cout << "Tempo demorado em milisegs: " << t1_ms.count() << " ms\n";
    cout << "Tempo demorado em segundos: " << t1_seg << " seg\n";
    cout << "O maior lucro possivel foi de: " << max_profit << endl;
    cout << "--------------------------------------" << endl;

    cout << "Guloso, porValor" << endl;
    cout << "Tempo demorado em milisegs: " << t2_ms.count() << " ms\n";
    cout << "Tempo demorado em segundos: " << t2_seg << " seg\n";
    cout << "O lucro obtido foi de: " << porValor_profit << endl;

    float valor1 = desempenho(max_profit,porValor_profit);
    cout << "A resposta obtida esta: " << valor1 << '%' << " distante da solucao otima." << endl;

    cout << "--------------------------------------" << endl;

    cout << "Guloso, porPeso" << endl;
    cout << "Tempo demorado em milisegs: " << t3_ms.count() << " ms\n";
    cout << "Tempo demorado em segundos: " << t3_seg << " seg\n";
    cout << "O lucro obtido foi de: " << porPeso_profit << endl;

    float valor2 = desempenho(max_profit,porPeso_profit);
    cout << "A resposta obtida esta: " << valor2 << '%' << " distante da solucao otima." << endl;

    cout << "--------------------------------------" << endl;

    return 0;
}