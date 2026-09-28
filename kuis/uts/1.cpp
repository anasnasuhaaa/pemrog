#include <bits/stdc++.h>
using namespace std;
class BangunDatar
{
protected:
  string id;

public:
  BangunDatar(string i) : id(i) {}
  virtual double hitungLuas() const = 0;
  virtual ~BangunDatar() = default;
};

class Persegi : public BangunDatar
{
private:
  double sisi;

public:
  Persegi(string id, double s) : BangunDatar(id), sisi(s) {}
  double hitungLuas() const override
  {
    return sisi * sisi;
  }
};

class PersegiPanjang : public BangunDatar
{
private:
  double panjang;
  double lebar;

public:
  PersegiPanjang(string i, double p, double l) : BangunDatar(i), panjang(p), lebar(l) {}
  double hitungLuas() const override
  {
    return panjang * lebar;
  }
};

int main()
{
  string input;

  while (getline(cin, input))
  {

    if (!input.empty() && input.back() == '\r')
      input.pop_back();
    if (input.empty())
      continue;

    vector<string> tokens;
    string tmp;

    stringstream ss(input);
    while (getline(ss, tmp, ','))
    {
      tokens.push_back(tmp);
    }

    BangunDatar *b = nullptr;
    if (tokens[0] == "1")
    {
      b = new Persegi(tokens[1], stod(tokens[2]));
    }
    else if (tokens[0] == "2")
    {
      b = new PersegiPanjang(tokens[1], stod(tokens[2]), stod(tokens[3]));
    }

    if (b != nullptr)
    {
      cout << tokens[1] << " : " << b->hitungLuas() << endl;
    }
    delete b;
  }
  return 0;
}