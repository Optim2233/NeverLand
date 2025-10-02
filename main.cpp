#include <iostream>
class Distance 
{
    private: int feet; int in;
    public: 
    Distance(int f, int i) : feet(f) , in(i){std::cout<<feet<<" "<<in;}
};
int main() {
    std::cout << "Hello from NeverLand!" << std::endl;
    Distance(4,2);
    return 0;
}
