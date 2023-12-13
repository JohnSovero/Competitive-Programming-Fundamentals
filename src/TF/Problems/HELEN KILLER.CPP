#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define F first
#define S second

using namespace std;

const int N = 3e5 + 10, tamano = 1e6 + 5;
int n, m, lst[N], fen[tamano], ans[N], L[tamano];
vector<int> R[tamano], p[tamano];

void ADD(int ind, int val)
{
	for (; ind < tamano; ind += (ind & (-ind)))
	{
		fen[ind] += val;
	}
}

int calc(int ind)
{
	int res = 0;
	for (; ind > 0; ind -= (ind & (-ind)))
	{
		res += fen[ind];
	}
	return res;
}
void mostrar_arbol()
{
	for (int i = 0; i < 30; i++)
	{
		cout << fen[i] << " ";
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, l, r; i <= n; i++)
	{
		cin >> l >> r;
		L[l]++;
		R[r].push_back(l);
	}
	for (int i = 1, cnt; i <= m; i++)
	{
		cin >> cnt;
		for (int j = 1, a; j <= cnt; j++)
		{
			cin >> a;
			p[a].push_back(i);
		}
	}
	for (int i = 1; i < tamano; i++)
	{
		for (auto x : p[i])
		{
			cout << "I: " << i << endl;
			cout << "X: " << x << " " << endl;
		}
	}

	cout << endl;
	mostrar_arbol();
	for (int i = 1; i < tamano; i++)
	{

		ADD(i, L[i]);
		if (i < 10)
		{
			mostrar_arbol();
		}
		for (auto x : p[i])
		{

			cout << "I: " << i << endl;
			cout << "L[" << i << "]: " << L[i] << endl;
			cout << "X: " << x << endl;
			cout << "lst[x]: " << lst[x] << endl;
			cout << "ANS[" << x << "] = " << ans[x] + calc(i) - calc(lst[x]) << " = CALC(" << i << "): " << calc(i) << " - CALC(" << lst[x] << "): " << calc(lst[x]) << endl;
			ans[x] += calc(i) - calc(lst[x]);
			lst[x] = i;
		}
		for (auto x : R[i])
		{
			ADD(x, -1);
			if (i < 10)
			{
				cout << "QUITANDO: ";
				mostrar_arbol();
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << endl;
	}
}