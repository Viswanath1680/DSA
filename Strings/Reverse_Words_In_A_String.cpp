#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

string reverseWords(string s)
{
    int left = 0;
    int right = s.length() - 1;
    string temp = "";
    string ans = "";
    while (left <= right)
    {
        char ch = s[left];
        if (ch != ' ')
        {
            temp += ch;
        }
        else if (ch == ' ')
        {
            if (ans != "")
                ans = temp + " " + ans;
            else
                ans = temp;
            temp = "";
        }
        left++;
    }
    if (temp != "")
    {
        if (ans != "")
            ans = temp + " " + ans;
        else
            ans = temp;
    }

    string output_string = "";
    bool space_flag = false; // Flag to check if spaces have occurred

    for (size_t index = 0; index < ans.length(); ++index)
    {
        if (ans[index] != ' ')
        {
            if (space_flag)
            {
                if (ans[index] == '.' || ans[index] == '?' || ans[index] == ',')
                {
                    // Do nothing
                }
                else
                {
                    output_string += ' ';
                }
                space_flag = false;
            }
            output_string += ans[index];
        }
        else if (index > 0 && ans[index - 1] != ' ')
        {
            space_flag = true;
        }
    }

    return output_string;
}

int32_t main()
{
    return 0;
}