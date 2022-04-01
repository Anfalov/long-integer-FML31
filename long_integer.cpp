//#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
 
using namespace std;
 
class dlin
{
public:
 
    dlin()
    {
        number.clear();
        number.push_back(0);
    }
 
    dlin(unsigned long long x)
    {
        number.clear();
        while (x != 0)
        {
            number.push_back(x % 10);
            x /= 10;
        }
    }
 
    dlin(const string& s)
    {
        number.clear();
        number.insert(number.begin(), s.begin(), s.end());
        reverse(number.begin(), number.end());
        for (int& c : number)
            c -= '0';
    }
 
    friend ostream& operator<<(ostream& out, const dlin& number);
 
    friend istream& operator>>(istream& in, dlin& number);
 
    string to_string() const
    {
        string s;
        s.insert(s.begin(), number.begin(), number.end());
        reverse(s.begin(), s.end());
        for (char& c : s)
            c += '0';
        return s;
    }
 
    dlin operator+(const dlin& second) const
    {
        dlin result;
        result.number.resize(max(this->number.size(), second.number.size()) + 1, 0);
        int i;
        for (i = 0; i < max(this->number.size(), second.number.size()); i++)
        {
            result.number[i] += ((i < number.size() ? this->number[i] : 0)
                + (i < second.number.size() ? second.number[i] : 0));
            if (result.number[i] > 9)
            {
                result.number[i + 1] += 1;
                result.number[i] = result.number[i] % 10;
            }
        }
        if (result.number.back() == 0)
            result.number.pop_back();
        return result;
    }
 
    dlin& operator+=(const dlin& second)
    {
        *this = *this + second;
        return *this;
    }
 
    dlin operator-(dlin second) const
    {
        dlin result;
        result.number.resize(this->number.size(), 0);
        int i, q = 0;
        for (i = 0; i < this->number.size(); i++)
        {
            result.number[i] = (this->number[i]
                - (i < second.number.size() ? second.number[i] : 0)) - q;
            q = 0;
            if (result.number[i] < 0)
            {
                result.number[i] = (result.number[i] + 10) % 10;
                q = 1;
            }
        }
        while (result.number.back() == 0 && result.number.size() > 1)
            result.number.pop_back();
        return result;
    }
 
    dlin operator-=(dlin second)
    {
        *this = *this - second;
        return *this;
    }
 
    dlin operator*(dlin second) const
    {
        dlin result;
        result.number.resize((this->number.size() + second.number.size() + 1), 0);
        for (int i = 0; i < this->number.size(); i++)
        {
            for (int j = 0; j < second.number.size(); j++)
            {
                result.number[i + j] += this->number[i] * second.number[j];
                result.number[i + j + 1] += result.number[i + j] / 10;
                result.number[i + j] %= 10;
            }
        }
        while (result.number.back() == 0 && result.number.size() > 1)
            result.number.pop_back();
        return result;
    }
 
    dlin operator*=(dlin second)
    {
        *this = *this * second;
        return *this;
    }
 
    bool operator==(const dlin& second) const
    {
        return number == second.number;
    }
 
    bool operator<(const dlin& second) const
    {
        return false;
    }
 
    bool operator<=(const dlin& second) const
    {
        return false;
    }
 
    bool operator>(const dlin& second) const
    {
        return false;
    }
 
    bool operator>=(const dlin& second) const
    {
        return false;
    }
 
    bool operator!=(const dlin& second) const
    {
        return number != second.number;
    }
 
private:
    vector<int> number;
};
 
ostream& operator<<(ostream& out, const dlin& number)
{
    out << number.to_string();
    return out;
}
 
istream& operator>>(istream& in, dlin& number)
{
    string s;
    in >> s;
    number = dlin(s);
    return in;
}
 
dlin q("0");
int n;
vector<dlin> dp;
 
int main()
{
    dlin a(1);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        a *= 45;
    }
    cout << a;
}
