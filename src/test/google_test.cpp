#include <gtest/gtest.h>

#include "point.hpp"
#include "triangle.hpp"
#include "finder.hpp"

void comparePoints(const Point& a, const Point& b){
	EXPECT_DOUBLE_EQ(a.getX(), b.getX());
	EXPECT_DOUBLE_EQ(a.getY(), b.getY());
}
void comparePoints(const Point& a, double x, double y){
	EXPECT_DOUBLE_EQ(a.getX(), x);
	EXPECT_DOUBLE_EQ(a.getY(), y);
}
void compareTrianglesWithPoints(const Triangle& a, 
					double x1, double y1, 
					double x2, double y2, 
					double x3, double y3){
	EXPECT_DOUBLE_EQ(a.getPointA().getX(), x1);
	EXPECT_DOUBLE_EQ(a.getPointA().getY(), y1);
	EXPECT_DOUBLE_EQ(a.getPointB().getX(), x2);
	EXPECT_DOUBLE_EQ(a.getPointB().getY(), y2);
	EXPECT_DOUBLE_EQ(a.getPointC().getX(), x3);
	EXPECT_DOUBLE_EQ(a.getPointC().getY(), y3);
}

void compareTriangles(const Triangle& a, const Triangle& b){
	EXPECT_DOUBLE_EQ(a.getPointA().getX(), b.getPointA().getX());
	EXPECT_DOUBLE_EQ(a.getPointA().getY(), b.getPointA().getY());
	EXPECT_DOUBLE_EQ(a.getPointB().getX(), b.getPointB().getX());
	EXPECT_DOUBLE_EQ(a.getPointB().getY(), b.getPointB().getY());
	EXPECT_DOUBLE_EQ(a.getPointC().getX(), b.getPointC().getX());
	EXPECT_DOUBLE_EQ(a.getPointC().getY(), b.getPointC().getY());
	EXPECT_DOUBLE_EQ(a.getSquare(), b.getSquare());
	EXPECT_DOUBLE_EQ(a.isIsosceles(), b.isIsosceles());
}


TEST(PointTests, PointCreation){
	double x = 1.0;
	double y = 2.0;
	Point point(x, y);
	comparePoints(point, x, y);
}

TEST(PointTests, EmptyPoint){
	Point point;
	comparePoints(point, 0.0, 0.0);
}

TEST(PointTests, CheckDistance){
	Point pointA(3, 0);
	Point pointB(0, 4); 
	EXPECT_DOUBLE_EQ(5.0, pointA.distanceToPoint(pointB));
	EXPECT_DOUBLE_EQ(5.0, pointB.distanceToPoint(pointA));
}

TEST(TriangleTests, TriangleCreationByDouble){
	double x1 = 1.0;
	double y1 = 2.0;
	double x2 = 3.0;
	double y2 = 4.0;
	double x3 = 5.0;
	double y3 = 6.0;
	Triangle triangle(x1, y1, x2, y2, x3, y3);
	compareTrianglesWithPoints(triangle, x1, y1, x2, y2, x3, y3);
}

TEST(TriangleTests, TriangleCreationByPointClass){
	double x1 = 1.0;
	double y1 = 2.0;
	double x2 = 3.0;
	double y2 = 4.0;
	double x3 = 5.0;
	double y3 = 6.0;
	Triangle triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
	compareTrianglesWithPoints(triangle, x1, y1, x2, y2, x3, y3);
}

TEST(TriangleTests, EmptyTriangleCreation){
	Triangle triangle;
	compareTrianglesWithPoints(triangle, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	EXPECT_DOUBLE_EQ(0.0, triangle.getSquare());
}

TEST(TriangleTests, IsoscelesTest){
	Triangle triangle(Point(0, 0), Point(1, 0), Point(0, 1));
	EXPECT_EQ(triangle.isIsosceles(), true);
}

TEST(TriangleTests, NotIsoscelesTest){
	Triangle triangle(Point(1, 1), Point(2, 2), Point(2, 3));
	EXPECT_EQ(triangle.isIsosceles(), false);
}

TEST(TriangleTests, TestSquare){
	Triangle triangle(Point(1, 1), Point(-2, 4), Point(-2, -2));
	EXPECT_DOUBLE_EQ(triangle.getSquare(), 9.0);
}

TEST(FinderTests, Test0){
	MaxTriangleFinder maxTriangleFinder;
	std::ifstream inputFile("../example_tests/test_0.txt");
	maxTriangleFinder.findMaxTriangleInFile(inputFile);
	
	Triangle res = maxTriangleFinder.getMaxIsoscelesTriangle();
	Triangle correctTriangle = Triangle(1000, 0, 0, 1000, 0, 0);

	compareTriangles(res, correctTriangle);
}

TEST(FinderTests, Test1){
	MaxTriangleFinder maxTriangleFinder;
	std::ifstream inputFile("../example_tests/test_1.txt");
	maxTriangleFinder.findMaxTriangleInFile(inputFile);

	Triangle res = maxTriangleFinder.getMaxIsoscelesTriangle();
	Triangle correctTriangle = Triangle(1000, 0, 0, 1000, 0, 0);

	compareTriangles(res, correctTriangle);
}

TEST(FinderTests, Test2){
	MaxTriangleFinder maxTriangleFinder;
	std::ifstream inputFile("../example_tests/test_2.txt");
	maxTriangleFinder.findMaxTriangleInFile(inputFile);

	Triangle res = maxTriangleFinder.getMaxIsoscelesTriangle();
	Triangle correctTriangle = Triangle(Point(-1, -1), Point(10, -1), Point(-1, 10));

	compareTriangles(res, correctTriangle);
}

TEST(FinderTests, Test3){
	MaxTriangleFinder maxTriangleFinder;
	std::ifstream inputFile("../example_tests/test_3.txt");
	maxTriangleFinder.findMaxTriangleInFile(inputFile);

	Triangle res = maxTriangleFinder.getMaxIsoscelesTriangle();
	Triangle correctTriangle = Triangle(Point(-1, -1), Point(10, -1), Point(-1, 10));

	compareTriangles(res, correctTriangle);
}

TEST(FinderTests, Test4){
	MaxTriangleFinder maxTriangleFinder;
	std::ifstream inputFile("../example_tests/test_4.txt");
	maxTriangleFinder.findMaxTriangleInFile(inputFile);
	Triangle res = maxTriangleFinder.getMaxIsoscelesTriangle();
	Triangle correctTriangle = Triangle(Point(0, 0), Point(0, 0), Point(0, 0));

	compareTriangles(res, correctTriangle);
}

int main(int argc, char* argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}