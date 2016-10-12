#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class SnakeGame {
private:
    int score;
    queue<pair<int, int> > snake;
    vector<vector<bool> > table;
    int w;
    int h;
    vector<pair<int, int>> f;
    vector<pair<int, int>>::iterator it;
    bool isDead(int x, int y){
        if(x < 0||x >= h||y < 0||y >= w||table[x][y] || score == -1){
            score = -1;
            return true;
        }
        else
            return false;
        
    }
    bool isFood(int x, int y){
        if(it == f.end())   return false;
        int f_x = (*it).first, f_y = (*it).second;
        if(f_x == x && f_y == y){
            ++it;
            ++score;
            return true;
        }
        else{
            return false;
        }
    }
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        score = 0;
        snake.push(make_pair(0,0));
        w = width;
        h = height;
        f = food;
        it = f.begin();
        table = vector<vector<bool> >(h, vector<bool>(w, false));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> head = snake.back(); 
        int x = head.first, y = head.second;
        if(direction == "U")    x--;
        else if(direction == "D") x++;
        else if(direction == "L") y--;
        else if(direction == "R") y++;
        
        if(isDead(x,y)){
            return -1;
        }
        else{
            if(!isFood(x,y)){
                // if not food, advance
                table[snake.front().first][snake.front().second] = false;
                snake.pop();
            }
            snake.push(make_pair(x,y));
            table[x][y] = true;
        }
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */

int main(int argc, char ** argv){
	vector<pair<int, int> > food;
	food.push_back(make_pair(1,2));
	food.push_back(make_pair(0,1));
	SnakeGame obj = SnakeGame(3, 2, food);
	cout<<"Step 1: "<<obj.move("R")<<endl;
	cout<<"Step 2: "<<obj.move("D")<<endl;
	cout<<"Step 3: "<<obj.move("R")<<endl;
	cout<<"Step 4: "<<obj.move("U")<<endl;
	cout<<"Step 5: "<<obj.move("L")<<endl;
	cout<<"Step 6: "<<obj.move("U")<<endl;
	return 0;
}
