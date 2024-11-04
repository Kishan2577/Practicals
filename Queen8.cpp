#include<iostream>
#include<vector>
using namespace std;

void addResults(vector<vector<int>> &board,vector<vector<int>> &ans,int n,int col)
{
    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool check(vector<vector<int>> &board,int row,int col,int n)
{
    int r = row;
    int c = col;
    while(c >= 0)
    {
        if(board[r][c] == 1)
        {
            return false;
        }
        c--;
    }


    r = row;
    c = col;
    while(r >= 0 && c >= 0)
    {
        if(board[r][c] == 1)
        {
            return false;
        }
        c--;
        r--;
    }

    r = row;
    c = col;
    while(c >= 0 && r < n)
    {
        if(board[r][c] == 1)
        {
            return false;
        }
        c--;
        r++;
    }

    return true;
}


void Queen(vector<vector<int>> &board,vector<vector<int>> &ans,int n,int col)
{
    if(col == n)
    {
        addResults(board,ans,n,col);
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(check(board,i,col,n))
        {
            board[i][col] = 1;

            Queen(board,ans,n,col+1);

            board[i][col] = 0;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    Queen(board,ans,n,0);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            if(j % n == 0)
            {
                cout<<endl;
            }
            cout<<" "<<ans[i][j];
            
        }
        cout<<" "<<i+1<<endl;
    }
    return 0;
}