# quad_trees

In this project a slightly more complex version of binary search
trees is implemented. The trees on in this project let us search on two-dimensional spaces,
and extensions to higher dimensional spaces should be obvious. Instead of each node
having at most 2 children, in such trees, nodes have at most 4 children. These children called as TopLeft, TopRight, BottomLeft
and BottomRight. You are given a (possibly very large) database of rectangles. These rectangle objects will look like 



![alt text](http://url/to/img.png)



The coordinate system in this representation is such that, as we go towards right and bottom, the x and y coordinates
(respectively) increase, that is, for a rectangle, Bottom > Top and Right > Left.

A point (x, y), on the Cartesian plane is considered to be inside a rectangle object R (or intersects R), if R.Left <= x < R.Right and R.Top <= y < R.Bottom, that is, the points on the right and bottom boundaries of the rectangle are not considered to be in the rectangle. Given such a point, our tree data structure will enable us to find all rectangles that contain that point. One can obviously do this by keeping all
rectangles in a linked list and searching through the list by checking if the point is inside a rectangle or not, but when you have 1,000,000 or 50,000,000 rectangles2, that will not be very efficient.
