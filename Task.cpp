// Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
struct rezultat { //struktura za memorisanje rezultata
    int rez, br_operacija;
};
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;// long long zbog uslova zadatka
int main()
{
    int T, n = 0;
    vector<rezultat> rez;
    rezultat final;
    cin >> T; //unos broja testnih slučajeva
    while (n<T) { //unos testnih slučajeva
        ll N, X; //N->broj elemenata u nizu;X->operator za XOR;
        unordered_map<ll, ll> niz,br_oper;
        cin >> N >> X;

        vector<ll>v(N);
        for (ll i = 0; i < N; i++) {
            cin >> v[i];
            niz[v[i]]++; //broj pojavljivanja
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
            for (ll i = 0; i < N; i++) { //trazimo kombinaciju najveci broj ponavljanja + najmanji broj operacija
                if (niz[v[i]] + br_oper[v[i]] > ans) {
                    ans = niz[v[i]] + br_oper[v[i]];
                    promjene = br_oper[v[i]];
                }
                else if (niz[v[i]] + br_oper[v[i]] == ans) {
                    promjene = min(promjene, br_oper[v[i]]);
                }
            }
        }
        final.rez = ans; final.br_operacija = promjene; 
        rez.push_back(final);//upis rezultata u vektor za upis
        n++;
    }
    for(int i=0;i<rez.size();i++) //ispis rezultata
    {
        cout << rez[i].rez << " " << rez[i].br_operacija << endl;
    }
    system("Pause");
    return 0;
}