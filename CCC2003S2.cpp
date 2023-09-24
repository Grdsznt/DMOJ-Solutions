#include <bits/stdc++.h>

using namespace std;
string check(string[] endings) {
    if (endings[0] == endings[1] and endings[1] == endings[2] and endings[2] == endings[3]){
        return "perfect" 
    }
    else if endings[0] == endings[1] and endings[2] == endings[3]{
        return "even"
    }
    else if endings[0] == endings[2] and endings[1] == endings[3]{
        return "cross"
    }
    else if endings[0] == endings[3] and endings[1] == endings[2]{
        return "shell"
    }
    else{
        return "free"
    }
}

int main() {

}

