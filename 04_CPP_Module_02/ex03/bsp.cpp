/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:43:40 by mott              #+#    #+#             */
/*   Updated: 2024/09/01 15:46:03 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// The area of a triangle defined by three points A(x1,y1), B(x2,y2) and C(x3,y3) can be calculated using the determinant method. The formula for the area ABC of the triangle is:
// 	area_ABC = 1/2 * | x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) |
// This formula calculates twice the signed area of the triangle, and we take the absolute value to ensure the area is positive, dividing by 2 to get the correct triangle area.
Fixed triangle_area(const Point& one, const Point& two, const Point& three) {
	Fixed area = Fixed(0.5f) * (one.getX() * (two.getY() - three.getY())
							 + two.getX() * (three.getY() - one.getY())
							 + three.getX() * (one.getY() - two.getY()));
	if (area < 0) {
		area = area * Fixed(-1);
	}
	return area;
}

// To determine if a point P(x,y) is strictly inside the triangle ABC, we calculate the areas of three sub-triangles formed by P and the vertices of the triangle ABC:
// 	area_PAB - Area of triangle PAB
// 	area_PBC - Area of triangle PBC
// 	area_PCA - Area of triangle PCA
// The logic is based on the property that if a point is inside a triangle, the sum of the areas of these three sub-triangles will exactly equal the area of the main triangle ABC. Therefore, if:
// 	area_ABC = arae_PAB + area_PBC + area_PCA
// and none of the sub-areas area_PAB, area_PBC or area_PCA are zero, then point P is strictly inside the triangle ABC.
// If any of the sub-areas is zero, it indicates that point P is either on an edge or a vertex of the triangle, which means it is not strictly inside the triangle.
bool bsp(const Point& a, const Point& b, const Point& c, const Point& point) {
	Fixed area_abc = triangle_area(a, b, c);
	Fixed area_pab = triangle_area(point, a, b);
	Fixed area_pbc = triangle_area(point, b, c);
	Fixed area_pca = triangle_area(point, c, a);

	return (area_abc == area_pab + area_pbc + area_pca) && (area_pab != Fixed(0)) && (area_pbc != Fixed(0)) && (area_pca != Fixed(0));
}
