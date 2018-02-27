/*
H-Tree Construction

An H-tree is a geometric shape that consists of a repeating pattern resembles the letter “H”.

It can be constructed by starting with a line segment of arbitrary length, drawing two segments of the same length at right angles to the first through its endpoints, and continuing in the same vein, reducing (dividing) the length of the line segments drawn at each stage by √2.

Here are some examples of H-trees at different levels of depth:

alt depth = 1

alt depth = 2

alt depth = 3

General link: https://i.stack.imgur.com/EIdPG.png

Write a function drawHTree that constructs an H-tree, given its center (x and y coordinates), a starting length, and depth. Assume that the starting line is parallel to the X-axis.

Use the function drawLine provided to implement your algorithm. In a production code, a drawLine function would render a real line between two points. However, this is not a real production environment, so to make things easier, implement drawLine such that it simply prints its arguments (the print format is left to your discretion).

Analyze the time and space complexity of your algorithm. In your analysis, assume that drawLine's time and space complexities are constant, i.e. O(1).

Constraints:

[time limit] 5000ms

[input] double x

[input] double y

[input] double length

[input] double depth

0 ≤ depth ≤ 10
*/

#include <iostream>
#include <cmath>

using namespace std;

void drawLine(double x1, double y1, double x2, double y2) {
  cout << "(" << x1 << "," << y1 << ")-(" << x2 << "," << y2 << ")" << endl;
}

void drawTree(double x, double y, double length, double depth) {
  if(depth == 0)
    return;
  //horizontal
  drawLine(x - (length/2.0), y, x + (length/2.0), y);
  //left vertical
  drawLine(x - (length/2.0), y - (length/2.0), x - (length/2.0), y + (length/2.0));
  //right vertical
  drawLine(x + (length/2.0), y - (length/2.0), x + (length/2.0), y + (length/2.0));
  
  double x1,y1,x2,y2,x3,y3,x4,y4;
  x1 = x - (length/2.0);
  y1 = y - (length/2.0);
  x2 = x - (length/2.0);
  y2 = y + (length/2.0);
  
  x3 = x + (length/2.0);
  y3 = y - (length/2.0);
  x4 = x + (length/2.0);
  y4 = y + (length/2.0);
  
  drawTree(x1, y1, length / sqrt(2), depth-1);
  drawTree(x2, y2, length / sqrt(2), depth-1);
  drawTree(x3, y3, length / sqrt(2), depth-1);
  drawTree(x4, y4, length / sqrt(2), depth-1);
  
}

int main()
{
    std::cout << "Practice makes Perfect!" << std::endl;
    drawTree(4,4,2,1);
    cout << endl;
    drawTree(4,4,2,2);
    return 0;
}

//time - O(4^depth)
//space - O(1)

// drawLine(x1, y1, x2, y2) {
  
// }
//
// drawTree(x, y, length, depth)




