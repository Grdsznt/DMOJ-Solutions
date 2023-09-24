#include <bits/stdc++.h>
using namespace std;

namespace Validator {
  bool _hasLast = false;
  char _last;

  char _peekChar() {
    _last = _hasLast ? _last : getchar();
    _hasLast = true;
    return _last;
  }

  char _getChar() {
    char ret = _peekChar();
    _hasLast = false;
    return ret;
  }

  long long readInt(long long minValid = std::numeric_limits<long long>::min(), long long maxValid = std::numeric_limits<long long>::max()) {
    std::string token = "";
    while (isdigit(_peekChar()) || _peekChar() == '-') token.push_back(_getChar());
    long long ret = std::stoll(token);
    assert(minValid <= ret && ret <= maxValid);
    return ret;
  }

  long double readFloat(long double minValid = std::numeric_limits<long double>::lowest(), long double maxValid = std::numeric_limits<long double>::max()) {
    std::string token = "";
    while (isdigit(_peekChar()) || _peekChar() == '-' || _peekChar() == '.') token.push_back(_getChar());
    long double ret = std::stold(token);
    assert(minValid <= ret && ret <= maxValid);
    return ret;
  }

  std::string readString(const std::regex &rgx) {
    std::string ret = "";
    while (!isspace(_peekChar())) ret.push_back(_getChar());
    assert(std::regex_match(ret, rgx));
    return ret;
  }

  std::string readString() {
    std::string ret = "";
    while (!isspace(_peekChar())) ret.push_back(_getChar());
    return ret;
  }

  char readChar(const std::regex &rgx) {
    char ret = _getChar();
    assert(std::regex_match(std::string(1, ret), rgx));
    return ret;
  }

  char readChar() {
    return _getChar();
  }

  std::string readLine(const std::regex &rgx) {
    std::string ret = "";
    while (_peekChar() != '\n') ret.push_back(_getChar());
    assert(std::regex_match(ret, rgx));
    return ret;
  }

  std::string readLine() {
    std::string ret = "";
    while (_peekChar() != '\n') ret.push_back(_getChar());
    return ret;
  }

  void readSpace() {
    assert(_getChar() == ' ');
  }

  void readNewLine() {
    assert(_getChar() == '\n');
  }

  void readEOF() {
    assert(_getChar() == std::char_traits<char>::eof());
  }
}

using namespace Validator;

long long qp(long long x, long long exp, long long mod) {
    if (exp == 0) return 1;
    long long tmp = qp(x, exp/2, mod); tmp = tmp*tmp%mod;
    if (exp % 2 == 1) return tmp*x % mod;
}
int main() {
    int n = readInt(1, 100); readSpace(); int m = readInt(1, 100), cost = 0; readNewLine();
    vector<int> vec;
    for (int i = 0;i<n;i++) {
        vec.push_back(readInt(0, 50)); if (i != n-1 ) readSpace();
    }
    readNewLine();
    sort(vec.begin(), vec.end(), greater<int>());
    for (int i = 0;i<n;i++) {
        cost = (cost + qp(vec[i], i/m, 1000000007));
    }
    printf("%d\n", cost);
}