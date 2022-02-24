#include<iostream>
#include<vector>
#include<string>

using namespace std;

class very_long_integer {
    // Старшие разряды на старших позициях
    vector<int> data;
    const int mod = 1e9;

public:
    very_long_integer(string str = "0")
    {
        while (str.size() > 9)
        {
            data.push_back(stoi(str.substr(str.size() - 9)));
            str.resize(str.size() - 9);
        }
        data.push_back(stoi(str));
    }

    very_long_integer& operator=(const very_long_integer& other)
    {
        data = other.data;
        return (*this);
    }

    very_long_integer operator+(const very_long_integer& other)
    {
        very_long_integer ans = other;
        int perenos = 0;
        for (int i = 0; i < max(data.size(), ans.data.size()) || perenos; i++)
        {
            if (ans.data.size() == i)
                ans.data.push_back(0);
            ans.data[i] = ans.data[i] + perenos
                    + (i < data.size() ? data[i] : 0);
            perenos = ans.data[i] / mod;
            ans.data[i] %= mod;
        }
        return ans;
    }

    friend ostream& operator<<(ostream& out, const very_long_integer &num);
    friend istream& operator>>(istream& in, very_long_integer &num);

};

ostream& operator<<(ostream& out, const very_long_integer &num)
{
    for (int i = num.data.size() - 1; i >= 0; i--)
        out << num.data[i];
    return out;
}

istream& operator>>(istream& in, very_long_integer &num)
{
    string s;
    in >> s;
    num = very_long_integer(s);
    return in;
}


int main()
{
    very_long_integer vli("55");
    very_long_integer vli2("45");
    cout << vli << " " << vli2 << " ";
    cout << vli + vli2;
}



