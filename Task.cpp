// Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Task description:
// You are given an array A consisting of N integers and an integer X. 
// Your goal is to have as many equal integers as possible in the array.To achieve this goal, you can do the following operation :
// Choose an index i(1≤i≤N) and set Ai = Ai⊕X, where ⊕ denotes the bitwise xor operation.
// Find the maximum number of equal integers you can have in the final array and the minimum
// number of operations to obtain these many equal integers.
// CONSTRAINTS:
// 1≤T≤10 ^ 4
// 1≤N≤10 ^ 5
// 0≤X≤10 ^ 9
// 0≤Ai≤10 ^ 9
// The sum of N over all test cases does not exceed 5⋅10 ^ 5.

struct rezultat {
    int rez, br_operacija;
};
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
int main()
{
    int T, n = 0;
    vector<rezultat> rez;
    rezultat final;
    cin >> T; //unos broja testnih slučajeva
    while (n<T) { //unos testnih slučajeva
        ll N, X, a;
        unordered_map<ll, ll> niz,br_oper;
        cin >> N >> X;

        vector<ll>v(N);
        for (ll i = 0; i < N; i++) {
            cin >> v[i];
            niz[v[i]]++; //broj pjavljivanja
            br_oper[v[i] ^ X]++; //broj operacija da se dobije vrijednost
        } 
        ll ans = 0,promjene = 1e18;
        if (N == 1) { //ako je u nizu samo jedan elemnent
            final.rez = 1; final.br_operacija = 0;
            rez.push_back(final); continue;
        }
        else if (X == 0) { //ako je X=0 uzmemo najvecu frekvenciju pojavljivanja elementa kao rješenje
            for (auto it = niz.begin(); it != niz.end(); it++) {
                ans = max(ans, it->second);
            }
            promjene = 0;
        }
        else {
            for (ll i = 0; i < N; i++) {
                if (niz[v[i]] + br_oper[v[i]] > ans) {
                    ans = niz[v[i]] + br_oper[v[i]];
                    promjene = br_oper[v[i]];
                }
                else if (niz[v[i]] + br_oper[v[i]] == ans) {
                    promjene = min(promjene, br_oper[v[i]]);
                }
            }
        }
        final.rez = ans; final.br_operacija = promjene; //upis rezultata u vektor za upis
        rez.push_back(final);
        n++;
    }
    //ispis rezultata
    for(int i=0;i<rez.size();i++)
    {
        cout << rez[i].rez << " " << rez[i].br_operacija << endl;
    }
    return 0;
}