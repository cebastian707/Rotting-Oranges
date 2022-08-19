/*BY::CEBASTAIN SANTIAGO
* LEETCODE 994
*/
#include<iostream>
#include<vector>
#include<queue>
#include<utility>



int orangesRotting(std::vector<std::vector<int>>& grid){
	//variables and DATA STRUCTRUE 
	int fresh = 0;
	int time = 0;
	std::queue<std::pair<int, int>> rotten;


	//first loop keep track of rotten oranges and how much fresh fruit we have
	for (int row = 0; row < grid.size();row++) {
		for (int col = 0; col < grid[row].size();col++){
			//track how many fresh organes we have 
			if (col == 1 ){
				fresh++;
			}
			//track the amount of rotten oranges 
			else if (col == 2) {
				rotten.push(std::make_pair(row,col));
			}
		}
	}


	//while the queue is'nt empty keep looking for
	//rotten oranges
	while (!rotten.empty()){

	}



	return 0;
}




int main(int argc, char* argv[]) {
	std::vector<std::vector<int>> grid = { {2,1,1},
										   {1,1,0},
										   {1,0,1} };

	std::cout << orangesRotting(grid);

	return 0;
}