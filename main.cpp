//
//  main.cpp
//  Gomoku
//
//  Created by Simon Gavins Lee on 14/09/2017.
//  Copyright © 2017 Simon Gavins Lee. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Welcome to Gomoku!" << endl << "Enter the location to place!" << endl;
    char pad[15][15];
    bool player = true;
    int x, y;
    
    for(int ix = 0; ix < 15; ++ix)
        for(int iy = 0; iy < 15; ++iy)
            pad[ix][iy] = '.';
    
    while(true){
        //输出棋盘
        cout << endl << " \t1 2 3 4 5 6 7 8 9 101112131415" << endl;
        for(int ix = 0; ix < 15; ++ix){
            cout << ix + 1 << '\t';
            for(int iy = 0; iy < 15; ++iy)
                cout << pad[ix][iy] << ' ';
        }
        
        player = !player;   //交换棋权
        
        
        //落子及判断
        while(true){
            cout << endl << endl << "Player " << (player ? 'o':'*') << ": ";
            cin >> x >> y;
            if(pad[x-1][y-1] == '.'){
                pad[x-1][y-1] = player ? 'o':'*';
                break;
            }
            else{
                cout << "It's been placed!" << endl;
                continue;
            }
        }
        
        
        //胜利判断
        //横向胜利判断
        int count1 = 0;
        for(int ix = x - 1, iy = y - 1; pad[ix][iy] == (player ? 'o':'*') && ix >= 0; --ix)
            ++count1;
        for(int ix = x - 1, iy = y - 1; pad[ix][iy] == (player ? 'o':'*') && ix <= 14; ++ix)
            ++count1;
        if(count1 >= 6){
            //因为自己这一颗棋遍历时被计了2次
            cout << endl << " \t1 2 3 4 5 6 7 8 9 101112131415" << endl;
            for(int ix = 0; ix < 15; ++ix){
                cout << ix + 1 << '\t';
                for(int iy = 0; iy < 15; ++iy)
                    cout << pad[ix][iy] << ' ';
            }
            cout << endl << "Player " << (player ? 'o':'*') << " wins!" << endl;
            break;
        }
        
        //竖向胜利判断
        int count2 = 0;
        for(int ix = x - 1, iy = y - 1; pad[ix][iy] == (player ? 'o':'*') && iy >= 0; --iy)
            ++count2;
        for(int ix = x - 1, iy = y - 1; pad[ix][iy] == (player ? 'o':'*') && iy <= 14; ++iy)
            ++count2;
        if(count2 >= 6){
            cout << endl << " \t1 2 3 4 5 6 7 8 9 101112131415" << endl;
            for(int ix = 0; ix < 15; ++ix){
                cout << ix + 1 << '\t';
                for(int iy = 0; iy < 15; ++iy)
                    cout << pad[ix][iy] << ' ';
            }
            cout << endl << "Player " << (player ? 'o':'*') << " wins!" << endl;
            break;
        }
        
        //斜向胜利判断
        int count3 = 0;
        for(int ix = x - 1, iy = y - 1; pad[ix][iy] == (player ? 'o':'*') && (iy >= 0 || ix >= 0);){
            ++count3;
            --ix;
            --iy;
        }
        for(int ix = x - 1, iy = y - 1; pad[ix][iy] == (player ? 'o':'*') && (iy <= 14 || ix <= 14); ++iy){
            ++count3;
            ++ix;
            ++iy;
        }
        if(count3 >= 6){
            cout << endl << " \t1 2 3 4 5 6 7 8 9 101112131415" << endl;
            for(int ix = 0; ix < 15; ++ix){
                cout << ix + 1 << '\t';
                for(int iy = 0; iy < 15; ++iy)
                    cout << pad[ix][iy] << ' ';
            }
            cout << endl << "Player " << (player ? 'o':'*') << " wins!" << endl;
            break;
        }
        
        int count4 = 0;
        for(int ix = x - 1, iy = y - 1; pad[ix][iy] == (player ? 'o':'*') && (iy >= 0 || ix <= 14);){
            ++count4;
            ++ix;
            --iy;
        }
        
        for(int ix = x - 1, iy = y - 1; pad[ix][iy] == (player ? 'o':'*') && (iy <= 14 || ix >= 0);){
            ++count4;
            --ix;
            ++iy;
        }
        if(count4 >= 6){
            cout << endl << " \t1 2 3 4 5 6 7 8 9 101112131415" << endl;
            for(int ix = 0; ix < 15; ++ix){
                cout << ix + 1 << '\t';
                for(int iy = 0; iy < 15; ++iy)
                    cout << pad[ix][iy] << ' ';
            }
            cout << endl << "Player " << (player ? 'o':'*') << " wins!" << endl;
            break;
        }
        
        
        cout << endl;
    }

    return 0;
}
