#include"Stack.h"

int main()
{
    Stack<char> s1(100);
    s1.postfix("((12 + 13) * (20 - 30)) / (811 + 99)");
    cout << endl;
    s1.postfix("(a-b/c)*(a/k-l)");
    cout << endl;
  
   

    return 0;
}