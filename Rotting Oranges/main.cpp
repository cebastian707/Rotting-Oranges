/*BY::CEBASTAIN SANTIAGO
* LEETCODE 994
*/
#include<iostream>
#include<vector>
#include<queue>
#include<utility>



int orangesRotting(std::vector<std::vector<int>>& grid) {
	//variables and DATA STRUCTRUE 
	int fresh = 0;
	int time = -1;
	std::queue<std::pair<int, int>> rotten;
	std::vector<std::vector<int>> directions = { {0,1},{0,-1},{1,0},{-1,0} };

	//first loop keep track of rotten oranges and how much fresh fruit we have
	for (int row = 0; row < grid.size(); row++) {
		for (int col = 0; col < grid[row].size(); col++) {
			//track how many fresh organes we have 
			if (grid[row][col] == 1) {
				fresh++;
			}
			//track the amount of rotten oranges 
			else if (grid[row][col] == 2) {
				rotten.push(std::make_pair(row, col));
			}
		}
	}

	//mark the start of te timer
	rotten.push(std::make_pair(-1, -1));

	//while the queue is'nt empty keep looking for
	//rotten oranges
	while (!rotten.empty()) {
		int row = rotten.front().first;
		int col = rotten.front().second;
		
		rotten.pop();

		if (row == -1) {
			time++;
			
			if (!rotten.empty()) {
				rotten.push(std::make_pair(-1, -1));
			}
		}
		else {
			for (int i = 0; i < directions.size(); i++) {
				int row_neighbor = row + directions[i][0];
				int col_neighbor = col + directions[i][1];

				//boundary check
				if (row_neighbor > grid.size() - 1 || row_neighbor < 0 || col_neighbor < 0 || col_neighbor > grid[0].size()-1) {
					continue;
				}

				//check for fresh oranges
				if (grid[row_neighbor][col_neighbor] == 1) {
					//this know becomes a rotten orange
					grid[row_neighbor][col_neighbor] = 2;
					fresh--;
					rotten.push(std::make_pair(row_neighbor, col_neighbor));
				}

			}
		}
	}

	if (fresh == 0) {
		return time;
	}
	
	else {
		return -1;
	}
}



int main(int argc, char* argv[]) {
	std::vector<std::vector<int>> grid = { {2,1,1},
										   {1,1,0},
										   {0,1,1} };

	std::cout << orangesRotting(grid);

	return 0;
}