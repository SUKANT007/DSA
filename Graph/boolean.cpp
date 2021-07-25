#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001][2];
int solve(string s, int i, int j, int flag)
{
    //Base Condition
    if (i > j)return false;
    if (i == j)
    {
        if (flag == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    //Induction
    if (dp[i][j][flag] != -1)
        return dp[i][j][flag];
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int left_False, left_True, right_True, right_False;
        if (dp[i][k - 1][1] == -1)
        { left_True = solve(s, i, k - 1, 1);}
        else { left_True = dp[i][k - 1][1];}

        if (dp[k + 1][j][1] == -1)
        { right_True = solve(s, k + 1, j, 1);}
        else { right_True = dp[k + 1][j][1];}

        if (dp[i][k - 1][0] == -1)
        { left_False = solve(s, i, k - 1, 0);}
        else { left_False = dp[i][k - 1][0];}

        if (dp[k + 1][j][0] == -1)
        { right_False = solve(s, k + 1, j, 0);}
        else { right_False = dp[k + 1][j][0];}

        if (s[k] == '&')
        {
            if (flag == 1)
                ans = ans + left_True * right_True;
            else
                ans = ans + left_False * right_False + left_True * right_False + left_False * right_True;
        }
        else if (s[k] == '|')
        {
            if (flag == 1)
                ans += left_True * right_True + left_True * right_False + left_False * right_True;
            else
                ans = ans + left_False * right_False;
        }
        else if (s[k] == '^')
        {
            if (flag == 1)
                ans = ans + left_False * right_True + left_True * right_False;
            else
                ans = ans + left_True * right_True + left_False * right_False;
        }
        dp[i][j][flag] = ans % 1003;
    }
    return ans % 1003;
}

int Solution::cnttrue(string A) {
    int n = A.length();
    memset(dp, -1, sizeof(dp));
    return solve(A, 0, n - 1, 1);
}