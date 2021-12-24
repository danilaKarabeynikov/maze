#include "pch.h"
#include "Maze.h"

TEST(Maze, 1)
{
	/*int **maze = new int*[12];
	maze[0] = new int[14]{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	maze[1] = new int[14]{ 1,0,0,0,1,0,0,0,0,0,0,0,0,1 };
	maze[2] = new int[14]{ 1,1,1,0,1,0,1,1,1,1,1,0,0,1 };
	maze[3] = new int[14]{ 1,0,0,0,1,0,1,0,0,0,0,0,0,1 };
	maze[4] = new int[14]{ 1,0,1,0,1,0,1,0,0,0,1,1,0,1 };
	maze[5] = new int[14]{ 1,0,1,0,1,0,1,0,1,0,0,0,0,1 };
	maze[6] = new int[14]{ 1,0,0,0,1,0,0,0,1,0,0,1,1,1 };
	maze[7] = new int[14]{ 1,0,1,0,1,0,1,0,1,0,0,0,0,1 };
	maze[8] = new int[14]{ 1,1,1,0,1,0,1,0,1,0,1,1,1,1 };
	maze[9] = new int[14]{ 1,0,0,0,0,0,1,0,1,0,1,0,0,1 };
	maze[10] = new int[14]{ 1,0,0,1,0,0,1,0,1,0,0,0,0,1 };
	maze[11] = new int[14]{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1 };*/

	std::cout << (Maze("1.txt")) << std::endl;
	std::cout << (Maze("2.txt")) << std::endl;
	EXPECT_EQ("Bad Way", Maze("2.txt"));
	EXPECT_EQ("The way is: rrddddddddrruuurruurrdrddldddrrr", Maze("1.txt"));
	EXPECT_EQ("The way is: rrddddddddrruuurruurrdrddldddrrr", Maze("3.txt"));
}