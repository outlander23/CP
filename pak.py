from fractions import Fraction
import math

def incircle_radius_fraction(a, b, c, max_denominator=1000000):
    """
    Calculate the radius of the incircle of a triangle and return it as a reduced fraction.
    
    Parameters:
    - a, b, c: Lengths of the triangle's sides
    - max_denominator: The maximum denominator value for the Fraction approximation
    
    Returns:
    - Fraction representing the inradius
    """
    # Calculate semi-perimeter
    s = (a + b + c) / 2



    # Calculate area using Heron's formula
    area = math.sqrt(s * (s - a) * (s - b) * (s - c))

    # Calculate the radius of the incircle
    radius = area / s

   
    print(radius*radius)




# Example Usage:
a = 5
b = 7
c = 9
incircle_radius_fraction(a, b, c)