"""Test suite of unit tests for simple PyBind module"""
import unittest
import numpy as np

# import module created using PyBind
import utils


class UtilsTest(unittest.TestCase):
    """Test utility functions"""

    def setUp(self) -> None:
        """Provide some local variables for each test"""
        self.i3 = 3
        self.i4 = 4
        self.i5 = 5
        self.f3 = float(3.0)
        self.f4 = float(4.0)
        self.f5 = float(5.0)
        self.d3 = np.float64(3.0)
        self.d4 = np.float64(4.0)
        self.d5 = np.float64(5.0)

    def test_add(self):
        """Expectation: add two numbers using correct template"""
        with self.subTest("Testing add() using ints"):
            computed = utils.add(self.i3, self.i4)
            self.assertIsInstance(computed, int)
            self.assertEqual(computed, int(3 + 4))

        with self.subTest("Testing add() using floats"):
            computed = utils.add(self.f3, self.f4)
            self.assertIsInstance(computed, float)
            self.assertEqual(computed, self.f3 + self.f4)

    def test_subtract(self):
        """Expectation: subtract one number from another using C++ lambda function"""
        with self.subTest("Testing subtract() using ints"):
            computed = utils.subtract(self.i3, self.i4)
            self.assertIsInstance(computed, int)
            self.assertEqual(computed, int(3 - 4))

        with self.subTest("Testing subtract() using floats"):
            computed = utils.subtract(self.f3, self.f4)
            self.assertIsInstance(computed, float)
            self.assertEqual(computed, self.f3 - self.f4)

    def test_divide(self):
        """Expectation: divide one number by another using the correct template"""
        with self.subTest("Testing divide() using integers"):
            computed = utils.divide(self.i3, self.i4)
            self.assertIsInstance(computed, int)
            self.assertEqual(computed, int(self.i3 / self.i4))

        with self.subTest("Testing divide() using floats"):
            computed = utils.divide(self.f3, self.f4)
            self.assertIsInstance(computed, float)
            self.assertEqual(computed, self.f3 / self.f4)

    def test_hyp(self):
        """Expectation: hypotenuse is computed using the correct template"""
        with self.subTest(msg="Testing hyp() using ints"):
            computed = utils.hyp(self.i3, self.i4)
            hyp_int = int(np.power(self.i3 ** 2 + self.i4 ** 2, 0.5))
            self.assertIsInstance(computed, int)
            self.assertEqual(computed, hyp_int)

        with self.subTest(msg="Testing hyp() using floats"):
            computed = utils.hyp(self.f3, self.f4)
            hyp_float = np.power(self.f3 ** 2 + self.f4 ** 2, 0.5)
            self.assertIsInstance(computed, float)
            self.assertEqual(computed, hyp_float)


if __name__ == "__main__":
    unittest.main(verbosity=3)
