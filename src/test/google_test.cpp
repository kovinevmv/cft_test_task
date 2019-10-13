#include <gtest/gtest.h>

#include "point.hpp"
#include "triangle.hpp"

TEST(PointTests, PointCreation){
	double x = 1.0;
	double y = 2.0;
	Point point(x, y);
	EXPECT_DOUBLE_EQ(point.getX(), x);
	EXPECT_DOUBLE_EQ(point.getY(), y);
}

TEST(PointTests, EmptyPoint){
	Point point;
	EXPECT_DOUBLE_EQ(point.getX(), 0.0);
	EXPECT_DOUBLE_EQ(point.getY(), 0.0);
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
	EXPECT_DOUBLE_EQ(x1, triangle.getPointA().getX());
	EXPECT_DOUBLE_EQ(y1, triangle.getPointA().getY());
	EXPECT_DOUBLE_EQ(x2, triangle.getPointB().getX());
	EXPECT_DOUBLE_EQ(y2, triangle.getPointB().getY());
	EXPECT_DOUBLE_EQ(x3, triangle.getPointC().getX());
	EXPECT_DOUBLE_EQ(y3, triangle.getPointC().getY());
}

TEST(TriangleTests, TriangleCreationByPointClass){
	double x1 = 1.0;
	double y1 = 2.0;
	double x2 = 3.0;
	double y2 = 4.0;
	double x3 = 5.0;
	double y3 = 6.0;
	Triangle triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
	EXPECT_DOUBLE_EQ(x1, triangle.getPointA().getX());
	EXPECT_DOUBLE_EQ(y1, triangle.getPointA().getY());
	EXPECT_DOUBLE_EQ(x2, triangle.getPointB().getX());
	EXPECT_DOUBLE_EQ(y2, triangle.getPointB().getY());
	EXPECT_DOUBLE_EQ(x3, triangle.getPointC().getX());
	EXPECT_DOUBLE_EQ(y3, triangle.getPointC().getY());
}

TEST(TriangleTests, EmptyTriangleCreation){
	Triangle triangle;
	EXPECT_DOUBLE_EQ(0.0, triangle.getPointA().getX());
	EXPECT_DOUBLE_EQ(0.0, triangle.getPointA().getY());
	EXPECT_DOUBLE_EQ(0.0, triangle.getPointB().getX());
	EXPECT_DOUBLE_EQ(0.0, triangle.getPointB().getY());
	EXPECT_DOUBLE_EQ(0.0, triangle.getPointC().getX());
	EXPECT_DOUBLE_EQ(0.0, triangle.getPointC().getY());
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

int main(int argc, char* argv[]){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}