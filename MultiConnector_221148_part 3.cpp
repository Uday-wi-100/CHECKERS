#include <iostream>

using namespace std;

void print(int** board, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[m - 1 - i][j] << " ";
        }
        cout << endl;
    }
}

int evaluate(int** board, int m, int n, int p, int a)
{
    print(board, m, n);
    int status = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n-a;j++){
            int u=0;
            for(int k=0;k<a;k++){
                if(board[i][j+k]==p){
                    u++;
                }
            }
            if(u==a){
                status = 1;
                break;
            }
        }
        if(status == 1){
            break;
        }

    }
    for(int i=0;i<m-a;i++){
        for(int j=0;j<n;j++){
            int v=0;
            for(int k=0;k<a;k++){
                if(board[i+k][j]==p){
                    v++;
                }
            }
            if(v==a){
                status = 1;
                break;
            }
        }
        if(status == 1){
            break;
        }

    }
    for(int i=0;i<m-a;i++){
        for(int j=0;j<n-a;j++){
            int w=0;
            for(int k=0;k<a;k++){
                if(board[i+k][j+k]==p){
                    w++;
                }
            }
            if(w==a){
                status = 1;
                break;
            }
        }
        if(status == 1){
            break;
        }

    }
    for(int i=0;i<m-a;i++){
            int q=0;
            for(int k=0;k<a;k++){
                if(board[i+a-1-k][k]==p){
                    q++;
                }
            }
            if(q==a){
                status = 1;
                break;
            }
    }
     for(int i=0;i<m;i++){
            int u=0;
            for(int k=0;k<a;k++){
                if(board[i][k]==p){
                    u++;
                }
            }
            if(u==a){
                status = 1;
                break;
            }
    }
    for(int i=0;i<m-a;i++){
            int v=0;
            for(int k=0;k<a;k++){
                if(board[k][i]==p){
                    v++;
                }
            }
            if(v==a){
                status = 1;
                break;
            }
    }
    for(int i=0;i<m;i++){
            int w=0;
            for(int k=0;k<a;k++){
                if(board[k][i+k]==p){
                    w++;
                }
            }
            if(w==a){
                status = 1;
                break;
            }
    }
    for(int i=0;i<m;i++){
            int q=0;
            for(int k=0;k<a;k++){
                if(board[a-1-k][k]==p){
                    q++;
                }
            }
            if(q==a){
                status = 1;
                break;
            }
    }
    if(status == 1)
    {
        cout<<"player : " <<p<<" won the game"<<endl;
    }
    // Add your evaluation logic here
    return status;
}

int main()
{
    cout<<"enter Two Number m and n : ";
    int m, n, a;
    cin >> m >> n;
    cout <<"enter connecting number : ";
    cin >> a;

    int winstate = 0;

    int** board = new int* [m];
    for (int i = 0; i < m; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    int* count = new int[n];
    cout << "Enter the row number where you wish to place the object" << endl;

    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < m * n; i++)
    {
        int row;

        if (i % 2 == 0)
        {
            cout << "Player 1: ";
            cin >> row;
            row = row - 1;

            if (row >= n)
            {
                cout << "Not a valid position" << endl;
                i--;
                continue;
            }

            if (row < 0)
            {
                cout << "Not a valid position" << endl;
                i--;
                continue;
            }

            board[count[row]][row] = 1;
            count[row]++;
            winstate = evaluate(board, m, n, 1, a);
        }
        else
        {
            cout << "Player 2: ";
            cin >> row;
            row = row - 1;
            if (row >= n)
            {
                cout << "Not a valid position" << endl;
                i--;
                continue;
            }

            if (row < 0)
            {
                cout << "Not a valid position" << endl;
                i--;
                continue;
            }
            board[count[row]][row] = 2;
            count[row]++;
            winstate = evaluate(board, m, n, 2, a);
        }

        if (winstate == 1)
        {
            break;
        }
    }

    if (winstate == 0)
    {
        cout << "draw";
    }
    char xl;
    cout << "Enter any key to exit";
    cin >> xl;


}
