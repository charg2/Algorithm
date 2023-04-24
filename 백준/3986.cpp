#include <iostream>
#include <stack>

bool CheckGoodWording( const std::string& wording )
{
    if ( ( wording.size() % 2 ) != 0 )
        return false;

    std::stack< char > s;
    for ( char c : wording )
    {
        if ( s.empty() )
        {
            s.push( c );
            continue;
        }

        if ( s.top() == c )
            s.pop();
        else
            s.push( c );
    }
    
    return s.empty();
}

int main()
{
    int lineNum{};
    int cnt{};
    std::cin >> lineNum;

    std::string wording;
    for ( int n{}; n < lineNum; n += 1 )
    {
        std::cin >> wording;
        if ( CheckGoodWording( wording ) )
            cnt += 1;
    }

    std::cout << cnt;
}
